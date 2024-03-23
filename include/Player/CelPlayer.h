# ifndef PLAYERCONTROLLER_HPP
# define PLAYERCONTROLLER_HPP

#include "CelUtil/CelGameObject.hpp"
#include "Util/Time.hpp"

enum MovementState{
    OnGround,
    TouchRightWall,
    TouchLeftWall,
    Falling,
    Jumping,
    WallJumping,
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
        void MoveWithDiraction(glm::vec2 DiractionAmount);
        /**detect function*/
        bool OnCollides(std::shared_ptr<CelUtil::CelGameObject> other,glm::vec2 position);
        bool CheckCollides(glm::vec2 newPosition);
        /**thing to detect*/
        std::vector<std::shared_ptr<CelUtil::CelGameObject>> m_solids;

    /**jump function*/
    private:
        void Jump(glm::vec2 DiractionAmount);
        glm::vec2 m_JumpBuffer;
        const glm::vec2 m_JumpUpMax = glm::vec2(0,8);
        const glm::vec2 m_JumpRightUpMax = glm::vec2(4,8);
        const glm::vec2 m_JumpLeftUpMax = glm::vec2(-4,8);

        const float m_JumpDecreaseScalarY = -glm::pow(Util::Time::GetDeltaTime(),0.5);

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