#include "engine/math/line.h"

namespace Engine::Math {

    Line::Line(Vector2C vec1, Vector2C vec2)
        : m_vecLeft(vec1), m_vecRight(vec2) {}

}