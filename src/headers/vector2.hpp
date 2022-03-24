#ifndef Vector2_H
#define Vector2_H

#include <cfloat>
#include <climits>

/*
 * https://codereview.stackexchange.com/questions/26608/review-of-2d-vector-class
 */

/*The Vector2 class is an object consisting of simply an x and
  y value. Certain operators are overloaded to make it easier
  for vector math to be performed.*/

class Vector2 {
public:
    /*The x and y values are public to give easier access for
      outside funtions. Accessors and mutators are not really
      necessary*/
    float x;
    float y;

    //Constructor assigns the inputs to x and y.
    Vector2();
    Vector2(float, float);

    /*The following operators simply return Vector2s that
      have operations performed on the relative (x, y) values*/
    Vector2 operator+(const Vector2&) const;
    Vector2 operator-(const Vector2&) const;
    Vector2 operator*(const Vector2&) const;
    Vector2 operator/(const Vector2&) const;

    //Check if the Vectors have the same values.
    bool operator==(const Vector2&) const;

    /*Check which Vectors are closer or further from the
      origin.*/
    bool operator>(const Vector2&) const;
    bool operator<(const Vector2&) const;
    bool operator>=(const Vector2&) const;
    bool operator<=(const Vector2&) const;

    //Negate both the x and y values.
    Vector2 operator-() const;

    void print();

    //Apply scalar operations.
    Vector2 operator*(const float&) const;
    Vector2 operator/(const float&) const;

    //Product functions
    static float DotProduct(const Vector2&, const Vector2&);
    static float CrossProduct(const Vector2&, const Vector2&);

    //Returns the length of the vector from the origin.
    static float Magnitude(const Vector2&);

    //Return the unit vector of the input
    static Vector2 Normal(const Vector2&);

    //Return a vector perpendicular to the left.
    static Vector2 Perpendicular(const Vector2&);

    //Return true if two line segments intersect.
    static bool Intersect(const Vector2&, const Vector2&, const Vector2&, const Vector2&);

    //Return the point where two lines intersect.
    static Vector2 GetIntersect(const Vector2&, const Vector2&, const Vector2&, const Vector2&);
};

#endif
