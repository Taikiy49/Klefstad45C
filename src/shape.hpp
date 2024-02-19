#ifndef SHAPE_HPP
#define SHAPE_HPP
using namespace std;
#include <iosfwd>
#include <string>

struct Point{
    int x;
    int y;
};

class Shape{
public:
    // constructs this Shape with given center and name.
    Shape(Point center, string name);
    void print(ostream &out) const;

    // deletes assignment to prevent accidental slicing?
    Shape &operator=(const Shape &other) = delete;

    // computes and returns the area of this Shape.
    virtual double area() const = 0;

    // draws the shape using graphics ooooo
    virtual void draw(ostream &out) const = 0;
    virtual Shape *clone() const = 0;
    virtual ~Shape() = default;

protected:
    Shape(const Shape &other) = default;
private:
    Point center;
    string name;
};

#endif