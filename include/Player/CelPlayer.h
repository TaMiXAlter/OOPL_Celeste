# ifndef PLAYERCONTROLLER_HPP
# define PLAYERCONTROLLER_HPP

#include "Object/CelGameObject.hpp"
#include <glm/fwd.hpp>
#include "CelPlayerMovement.h"

namespace Player {
    class CelPlayer: public Object::CelGameObject{
    public:
        CelPlayer();
        void Update();

        void UpdateSolid(std::vector<std::shared_ptr<Object::CelGameObject>> solids);
        std::vector<std::shared_ptr<Object::CelGameObject>>  GetSolid();

        void KillPlayer();
        void SetSpawnPosition(glm::vec2 newPosition);
    private:
        Player::CelPlayerMovement* m_playerMovement = new CelPlayerMovement(this);

        glm::vec2 m_SpawnPosition;
        std::vector<std::shared_ptr<Object::CelGameObject>> m_solids;
        /**Revive*/
    public:
        bool m_isAlive;
        void RevivePlayer();
    };
};

#endif