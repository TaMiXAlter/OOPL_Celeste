#include "Player/CelPlayer.h"
#include "Object/CelGameObject.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"
namespace Player {

    CelPlayer::CelPlayer() {
        SetImage(RESOURCE_DIR"/Imgs/Celeste_Player/6.png");
        m_Transform.scale = glm::vec2 (1.8 ,1.8);
        m_isAlive = true;

    }

    void CelPlayer::Update() {
        PlayerMovement->UPDATE();

        switch (PlayerMovement->GetDashAmount()) {
            case 0:
                SetImage(RESOURCE_DIR"/Imgs/Celeste_Player/8.png");
                break;
            case 1:
                SetImage(RESOURCE_DIR"/Imgs/Celeste_Player/6.png");
                break;
            case 2:
                SetImage(RESOURCE_DIR"/Imgs/Celeste_Player/9.png");
                break;
        }
    }
    void CelPlayer::UpdateSolid(std::vector<std::shared_ptr<Object::CelGameObject>> solids) {
        m_solids = solids;
    }

    std::vector<std::shared_ptr<Object::CelGameObject>> CelPlayer::GetSolid() {
        return m_solids;
    }

    void CelPlayer::KillPlayer() {
        m_isAlive = false;
    }

    void CelPlayer::RevivePlayer() {
        PlayerMovement->ResetValue();
        m_Transform.translation = m_SpawnPosition;
        m_isAlive = true;
    }

    void CelPlayer::SetSpawnPosition(glm::vec2 newPosition) {
        m_SpawnPosition = newPosition+glm::vec2(0,2) ;
    }
}