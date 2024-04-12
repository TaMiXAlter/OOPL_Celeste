#include "App.hpp"
#include "Player/CelPlayer.h"
#include "Util/Logger.hpp"
#include "Util/Root.hpp"
#include <memory>

void App::Start() {
    LOG_TRACE("Start");
    m_CurrentState = State::UPDATE;

    /**creat player */
    m_Player = std::make_shared<Player::CelPlayer>(RESOURCE_DIR"/Imgs/Celeste_Player/0.png");
    m_CelMapManager = std::make_shared<Level::CelMapManager>(m_Player);
    m_Player->UpdateSolid(m_CelMapManager->AllObject);
    m_Player->KillPlayer();

}