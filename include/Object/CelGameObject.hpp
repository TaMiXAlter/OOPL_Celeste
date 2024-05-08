#ifndef CELGAMEOBJECT_HPP
#define CELGAMEOBJECT_HPP

#include "Util/GameObject.hpp"
#include "string"

namespace Object {
class CelGameObject:public Util::GameObject{
public:
    CelGameObject() ;
    virtual void Update(){};
    CelGameObject(const CelGameObject& other);
    /***/
    CelGameObject(const std::string& ImagePath,glm::vec2 Initposition = glm::vec2(0,0));
    CelGameObject(std::shared_ptr<Object::CelGameObject> sharedPtr);
public:

    /** Get the Edges */
    virtual glm::vec2 GetHorizonLine();
    virtual glm::vec2 GetVertualLine();
    /**Get the Predict Edges*/
    glm::vec2 GetHorizonLine(float newXPosition);
    glm::vec2 GetVertualLine(float newYPosition);

protected:
    /**Set IMG*/
    void SetImage(const std::string& ImagePath);
    void SetAnimation(const std::vector<std::string> &paths, bool play,
                      std::size_t interval, bool looping = true,
                      std::size_t cooldown = 100);
};
}


#endif