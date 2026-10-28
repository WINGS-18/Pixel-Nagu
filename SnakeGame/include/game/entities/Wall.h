#pragma once

#include "engine/core/bodies/RigidBody.h"

namespace sg {

    namespace ec = Engine::Core;

    class Wall {
    private:
        ec::RigidBody m_wallBody;

    public:
        Wall(bool isActive, int rows, int cols);

        void init(const std::vector<char>& sym);
        void initAll(char sym);

        void setWallPosition(float x, float y);

        const ec::Cell& getCell(int index) const noexcept;
        const ec::RigidBody& getBody() const noexcept;

        Engine::Math::vector2f origin() noexcept {
            return m_wallBody.origin();
        }

    };

}