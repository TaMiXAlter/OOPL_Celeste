#include "Player/CelPlayer.h"
#include "CelUtil/CelGameObject.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"
#include "Util/Time.hpp"
namespace Player {

    CelPlayer::CelPlayer(const std::string ImgPath) {
        SetImage(ImgPath);
        m_MovementState = Falling;
        m_JumpBuffer = glm::vec2 (0,0);

        m_speed = glm::vec2 (0,0);
    }

    void CelPlayer::Update() {
        if(Util::Input::IsKeyPressed(Util::Keycode::D)) MoveX(5);
        if(Util::Input::IsKeyPressed(Util::Keycode::A)) MoveX(-5);

        if(Util::Input::IsKeyDown(Util::Keycode::SPACE)) {
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
            }
            m_MovementState = Jumping;
        };

        switch (m_MovementState) {
            case OnGround:
                m_JumpBuffer = glm::vec2(0,0);
                m_dropSpeed = 0;
                break;
            case TouchRightWall:
                Sliding();
                m_JumpBuffer = glm::vec2(0,0);
                m_dropSpeed = 0;
                break;
            case TouchLeftWall:
                Sliding();
                m_JumpBuffer = glm::vec2(0,0);
                m_dropSpeed = 0;
                break;
            case Jumping:
                Jump(m_JumpBuffer);
                ApplyGravity();
                break;
            case Falling:
                ApplyGravity();
                break;
        }
    }
    void CelPlayer::UpdateSolid(std::vector<std::shared_ptr<CelUtil::CelGameObject>> solids) {
        m_solids = solids;
    }

    /**collider checker and move*/
    void CelPlayer::MoveX(float amount) {
        m_speed.x += amount;
        int move = glm::round(m_speed.x);
        if (move != 0){
            m_speed.x -= move;
            int sign = glm::sign(move);
            while (move != 0){
                if (!CheckCollides(m_Transform.translation + glm::vec2(sign, 0))){
                    m_Transform.translation.x += sign;
                    move -= sign;
                }
                else{
                    m_speed.x = 0;
                    break;
                }
            }
        }
    }

    void CelPlayer::MoveY(float amount) {
        /**如果沒有碰到地面 isFalling*/
        m_speed.y += amount;
        float move = glm::round(m_speed.y);
        if (move != 0){
            m_speed.y -= move;
            float sign = glm::sign(move);
            while (move != 0){
                if (!CheckCollides(m_Transform.translation + glm::vec2(0,sign))){
                    m_Transform.translation.y += sign;
                    move -= sign;
                }else{
                    m_speed.y = 0;
                    break;
                }
            }
        }
    }

    bool CelPlayer::CheckCollides(glm::vec2 newPosition) {
        /** check all the m_solids*/
        for (int i = 0; i < m_solids.size(); ++i) {
            if(OnCollides(m_solids[i],newPosition)){
                return true;
            }
        }
        return false;
    }

    bool CelPlayer::OnCollides(std::shared_ptr<CelUtil::CelGameObject> other, glm::vec2 position) {
        bool XCollideCheck = other->GetHorizonLine().y >= GetHorizonLine(position.x).x&&
                             GetHorizonLine(position.x).y >= other->GetHorizonLine().x;
        bool YCollideCheck = other->GetVertualLine().y >= GetVertualLine(position.y).x &&
                             GetVertualLine(position.y).y >= other->GetVertualLine().x;

        bool TouchTheGround = other->GetVertualLine().y == GetVertualLine(position.y).x;

        bool isTouchRightWall = other->GetVertualLine().y  == GetVertualLine(position.y).x;
        bool isTouchLeftWall = GetVertualLine(position.y).y == other->GetVertualLine().x;

        bool OverSideEage = other->GetHorizonLine().y == GetHorizonLine(position.x).x ||
                             GetHorizonLine(position.x).y == other->GetHorizonLine().x;
        /**AABB*/
       if(XCollideCheck && YCollideCheck){
           if(TouchTheGround && m_dropSpeed <= 0){
               m_MovementState = OnGround;
               m_dropSpeed = 0;
           }
           if((m_MovementState == Falling||m_MovementState == Jumping) ){
               if(isTouchRightWall){
                   m_MovementState = TouchRightWall;
                   LOG_DEBUG("touch right wall");
               }else if(isTouchLeftWall){
                   m_MovementState = TouchLeftWall;
               }

           }
           return true;
       }

       if(m_MovementState == OnGround && OverSideEage){
           m_MovementState = Falling;
       }

        return false;
    }

    void CelPlayer::Jump(glm::vec2 DiractionAmount) {
        MoveWithDiraction(DiractionAmount);
        m_JumpBuffer += glm::vec2(0,m_JumpDecreaseScalarY) ;
        if( m_JumpBuffer.y <=0){
            m_MovementState = Falling;
        }
    }
    void CelPlayer::ApplyGravity() {
        m_dropSpeed -= glm::pow(Util::Time::GetDeltaTime(),m_dropScaleSpeed) ;
        MoveY(m_dropSpeed);
    }

    void CelPlayer::Sliding() {
        if(m_speed.x != 0){
            m_MovementState = Falling;
        }
        MoveY(m_SlideDropSpeed);
    }

    void CelPlayer::MoveWithDiraction(glm::vec2 DiractionAmount) {
        MoveX(DiractionAmount.x);
        MoveY(DiractionAmount.y);
    }


}