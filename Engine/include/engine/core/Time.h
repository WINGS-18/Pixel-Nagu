/**
 * Time is a singleton.
 * Provides various time related function.
 * Class acts as a wrapper around chrono library.
 * Hides complex syntax and even math to provide highly abstracted functions.
 */

#pragma once

#include <chrono>

namespace Engine {

    class Time {
    private:
        std::chrono::time_point<std::chrono::steady_clock> m_engineStart;
        std::chrono::time_point<std::chrono::steady_clock> m_frameStart;

    private:
        std::uint64_t m_globalFrameCounter {0};
        std::uint64_t m_localFrameCounter {0};
        
    public:
        void sleep(double millisec);
        void startFrame();      //Resets m_frame to current time.
        double getUpTime();     //rturns elapsed time from the moment the engine started to the called time.
        void sleepUntil(double millisec);

        void resetLocalFrameCounter() noexcept;

        std::uint64_t getGlobalFrameCounter() const noexcept;
        std::uint64_t getLocalFrameCounter() const noexcept;
        
    private:
        Time();
        
    public:
        static Time& getTime();

    public:
        //explicitly deleting constructors and copy assignment operator to avoid object copying or moving.
        Time(Time&) = delete;
        Time(Time&&) = delete;
        void operator= (Time other) = delete;
    };

}