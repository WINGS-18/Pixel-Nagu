#pragma once

#include "engine/math/vector4.h"

namespace Engine::Math {

    struct Rect {
        Vector4 m_upper;
        Vector4 m_lower;

        Rect() = default;
        Rect(Vector4 upper, Vector4 lower);
    };

}