#pragma once

#include "engine/math/vector2C.h"

namespace Engine::Math {

    struct Vector4 {
        Vector2C m_vecLeft {0, 0};
        Vector2C m_vecRight {0, 0};

        Vector4() = default;

        Vector4(Vector2C vec1, Vector2C vec2);

    };
    
}