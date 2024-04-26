
#include "Object/CelGameObject.hpp"
#include <glm/fwd.hpp>
#include "Util/Image.hpp"
#include "Util/Animation.hpp"
namespace Object {


    CelGameObject::CelGameObject() {
        //for gird
        m_Transform.scale = glm::vec2 {2,2};
    }
    CelGameObject::CelGameObject(const std::string& ImagePath,glm::vec2 Initposition){
        SetImage(ImagePath);
        this->m_Transform.translation = Initposition;
    }

    void CelGameObject::SetImage(const std::string& ImagePath){
        m_Drawable = std::make_shared<Util::Image>(ImagePath);
    }

    void CelGameObject::SetAnimation(const std::vector<std::string> &paths, bool play,
                                     std::size_t interval, bool looping ,std::size_t cooldown) {
        m_Drawable = std::make_shared<Util::Animation>(paths,play,interval);
    }

    glm::vec2 CelGameObject::GetHorizonLine(){
        const float Width = this->GetScaledSize().x;
        const float XPosition = this->m_Transform.translation.x;
        
        //** x:Left and y:Right edges */
        return {round(XPosition - (Width/2)),round(XPosition + (Width/2))};
    }

    glm::vec2 CelGameObject::GetVertualLine(){
        const float Heigth= this->GetScaledSize().y;
        const float YPosition = this->m_Transform.translation.y ;

        //** x:Bottom  and y:Top edges */
        return {round(YPosition - (Heigth/2)),round(YPosition + (Heigth/2))};

    }

    CelGameObject::CelGameObject(const CelGameObject &other) {
        m_Drawable = other.m_Drawable;
        m_Transform = other.m_Transform;
    }

    glm::vec2 CelGameObject::GetHorizonLine(float newXPosition) {
        const float Width = this->GetScaledSize().x;

        //** x:Left and y:Right edges */
        return {round (newXPosition - (Width/2)),round(newXPosition + (Width/2))};
    }

    glm::vec2 CelGameObject::GetVertualLine(float newYPosition) {
        const float Heigth= this->GetScaledSize().y;
        //** x:Bottom and y:Top edges */
        return {round(newYPosition - (Heigth/2)),round (newYPosition + (Heigth/2))};
    }

    CelGameObject::CelGameObject(std::shared_ptr<Object::CelGameObject> sharedPtr) {
        m_Drawable = sharedPtr->m_Drawable;
        m_Transform = sharedPtr->m_Transform;
    }




}
