//
// Created by tami on 2024/4/19.
//

#include <functional>
#include "Object/CelBoxObject.h"
#include "Util/Animation.hpp"
#include "Util/Time.hpp"
using namespace std;
namespace Object {
    CelBoxObject::CelBoxObject(glm::vec2 Initposition) {
        m_BoxState = BoxState::Idel;
        SetAnimation(m_aniPath,false,m_animInterval,false,0);
        m_anim = std::dynamic_pointer_cast<Util::Animation>(m_Drawable);
        m_anim->Pause();
        m_Transform.translation = Initposition;
    }

    void CelBoxObject::Update() {
        CelGameObject::Update();
        /**停在完整的箱子*/
        if(m_BoxState == Idel && m_anim->GetCurrentFrameIndex() == 0){
            m_anim->Pause();
        }
        /**結束破壞*/
        if( m_BoxState == BoxState::Brokening && Util::Time::GetElapsedTimeMs() - m_StartBrokenTime>m_BrokenTotalTime){
            m_BoxState = Broken;
            SetVisible(false);
            m_StartWaitForRevive = Util::Time::GetElapsedTimeMs();
        }
        /**復活*/
        if(m_BoxState == BoxState::Broken && Util::Time::GetElapsedTimeMs() - m_StartWaitForRevive > m_ReviveTotalTime){
            m_BoxState = Idel;
            SetVisible(true);
            m_anim->Play();
        }
    }
    void CelBoxObject::StartBroken() {
        /**開始破壞*/
        m_BoxState = Brokening;
        m_StartBrokenTime = Util::Time::GetElapsedTimeMs();
        m_anim->Play();
    }

    BoxState CelBoxObject::GetBoxState() {
        return m_BoxState;
    }

    glm::vec2 CelBoxObject::GetHorizonLine() {
        if(m_BoxState == Broken){
            return {0,0};
        }
        return CelGameObject::GetHorizonLine();
    }

    glm::vec2 CelBoxObject::GetVertualLine() {
        if(m_BoxState == Broken){
            return {0,0};
        }
        return CelGameObject::GetVertualLine();
    }
} // Object