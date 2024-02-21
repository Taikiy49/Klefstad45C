#include "circle.hpp"
#include <iostream>
#include <numbers>

using namespace std;

Circle::Cricle(Point center, string name, int radius) : Shape(center, name)
{
    this->radius = radius;
}

Circle *Circle::clone() const
{
    return new Circle(*this);
}

void Circle::draw(ostream &out) const
{
    for (int y = -radius; y <= radius; y += 2)
        for (int x = -radius; x <= radius; ++x)
            out << (x * x + y * y <= radius * radius ? '*' : ' ');
    out << '\n';
}

double Circle::area() const{
    const double pi = pi_v<double>;
    return radius*radius*pi;
}