//
// Created by tami on 2024/4/8.
//

#ifndef PICO8_CELESTE_CELSPIKEOBJECT_H
#define PICO8_CELESTE_CELSPIKEOBJECT_H
#include "CelGameObject.hpp"
#include "../../PTSD/lib/glm/glm/vec2.hpp"

namespace Object{
    class CelSpikeObject :public CelGameObject{
    public:
        CelSpikeObject(glm::vec2 Initposition = glm::vec2(0,0));
        glm::vec2 GetVertualLine() override;
    };
}
#endif //PICO8_CELESTE_CELSPIKEOBJECT_H
