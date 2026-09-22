#include "engine/math/rect.h"

namespace Engine::Math {

    Rect::Rect(Vector4 upper, Vector4 lower)
        : m_upper(upper), m_lower(lower) {}

}