# ifndef PLAYERCONTROLLER_HPP
# define PLAYERCONTROLLER_HPP

#include "CelUtil/CelGameObject.hpp"

namespace Player {
    class CelPlayer: public CelUtil::CelGameObject{
    public:
        CelPlayer( const std::string &ImagePath);

        /** Collider Checker*/
        bool OnHit(CelGameObject* TargetActor);

        /** Moving Function*/
        void MoveLeft();
        void MoveRight();

    };
};

#endif