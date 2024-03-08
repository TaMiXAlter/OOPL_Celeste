
#include "CelUtil/CelGameObject.hpp"
#include <glm/fwd.hpp>
#include "Util/Image.hpp"

namespace CelUtil {

    CelGameObject::CelGameObject(const std::string& ImagePath,glm::vec2 Initposition){
        SetImage(ImagePath);

        this->m_Transform.translation = Initposition;
    }

    void CelGameObject::SetImage(const std::string& ImagePath){
        m_Drawable = std::make_shared<Util::Image>(ImagePath);
    }

    glm::vec2 CelGameObject::HorizonColliderLine(){
        const float Width = this->m_Drawable->GetSize().x;
        const float XPosition = this->m_Transform.translation.x;
        
        //** x:Left and y:Right edges */
        return glm::vec2(XPosition - (Width/2),XPosition + (Width/2));
    }

    glm::vec2 CelGameObject::VertualColliderLine(){
        const float Heigh= this->m_Drawable->GetSize().y;
        const float YPosition = this->m_Transform.translation.y;

        //** x:Down and y:Top edges */
        return glm::vec2(YPosition - (Heigh/2),YPosition + (Heigh/2));
    }

}
