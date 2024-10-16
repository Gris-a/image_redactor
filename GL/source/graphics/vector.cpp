#include "../../include/graphics/vector.hpp"

namespace GL
{

Vector2d::Vector2d(): x_(0), y_(0) {}
Vector2d::Vector2d(double x, double y): x_(x), y_(y) {}


double Vector2d::x() const
{
    return x_;
}

double Vector2d::y() const
{
    return y_;
}


void Vector2d::set_x(double x)
{
    x_ = x;
}

void Vector2d::set_y(double y)
{
    y_ = y;
}


double Vector2d::len() const
{
    return std::sqrt(x_ * x_ + y_ * y_ );
}


Vector2d &Vector2d::operator+=(const Vector2d &diff)
{
    x_ += diff.x_;
    y_ += diff.y_;

    return *this;
}

Vector2d &Vector2d::operator-=(const Vector2d &diff)
{
    x_ -= diff.x_;
    y_ -= diff.y_;

    return *this;
}


Vector2d &Vector2d::operator*=(double scale)
{
    x_ *= scale;
    y_ *= scale;

    return *this;
}

Vector2d &Vector2d::operator/=(double scale)
{
    x_ /= scale;
    y_ /= scale;

    return *this;
}


Vector2d operator+(const Vector2d &vec1, const Vector2d &vec2)
{
    Vector2d res = vec1;
    res += vec2;

    return res;
}

Vector2d operator-(const Vector2d &vec1, const Vector2d &vec2)
{
    Vector2d res = vec1;
    res -= vec2;

    return res;
}


Vector2d operator*(const Vector2d &vec, const double scale)
{
    Vector2d res = vec;
    res *= scale;

    return res;
}

Vector2d operator*(const double scale, const Vector2d &vec)
{
    Vector2d res = vec;
    res *= scale;

    return res;
}


Vector2d operator/(const Vector2d &vec, const double scale)
{
    Vector2d res = vec;
    res /= scale;

    return res;
}


Vector2d normalize(const Vector2d &vec)
{
    Vector2d normal = vec;

    double vec_len = vec.len();
    if(vec_len != 0.0)
    {
        normal /= vec_len;
    }

    return normal;
}

}; // namespace GL