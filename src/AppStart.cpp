#include "App.hpp"
#include "Player/CelPlayer.h"
#include "Util/Logger.hpp"
#include <memory>

void App::Start() {
    LOG_TRACE("Start");
    m_CurrentState = State::UPDATE;

    /** creat map */
    m_CelTestObject = std::make_shared<CelUtil::CelGameObject>(RESOURCE_DIR"/Solid/Block.jpeg",glm::vec2 (200,-50));
    m_Floor = std::make_shared<CelUtil::CelGameObject>(RESOURCE_DIR"/Solid/Floor.jpg",glm::vec2 (0,-300));



    AllObject.push_back(m_Floor);
    AllObject.push_back(m_CelTestObject);
    /**creat player */
    m_Player = std::make_shared<Player::CelPlayer>(RESOURCE_DIR"/Player/Character.png");
    m_Player->UpdateSolid(AllObject);

}