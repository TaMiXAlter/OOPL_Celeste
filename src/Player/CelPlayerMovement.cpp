//
// Created by tami on 2024/3/21.
//

#include "Player/CelPlayerMovement.h"
#include "Player/CelPlayer.h"
#include "Util/Keycode.hpp"
#include "Util/Input.hpp"
#include "Util/Logger.hpp"
#include "Util/Time.hpp"
#include "Object/CelSpringObject.h"
#include "Object/CelSolidObject.h"
#include "Object/CelSpikeObject.h"
#include "Object/CelBoxObject.h"
#include "Object/CelBalloonObject.h"

namespace Player{

    CelPlayerMovement::CelPlayerMovement(CelPlayer* Owner) {
        m_owner = Owner;
        ResetValue();
    }

    void CelPlayerMovement::UPDATE() {
        LOG_INFO(m_dropSpeed);
        //todo: Save the input
        if (Util::Input::IsKeyPressed(Util::Keycode::RIGHT)) {
            Run(m_RunSpeed);
            m_direction.x = 1;
        }
        else if (Util::Input::IsKeyPressed(Util::Keycode::LEFT)) {
            Run(-m_RunSpeed);
            m_direction.x = -1;
        }else if(Util::Input::IsKeyPressed(Util::Keycode::UP) ||Util::Input::IsKeyPressed(Util::Keycode::DOWN)){
            m_direction.x = 0;
        }

        if (m_MovementState != Dashing) {
            if (Util::Input::IsKeyPressed(Util::Keycode::UP)) m_direction.y = 1;
            else if (Util::Input::IsKeyPressed(Util::Keycode::DOWN)) m_direction.y = -1;
            else m_direction.y = 0;
        }
        if (Util::Input::IsKeyPressed(Util::Keycode::X)) {
            if (m_DashAmount > 0) {
                m_DashAmount--;
                m_MovementState = Dashing;
                m_dashDuration = 10;
                m_canRun = false;
            }
        }
        if (Util::Input::IsKeyDown(Util::Keycode::Z)) {
            if(m_MovementState != Jumping && m_MovementState != Falling){
                switch (m_MovementState) {
                    case OnGround:
                        m_JumpBuffer = m_JumpUpMax;
                        break;
                    case TouchLeftWall:
                        m_JumpBuffer = m_JumpRightUpMax;
                        break;
                    case TouchRightWall:
                        m_JumpBuffer = m_JumpLeftUpMax;
                        break;
                    default:
                        break;
                }
                m_MovementState = Jumping;
                if (m_JumpBuffer.x != 0) m_canRun = false;
            }
        }

        //todo: make it into state machine
        switch (m_MovementState) {
            case OnGround:
                m_JumpBuffer = glm::vec2(0, 0);
                m_canRun = true;
                break;
            case TouchRightWall:
                Sliding();
                m_JumpBuffer = glm::vec2(0, 0);
                break;
            case TouchLeftWall:
                Sliding();
                m_JumpBuffer = glm::vec2(0, 0);
                break;
            case Jumping:
                Jump(m_JumpBuffer);
                break;
            case Falling:
                ApplyGravity();
                m_canRun = true;
                break;
            case Dashing:
                m_JumpBuffer = glm::vec2(0, 0);
                ResetGravity();
                Dash();
                break;
        }
    }
    void CelPlayerMovement::ResetValue() {
        m_MovementState = OnGround;
        m_JumpBuffer = glm::vec2 (0,0);
        m_speed = glm::vec2 (0,0);
        ResetGravity();
        m_canRun = true;
        ApplyCollide = true;
    }
    /**move unit*/
    void CelPlayerMovement::MoveX(float amount) {
        m_speed.x += amount;
        float move = glm::round(m_speed.x);
        if (move != 0){
            m_speed.x -= move;
            float sign = glm::sign(move);
            while (move != 0){
                if (OnCollides(m_owner->GetSolid(),m_owner->m_Transform.translation + glm::vec2(sign, 0)) && ApplyCollide){
                    m_speed.x = 0;
                    break;
                }
                m_owner->m_Transform.translation.x += sign;
                move -= sign;
            }
        }
    }
    void CelPlayerMovement::MoveY(float amount) {
        /**如果沒有碰到地面 isFalling*/
        m_speed.y += amount;
        float move = glm::round(m_speed.y);
        if (move != 0){
            m_speed.y -= move;
            float sign = glm::sign(move);
            while (move != 0){
                if (OnCollides(m_owner->GetSolid(),m_owner->m_Transform.translation+ glm::vec2(0,sign))
                    && ApplyCollide ){
                    m_speed.y = 0;
                    break;
                }
                m_owner->m_Transform.translation.y += sign;
                move -= sign;
            }
        }
    }
    void CelPlayerMovement::MoveWithDirection(glm::vec2 DiractionAmount) {
        MoveX(DiractionAmount.x);
        MoveY(DiractionAmount.y);
    }


    /**Move Function*/
    void CelPlayerMovement::Jump(glm::vec2 DirectionAmount) {
        MoveWithDirection(DirectionAmount);
        m_JumpBuffer.y *= m_JumpDecreaseScalarY;
        if(m_JumpBuffer.y <=0.1){m_MovementState = Falling; ResetGravity();};
    }
    void CelPlayerMovement::ApplyGravity() {
        m_dropSpeed *= m_dropScaleSpeed;
        MoveY(m_dropSpeed);
    }

    void CelPlayerMovement::Sliding() {
        /**Apply Slide*/
        MoveY(m_SlideDropSpeed);
    }

    void CelPlayerMovement::Run(float speed){
        if(m_canRun){
            if(m_JumpBuffer.x!=0) m_JumpBuffer.x -=1;
            MoveX(speed);
        }
    }
    void CelPlayerMovement::Dash(){
        if(m_dashDuration == 0) {m_MovementState = Falling; ResetGravity();}
        MoveWithDirection(m_direction * m_dashBuffer);
        m_canRun = false;
        m_dashDuration--;
    }

    /**Collide Checker*/
    bool CelPlayerMovement::OnCollides(const std::vector<std::shared_ptr<Object::CelGameObject>>& objs, glm::vec2 position) {
        /**over window checker*/
        if(position.x < -256+(m_owner->GetScaledSize().x/2) || position.x > 256-(m_owner->GetScaledSize().x/2) ) return true;
        /**collide checker*/
        for (const auto& other : objs) {
            if(std::shared_ptr<Object::CelSolidObject> SolidObj = std::dynamic_pointer_cast<Object::CelSolidObject>(other)){
                /**If touch Solid*/
                if(isSolids(SolidObj, position)){
                    if(isOnGround(SolidObj,position)){
                        m_MovementState = OnGround;
                        m_DashAmount = maxDashAmount;
                        ResetGravity();
                    }
                    else if(isTouchLeftWall(SolidObj,position) && Util::Input::IsKeyPressed(Util::Keycode::LEFT)) m_MovementState = TouchLeftWall;
                    else if(isTouchRightWall(SolidObj,position) && Util::Input::IsKeyPressed(Util::Keycode::RIGHT)) m_MovementState = TouchRightWall;
                    return true;
                }
                else{
                    if(m_MovementState == TouchRightWall || m_MovementState == TouchLeftWall) m_MovementState = Falling;
                    if(isOverEage(other,position)) m_MovementState = Falling;
                }
            }else if (std::shared_ptr<Object::CelSpringObject> SpringObj = std::dynamic_pointer_cast<Object::CelSpringObject>(other)){
                /**If TouchSpring*/
                if(isOnSpring(SpringObj, position)){
                    m_DashAmount = maxDashAmount;
                    ResetGravity();
                    m_JumpBuffer = m_SpringJumpMax;
                    m_MovementState = Jumping;
                    return true;
                };
            }else if(std::shared_ptr<Object::CelSpikeObject> SpikeObj = std::dynamic_pointer_cast<Object::CelSpikeObject>(other)){
                if(isOnSpike(SpikeObj, position)){
                    m_owner->KillPlayer();
                }
            }else if(std::shared_ptr<Object::CelBoxObject> BoxObj = std::dynamic_pointer_cast<Object::CelBoxObject>(other)){
                if(isSolids(BoxObj,position)){
                    if(isOnGround(BoxObj,position)){
                        if(BoxObj->GetBoxState() == BoxState::Broken) m_MovementState = Falling;
                        if(BoxObj->GetBoxState() == BoxState::Idel)BoxObj->StartBroken();
                        m_MovementState = OnGround;
                        m_DashAmount = maxDashAmount;
                        ResetGravity();
                    }
                    else if(isTouchLeftWall(BoxObj,position) && Util::Input::IsKeyPressed(Util::Keycode::LEFT)){
                        m_MovementState = TouchLeftWall;
                        if(BoxObj->GetBoxState() == BoxState::Idel)BoxObj->StartBroken();
                    }
                    else if(isTouchRightWall(BoxObj,position) && Util::Input::IsKeyPressed(Util::Keycode::RIGHT)){
                        m_MovementState = TouchRightWall;
                        if(BoxObj->GetBoxState() == BoxState::Idel)BoxObj->StartBroken();
                    }
                    return true;
                }else{
                    if(m_MovementState == TouchRightWall || m_MovementState == TouchLeftWall) {m_MovementState = Falling; ResetGravity();};
                    if(isOverEage(other,position)) {m_MovementState = Falling; ResetGravity();}
                }
            }else if(std::shared_ptr<Object::CelBalloonObject> Balloon = std::dynamic_pointer_cast<Object::CelBalloonObject>(other)){
                ResetDashAmount();
            }
        }
        return false;

    }
    /**Collider boolean */
    bool CelPlayerMovement::isSolids(const std::shared_ptr<Object::CelGameObject> other, glm::vec2 position) {
        bool XCollideCheck = other->GetHorizonLine().y >= m_owner->GetHorizonLine(position.x).x &&
                             m_owner->GetHorizonLine(position.x).y >= other->GetHorizonLine().x;
        bool YCollideCheck = other->GetVertualLine().y >= m_owner->GetVertualLine(position.y).x &&
                             m_owner->GetVertualLine(position.y).y >= other->GetVertualLine().x;
        return XCollideCheck && YCollideCheck;
    }
    bool CelPlayerMovement::isOnSpring(const std::shared_ptr<Object::CelGameObject> other, glm::vec2 position) {
        bool XCollideCheck = other->GetHorizonLine().y >= m_owner->GetHorizonLine(position.x).x &&
                             m_owner->GetHorizonLine(position.x).y >= other->GetHorizonLine().x;
        bool YCollideCheck = other->GetVertualLine().y >= m_owner->GetVertualLine(position.y).x &&
                             m_owner->GetVertualLine(position.y).y >= other->GetVertualLine().x;
        return XCollideCheck && YCollideCheck;
    }
    bool CelPlayerMovement::isOnSpike(std::shared_ptr<Object::CelGameObject> other, glm::vec2 position) {
        bool XCollideCheck = other->GetHorizonLine().y >= m_owner->GetHorizonLine(position.x).x &&
                             m_owner->GetHorizonLine(position.x).y >= other->GetHorizonLine().x;
        bool YCollideCheck = other->GetVertualLine().y>= m_owner->GetVertualLine(position.y).x &&
                             m_owner->GetVertualLine(position.y).y >= other->GetVertualLine().x;
        return XCollideCheck && YCollideCheck;
    }
    bool CelPlayerMovement::isOnGround(const std::shared_ptr<Object::CelGameObject> other, glm::vec2 position) {
        return  other->GetVertualLine().y == m_owner->GetVertualLine(position.y).x && m_dropSpeed < -2.f;
    }
    bool CelPlayerMovement::isOverEage(const std::shared_ptr<Object::CelGameObject> other, glm::vec2 position) {
        return (other->GetHorizonLine().y == m_owner->GetHorizonLine(position.x).x
                ||m_owner->GetHorizonLine(position.x).y == other->GetHorizonLine().x)
                && m_MovementState == OnGround ;
    }
    bool CelPlayerMovement::isTouchRightWall(const std::shared_ptr<Object::CelGameObject> other, glm::vec2 position) {
        return (m_MovementState == Falling||m_MovementState == Jumping )
        && other->GetHorizonLine().y  >= m_owner->GetHorizonLine(position.y).x
        && Util::Input::IsKeyPressed(Util::Keycode::RIGHT);

    }
    bool CelPlayerMovement::isTouchLeftWall(const std::shared_ptr<Object::CelGameObject> other, glm::vec2 position) {
        return (m_MovementState == Falling||m_MovementState == Jumping )
        && m_owner->GetHorizonLine(position.y).y >= other->GetHorizonLine().x
        && Util::Input::IsKeyPressed(Util::Keycode::LEFT);
    }



}