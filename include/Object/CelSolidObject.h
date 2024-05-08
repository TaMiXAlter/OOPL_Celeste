//
// Created by tami on 2024/3/29.
//

#ifndef PICO8_CELESTE_CELSOLIDOBJECT_H
#define PICO8_CELESTE_CELSOLIDOBJECT_H

#include "CelGameObject.hpp"
namespace Object{

    class CelSolidObject : public CelGameObject {
    public:
        CelSolidObject(const std::string& ImagePath,glm::vec2 Initposition = glm::vec2(0,0)){
            SetImage(ImagePath);
            m_Transform.translation = Initposition;
        };
    };

} // Object

#endif //PICO8_CELESTE_CELSOLIDOBJECT_H
