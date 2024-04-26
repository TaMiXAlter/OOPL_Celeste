//
// Created by tami on 2024/4/8.
//
#include "Object/CelSpikeObject.h"
namespace Object{
    CelSpikeObject::CelSpikeObject(glm::vec2 Initposition) {
        SetImage(RESOURCE_DIR"/Imgs/Celeste_objects/spikes.png");
        m_Transform.translation = Initposition;
        m_Transform.scale = glm::vec2(1.9,1.9);
    }

    glm::vec2 CelSpikeObject::GetVertualLine() {
        const float Heigth= this->GetScaledSize().y;
        const float YPosition = this->m_Transform.translation.y ;

        return {round(YPosition - (Heigth/2)),round(YPosition)};
    }
}