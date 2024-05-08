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

        this->m_Transform.translation.x += m_MoveSpeed*m_Direction;
    }

    glm::vec2 CelCloudObject::GetHorizonLine() {
        return {-300,-300};
    }

    glm::vec2 CelCloudObject::GetVertualLine() {
        return {0,CelGameObject::GetVertualLine().y};
    }
} // Object