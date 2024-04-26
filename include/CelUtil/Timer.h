//
// Created by tami on 2024/3/15.
//

#ifndef PICO8_CELESTE_TIMER_H
#define PICO8_CELESTE_TIMER_H

namespace CelUtil{
    class Timer {
    /**60fps*/
    public:
        bool WaitForSeconds(unsigned long time);
        void ReturnZero();
        //save by ms
        int currentTime();
    private:
        unsigned long m_CountFrame =0 ;
    };
}



#endif //PICO8_CELESTE_TIMER_H
