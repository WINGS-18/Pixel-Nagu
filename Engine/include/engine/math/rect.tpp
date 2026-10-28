#include "engine/math/rect.h"

namespace Engine::Math {

    template<IsAllowed T>
    Rect<T>::Rect(Vector2C<T> min, Vector2C<T> max)
    : m_min(min), m_max(max) {}
    
    template<IsAllowed T>
    bool Rect<T>::intersect(const Rect<T>& other) {
        if (
            m_max.x < other.m_min.x || // A's right edge is to the left of B's left edge
            m_min.x > other.m_max.x || // A's left edge is to the right of B's right edge
            m_max.y < other.m_min.y || // A's bottom edge is above B's top edge
            m_min.y > other.m_max.y    // A's top edge is below B's bottom edge
        ) {
            return false; // No overlap
        }
        
        return true; // Overlap!
    }
}