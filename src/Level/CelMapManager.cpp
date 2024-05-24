//
// Created by tami on 2024/4/7.
//

#include "Level/CelMapManager.h"
#include "Core/GameManager.h"

#include "Object/CelSolidObject.h"
#include "Object/CelSpikeObject.h"
#include "Object/CelSpringObject.h"
#include "Object/CelBoxObject.h"
#include "Object/CelBalloonObject.h"
#include "Object/CelCloudObject.h"
#include "Object/CelCoinObject.h"

using std::string;
namespace Level {

    CelMapManager::CelMapManager(Core::GameManager* GM) {
        m_GM = GM;
    }

    void CelMapManager::DrawALL() {
        for(long unsigned int i = 0 ;i < AllObject.size();i++){
            AllObject[i]->Update();
            AllObject[i]->Draw();
        }
    }

    void CelMapManager::LoadLevel(int LevelNum) {
        /**remove this in better way*/
        std::shared_ptr<Object::CelSpringObject> tempSpring;
        if(LevelNum > Levels->LevelContainer.size() || LevelNum < 1){
            LOG_ERROR("Out of Map Array");
            return;
        }
        AllObject.clear();
        const char* LevelData = Levels->LevelContainer[LevelNum-1];
        for(int y = 0; y < 16; y++){
            for (int x = 0; x < 16; ++x) {
                //get position
                glm::vec2 currentPosition = m_StartPoint + glm::vec2 (m_TileWidth * x, -m_TileHeight * y);
                glm::vec2 nextPosition = m_StartPoint + glm::vec2 (m_TileWidth * (x+1), -m_TileHeight * y);
                switch (LevelData[x+y*m_GridWidth]) {
                    case 'p':
                        //todo:: need to fix in future
                        m_GM->GetPlayer().SetSpawnPosition(currentPosition);
                        break;
                    case 's':
                        AllObject.push_back(std::make_shared<Object::CelSolidObject>(GetSolidPath(LevelData,x,y),currentPosition));
                        break;
                    case 'k':
                        AllObject.push_back(std::make_shared<Object::CelSpikeObject>(currentPosition, GetAutoRotation(LevelData,x,y)));
                        break;
                    case 'S':
                        if(LevelData[x+(y+1)*m_GridWidth] == 'b'){
                            tempSpring =  std::make_shared<Object::CelSpringObject>(currentPosition,true);
                            AllObject.push_back(tempSpring);
                        }else{
                            AllObject.push_back(std::make_shared<Object::CelSpringObject>(currentPosition,false));
                        }
                        break;
                    case 'b':
                        if(LevelData[x+(y-1)*m_GridWidth] == 'S'){
                            std::shared_ptr<Object::CelBoxObject> box = std::make_shared<Object::CelBoxObject>(currentPosition);
                            if(tempSpring){
                                tempSpring->AddOnBounceFunction(std::string ("BoxBroken"),[box](){box->StartBroken();});
                            }else{
                                LOG_ERROR("Can't Find Target Spring ");
                            }
                            AllObject.push_back(box);
                        }else{
                            AllObject.push_back(std::make_shared<Object::CelBoxObject>(currentPosition));
                        }
                        break;
                    case 'B':
                        AllObject.push_back(std::make_shared<Object::CelBalloonObject>(currentPosition));
                        break;
                    case 'C':
                        AllObject.push_back(std::make_shared<Object::CelCloudObject>(currentPosition,-1,true));
                        AllObject.push_back(std::make_shared<Object::CelCloudObject>(nextPosition,-1,false));
                        break;
                    case 'c':
                        AllObject.push_back(std::make_shared<Object::CelCloudObject>(currentPosition,1,true));
                        AllObject.push_back(std::make_shared<Object::CelCloudObject>(nextPosition,1,false));
                        break;
                    case 'd':
                        AllObject.push_back(std::make_shared<Object::CelCoinObject>(currentPosition));
                }
            }
        }
    }

    std::string CelMapManager::GetSolidPath(const char* LevelData, int x, int y) {
        bool Top = y-1 == -1 ||LevelData[x+(y-1)*m_GridWidth] == 's';
        bool Bottom = y+1 == 16  ||LevelData[x+(y+1)*m_GridWidth] == 's';
        bool Right = x+1 == 16 ||LevelData[(x+1)+y*m_GridWidth] == 's';
        bool Left = x-1 == -1 ||LevelData[(x-1)+y*m_GridWidth] == 's';

        /**全部的可能性
         * 1.都沒有 mono
         * 2.只有上面 vertual_bottom
         *      a. 上下 vertual_mid
         *      b. 上右 bottomleft
         *      c. 上左 bottomright
         *      d. 上左右 bottom
         *      e. 上下右 left
         *      f. 上下左 right
         * 3.只有下面 vertual_top
         *      a. 下右 topleft
         *      b, 下左 topright
         *      c. 下左右 top
         * 4.只有右邊 horizon_left
         * 5.只有左邊 horizon_right
         *      a. 左右 horizon_mid
         * 6.上下左右 mid1 || mid2
        */
        if(Top){
            if(Bottom){
                //todo: 讓mid2 隨機出現
                if(Right && Left) return CombineString("mid1");//6
                if(Right)return CombineString("left");//2_e
                if(Left) return CombineString("right");//2_f
                return CombineString("vertual_mid");//2_a
            }else if(Right){
                if(Left) return CombineString("bottom");//2_d
                return CombineString("bottomleft");//2_b
            }else if(Left){
                return CombineString("bottomright");//2_c
            }
            return CombineString("vertual_bottom");//2
        }else{
            if(Bottom){
                if(Right && Left) return CombineString("top");//3_c
                if(Right)return CombineString("topleft");//3_a
                if(Left) return CombineString("topright");//3_b
                return CombineString("vertual_top");//3
            }
            if(Right && Left) return CombineString("horizon_mid");//5_a
            if(Right)return CombineString("horizon_left");//4
            if(Left) return CombineString("horizon_right");//5
            return CombineString("mono");//1
        }
    }
    std::string CelMapManager::CombineString(std::string addString) {
        return RESOURCE_DIR"/Imgs/Celeste_Solid1/"+addString+".png";
    }

    float CelMapManager::GetAutoRotation(const char* LevelData, int x, int y) {
        bool Top = y-1 == -1 ||LevelData[x+(y-1)*m_GridWidth] == 's';
        bool Bottom = y+1 == 16  ||LevelData[x+(y+1)*m_GridWidth] == 's';
        bool Right = x+1 == 16 ||LevelData[(x+1)+y*m_GridWidth] == 's';
        bool Left = x-1 == -1 ||LevelData[(x-1)+y*m_GridWidth] == 's';

        if(Top) return 180;
        if(Bottom) return 0;
        if(Right) return 90;
        if(Left) return 270;
    }


}