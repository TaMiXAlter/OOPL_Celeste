//
// Created by tami on 2024/4/7.
//

#ifndef PICO8_CELESTE_CELMAPMANAGER_H
#define PICO8_CELESTE_CELMAPMANAGER_H

#include "CelLevels.h"
#include "config.hpp"
#include "Player/CelPlayer.h"
#include "CelLevels.h"
#include "Object/CelGameObject.hpp"

namespace Core{
    class GameManager;
}
namespace Level {
    class CelMapManager {
    /**
     * 畫面尺寸為512*512
     * 為16*16的tile組合而成
     * */
    public:
        CelMapManager(Core::GameManager* GM);
        void DrawALL();
        void LoadLevel(int LevelNum);
        std::vector<std::shared_ptr<Object::CelGameObject>> AllObject;
        /**Revive*/
        void ReviveAll();
    private:
        std::vector<std::shared_ptr<Object::CelGameObject>> m_ObjectsToRevive;
    private:
        /**Auto Adap */
        /*solid**/
        std::string GetSolidPath(const char* LevelData, int deltaX, int deltaY);
        std::string CombineString(std::string addString);
        /*Spike **/
        float GetAutoRotation(const char* LevelData,int MyX,int MyY);
        Core::GameManager* m_GM;
    private:
        /**propety*/
        const int m_GridWidth = 16;
        const int m_GridHeight =16;
        const int m_TileWidth = 512/m_GridWidth;
        const int m_TileHeight= 512/m_GridHeight;
        /**start from top-left
         * (-1*WINDOW_WIDTH/2)+m_TileWidth/2,(WINDOW_HEIGHT/2)-m_TileHeight/2 不知道為啥不能用*/
        const glm::vec2 m_StartPoint = glm::vec2 (-240,240);
    private:
        /**get level data*/
        const CelLevels* Levels = new CelLevels();
    };

} // Level

#endif //PICO8_CELESTE_CELMAPMANAGER_H
