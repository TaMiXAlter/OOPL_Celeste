#include "App.hpp"
#include "Player/CelPlayer.hpp"
#include "Util/Logger.hpp"
#include <memory>

void App::Start() {
    LOG_TRACE("Start");
    m_CurrentState = State::UPDATE;

    /***/
    m_Player = std::make_shared<Player::CelPlayer>(RESOURCE_DIR"/Player/Character.png");
}