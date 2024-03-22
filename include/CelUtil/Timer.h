//
// Created by tami on 2024/3/15.
//

#ifndef PICO8_CELESTE_TIMER_H
#define PICO8_CELESTE_TIMER_H

namespace CelUtil{
    class Timer {
    public:
        static bool WaitForSeconds(unsigned long time);
    private:
        static unsigned long m_nowTime;
    };
}



#endif //PICO8_CELESTE_TIMER_H
