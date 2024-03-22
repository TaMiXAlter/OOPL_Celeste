#ifndef APP_HPP
#define APP_HPP

#include "CelUtil/CelGameObject.hpp"
#include "Player/CelPlayer.h"
#include "pch.hpp" // IWYU pragma: export
#include <memory>

class App {
public:
    enum class State {
        START,
        UPDATE,
        END,
    };

    State GetCurrentState() const { return m_CurrentState; }

    void Start();

    void Update();

    void End(); // NOLINT(readability-convert-member-functions-to-static)

private:
    void ValidTask();

private:
    State m_CurrentState = State::START;

    /**GameObjects*/
    std::shared_ptr<CelUtil::CelGameObject> m_CelTestObject;
    std::shared_ptr<CelUtil::CelGameObject> m_Floor;
    /** Collection of Solid*/
    std::vector<std::shared_ptr<CelUtil::CelGameObject>> AllObject;

    std::shared_ptr<Player::CelPlayer> m_Player;
};

#endif
