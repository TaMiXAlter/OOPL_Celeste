#include "Player/CelPlayer.hpp"
#include "CelUtil/CelGameObject.hpp"
namespace Player {


    bool CelPlayer::OnHit(CelGameObject* TargetActor){
        glm::vec2 MyHorizon = this->HorizonColliderLine();
        glm::vec2 MyVertual = this->VertualColliderLine();

        glm::vec2 TargetHorizon = TargetActor->HorizonColliderLine();
        glm::vec2 TargetVertual = TargetActor->VertualColliderLine();
        if(TargetHorizon.y > MyHorizon.x && MyHorizon.y > TargetHorizon.x 
            && TargetVertual.y > MyVertual.x && MyVertual.y > TargetVertual.y){
                return true;
        }
        return false;
    }

    CelPlayer::CelPlayer(const std::string &ImagePath){
        this->SetImage(ImagePath);
    }

    void CelPlayer::MoveLeft() {
        this->m_Transform.translation.x -= 10;
    }

    void CelPlayer::MoveRight() {
        this->m_Transform.translation.x += 10;
    }


}