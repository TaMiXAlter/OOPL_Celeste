//
// Created by tami on 2024/3/21.
//


#ifndef PICO8_CELESTE_CELPLAYERMOVEMENT_H
#define PICO8_CELESTE_CELPLAYERMOVEMENT_H

#include <glm/vec2.hpp>
#include "Object/CelGameObject.hpp"

namespace Player{
    class CelPlayer;
}
/**todo:
 *  1. move will switch into falling
 *  a. 蹬牆跳應該要摸到牆就可以觸發
 *  b. 摸到牆的時候會停在牆上一段時間
 * 3. 儲存輸入控制*/
enum MovementState{
    OnGround,
    TouchRightWall,
    TouchLeftWall,
    Falling,
    Jumping,
    Dashing
};
namespace Player{
    class CelPlayerMovement {
    public:
        CelPlayerMovement(CelPlayer* Owner);
        void UPDATE();
        bool ApplyCollide;
        void ResetValue();
    private:
        /**collision function*/
        /**move function*/
        void MoveX(float amount);
        void MoveY(float amount);
        void MoveWithDirection(glm::vec2 DiractionAmount);
    private:
        bool OnCollides(const std::vector<std::shared_ptr<Object::CelGameObject>>& objs, glm::vec2 position);
        /**detect bool*/
        bool isSolids(const std::shared_ptr<Object::CelGameObject>& other, glm::vec2 position);
        bool isOnGround(const std::shared_ptr<Object::CelGameObject>& other, glm::vec2 position);
        bool isTouchRightWall(const std::shared_ptr<Object::CelGameObject>& other, glm::vec2 position);
        bool isTouchLeftWall(const std::shared_ptr<Object::CelGameObject>& other, glm::vec2 position);
        /**other object*/
        bool isOnSpring(const std::shared_ptr<Object::CelGameObject>& other, glm::vec2 position);
        bool isOnSpike(const std::shared_ptr<Object::CelGameObject>& other, glm::vec2 position);
        bool isOnCloud(const std::shared_ptr<Object::CelGameObject>& Cloud, glm::vec2 position);
        /**Horizon Movement*/
    private:
        const float m_RunSpeed = 3.5f;
        void Run(float speed);
    public:
        bool m_canRun;
        /**jump*/
    private:
        void Jump(glm::vec2 DirectionAmount);

        const glm::vec2 m_JumpUpMax = glm::vec2(0,15.f);
        const glm::vec2 m_JumpRightUpMax = glm::vec2(4.f,15.f);
        const glm::vec2 m_JumpLeftUpMax = glm::vec2(-4.f,15.f);
    public:
        glm::vec2 m_JumpBuffer;
    private:
        /**Spring Jump*/
        const glm::vec2 m_SpringJumpMax = m_JumpUpMax*glm::vec2 (0,1.5);
        const float m_JumpDecreaseScalarY = 0.85f;

        /**gravity*/
    private:
        void ApplyGravity();
        const float m_dropScaleSpeed = 1.05f;
        const float m_slowDropScaleSpeed = 1.02;
        void ResetGravity(){m_dropSpeed = -1;}
    public:
        float m_dropSpeed;
        /**TouchWall Slide*/
    private:
        const float m_SlideDropSpeed = -3 ;
        /**Dash*/
    public:
        void ResetDashAmount(){
            m_DashAmount = maxDashAmount;
        };
        void SetMaxDashAmount(int Delta){
            maxDashAmount = Delta;
        }
    private:
        void Dash();
        const float m_dashBuffer = 9.5;
        float m_dashDuration = 0;
        int m_DashAmount = 1;
        int maxDashAmount = 1;
        /***/
    private:
        MovementState m_MovementState;
        glm::vec2 m_speed ;
        glm::vec2 m_direction;
        Player::CelPlayer* m_owner;
    };
}

#endif //PICO8_CELESTE_CELPLAYERMOVEMENT_H
