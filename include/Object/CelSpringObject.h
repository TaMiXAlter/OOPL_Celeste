//
// Created by tami on 2024/3/29.
//

#ifndef PICO8_CELESTE_CELSPRINGOBJECT_H
#define PICO8_CELESTE_CELSPRINGOBJECT_H

#include "CelGameObject.hpp"
namespace Object {

/**todo: Spring on Box*/
class CelSpringObject: public Object::CelGameObject{
public:
    CelSpringObject(glm::vec2 Initposition = glm::vec2(0,0)){
        SetImage(RESOURCE_DIR"/Imgs/Celeste_objects/spring1.png");
        m_Transform.translation = Initposition;
        m_Transform.scale = glm::vec2(2,2);
    };
};

} // Object

#endif //PICO8_CELESTE_CELSPRINGOBJECT_H
