#ifndef CELGAMEOBJECT_HPP
#define CELGAMEOBJECT_HPP

#include "../../PTSD/include/Util/GameObject.hpp"
#include "../../../../../../usr/include/c++/11/string"

namespace Object {
class CelGameObject:public Util::GameObject{
public:
    CelGameObject() ;
    CelGameObject(const CelGameObject& other);
    /***/
    CelGameObject(const std::string& ImagePath,glm::vec2 Initposition = glm::vec2(0,0));
    CelGameObject(std::shared_ptr<Object::CelGameObject> sharedPtr);
public:

    /** Get the Edges */
    glm::vec2 GetHorizonLine();
    glm::vec2 GetVertualLine();
    /**Get the Predict Edges*/
    glm::vec2 GetHorizonLine(float newXPosition);
    glm::vec2 GetVertualLine(float newYPosition);

protected:
    /**Set IMG*/
    void SetImage(const std::string& ImagePath);
};
}


#endif