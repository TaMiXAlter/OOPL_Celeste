#ifndef CELGAMEOBJECT_HPP
#define CELGAMEOBJECT_HPP

#include "Util/GameObject.hpp"
#include <string>

namespace CelUtil {
class CelGameObject:public Util::GameObject{
public:
    CelGameObject() = default;
    /***/
    CelGameObject(const std::string& ImagePath,glm::vec2 Initposition = glm::vec2(0,0));

public:
    /**Set IMG*/
    void SetImage(const std::string& ImagePath);
    /** Get the Edges */
    glm::tvec2<float>HorizonColliderLine();
    glm::tvec2<float>VertualColliderLine(); 
};
}


#endif