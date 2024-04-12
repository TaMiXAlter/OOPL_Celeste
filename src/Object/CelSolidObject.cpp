//
// Created by tami on 2024/3/29.
//

#include "Object/CelSolidObject.h"

namespace Object {
    CelSolidObject::CelSolidObject(const std::string &ImagePath, glm::vec2 Initposition){
        SetImage(ImagePath);
        m_Transform.translation = Initposition;
    }
} // Object