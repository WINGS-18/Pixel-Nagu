#include "engine/core/Time.h"
#include <thread>
#include <chrono>

namespace Engine {

    Time& Time::getTime() {
        static Time t;
        return t;
    }

    void Time::sleep(int millisec) {
        std::this_thread::sleep_for(std::chrono::milliseconds(millisec));
    }

}