//
// Created by tami on 2024/3/29.
//

#ifndef PICO8_CELESTE_CELSPRINGOBJECT_H
#define PICO8_CELESTE_CELSPRINGOBJECT_H

#include "CelGameObject.hpp"
enum SpringStage{
    Idle,
    Bounced,
    isBroken
};
namespace Object {
/**todo: Spring on Box*/
class CelSpringObject: public Object::CelGameObject{
public:
    CelSpringObject(glm::vec2 Initposition = glm::vec2(0,0),bool IsOnBox = false){
        SetImage(IdleImgPath);
        m_Transform.translation = Initposition;
        m_Transform.scale = glm::vec2(2,2);
        bIsOnBox = IsOnBox;
        m_SpringStage = Idle;
        OnChangeTime = 0;
    };
    ~CelSpringObject() override{
        ClearDelegate();
    }
    glm::vec2 GetVertualLine() override;
    glm::vec2 GetHorizonLine() override;
    void Update() override;
    /**Revive*/
public:
    void Revive() override;
private:
    SpringStage m_SpringStage;
    bool bIsOnBox;
public:
    std::map<std::string,std::function<void()>> OnBounceFunctions;
    void AddOnBounceFunction(const std::string& key,const std::function<void()>& function);
    void ClearDelegate(){
        OnBounceFunctions.clear();
    }
    void OnBounce();
private:
    float OnChangeTime;
    const float ResetTime = 200;
    const float BrokenTime = 450;
    const float ReviveTime = 3000;
private:
    const std::string IdleImgPath = RESOURCE_DIR"/Imgs/Celeste_objects/spring1.png";
    const std::string BounceImgPath = RESOURCE_DIR"/Imgs/Celeste_objects/spring2.png";
};

} // Object

#endif //PICO8_CELESTE_CELSPRINGOBJECT_H
