//
// Created by tami on 2024/3/8.
//

#ifndef PICO8_CELESTE_CELPLAYERCONTROLLER_H
#define PICO8_CELESTE_CELPLAYERCONTROLLER_H

#include "Player/CelPlayer.hpp"
namespace Player {

    class CelPlayerController {
    public:
        explicit CelPlayerController(CelPlayer* MyPlayer);

        /**Singleton*/
        static CelPlayerController& getInstance(CelPlayer *MyPlayer) ;

        void Update();
    private:
        CelPlayer* m_player;

        static CelPlayerController* sInstance;
    };

} // Player

#endif //PICO8_CELESTE_CELPLAYERCONTROLLER_H
