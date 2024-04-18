//
// Created by tami on 2024/4/12.
//

#ifndef PICO8_CELESTE_SINGLETON_H
#define PICO8_CELESTE_SINGLETON_H


namespace CelUtil {

    class Singleton {
    public:

    protected:
        Singleton()=default;
    private:
        static  Singleton *sInstance;
    };

} // CelUtil

#endif //PICO8_CELESTE_SINGLETON_H
