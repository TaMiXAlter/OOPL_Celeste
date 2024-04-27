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
 * S = spring
 * b = box
 * B = Balloon*/
 //todo: better Data saving
static const char* s_tempLevel= "ssssssssssss,,ssssssssssssss,,ssssssssssssss,,ssssssssssssss,,sssssss,sss,,,,,ss,,sss,,,,,,,,,ss,,kkk,,,,,,,,sss,,,,,,,,,,,,,sss,,,,,,,,,B,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,p,,,,,,,,,,,,,,sss,,,,,,,,,,,,,sssssss,,,,,,,sssssssss,,,sssssssssssss,,,ssssss";
namespace Level{

    class CelLevels{
    public:
        inline CelLevels(){
            LevelContainer.push_back(s_tempLevel);
        };
        std::vector<const char*> LevelContainer{
                "sssssssssssss,,sssssssss,,,,,,,sssss,,,,,,,,,,,ssss,,,,,,,,,,ssssss,,,,,,,,,ssss""sss,,,,,,,,,,,sssssss,,,,,,,,,,sss,,,,,,,,,,,,,ss,,,,,,,,,,,,,,ss,,,,,,,,,,,,sss,,,,,,,,,,,,,,ss,,,,,,,,,,,,,,ss,p,ss,,ss,,,,,sssssss,,ss,,kkksssssss,,sskksssssssssskksssssssss",
                "ssssssssssss,,,sssssss,,,,ss,,,sssss,,,,,,ss,,,ssss,,,,,,,ss,,,ssss,,,,,,,s,,,,ssss,,,,k,,s,,,,ss,,,,,,s,,,,,,ssssss,,,s,,,,,,ssssss,,,s,,,,,,ssssss,,,s,,,,,,ssssss,,,s,,,,,sssssss,,,s,,,,,,,s,,ss,,,s,,,,,,,s,,,s,,,skkk,,,,,,p,,,,,ssss,,,,,sssssssssss,,,,,",
                "ssssssss,,,,ssssssssss,,,,,,,sssssssss,,,,,,,ssssssss,,,,,,,,,sss,sss,,,,,,,,,,s,,,ssss,,,,,,,,,,,,,ssskkkk,,,,,,,,,sssssss,,,,,,,,,,,,,ss,,,,ss,,,,,,,,,,,,,,ss,,,,,,,,,,,,,,ss,,,,,,,kkkk,,,ss,,,,,,,ssss,,,ss,p,,,,,,ss,,,,sssss,,S,,ss,,,Ssssss,,s,,ss,,,sss",
                "sssss,,,ssssssss,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,sss,,,,,,,,,,,,,ssss,,,,,,,,,,,,,ss,,,,,,,,,,,,,,ss,,,,bb,,,,,,,,ss,,,,,,,,,,,,,,ss,,,,,,,,,,,,,,ss,,,bb,,,,,,,,,ss,,,,,,,,,,,,,,ss,,,,,,bb,p,,,,,,,,,,,,,,ssss,,,,,,,,bb,,ssss,,,,bb,,,,,,ssssbb,,,,,,,,,,",
                "ss,,,sssssssssss,,,,,s,,,,,,,,ss,,,,,,,,,,,,,,,s,,,sss,,,,,,,,,s,,,,,,,,,,kk,,,s,,,,,,,,,,ss,,,,,,,,,,kk,,ss,,,,,,,,,,ss,,ss,,,,,,,,,,s,,,sss,,,,,,,,,s,,,,ss,,,,,,,,,s,,,,,,,,,,p,,,,s,,,,,,,,,ssss,,s,,,,,,,,,,,s,,,s,,,,sssss,,s,,,s,,,,,s,,,,,s,,,s,,,,,s,,,"
        };
    };
}
#endif //PICO8_CELESTE_CELLEVELS_H
