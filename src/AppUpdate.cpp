#include "App.hpp"

#include "CelUtil/CelGameObject.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"


void App::Update() {

//    LOG_INFO(AllObject.size());
    for (int i = 0; i < int(AllObject.size()); ++i) {
        AllObject[i]->Draw();
    }

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

