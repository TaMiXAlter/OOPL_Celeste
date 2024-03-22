
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

    glm::vec2 CelGameObject::GetHorizonLine(){
        const float Width = this->m_Drawable->GetSize().x;
        const float XPosition = this->m_Transform.translation.x;
        
        //** x:Left and y:Right edges */
        return {XPosition - (Width/2),XPosition + (Width/2)};
    }

    glm::vec2 CelGameObject::GetVertualLine(){
        const float Heigth= this->m_Drawable->GetSize().y;
        const float YPosition = this->m_Transform.translation.y;

        //** x:Left and y:Right edges */
        return {YPosition - (Heigth/2),YPosition + (Heigth/2)};

    }

    CelGameObject::CelGameObject(const CelGameObject &other) {
        m_Drawable = other.m_Drawable;
        m_Transform = other.m_Transform;
    }

    glm::vec2 CelGameObject::GetHorizonLine(float newXPosition) {
        const float Width = this->m_Drawable->GetSize().x;

        //** x:Left and y:Right edges */
        return {newXPosition - (Width/2),newXPosition + (Width/2)};
    }

    glm::vec2 CelGameObject::GetVertualLine(float newYPosition) {
        const float Heigth= this->m_Drawable->GetSize().y;
        //** x:Left and y:Right edges */
        return {newYPosition - (Heigth/2),newYPosition + (Heigth/2)};
    }

    CelGameObject::CelGameObject(std::shared_ptr<CelUtil::CelGameObject> sharedPtr) {
        m_Drawable = sharedPtr->m_Drawable;
        m_Transform = sharedPtr->m_Transform;
    }


}
