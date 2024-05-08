//
// Created by tami on 5/3/24.
//

#ifndef PICO8_CELESTE_CELCLOUDOBJECT_H
#define PICO8_CELESTE_CELCLOUDOBJECT_H
#include "CelGameObject.hpp"

namespace Object {

    class CelCloudObject : public CelGameObject{
    public:
        CelCloudObject(glm::vec2 Initposition,float Direction,bool isFront){
            /**make it into 2 piece*/
            if(isFront)SetImage(RESOURCE_DIR"/Imgs/Celeste_objects/cloud1.png");
            if(!isFront)SetImage(RESOURCE_DIR"/Imgs/Celeste_objects/cloud2.png");

            SetZIndex(-1);
            m_Transform.translation = Initposition;
            m_Direction = Direction;
        }
        void Update() override;
        glm::vec2 GetHorizonLine() override;
        glm::vec2 GetVertualLine() override;
    private:
        float m_Direction;
        const float m_MoveSpeed = 1;
    };

} // Object

#endif //PICO8_CELESTE_CELCLOUDOBJECT_H
