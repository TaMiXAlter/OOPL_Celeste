//
// Created by tami on 2024/3/29.
//

#include "Object/CelSpringObject.h"

namespace Object {

    CelSpringObject::CelSpringObject(glm::vec2 Initposition){
        SetImage(RESOURCE_DIR"/Imgs/Celeste_objects/spring1.png");
        m_Transform.translation = Initposition;
        m_Transform.scale = glm::vec2(2,2);
    }
} // Object