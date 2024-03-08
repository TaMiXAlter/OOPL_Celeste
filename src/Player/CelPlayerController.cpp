//
// Created by tami on 2024/3/8.
//

#include "Player/CelPlayerController.h"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"

namespace Player {
    CelPlayerController::CelPlayerController(CelPlayer *MyPlayer) {
        m_player = MyPlayer;
    }

    CelPlayerController &CelPlayerController::getInstance(CelPlayer *MyPlayer) {
        if (sInstance == nullptr) {
            sInstance = new CelPlayerController(MyPlayer);
        }
        return *sInstance;

    }

    void CelPlayerController::Update() {
        if(Util::Input::IsKeyDown(Util::Keycode::RIGHT)){
            m_player->MoveRight();
        }
    }


} // Player