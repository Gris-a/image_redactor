#pragma once

#include <cmath>

namespace GL
{

class Vector2d;
using Dot2d = Vector2d;

class Vector2d
{
private:
    double x_, y_;

public:
    Vector2d();
    Vector2d(double x, double y);

    double x() const;
    double y() const;

    void set_x(double x);
    void set_y(double y);

    double len() const;

    Vector2d &operator+=(const Vector2d &diff);
    Vector2d &operator-=(const Vector2d &diff);

    Vector2d &operator*=(double scale);
    Vector2d &operator/=(double scale);

    friend Vector2d operator+(const Vector2d &vec1, const Vector2d &vec2);
    friend Vector2d operator-(const Vector2d &vec1, const Vector2d &vec2);

    friend Vector2d operator*(const Vector2d &vec, const double scale);
    friend Vector2d operator*(const double scale, const Vector2d &vec);
    friend Vector2d operator/(const Vector2d &vec, const double scale);

    friend Vector2d normalize(const Vector2d &vec);
};


}; // namespace GL