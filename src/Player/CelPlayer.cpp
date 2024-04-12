#include "Player/CelPlayer.h"
#include "Object/CelGameObject.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"
namespace Player {

    CelPlayer::CelPlayer(const std::string ImgPath) {
        SetImage(ImgPath);
        m_isAlive = true;
    }

    void CelPlayer::Update() {
        m_playerMovement->UPDATE();
        if(m_Transform.translation.y <=-360 ) KillPlayer();
        if(!m_isAlive) RevivePlayer();

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
        m_playerMovement->ResetValue();
        m_Transform.translation = m_SpawnPosition;
        m_isAlive = true;
    }

    void CelPlayer::SetSpawnPosition(glm::vec2 newPosition) {
        m_SpawnPosition = newPosition;
    }


}