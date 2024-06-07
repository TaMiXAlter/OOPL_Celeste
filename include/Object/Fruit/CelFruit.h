//
// Created by tami on 6/7/24.
//

#ifndef PICO8_CELESTE_CELFRUIT_H
#define PICO8_CELESTE_CELFRUIT_H

#include "Object/CelGameObject.hpp"

namespace Object{
    class CelFruit: public  CelGameObject{
    public:
        CelFruit(glm::vec2 Initposition,bool isFlying){
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
            const float Heigth= this->GetScaledSize().y;
            const float YPosition = this->m_Transform.translation.y ;

            if(isEat) return {0,0};
            else return {round(YPosition - (Heigth/2)),round(YPosition + (Heigth/2))};
        }

        glm::vec2 GetHorizonLine() override{
            const float Width = this->GetScaledSize().x;
            const float XPosition = this->m_Transform.translation.x;

            //** x:Bottom  and y:Top edges */
            if(isEat) return {0,0};
            else return {round(XPosition - (Width/2)),round(XPosition + (Width/2))};
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
