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
            const float Heigth= this->GetScaledSize().y;
            const float YPosition = this->m_Transform.translation.y ;

            if(IsTouched) return {0,0};
            else return {round(YPosition - (Heigth/2)),round(YPosition + (Heigth/2))};
        }

        glm::vec2 GetHorizonLine() override{
            const float Width = this->GetScaledSize().x;
            const float XPosition = this->m_Transform.translation.x;

            //** x:Bottom  and y:Top edges */
            if(IsTouched) return {0,0};
            else return {round(XPosition - (Width/2)),round(XPosition + (Width/2))};
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
