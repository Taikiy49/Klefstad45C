#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "rectangle.hpp"

class Square : public Rectangle{
public:
    Square(Point center, string name, int side);

    double area() const override;
    void draw(ostream &out) const override;
    Square* clone() const override;
protected:
    Square(const Square& other) = default;
private:
};

#endif
