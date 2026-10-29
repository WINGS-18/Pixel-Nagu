#include "engine/core/Time.h"
#include <thread>

namespace Engine {

    Time::Time() {
        m_engineStart = std::chrono::steady_clock::now();
        m_currentFrame = std::chrono::steady_clock::now();
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
        ++m_globalFrameCounter;
        ++m_localFrameCounter;
        m_lastFrame = m_currentFrame;
        m_currentFrame = std::chrono::steady_clock::now();
        std::chrono::duration<float, std::milli> delta = m_currentFrame - m_lastFrame;
        m_delta = delta.count() * 0.001f;
    }

    double Time::getUpTime() {
        auto curr = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed = curr - m_engineStart;
        return elapsed.count();
    }

    void Time::sleepUntil(double millisec) {
        auto curr = std::chrono::steady_clock::now();
        std::chrono::duration<double, std::milli> elapsed = curr - m_currentFrame;

        double remainingTime = millisec - elapsed.count();

        if(remainingTime > 0.0)
            sleep(remainingTime);
    }

    float Time::delta() const {
        return m_delta;
    }

    void Time::resetLocalFrameCounter() noexcept {
        m_localFrameCounter = 0;
    }

    std::uint64_t Time::getGlobalFrameCounter() const noexcept {
        return m_globalFrameCounter;
    }

    std::uint64_t Time::getLocalFrameCounter() const noexcept {
        return m_localFrameCounter;
    }

}