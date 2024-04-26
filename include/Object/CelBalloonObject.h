//
// Created by tami on 2024/4/20.
//

#ifndef PICO8_CELESTE_CELBALLOONOBJECT_H
#define PICO8_CELESTE_CELBALLOONOBJECT_H
#include "CelGameObject.hpp"

namespace Object{
    class CelBalloonObject : public Object::CelGameObject{
    public:
        CelBalloonObject(glm::vec2 Initposition);
    };
}



#endif //PICO8_CELESTE_CELBALLOONOBJECT_H
