//
// Created by tami on 5/17/24.
//
#include "Object/CelSpringObject.h"
#include "Util/Logger.hpp"
#include "Util/Time.hpp"
#include <functional>
namespace Object{
    glm::vec2 CelSpringObject::GetVertualLine() {
        glm::vec2 vertualLine = (m_SpringStage == SpringStage::isBroken) ?  glm::vec2{0,0} : CelGameObject::GetVertualLine();
        return vertualLine;
    }

    glm::vec2 CelSpringObject::GetHorizonLine() {
        glm::vec2 HorizonLine = (m_SpringStage == SpringStage::isBroken) ?  glm::vec2{0,0} : CelGameObject::GetHorizonLine();
        return HorizonLine;
    }

    void CelSpringObject::Update() {
        if(m_SpringStage == Bounced){
            if(bIsOnBox){
                if(Util::Time::GetElapsedTimeMs() > OnChangeTime + BrokenTime){
                    SetVisible(false);
                    m_SpringStage = isBroken;
                    OnChangeTime = Util::Time::GetElapsedTimeMs();
                }
            } else{
                if(Util::Time::GetElapsedTimeMs() > OnChangeTime + ResetTime){
                    SetImage(IdleImgPath);
                    m_SpringStage = Idle;
                }
            }
        }

        if(m_SpringStage == isBroken){
            if(Util::Time::GetElapsedTimeMs() > OnChangeTime+ReviveTime){
                SetVisible(true);
                SetImage(IdleImgPath);
                m_SpringStage = Idle;
            }
        }
    }

    void CelSpringObject::AddOnBounceFunction( const std::string& key, const std::function<void()>& function) {
        auto iter =OnBounceFunctions.find(key);
        if (iter != OnBounceFunctions.end()) {
            LOG_ERROR("Bind Function %s twice",key);
        } else{
            OnBounceFunctions[key] = function;
        }
    }

    void CelSpringObject::OnBounce() {
        SetImage(BounceImgPath);
        OnChangeTime  = Util::Time::GetElapsedTimeMs();
        m_SpringStage = Bounced;
        if(bIsOnBox){
            for (const auto& func: OnBounceFunctions) {
                func.second();
            }
        }
    }

    void CelSpringObject::Revive() {
        m_SpringStage = Idle;
        SetImage(IdleImgPath);
        SetVisible(true);
    }


}