//
// Created by tami on 6/7/24.
//

#ifndef PICO8_CELESTE_CELFRUIT_H
#define PICO8_CELESTE_CELFRUIT_H

#include "Object/CelGameObject.hpp"

namespace Object{
    class CelFruit: public  CelGameObject{
    public:
        CelFruit(glm::vec2 Initposition,bool isFlying = false){
            SetImage(RESOURCE_DIR"/Imgs/Celeste_Fruit/fruit.png");
            this->m_Transform.translation = Initposition;
            if(isFlying){
                isAFlyingFruit = isFlying;
                MovementMax = Initposition.y+15;
                MovementMin = Initposition.y-15;
            }

        }
        virtual void Update() override{
            if(isAFlyingFruit && !isFlyingAway){
                FlyUpAndDown(m_Transform.translation.y);
            }else if(isFlyingAway && GetTransform().translation.y <300){
                this->m_Transform.translation.y += 2;
            }
        };
        glm::vec2 GetVertualLine() override{
            if(isEat) return {0,0};
            else return CelGameObject::GetVertualLine();
        }

        glm::vec2 GetHorizonLine() override{
            if(isEat) return {0,0};
            else return CelGameObject::GetHorizonLine();
        }
        void FlyAway(){
            if(isAFlyingFruit ){
               isFlyingAway = true;
            }
        }
        void Disable(){
            isEat = true;
            SetVisible(false);
        }

    private:
        /**fly up nad down*/
        float MovementDelta = 0.7;
        float MovementMax;
        float MovementMin;
        void FlyUpAndDown(float& CurrentYPosition){
            if(CurrentYPosition>MovementMax || CurrentYPosition<MovementMin){
                MovementDelta *= -1;
            }
            CurrentYPosition += MovementDelta;
        }
        /**Status*/
    public:
        bool GetisFlyingFruit() const{return isAFlyingFruit;}
    private:
        bool isAFlyingFruit;
        bool isFlyingAway = false;
        bool isEat =false;
    };
}
#endif //PICO8_CELESTE_CELFRUIT_H
