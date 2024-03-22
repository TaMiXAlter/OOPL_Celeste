# ifndef PLAYERCONTROLLER_HPP
# define PLAYERCONTROLLER_HPP

#include "CelUtil/CelGameObject.hpp"

enum MovementState{
    OnGround,
    TouchWall,
    Falling,
    Jumping,
    Dashing,
};
namespace Player {
    class CelPlayer: public CelUtil::CelGameObject{
    public:
        CelPlayer(const std::string ImgPath);
        void UpdateSolid(std::vector<std::shared_ptr<CelUtil::CelGameObject>> solids);
        void Update();
    /**collision function*/
    private:
        /**move function*/
        void MoveX(float amount);
        void MoveY(float amount);
        /**detect function*/
        bool OnCollides(std::shared_ptr<CelUtil::CelGameObject> other,glm::vec2 position);
        bool CheckCollides(glm::vec2 newPosition);
        /**thing to detect*/
        std::vector<std::shared_ptr<CelUtil::CelGameObject>> m_solids;

    /**jump function*/
    private:
        void Jump();
        float m_JumpBuffer;


        const float m_MaxJumpBuffer = 8;
        const float m_JumpDecreaseScaler = 0.5f;

    /**gravity function*/
    private:
        void ApplyGravity();
        float m_dropSpeed;
        const float m_dropScaleSpeed = 0.5f;
    /**TouchWall Slide*/
    private:
        void Sliding();
        const float m_SlideDropSpeed = -2;
    /***/
    private:
        MovementState m_MovementState;
        glm::vec2 m_speed ;
    };
};

#endif