//
// Created by tami on 2024/3/29.
//

#ifndef PICO8_CELESTE_CELSPRINGOBJECT_H
#define PICO8_CELESTE_CELSPRINGOBJECT_H

#include "CelGameObject.hpp"
namespace Object {

class CelSpringObject: public Object::CelGameObject{
public:
    CelSpringObject(glm::vec2 Initposition = glm::vec2(0,0));
    };

} // Object

#endif //PICO8_CELESTE_CELSPRINGOBJECT_H
