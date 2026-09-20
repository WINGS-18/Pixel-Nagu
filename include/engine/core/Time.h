#pragma once

namespace Engine {

    class Time {
    private:
        Time() = default;

    public:
        static Time& getTime();

        void sleep(int millisec);
    };

}