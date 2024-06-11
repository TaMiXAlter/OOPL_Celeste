//
// Created by tami on 2024/3/8.
//

#include "Core/GameManager.h"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"

namespace Core {

    GameManager::GameManager() {
       m_player = std::make_shared<Player::CelPlayer>();
       m_MapManager = std::make_shared<Level::CelMapManager>(this);
        m_LevelNow = 1;
    }
    void GameManager::Awake() {
        m_MapManager->LoadLevel(m_LevelNow);
        m_player->UpdateSolid(m_MapManager->AllObject);
        m_player->KillPlayer();
    }

    void GameManager::Update() {
        m_player->Update();
        m_player->Draw();
        m_MapManager->DrawALL();
        /**Revive Player*/
        if(!m_player->m_isAlive){
            m_player->RevivePlayer();
            m_MapManager->ReviveAll();
        }
        /**Kill Player for height*/
        if(m_player->m_Transform.translation.y<-260){
            m_player->KillPlayer();
        }
        //For Testing
        if(m_player->m_Transform.translation.y >= 256 || Util::Input::IsKeyDown(Util::Keycode::F)){
            if(m_LevelNow == 22){
                m_player->PlayerMovement->SetMaxDashAmount(2);
            }
            m_LevelNow++;
            m_MapManager->LoadLevel(m_LevelNow);
            m_player->UpdateSolid(m_MapManager->AllObject);
            m_player->KillPlayer();
        }else if(Util::Input::IsKeyDown(Util::Keycode::D)){
            if(m_LevelNow == 22){
                m_player->PlayerMovement->SetMaxDashAmount(1);
            }
            m_LevelNow --;
            m_MapManager->LoadLevel(m_LevelNow);
            m_player->UpdateSolid(m_MapManager->AllObject);
            m_player->KillPlayer();
        }else if(Util::Input::IsKeyDown(Util::Keycode::A)){
            //infinite Dash
            if(m_player->PlayerMovement->GetDashDelta() == 1){
                m_player->PlayerMovement->SetDashDelta(0);
            }else{
                m_player->PlayerMovement->SetDashDelta(1);
            }
        }

    }

    Player::CelPlayer& GameManager::GetPlayer() {
        return *m_player;
    }

    Level::CelMapManager& GameManager::GetMapManager() {
        return *m_MapManager;
    }


} // Core