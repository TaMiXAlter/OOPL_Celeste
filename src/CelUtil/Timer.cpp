//
// Created by tami on 2024/3/15.
//

#include "CelUtil/Timer.h"
namespace CelUtil {
    bool Timer::WaitForSeconds(unsigned long time) {
        if(m_CountFrame == time*60){
            m_CountFrame = 0;
            return true;
        }

        m_CountFrame++;
        return false;
    }

    void Timer::ReturnZero() {
        m_CountFrame = 0;
    }
}
