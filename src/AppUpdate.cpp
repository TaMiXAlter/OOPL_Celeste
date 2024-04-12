#include "App.hpp"

#include "Object/CelGameObject.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"
#include "Util/Input.hpp"

void App::Update() {

    m_CelMapManager->DrawALL();
    m_Player->Update();
    m_Player->Draw();
    /*
     * Do not touch the code below as they serve the purpose for
     * closing the window.
     */
    if (Util::Input::IsKeyUp(Util::Keycode::ESCAPE) ||
        Util::Input::IfExit()) {
        m_CurrentState = State::END;
    }
}

