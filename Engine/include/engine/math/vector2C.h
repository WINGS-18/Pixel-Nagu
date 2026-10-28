/**
 * @file Vector2C.h.
 * A struct instance capable of holding two coordinates namely x and y. 
 * It also provides many overloaded operators that will help in easy comparions.
 * Also in arithematic operations.
 */

#pragma once

#include <concepts>

namespace Engine::Math {

    template<typename T>
    concept IsAllowed = 
        std::is_same_v<T, float>  || 
        std::is_same_v<T, double> || 
        std::is_same_v<T, int>    || 
        std::is_same_v<T, short>;


    template<IsAllowed T>
    struct Vector2C {
        T x;
        T y;

        Vector2C();
        Vector2C(T x, T y);

        bool operator ==(const Vector2C& other) const;
        
        Vector2C operator -(const Vector2C& other) const;
        Vector2C operator +(const Vector2C& other)const; 

        Vector2C& operator +=(const Vector2C& other) noexcept;
        Vector2C& operator -=(const Vector2C& other) noexcept;

        Vector2C operator *(T scalar) const noexcept;
        Vector2C operator /(T scalar) const noexcept;
    };

    using vector2f = Vector2C<float>;
    using vector2i = Vector2C<int>;
    
}

#include "engine/math/vector2C.tpp"