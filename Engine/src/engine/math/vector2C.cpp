#include "engine/math/vector2C.h"

namespace Engine::Math {

    Vector2C::Vector2C()
        : x(0), y(0) {}

    Vector2C::Vector2C(int con_x, int con_y)
        : x(con_x), y(con_y) {}

    void Vector2C::operator =(Vector2C& other) {
        x = other.x;
        y = other.y;
    }
    
    bool Vector2C::operator ==(const Vector2C& other) const {
        return (x == other.x && y == other.y);
    }

    bool Vector2C::operator <(const Vector2C& other) const {
        return (x < other.x && y < other.y);
    }

    bool Vector2C::operator >(const Vector2C& other) const {
        return (x > other.x && y > other.y);
    }

    bool Vector2C::operator <=(const Vector2C& other) const {
        return (x <= other.x && y <= other.y);
    }

    bool Vector2C::operator >=(const Vector2C& other) const {
        return (x >= other.x && y >= other.y);
    }

    Vector2C Vector2C::operator +(const Vector2C& other) const {
        return {x + other.x, y + other.y};
    }

    Vector2C Vector2C::operator -(const Vector2C& other) const {
        return {x - other.x, y - other.y};
    }

}