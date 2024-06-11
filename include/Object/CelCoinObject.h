//
// Created by tami on 5/24/24.
//

#ifndef PICO8_CELESTE_CELCOINOBJECT_H
#define PICO8_CELESTE_CELCOINOBJECT_H

#include "CelGameObject.hpp"

namespace Object{
    class CelCoinObject: public CelGameObject{
    public:
        CelCoinObject(glm::vec2 Initposition){
            SetImage(RESOURCE_DIR"/Imgs/Celeste_objects/DashCoin.png");
            m_Transform.translation = Initposition;
            IsTouched = false;
        }
        glm::vec2 GetVertualLine() override{
            if(IsTouched) return {0,0};
            else return CelGameObject::GetVertualLine();
        }

        glm::vec2 GetHorizonLine() override{
            //** x:Bottom  and y:Top edges */
            if(IsTouched) return {0,0};
            else return CelGameObject::GetHorizonLine();
        }
        void Disable(){
            IsTouched = true;
            SetVisible(false);
        };
    private:
        bool IsTouched ;
    };
}
#endif //PICO8_CELESTE_CELCOINOBJECT_H
