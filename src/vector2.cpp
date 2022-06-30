
#include "vector2.hpp"
#include <cmath>
#include <iostream>

/**
 * https://codereview.stackexchange.com/questions/26608/review-of-2d-vector-class
 */

Vector2::Vector2()
{
    x = 0.0;
    y = 0.0;
}

void Vector2::print() {
    std::cout << "x: " << x << " y: " << y <<std::endl;
}

Vector2::Vector2(float sourceX, float sourceY)
{
    x = sourceX;
    y = sourceY;
}

Vector2 Vector2::operator+(const Vector2 &v) const
{
    return Vector2(x+v.x, y+v.y);
}

Vector2 Vector2::operator-(const Vector2 &v) const
{
    return Vector2(x-v.x, y-v.y);
}

Vector2 Vector2::operator*(const Vector2 &v) const
{
    return Vector2(x*v.x, y*v.y);
}

Vector2 Vector2::operator/(const Vector2 &v) const
{
    return Vector2(x/v.x, y/v.y);
}

bool Vector2::operator==(const Vector2 &v) const
{
    return ((x == v.x) && (y == v.y));
}

bool Vector2::operator>(const Vector2 &v) const
{
    return (x*x + y*y) > (v.x*v.x + v.y*v.y);
}

bool Vector2::operator<(const Vector2 &v) const
{
    return (x*x + y*y) < (v.x*v.x + v.y*v.y);
}

bool Vector2::operator>=(const Vector2 &v) const
{
    return (x*x + y*y) > (v.x*v.x + v.y*v.y) ||
           (x*x + y*y) == (v.x*v.x + v.y*v.y);
}

bool Vector2::operator<=(const Vector2 &v) const
{
    return (x*x + y*y) < (v.x*v.x + v.y*v.y) ||
           (x*x + y*y) == (v.x*v.x + v.y*v.y);
}
Vector2 Vector2::operator-() const
{
    return Vector2(-x, -y);
}

Vector2 Vector2::operator*(const float& scalar) const
{
    return Vector2(x*scalar, y*scalar);
}

Vector2 Vector2::operator/(const float& scalar) const
{
    return Vector2(x/scalar, y/scalar);
}

float Vector2::DotProduct(const Vector2 &a, const Vector2 &b)
{
    return ((a.x * b.x) + (a.y * b.y));
}

float Vector2::CrossProduct(const Vector2 &a, const Vector2 &b)
{
    return ((a.x * b.y) - (a.y * b.x));
}

float Vector2::Magnitude(const Vector2 &v)
{
    return sqrt((v.x * v.x) + (v.y * v.y));
}

Vector2 Vector2::Normal(const Vector2 &v)
{
    float magnitude = Magnitude(v);
    return Vector2(v.x / magnitude, v.y / magnitude);
}

Vector2 Vector2::Perpendicular(const Vector2 &v)
{
    return Vector2(v.y, -v.x);
}

bool Vector2::Intersect(const Vector2 &aa, const Vector2 &ab, const Vector2 &ba, const Vector2 &bb)
{
    Vector2 p = aa;
    Vector2 r = ab - aa;
    Vector2 q = ba;
    Vector2 s = bb - ba;

    float t = CrossProduct((q - p), s) / CrossProduct(r, s);
    float u = CrossProduct((q - p), r) / CrossProduct(r, s);

    return (0.0 <= t && t <= 1.0) &&
           (0.0 <= u && u <= 1.0);
}

Vector2 Vector2::GetIntersect(const Vector2 &aa, const Vector2 &ab, const Vector2 &ba, const Vector2 &bb)
{
    float pX = (aa.x*ab.y - aa.y*ab.x)*(ba.x - bb.x) -
               (ba.x*bb.y - ba.y*bb.x)*(aa.x - ab.x);
    float pY = (aa.x*ab.y - aa.y*ab.x)*(ba.y - bb.y) -
               (ba.x*bb.y - ba.y*bb.x)*(aa.y - ab.y);
    float denominator = (aa.x - ab.x)*(ba.y - bb.y) -
                        (aa.y - ab.y)*(ba.x - bb.x);

    return Vector2(pX / denominator, pY / denominator);
}