//
// Created by tami on 2024/4/7.
//

#ifndef PICO8_CELESTE_CELLEVELS_H
#define PICO8_CELESTE_CELLEVELS_H
#include "../Object/CelGameObject.hpp"
#include "../../PTSD/lib/glm/glm/vec2.hpp"
/**
 * s=solid
 * k = spike
 * p = playerSpawn
 * S = spring*/
 //todo: better Data saving
static const char* s_Level4 = "sssss,,,ssssssss,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,sss,,,,,,,,,,,,,ssss,,,,,,,,,,,,,ss,,,,,,,,,,,,,,ss,,,,bb,,,,,,,,ss,,,,,,,,,,,,,,ss,,,,,,,,,,,,,,ss,,,bb,,,,,,,,,ss,,,,,,,,,,,,,,ss,,,,,,bb,p,,,,,,,,,,,,,,ssss,,,,,,,,bb,,ssss,,,,bb,,,,,,ssssbb,,,,,,,,,,";
namespace Level{

    class CelLevels{
    public:
        inline CelLevels(){
            LevelContainer.push_back(s_Level4);
        };
        std::vector<const char*> LevelContainer{
                "sssssssssssss,,sssssssss,,,,,,,sssss,,,,,,,,,,,ssss,,,,,,,,,,ssssss,,,,,,,,,ssss""sss,,,,,,,,,,,sssssss,,,,,,,,,,sss,,,,,,,,,,,,,ss,,,,,,,,,,,,,,ss,,,,,,,,,,,,sss,,,,,,,,,,,,,,ss,,,,,,,,,,,,,,ss,p,ss,,ss,,,,,sssssss,,ss,,kkksssssss,,sskksssssssssskksssssssss",
                "ssssssssssss,,,sssssss,,,,ss,,,sssss,,,,,,ss,,,ssss,,,,,,,ss,,,ssss,,,,,,,s,,,,ssss,,,,k,,s,,,,ss,,,,,,s,,,,,,ssssss,,,s,,,,,,ssssss,,,s,,,,,,ssssss,,,s,,,,,,ssssss,,,s,,,,,sssssss,,,s,,,,,,,s,,ss,,,s,,,,,,,s,,,s,,,skkk,,,,,,p,,,,,ssss,,,,,sssssssssss,,,,,",
                "ssssssss,,,,ssssssssss,,,,,,,sssssssss,,,,,,,ssssssss,,,,,,,,,sss,sss,,,,,,,,,,s,,,ssss,,,,,,,,,,,,,ssskkkk,,,,,,,,,sssssss,,,,,,,,,,,,,ss,,,,ss,,,,,,,,,,,,,,ss,,,,,,,,,,,,,,ss,,,,,,,kkkk,,,ss,,,,,,,ssss,,,ss,p,,,,,,ss,,,,sssss,,S,,ss,,,Ssssss,,s,,ss,,,sss"
        };
    };
}
#endif //PICO8_CELESTE_CELLEVELS_H
