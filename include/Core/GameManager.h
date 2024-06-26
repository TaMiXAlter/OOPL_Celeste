//
// Created by tami on 2024/3/8.
//

#ifndef PICO8_CELESTE_GAMEMANAGER_H
#define PICO8_CELESTE_GAMEMANAGER_H

#include "Player/CelPlayer.h"
#include "Level/CelMapManager.h"
#include "Util/Text.hpp"
namespace Core {

class GameManager {
    public:
        GameManager();
        void Awake();
        void Update();
        Player::CelPlayer& GetPlayer();
        Level::CelMapManager& GetMapManager();
    private:
        int m_LevelNow;
        std::shared_ptr<Player::CelPlayer>   m_player;
        std::shared_ptr<Level::CelMapManager>  m_MapManager;
    };
} // Core

#endif //PICO8_CELESTE_GAMEMANAGER_H
