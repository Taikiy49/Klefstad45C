#include "picture.hpp"
#include <iostream>
#include <utility>

Picture::Picture(){
    head = nullptr;
    tail = nullptr;
}

Picture::Picture(const Picture &other){ // copy constructor
    head = nullptr;
    ListNode *h = nullptr;
    ListNode *prev = nullptr;
    for (ListNode *n = other.head; n!= nullptr; prev = h, n = n->next){
        h = new ListNode((n->shape)->clone(), nullptr);
        if (!head) head = h;
        if (prev) prev->next = h;
    }
    tail = prev;
}

Picture::Picture(Picture &&other){ // move constructor
    head = other.head;
    tail = other.tail;
    other.head = nullptr;
    other.tail = nullptr;
}

void Picture::swap(Picture &other){
    ListNode *t1 = head;
    ListNode *t2 = tail;
    head = other.head;
    tail = other.tail;
    other.head = t1;
    other.tail = t2;
}

Picture &Picture::operator=(const Picture &other){ // copy assignment
    if (&other == this) return *this;
    Picture temp(other);
    swap(temp);
    return *this;
}


Picture &Picture::operator=(Picture &&other){ // move assignment
    Picture::swap(other);
    return *this;
}

void Picture::add(const Shape &shape){
    Shape *dup_shape = shape.clone();
    if (!head){
        head = new Picture::ListNode(dup_shape, nullptr);
        tail = head;
    }
    else{
        tail->next = new Picture::ListNode(dup_shape, nullptr);
        tail = tail->next;
    }
}

void Picture::print_all(ostream &out) const{
    for (ListNode *n=head; n != nullptr; n=n->next){
        (n->shape)->print(out);
        (n->shape)->draw(out);
    }
}

void Picture::draw_all(ostream &out) const{
    for (ListNode *n = head; n!=nullptr; n=n->next)
        n->shape->draw(out);
}

double Picture::total_area() const{
    double k = 0;
    for (ListNode *n = head; n != nullptr; n = n->next){
        k += (n->shape)->area();
    }
    return k;
}

Picture::~Picture() {
    ListNode *current = head;
    while (current != nullptr) {
        ListNode *nextNode = current->next;
        delete current->shape; // Free the memory occupied by the shape object
        delete current; // Free the memory occupied by the ListNode
        current = nextNode; // Move to the next node
    }
}