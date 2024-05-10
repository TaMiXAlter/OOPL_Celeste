//
// Created by tami on 5/3/24.
//

#include "Object/CelCloudObject.h"

namespace Object {
    void CelCloudObject::Update() {
        CelGameObject::Update();
        /**Over Eage*/
        if(this->m_Transform.translation.x>320) this->m_Transform.translation.x = -256;
        else if(this->m_Transform.translation.x<-320) this->m_Transform.translation.x = 256;

        this->m_Transform.translation.x += GetMovement();
    }

    glm::vec2 CelCloudObject::GetVertualLine() {
        return {m_Transform.translation.y,CelGameObject::GetVertualLine().y};
    }
} // Object