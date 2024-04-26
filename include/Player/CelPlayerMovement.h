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

enum MovementState{
    OnGround,
    TouchRightWall,
    TouchLeftWall,
    Falling,
    Jumping,
    Dashing,
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
        bool isSolids(std::shared_ptr<Object::CelGameObject> other, glm::vec2 position);
        bool isOnGround(std::shared_ptr<Object::CelGameObject> other, glm::vec2 position);
        bool isTouchRightWall(std::shared_ptr<Object::CelGameObject> other, glm::vec2 position);
        bool isTouchLeftWall(std::shared_ptr<Object::CelGameObject> other, glm::vec2 position);
        bool isOverEage(std::shared_ptr<Object::CelGameObject> other, glm::vec2 position);
        /**other object*/
        bool isOnSpring(std::shared_ptr<Object::CelGameObject> other, glm::vec2 position);
        bool isOnSpike(std::shared_ptr<Object::CelGameObject> other, glm::vec2 position);
        /**Horizon Movement*/
    private:
        const float m_RunSpeed = 3.5f;
        void Run(float speed);
    public:
        bool m_canRun;
        /**jump*/
    private:
        void Jump(glm::vec2 DirectionAmount);

        const glm::vec2 m_JumpUpMax = glm::vec2(0,9);
        const glm::vec2 m_JumpRightUpMax = glm::vec2(4,9);
        const glm::vec2 m_JumpLeftUpMax = glm::vec2(-4,9);
    public:
        glm::vec2 m_JumpBuffer;
    private:
        /**Spring Jump*/
        const glm::vec2 m_SpringJumpMax = glm::vec2 (0, 11);
        const float m_JumpDecreaseScalarY = 0.2f;

        /**gravity*/
    private:
        void ApplyGravity();
        float m_dropScaleSpeed = 0.3f;
    public:
        float m_dropSpeed;
        /**TouchWall Slide*/
    private:
        void Sliding();
        const float m_SlideDropSpeed = -3 ;
        /**Dash*/
    private:
        void Dash();
        const float m_dashBuffer = 9.5;
        float m_dashDuration;
        int m_DashAmount = 1;
    public:
        int maxDashAmount = 1;
        void ResetDashAmount(){
            m_DashAmount = maxDashAmount;
        };
        void SetMaxDashAmount(int Delta){
            maxDashAmount+=1;
        }
        /***/
    private:
        MovementState m_MovementState;
        glm::vec2 m_speed ;
        glm::vec2 m_direction;
        Player::CelPlayer* m_owner;
    };
}

#endif //PICO8_CELESTE_CELPLAYERMOVEMENT_H
