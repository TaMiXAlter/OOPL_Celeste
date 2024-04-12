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

        bool OnCollides(const std::vector<std::shared_ptr<Object::CelGameObject>>& objs, glm::vec2 position);
        /**detect bool*/
        bool isSolids(const std::shared_ptr<Object::CelGameObject> other, glm::vec2 position);
        bool isOnSpring(const std::shared_ptr<Object::CelGameObject> other, glm::vec2 position);
        bool isOnGround(const std::shared_ptr<Object::CelGameObject> other, glm::vec2 position);
        bool isTouchRightWall(const std::shared_ptr<Object::CelGameObject> other, glm::vec2 position);
        bool isTouchLeftWall(const std::shared_ptr<Object::CelGameObject> other, glm::vec2 position);
        bool isOverEage(const std::shared_ptr<Object::CelGameObject> other, glm::vec2 position);
        /**Horizon Movement*/
    private:
        const float m_RunSpeed = 3.5f;
        bool m_canRun;
        void Run(float speed);
        /**jump*/
    private:
        void Jump(glm::vec2 DirectionAmount);
        glm::vec2 m_JumpBuffer;
        const glm::vec2 m_JumpUpMax = glm::vec2(0,9);
        const glm::vec2 m_JumpRightUpMax = glm::vec2(4,9);
        const glm::vec2 m_JumpLeftUpMax = glm::vec2(-4,9);
        /**Spring Jump*/
        const glm::vec2 m_SpringJumpMax = glm::vec2 (0, 16);

        const float m_JumpDecreaseScalarY = 0.2f;

        /**gravity*/
    private:
        void ApplyGravity();
        float m_dropSpeed;
        const float m_dropScaleSpeed = 0.3f;
        /**TouchWall Slide*/
    private:
        void Sliding();
        const float m_SlideDropSpeed = -3 ;
        /**Dash*/
    private:
        bool m_canDash;
        void Dash();
        const float m_dashBuffer = 10;
        float m_dashDuration;
        /***/
    private:
        MovementState m_MovementState;
        glm::vec2 m_speed ;
        glm::vec2 m_direction;
        Player::CelPlayer* m_owner;
    };
}

#endif //PICO8_CELESTE_CELPLAYERMOVEMENT_H
