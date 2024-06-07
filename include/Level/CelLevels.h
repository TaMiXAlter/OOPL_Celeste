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
 * B = Balloon
 * C = GoLeftCloud
 * c = GoRightCloud
 * d = DashCoin
 * f = normal fruit
 * F = Flying fruit*/
 //todo: better Data saving
namespace Level{

    class CelLevels{
    public:
        std::vector<const char*> LevelContainer{
                "sssssssssssss,,sssssssss,,,,,,,sssss,,,,,,,,,,,ssss,,,,,,,,,,ssssss,,,,,,,,,ssss""sss,,,,,,,,,,,sssssss,,,,,,,,,,sss,,,,,,,,,,,,,ss,,,,,,,,,,,,,,ss,,,,,,,,,,,,sss,,,,,,,,,,,,,,ss,,,,,,,,,,,,,,ss,p,ss,,ss,,,,,sssssss,,ss,,kkksssssss,,sskksssssssssskksssssssss",
                "ssssssssssss,,,sssssss,,,,ss,,,sssss,,,,,,ss,,,ssss,,,,,,,ss,,,ssss,,,,,,,s,,,,ssss,,,,k,,s,,,,ss,,,,,,s,,,,,,ssssss,,,s,,,,,,ssssss,,,s,,,,,,ssssss,,,s,,,,,,ssssss,,,s,,,,,sssssss,,,s,,,,,,,s,,ss,,,s,,,,,,,s,,,s,,,skkk,,,,,,p,,,,,ssss,,,,,sssssssssss,,,,,",
                "ssssssss,,,,ssssssssss,,,,,,,sssssssss,,,,,,,ssssssss,,,,,,,,,sss,sss,,,,,,,,,,s,,,ssss,,,,,,,,,,f,,ssskkkk,,,,,,,,,sssssss,,,,,,,,,,,,,ss,,,,ss,,,,,,,,,,,,,,ss,,,,,,,,,,,,,,ss,,,,,,,kkkk,,,ss,,,,,,,ssss,,,ss,p,,,,,,ss,,,,sssss,,S,,ss,,,Ssssss,,s,,ss,,,sss",
                "sssss,,,ssssssss,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,sss,,,,,,,,,,F,,ssss,,,,,,,,,,,,,ss,,,,,,,,,,,,,,ss,,,,bb,,,,,,,,ss,,,,,,,,,,,,,,ss,,,,,,,,,,,,,,ss,,,bb,,,,,,,,,ss,,,,,,,,,,,,,,ss,,,,,,bb,p,,,,,,,,,,,,,,ssss,,,,,,,,bb,,ssss,,,,bb,,,,,,ssssbb,,,,,,,,,,",
                "ss,,,sssssssssss,,,,,s,,,,,,,,ss,,,,,,,,,,,,,,,s,,,sss,,,,,,,,,s,,,,,,,,,,kk,,,s,,,,,,,,,,ss,,,,,,,,,,kk,,ss,,,,,,,,,,ss,,ss,,,,,,,,,,s,,,sss,,,,,,,,,s,,,,ss,,,,,,,,,s,,,,,,,,,,p,,,,s,,,,,,,,,ssss,,s,,,,,,,,,,,s,,,s,,,,sssss,,s,,,s,,,,,s,,,,,s,,,s,,,,,s,,,",
                "ssssssssssss,,ssssssssssssss,,ssssssssssssss,,ssssssssssssss,,sssssss,sss,,,,,ss,,sss,,,,,,,,,ss,,kkk,,,,,,,,sss,,,,,,,,,,,,,sss,,,,,,,,,B,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,p,,,,,,,,,,,,,,sss,,,,,,,,,,,,,sssssss,,,,,,,sssssssss,,,sssssssssssss,,,ssssss",
                "ssssss,,,,ssssssssssss,,,,ssssssssss,,,,,,,,ssssssk,,,,,,,,,,kssssk,,,,,,,,,,ksssskc,,,kk,,c,ksss,,,,,kssk,F,,,ss,,,,,,,,,,,,,,ss,C,,,,,,,C,,,,s,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,c,,,,,c,,,,,c,,,,,,,,,,,,,,,,,C,,,,,C,,,,,C,,,,,p,,,,,,,,,,,,,,sss,,,,,,,,,,,,",
                "s,,,,ssssssssssss,,,,,,,,ssssssss,,,,,,,,,,,,,sss,,,,,,,,,,,,,sss,,,,,B,,,,,,,sssk,,,,,,,,,,,,ssss,,,,,,,,,,,,ssss,,,,,,,,,,,,b,s,,,,,,,,,,,,,b,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,S,,,,,,,,,,,,,,,b,,,,p,,,,bbb,,,,,,,ssss,,,,,,,,,,,,",
                "sss,,,sssssssssss,,,,,sss,,,,,sss,,,,,sss,,,,,ss,,,,,,,,,,,,,,ss,,,,B,,,B,,,,,ss,,,,,,,,,,,,,,ss,,,,,,,,,,,,,,ss,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,p,,,kkk,,,,,,,kkskkksss,,,SS,,ssssssssskkksskkssssssssssssssss",
                "sss,,,,ssssssssssss,,,,ss,,,,ssssss,,,,s,,,,,,,ssss,,,,s,,,,,,,,ssss,,,s,,,,,,,,ssss,,,,,,,,,,,,ssss,,,,,,,,,s,,sssskk,,,,,,ks,,,,,sss,,,,,,ss,,,,,,,,,,,,,,,s,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,p,,,,,,,,,,,,,,,s,,,bb,,,bb,,,,,s,,,,,,,,,,,,,,",
                "ssssssssss,,,ssss,,,B,,,ss,,,ssss,kkk,,,,,,,,sss,,sss,,,,,,,,,ss,ssss,,,,,,,kkss,kss,,,,,,,kssss,kss,,,,,,,kssss,kss,,,,,,,,,sss,,,,,,kk,,,,,,,skkkkkkss,,,,,C,,sssssss,,,,,,,,,s,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,p,,,,bb,,,,,,,,,bb,,,,,,,,,,,,,",
                "ssss,,,,,,,,,,,ssss,,,,,,,,,,,,ssss,,,,,,,,,,,,ssss,,,,,,,,,,,ssss,,,,,,,,,,,sssss,,,,,,,,ssssssss,,,,ssssssss,,s,,,,,sssssss,,,s,,,,,sssss,,,,,s,,,,ssssssF,,,,s,,,,ssssss,,,,,,,,,ssssss,,,,,,,,,,ssssss,,,,,,,,p,ssssss,,,,,,,sssssssss,,,,,,,ssssssss,,,,,,,",
                "sssssssssssss,,,ss,,B,,,,,,,,,,,ss,,,,kk,,,,,,,,ss,,,,ss,,,,,,sssss,,,,ss,,B,,sssss,,,,sskkkkksss,,,,,,ssssssssss,B,,,,,,,,,,ssss,,,,,,,,,,,,,,ss,,,,,,,,,k,,,,,,,,,,,,,,ksk,,,,,,,,,,k,,,k,,s,,,,,,,ksk,,,,,,,,,p,,,,,,,,k,,,,,sssk,,,,,ks,,,,,sssk,,,,,ks,,,sss",
                "s,,,,,,,,,,,sssss,f,s,,,,,,,,,,,s,,,s,skkksss,,,sssssssssssss,,,ssssssssssssss,,ssssskkkkksss,,,sssss,,,,,sss,,,sssss,,,,,s,,,,,sssss,,,,,b,,,,,sssss,,,,,b,,,sssssss,,,,,,,,,sskkkk,,,,,,,,,,,s,,,,,,,,,,,,,,,,p,,,,,,,,,,,,,,,s,,,S,,,,,,,,,,,s,,,s,,,,,,,,,,,",
                "sssss,,,sssssssssss,,,,,kssssssssss,,,,,kssk,,,,sss,,,,,kssk,,,,sss,,,,,,,,,,,,,sss,,,,,,,,,,,,,ssskkkssskkkk,,,sssssssssssss,,,ss,,,ksssss,,,,,,,,,,ksssss,,,S,,,,,,ksssss,,,b,,,B,,,kkkss,,,,,,,,,,,,,,kk,,,,,,,,,,,p,,,,,,,,,,,,,,,bbbbb,,,,,,,,,,,,,,,,,,,,,",
                "ssss,,,sssssssssssss,,,,,,,,,sss,,,,,,,,,,,,,,,s,,,,,,,,,,,,,,,,,,,kk,,S,,,,,,B,,,kss,,b,,k,,,,,,,ksskkkkks,,,,k,,kssssssss,,,,b,,kskkkkkks,,,,b,,,k,,,,,,s,,,,k,,,,,,,k,,s,,,,,,,,k,,,s,,k,,,,,p,,s,,,s,,,,,,,,ss,s,,,s,,,,,,,,ss,s,S,s,,,,,,,,ss,s,b,s,,,,,,,,",
                ",,,,,,,,,sssssss,,,,,,,,,sssssss,,,,,,,,,sssssss,,,,,,,,,,,sssss,,,,,,,,,,,sssss,,,,,,,,,,,sssss,,,,,,,,,,,sssss,,,kkkk,,,,kkkkk,,,ssss,,,,,,,,,,,,sssssssss,,,,,,,,,ssskkkk,,,,,,,,,,ks,,,,,S,,,,,,,,ks,,,,,s,,,,p,,,,,,,,,,s,,sssssk,,,S,,,s,,sssssk,,,s,,,s,,",
                "s,,,ssssssssssssk,B,kkkkskkkkksk,,,,,,,,s,,,,,s,,,,,,,,,k,,,,,k,,,B,,k,,,,,k,,,,,,,,ksk,B,ksk,B,,,,,,k,,,,,k,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,B,,,,,,,,,,,,,k,,,,,,,,,,,,,,ksk,,,,,,,,,,,,,ksk,,,p,,,kkkk,,ksk,,ssskkssss,,,,,,,ssssssc,,,,,,,,,ssssss,,,,,,,,,,",
                ",,,,,,,,ks,,ssss,,,,,,,kks,,,,,s,,,,,,ksss,,,,,s,,,,,,,,ksss,,,kk,,,,,,,,,,s,,,ks,,,,,,,,,,k,,,ss,,,k,,,,,,k,,,sk,,,sk,,,,ks,,,kk,,,ss,,,,ks,,,ks,,,ks,,,,,k,,,ss,,,ks,,,,,k,,,sk,,,ss,,,,,s,,,k,,,,ss,,,,,s,,,k,,,,ks,,,,,,,,,sp,,,,s,,,,,,,,,ss,,,,,,,,,,,,,,k",
                "ss,,,,ssssssssssss,,,,sss,,,,,,,sk,,,,,,,,,,,,,,ssssssssssssk,,Bsssssssssssssk,,sssssssssssssk,,sssssss,,,,,sk,BsssssssB,,,,,,,,ssss,,,,,,,,,,,,ssss,,,,,,,,,,,,spssB,,,,,,,,,,,sb,,,,,,,,,,,,,,s,,,,,,,,,,,,,,,s,,,,,,,,,,,,,,,s,,,,,,,,,,,,,,,s,,,,,,,,,,,,,,,,",
                ",,,,,,,,,,,,ssss,,,,,,k,,,,,,,,s,,,,,ksk,S,,,,,,,,,k,,k,ksk,,,B,,,ksk,,,,k,,,,,,,,,k,,,k,,,,,,,,,,,,,,ksk,,B,,,,,p,,,,,k,,,,,,,,,skkkkkkkkkkkk,B,sssssssssssssk,,s,,,,,s,,,,,sk,,k,,,,,k,,,,,sk,,,,,B,,,,,B,,,,,,,,,,,,,,,,,,,B,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,",
                "ssssssssss,,,sss,,,,ssssss,,,sss,,,,,,,,,s,,,sss,,,,,,,,,,,,,s,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,d,,,,,,,,,,,,,,,,,,,,,,,,,,,,,ssssss,,,,,,,,,sssssss,sss,,p,,sssssssssssssssssssssssssssssssssssssssssss",
                "sssssk,,,,,,sssssssssk,,,,,,sssssssssk,,,kkssssssss,,,,,,sssssssss,,,,,,,sssssssss,,,,,,,,,,ssssss,,,,,,,,,,,,,,ss,,,,,,,,,,,,,,ss,,,,,,,,,,,,,,ss,,,,,,,,,,,,,,ss,,,,,,,,,,,,,,ss,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,p,,,,,,,,,,,,,,ss,,,,,,,,,F,,,,sss,,,,,,,,,,",
                "s,,,sssssssssssss,,,sssssssssssss,,,,,,,,,,,sssss,,,,,kkk,,,,ssss,,,,ksss,,,,sssskkkkssss,,ksssssssssssss,,kssssssssss,,,,,kssssssssss,,,,,kssssssssss,,,kkkssssssssss,,ksssssssssssss,,ksssssss,,,,,,,,ksssssss,,,,,,,,ksssssss,p,,,,,,ksssssssssss,,,,ksssssss",
                "sssssskkkksssss,ssssssk,,,kkkss,ssssssk,,,,,,ss,ssssssk,,,k,,ss,ssssssk,,,sk,ss,ssssssk,,,skSss,sssssskS,,skbss,,,,,,sks,,sk,,,,,,k,,sssk,ssssss,ksk,,,sk,,,,,,k,ksk,,,skkkk,,,k,ksk,,,sssss,,,k,,k,,,,kkkkk,,,k,,,,p,,,,,,,,,,k,,,,ssskkkkk,S,k,,,,ssssssss,b,k",
                "ssssssssssssss,,ss,,,,,,ssk,,,,,,,,,,,k,sk,,,s,,,,,,,ks,,,,,,s,,,,,,,ks,,,,,,s,,,,,,,ks,,,,,,s,,,,,,,kskkkkkksss,,,,ssssssssssss,,,,,,,,,,,,ksss,,,,,,,,,,,,sssskkkkk,,,,,,,ssssssssskksk,,,sssssssssssk,,,,kkss,p,,,,,,,,,,,,,ssss,,,,,,,,,,,,ssss,,,,,,,,,,,,,",
                "ssssssssssssssk,sssssssssssskk,,sssssskkkkss,,,,sssssk,,,,ks,,,,sssssk,,,,ks,,,,sssssk,,,,ks,,,,sssssk,,k,ksk,,,sssssk,ks,ksk,,,ssssskBks,ks,,,,kkkksk,ks,ksB,,,,,,,,,,ks,ks,,,,,,,,,,,ks,,,,,,,,,,,,,,ks,,,,,,,,,,,,,,ks,,,,,,,p,,,,,,ks,,,,,,,s,,,,,,,,,,,,,,,",
                "sssssss,,,,kssss,p,,,ss,,,,kssssssss,ss,,,,ks,,,,,,,,ssssk,ks,,,,,,,,ssssk,,,,,,,,,,,ssssk,,,,,,,kkkkssssk,,,,,,,ssssssssk,,k,,,,kkkkkkssk,ksk,,,,,,,,ksskbksk,,,,,,,,ksskkksk,,kkkk,,kssssssk,,ssss,,ssssssk,,,ssss,,,,,,,,,B,,ssss,,,,,,,,,,,,ssssbb,,,,,,,,,,",
                "sssssssssssss,,ssssssssssssss,,sf,,,,,,,,,,ss,,,,,,k,,,,,k,ss,,,,,ksk,B,ksk,k,,,,,,k,,,,,k,kskk,,,,,,,k,,,k,kksB,,,,,ks,,,skB,k,,k,,,,k,,,sk,,,,kskk,,,k,,k,,,,,,kksk,ksk,,,,,,,p,,k,,ksk,,,,,,,s,,,,,ksk,,,,,,,s,,,,,,k,,,,,,,,s,,S,,,,,,,,,,,,s,,s,,,,,,,,,,,,",
                "ssssss,,,ssssssssssskk,,,ss,,,sssskk,,,ssk,,,,ssssk,,,,ssk,,,,ssssk,,,,kk,,,,,ssssk,,,,,,,,,,ksssskkkk,,,B,,,kssssssssk,,,,,,,ksssssssk,,kk,,,kskkkkkk,kkssk,,kskp,,,,ksssssk,kskb,,,,kssskk,,,kkkkk,,kssk,,,B,,ssssk,,kk,,,,,,,sssskB,,,,,,,,,,ssssk,,,,,,,,,,,",
                ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,ss,,,,,,,,,,,,,ssss,,,,,,,,,,,ssssss,,,,,,,,,,ssssss,,,,,,,,,,ssssss,,,,,,,,,,sssssss,,,,,,ssssssssss,,,,p,sssssssssss,,,ssssssssssssssss"
        };
    };
}
#endif //PICO8_CELESTE_CELLEVELS_H
