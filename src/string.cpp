#include "string.hpp"
#include <iostream>

using namespace std;
using list::Node;

// constructor
String::String(const char *s){
    head = list::from_string(s);
}

// copy constructor
String::String(const char *s){
    head = list::copy(s.head);
}

// move constructor
String::String(String &&s){
    head = s.head;
    s.head = nullptr;
}

// deconstructor
String::~String(){
    list::free(head);
}

void String::print(ostream &out) const{
    list::print(out, head);
}

void String::swap(String &s){
    Node *temp = head;
    head = s.head;
    s.head = temp;
}

String &String::operator=(const String &s){
    if (this==s) return *this;
    list::free(head);
    head = copy(s.head);
    return *this;
}

String &String::operator=(String &&s){
    if (this==&s) return *this;
    list::free(head);
    head = s.head;
    s.head = nullptr; // move operator!
    return *this;
}

bool String::in_bounds(int index) const{
    return (list::nth(head, index));
}

char String::operator[](int index) const{
    Node *c = list::nth(head, index);
    if (c != nullptr) return c->data;
    cout << "ERROR" << endl;
    return '\0';
}

int String::size() const{
    return list::length(head);
}

void String::read(istream & in){
    char temphead[1024];
    in >> temphead;

    Node *k = list::from_string(temphead);
    Node *l = list::last(head);
    if (l != nullptr) l->next = k;
    else head = k;
}

ostream & operator<<(ostream &out, const String &s){
    s.print(out);
    return out;
}

ostream &operator>>(istream &in, String &s){
    s.read(in);
    return in;
}

int String::indexOf(char c) const{
    Node *f = list::find_char(head, c);
    int k = list::index(head, f);
    return k;
}