//
// Created by tami on 2024/3/8.
//

#include "Core/GameManager.h"

namespace Core {

    GameManager::GameManager() {
       m_player = std::make_shared<Player::CelPlayer>();
       m_MapManager = std::make_shared<Level::CelMapManager>(this);
    }
    void GameManager::Awake() {
        m_player->UpdateSolid(m_MapManager->AllObject);
        m_player->KillPlayer();
    }

    void GameManager::Update() {
        m_MapManager->DrawALL();
        m_player->Update();
        m_player->Draw();
    }

    Player::CelPlayer& GameManager::GetPlayer() {
        return *m_player;
    }

    Level::CelMapManager& GameManager::GetMapManager() {
        return *m_MapManager;
    }


} // Core