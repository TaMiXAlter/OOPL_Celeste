#ifndef APP_HPP
#define APP_HPP

#include "Object/CelGameObject.hpp"
#include "Player/CelPlayer.h"
#include "pch.hpp" // IWYU pragma: export
#include "Object/CelSolidObject.h"
#include "Object/CelSpringObject.h"
#include <memory>
#include "Level/CelMapManager.h"
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

    /**creat GM */
    std::shared_ptr<Core::GameManager > GM;
};

#endif
