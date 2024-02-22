#include "picture.hpp"
#include <iostream>
#include <utility>

Picture::Picture()
{ // this creates and empty
    head = nullptr;
    tail = nullptr;
}

Picture::Picture(const Picture &other)
{
    head = nullptr;
    tail = nullptr;
    for (ListNode *n = other.head; n != nullptr; n = n->next)
    {
        ListNode *newNode = new ListNode(n->shape->clone(), nullptr);
        if (!head)
            head = newNode;
        if (tail)
            tail->next = newNode;
        tail = newNode;
    }
}

Picture::Picture(Picture &&other)
{ // move constructor
    head = other.head;
    tail = other.tail;
    other.head = nullptr;
    other.tail = nullptr;
}

void Picture::swap(Picture &other)
{
    ListNode *t1 = head;
    ListNode *t2 = tail;
    head = other.head;
    tail = other.tail;
    other.head = t1;
    other.tail = t2;
}

Picture &Picture::operator=(const Picture &other)
{ // copy assignment
    Picture temp(other); // this is where we keep a copy
    swap(temp);
    return *this;
}

Picture &Picture::operator=(Picture &&other)
{ // move assignment
    swap(other);
    return *this;
}

void Picture::add(const Shape &shape) {
    ListNode *newNode = new ListNode(shape.clone(), nullptr);
    if (!head) { // If the list is empty, set head and tail to the new node
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode; // Link the new node to the end of the list
        tail = newNode; // Update tail to the new node
    }
}


void Picture::print_all(ostream &out) const
{
    for (ListNode *n = head; n != nullptr; n = n->next)
    {
        n->shape->print(out); // shape is pointer stored in n, print is a pointer stored in shape.
        n->shape->draw(out);
    }
}

void Picture::draw_all(ostream &out) const
{
    for (ListNode *n = head; n != nullptr; n = n->next)
        n->shape->draw(out); // looks like it always uses something along the lines of n->shape->(method from shape)
}

double Picture::total_area() const
{
    double k = 0;
    for (ListNode *n = head; n != nullptr; n = n->next)
    {
        k += n->shape->area(); // n->shape->area! makes sense!
    }
    return k;
}

    Picture::~Picture()
{
    for (ListNode *current = head; current != nullptr;)
    {
        ListNode *nextNode = current->next;
        delete current->shape; // this is for memory leak purposes.
        delete current;
        current = nextNode;
    }
}