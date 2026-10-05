#include "engine/core/Time.h"
#include <thread>

namespace Engine {

    Time::Time() {
        m_engineStart = std::chrono::steady_clock::now();
    }

    Time& Time::getTime() {
        static Time t;
        return t;
    }

    void Time::sleep(double millisec) {
        std::chrono::duration<double, std::milli> duration(millisec);
        std::this_thread::sleep_for(duration);
    }

    void Time::startFrame() {
        m_frameStart = std::chrono::steady_clock::now();
    }

    double Time::getUpTime() {
        auto curr = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed = curr - m_engineStart;
        return elapsed.count();
    }

    void Time::sleepUntil(double millisec) {
        auto curr = std::chrono::steady_clock::now();
        std::chrono::duration<double, std::milli> elapsed = curr - m_frameStart;

        double remainingTime = millisec - elapsed.count();

        if(remainingTime > 0.0)
            sleep(remainingTime);
    }

}