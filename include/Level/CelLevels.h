//
// Created by tami on 2024/4/7.
//

#ifndef PICO8_CELESTE_CELLEVELS_H
#define PICO8_CELESTE_CELLEVELS_H
#include "../Object/CelGameObject.hpp"
#include "../../PTSD/lib/glm/glm/vec2.hpp"

static  const  char* s_Level1 ="sssssssssssss,,s"
                              "ssssssss,,,,,,,s"
                              "ssss,,,,,,,,,,,s"
                              "sss,,,,,,,,,,sss"
                              "sss,,,,,,,,,ssss"
                              "sss,,,,,,,,,,,ss"
                              "sssss,,,,,,,,,,s"
                              "ss,,,,,,,,,,,,,s"
                              "s,,,,,,,,,,,,,,s"
                              "s,,,,,,,,,,,,sss"
                              ",,,,,,,,,,,,,,ss"
                              ",,,,,,,,,,,,,,ss"
                              ",p,ss,,ss,,,,,ss"
                              "sssss,,ss,,kkkss"
                              "sssss,,sskksssss"
                              "ssssskksssssssss";
namespace Level{

    class CelLevels{
    public:
        inline CelLevels(){
            LevelContainer.push_back(s_Level1);
        };
        std::vector<const char*> LevelContainer;
    };
}
#endif //PICO8_CELESTE_CELLEVELS_H
