//
// Created by tami on 2024/4/20.
//

#include "Object/CelBalloonObject.h"

namespace Object{

    CelBalloonObject::CelBalloonObject(glm::vec2 Initposition) {
        SetImage(RESOURCE_DIR"/Imgs/Celeste_objects/balloon.png");
        this->m_Transform.translation = Initposition;
    }

};
