#include "App.hpp"
#include "Player/CelPlayer.h"
#include "Util/Logger.hpp"
#include "Util/Renderer.hpp"
#include <memory>
#include "Core/GameManager.h"
void App::Start() {
    LOG_TRACE("Start");
    m_CurrentState = State::UPDATE;

    GM = std::make_shared<Core::GameManager>();
    GM->Awake();
}