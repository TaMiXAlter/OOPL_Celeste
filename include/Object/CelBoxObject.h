//
// Created by tami on 2024/4/19.
//

#ifndef PICO8_CELESTE_CELBOXOBJECT_H
#define PICO8_CELESTE_CELBOXOBJECT_H

#include <glm/vec2.hpp>
#include "CelGameObject.hpp"
#include "Util/Animation.hpp"
/**issue:
 * 2. 玩家死掉不會刷新方塊*/
enum BoxState{
    Idel,
    Brokening,
    Broken
};
namespace Object {

    class CelBoxObject: public CelGameObject{
    public:
        CelBoxObject(glm::vec2 Initposition);
        glm::vec2 GetHorizonLine() override;
        glm::vec2 GetVertualLine() override;
    private:
        const std::vector<std::string> m_aniPath{
            RESOURCE_DIR"/Imgs/Celeste_objects/brokenbox1.png",
            RESOURCE_DIR"/Imgs/Celeste_objects/brokenbox2.png",
            RESOURCE_DIR"/Imgs/Celeste_objects/brokenbox3.png",
        };
        std::shared_ptr<Util::Animation> m_anim;
        const std::size_t m_animInterval = 150;
    /**OnBroken*/
    public:
        void Update() override;
        void StartBroken();
        BoxState GetBoxState();
    private:
        unsigned long m_StartBrokenTime;
        unsigned long m_StartWaitForRevive;
        BoxState m_BoxState;
    private:
        const unsigned long m_BrokenTotalTime = m_animInterval*3;
        const unsigned long m_ReviveTotalTime = 3000;
    };

} // Object

#endif //PICO8_CELESTE_CELBOXOBJECT_H
