#ifndef VECTOR2D_H
#define VECTOR2D_H
#include <iostream>

class Vector2D
{
    public:
        float x,y;
        Vector2D();
        Vector2D(float x, float y);

        Vector2D& Add(const Vector2D& vec);
        Vector2D& Subtract(const Vector2D& vec);
        Vector2D& Multiply(const Vector2D& vec);
        Vector2D& Divide(const Vector2D& vec);

        friend Vector2D& operator+(Vector2D& obj1, Vector2D& obj2);
        friend Vector2D& operator-(Vector2D& obj1, Vector2D& obj2);
        friend Vector2D& operator*(Vector2D& obj1, Vector2D& obj2);
        friend Vector2D& operator/(Vector2D& obj1, Vector2D& obj2);

        Vector2D& operator+=(Vector2D& obj1);
        Vector2D& operator-=(Vector2D& obj1);
        Vector2D& operator*=(Vector2D& obj1);
        Vector2D& operator/=(Vector2D& obj1);

        friend std::ostream& operator<<(std::ostream& out, Vector2D vec);

};

#endif // VECTOR2D_H
