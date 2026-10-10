/**
 * @file Vector2C.h.
 * A struct instance capable of holding two coordinates namely x and y. 
 * It also provides many overloaded operators that will help in easy comparions.
 * Also in arithematic operations.
 */

#pragma once

namespace Engine::Math {

    struct Vector2C {
        int x;
        int y;

        Vector2C();
        Vector2C(int x, int y);

        void operator = (Vector2C& other);
        bool operator ==(const Vector2C& other) const;
        bool operator <(const Vector2C& other) const;
        bool operator >(const Vector2C& other) const;
        bool operator <=(const Vector2C& other) const;
        bool operator >=(const Vector2C& other) const;
        Vector2C operator -(const Vector2C& other) const;
        Vector2C operator +(const Vector2C& other)const; 
    };
    
}