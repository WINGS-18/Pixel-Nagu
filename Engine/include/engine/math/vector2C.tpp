#include "engine/math/vector2C.h"

namespace Engine::Math {

        
    template<IsAllowed T>
    Vector2C<T>::Vector2C()
        : x(0), y(0) {}

    template<IsAllowed T>
    Vector2C<T>::Vector2C(T con_x, T con_y)
    : x(con_x), y(con_y) {}


    template<IsAllowed T>
    bool Vector2C<T>::operator ==(const Vector2C<T>& other) const {
        return (x == other.x && y == other.y);
    }

    template<IsAllowed T>
    Vector2C<T> Vector2C<T>::operator +(const Vector2C<T>& other) const {
        return {x + other.x, y + other.y};
    }

    template<IsAllowed T>
    Vector2C<T> Vector2C<T>::operator -(const Vector2C<T>& other) const {
        return {x - other.x, y - other.y};
    }
    
    template<IsAllowed T>
    Vector2C<T>& Vector2C<T>::operator+=(const Vector2C<T>& other) noexcept {
        x += other.x;
        y += other.y;

        return (*this);
    }

    template<IsAllowed T>
    Vector2C<T>& Vector2C<T>::operator-=(const Vector2C<T>& other) noexcept {
        x -= other.x;
        y -= other.y;
        
        return (*this);
    }
    
    template<IsAllowed T>
    Vector2C<T> Vector2C<T>::operator*(T scalar) const noexcept {
        return {x * scalar, y * scalar};
    }

    template<IsAllowed T>
    Vector2C<T> Vector2C<T>::operator/(T scalar) const noexcept {
        return {x / scalar, y / scalar};
    }

}