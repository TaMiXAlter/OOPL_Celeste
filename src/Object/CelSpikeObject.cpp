//
// Created by tami on 2024/4/8.
//
#include "Object/CelSpikeObject.h"
namespace Object{
    CelSpikeObject::CelSpikeObject(glm::vec2 Initposition) {
        SetImage(RESOURCE_DIR"/Imgs/Celeste_objects/spikes.png");
        m_Transform.translation = Initposition;
    }
}