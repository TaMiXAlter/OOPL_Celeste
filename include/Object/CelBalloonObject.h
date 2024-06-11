//
// Created by tami on 2024/4/20.
//

#ifndef PICO8_CELESTE_CELBALLOONOBJECT_H
#define PICO8_CELESTE_CELBALLOONOBJECT_H
#include "CelGameObject.hpp"
#include "Util/Time.hpp"

namespace Object{
    class CelBalloonObject : public Object::CelGameObject{
    public:
        CelBalloonObject(glm::vec2 Initposition){
            SetImage(RESOURCE_DIR"/Imgs/Celeste_objects/balloon.png");
            this->m_Transform.translation = Initposition;
        };
        void Update() override{
            if(isEat){
                if(Util::Time::GetElapsedTimeMs() - m_StartBrokenTime > m_TotalBrokenTime){
                    isEat= false;
                    SetVisible(true);
                }
            }
        }
        void Eat(){
            m_StartBrokenTime = Util::Time::GetElapsedTimeMs();
            SetVisible(false);
            isEat = true;
        }
        glm::vec2 GetHorizonLine() override{
            if(isEat) return {0,0};
            else return CelGameObject::GetVertualLine();
        };
        glm::vec2 GetVertualLine() override{
            if(isEat) return {0,0};
            else return CelGameObject::GetVertualLine();
        };
    private:
        bool isEat = false;
        float m_StartBrokenTime=0;
        const float m_TotalBrokenTime = 500;
    };
}



#endif //PICO8_CELESTE_CELBALLOONOBJECT_H
