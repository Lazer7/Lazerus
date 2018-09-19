#include "Vector2D.h"
/**
    Constructor
*/
Vector2D::Vector2D()
{
    //ctor
    x= 0.0f;
    y= 0.0f;
}
/**
    Overloaded Constructor to set default values to the vector
*/
Vector2D::Vector2D(float x, float y) {
    this->x= x;
    this->y= y;
}
Vector2D& Vector2D::Add(const Vector2D& vec) {
    this->x += vec.x;
    this->y += vec.y;
}
Vector2D& Vector2D::Subtract(const Vector2D& vec) {
    this->x -= vec.x;
    this->y -= vec.y;
}
Vector2D& Vector2D::Multiply(const Vector2D& vec) {
    this->x *= vec.x;
    this->y *= vec.y;
}
Vector2D& Vector2D::Divide(const Vector2D& vec) {
    this->x /= vec.x;
    this->y /= vec.y;
}
/**Overriding arithmetic operators**/
Vector2D& operator+(Vector2D& obj1, Vector2D& obj2) {
    return obj1.Add(obj2);
}
Vector2D& operator-(Vector2D& obj1, Vector2D& obj2) {
    return obj1.Subtract(obj2);
}
Vector2D& operator*(Vector2D& obj1, Vector2D& obj2) {
    return obj1.Multiply(obj2);
}
Vector2D& operator/(Vector2D& obj1, Vector2D& obj2) {
    return obj1.Divide(obj2);
}

Vector2D& Vector2D::operator+=(Vector2D& obj1) {
    return this->Add(obj1);
}
Vector2D& Vector2D::operator-=(Vector2D& obj1) {
    return this->Subtract(obj1);
}
Vector2D& Vector2D::operator*=(Vector2D& obj1) {
    return this->Multiply(obj1);
}
Vector2D& Vector2D::operator/=(Vector2D& obj1) {
    return this->Divide(obj1);
}

std::ostream& operator<<(std::ostream& out, Vector2D vec) {
    out << "(" << vec.x << "," <<vec.y <<")";
    return out;
}

