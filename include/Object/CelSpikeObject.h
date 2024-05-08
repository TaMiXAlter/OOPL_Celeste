//
// Created by tami on 2024/4/8.
//

#ifndef PICO8_CELESTE_CELSPIKEOBJECT_H
#define PICO8_CELESTE_CELSPIKEOBJECT_H
#include "CelGameObject.hpp"
#include "glm/vec2.hpp"

namespace Object{
    class CelSpikeObject :public CelGameObject{
    public:
        CelSpikeObject(glm::vec2 Initposition,float Rota) {
            SetImage(RESOURCE_DIR"/Imgs/Celeste_objects/spikes.png");
            m_Transform.translation = Initposition;
            m_Transform.scale = glm::vec2(1.9,1.9);
            m_Transform.rotation = glm::radians(Rota);
        }
        glm::vec2 GetVertualLine() override{
            const float Heigth= this->GetScaledSize().y;
            const float YPosition = this->m_Transform.translation.y ;

            return {round(YPosition - (Heigth/2)),round(YPosition)};
        }
    };
}
#endif //PICO8_CELESTE_CELSPIKEOBJECT_H
