//
// Created by tami on 2024/4/7.
//

#include "Level/CelMapManager.h"
#include "Object/CelSolidObject.h"
#include "Object/CelSpikeObject.h"
using std::string;
namespace Level {

    CelMapManager::CelMapManager(std::shared_ptr<Player::CelPlayer> setPlayer) {
        m_player = setPlayer;
        //todo:: change this to different logic
        InitLevel();
    }

    void CelMapManager::DrawALL() {
        for(int i = 0 ;i<AllObject.size();i++){
            AllObject[i]->Draw();
        }
    }

    void CelMapManager::InitLevel() {
        std::string SolidPath = RESOURCE_DIR"/Imgs/Celeste_Solid1/mid1.png";
        for(int y = 0; y < 16; y++){
            for (int x = 0; x < 16; ++x) {
                //get position
                glm::vec2 currentPosition = m_StartPoint + glm::vec2 (m_TileWidth * x, -m_TileHeight * y);
                switch (Levels->Level1.MapGrid[y][x]) {
                    case 1:
                        //todo:: need to fix in future
                        m_player->SetSpawnPosition(currentPosition);
                        break;
                    case 2:
                        //todo: add different solid logic ,from now only mid solid
                        AllObject.push_back(std::make_shared<Object::CelSolidObject>(GetSolidPath(Levels->Level1,x,y),currentPosition));
                        break;
                    case 3:
                        AllObject.push_back(std::make_shared<Object::CelSpikeObject>(currentPosition));
                        break;
                }
            }
        }
    }

    std::string CelMapManager::GetSolidPath(CelBase LevelData, int deltaX, int deltaY) {
        bool Top = deltaY-1 == -1 ||LevelData.MapGrid[deltaY-1][deltaX] == 2;
        bool Bottom = deltaY+1 == 16  ||LevelData.MapGrid[deltaY+1][deltaX] == 2;
        bool Right = deltaX+1 == 16 ||LevelData.MapGrid[deltaY][deltaX+1] == 2;
        bool Left = deltaX-1 == -1 ||LevelData.MapGrid[deltaY][deltaX-1] == 2;

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


}