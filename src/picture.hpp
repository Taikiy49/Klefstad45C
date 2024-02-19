#ifndef PICTURE_HPP
#define PICTURE_HPP

#include <iosfwd>
#include "shape.hpp"

class Picture
{
public:
    Picture(); // creates an empty picture
    Picture(const Picture &other); // copy constructor
    Picture(Picture &&other); // move constructor

    void swap(Picture &other); // swaps this picture list with other picture's list

    Picture &operator=(const Picture &other); // copy assignment
    Picture &operator=(Picture &&other); // move assignment

    void add(const Shape &shape); // adds a clone of shape to the end
    void print_all(ostream &out) const; // calls print() on each shape in the order they were added.
    void draw_all(ostream &out) const; // draws the Shapes in this Picture in the order they were added.

    double total_area() const;
    ~Picture();

private:
    struct ListNode{
        Shape *shape; // the data in this ListNode
        ListNode *next; // pointer to next ListNode
    };

    ListNode *head; // pointer to the head 
    ListNode *tail; // pointer to the tail
};

#endif
