#include "square.hpp"
#include <iostream>
#include <numbers>

using namespace std;

Square::Square(Point center, string name, int side) : Rectangle(center, name, side, side){} // remmeber this is from the rectangle class!
double Square::area() const{
    return Rectangle::area();
}

void Square::draw(ostream& out) const{
    Rectangle::draw(out);
}

Square* Square::clone() const{
    return new Square(*this); //create a new square with all the information using *this!
}