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
        m_JumpBuffer = 0;

        m_speed = glm::vec2 (0,0);
    }

    void CelPlayer::Update() {
        if(Util::Input::IsKeyPressed(Util::Keycode::D)) MoveX(5);
        if(Util::Input::IsKeyPressed(Util::Keycode::A)) MoveX(-5);
        if(Util::Input::IsKeyDown(Util::Keycode::SPACE) && m_MovementState == OnGround) {
            m_MovementState = Jumping;
            m_JumpBuffer = m_MaxJumpBuffer;
        };
        switch (m_MovementState) {
            case OnGround:
                break;
            case TouchWall:
                Sliding();
                m_JumpBuffer = 0;
                break;
            case Jumping:
                Jump();
                ApplyGravity();
                if(m_JumpBuffer <= 0){
                    m_MovementState = Falling;
                }
                break;
            case Falling:
                ApplyGravity();
                break;

        }
        LOG_INFO(m_MovementState);
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
                    //There is no Solid immediately beside us so Move
                    m_Transform.translation.y += sign;
                    move -= sign;
                }
                else{
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
        bool TouchTheWall =(GetVertualLine(position.y).y >= other->GetVertualLine().x
                            ||other->GetVertualLine().y  >= GetVertualLine(position.y).x);

        bool OverSideEage = other->GetHorizonLine().y == GetHorizonLine(position.x).x ||
                             GetHorizonLine(position.x).y == other->GetHorizonLine().x;
        /**AABB*/
       if(XCollideCheck && YCollideCheck){
           if(TouchTheGround && m_dropSpeed <= 0){
               m_MovementState = OnGround;
               m_dropSpeed = 0;
           }
           if((m_MovementState == Falling||m_MovementState == Jumping) && TouchTheWall){
               m_MovementState = TouchWall;
           }
           return true;
       }

       if(m_MovementState == OnGround && OverSideEage){
           m_MovementState = Falling;
       }

        return false;
    }

    void CelPlayer::Jump() {
        MoveY(m_JumpBuffer);
        m_JumpBuffer -= glm::pow(Util::Time::GetDeltaTime(),m_JumpDecreaseScaler) ;
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
}