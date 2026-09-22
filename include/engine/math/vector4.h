#pragma once

#include "engine/math/vector2C.h"

namespace Engine::Math {

    struct Vector4 {
        Vector2C m_vec1 {0, 0};
        Vector2C m_vec2 {0, 0};

        Vector4() = default;

        Vector4(Vector2C vec1, Vector2C vec2);    
    };
    
}