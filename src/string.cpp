#include "string.hpp"
#include <iostream>

using namespace std;
using list::Node;

// constructor from c-style string
// const char *cstring = "Goodbye";
// String stringFromCString(cstring);
String::String(const char *s)
{
    head = list::from_string(s);
}

// copy constructor
// String originalString("Hello");
// String copiedString(orginalString);
// ^ this is legal because of the copy constructor
String::String(const String &s)
{
    head = list::copy(s.head);
}

// move constructor
// String temporaryString("World");
// String movedString(move(temporaryString));
String::String(String &&s)
{
    head = s.head;
    s.head = nullptr;
}

String::~String()
{
    list::free(head); // what does the free method do?
}

void String::print(ostream &out) const
{
    list::print(out, head);
}

void String::swap(String &s)
{
    Node *temp = head;
    head = s.head;
    s.head = temp;
}

String &String::operator=(const String &s)
{
    if (this == &s)
        return *this;
    list::free(head);
    head = copy(s.head); // since this is a copy, s.head does not have to be null.
    return *this;
}

String &String::operator=(String &&s)
{
    if (this == &s)
        return *this;
    list::free(head);
    head = s.head;
    s.head = nullptr; // in this case, since it is a move operator, s.head will transfer over to head, making s.head null.
    return *this;
}

bool String::in_bounds(int index) const
{
    return (list::nth(head, index)); // checks if the index is in bound using the nth method!
}

char String::operator[](int index) const
{
    Node *c = list::nth(head, index);
    if (c != nullptr) // if c is not null, it will return the data.
        return c->data;
    cout << "ERROR" << endl; // else it would print and error...
    return '\0';
}

int String::size() const
{
    return list::length(head); // using length method from list to return the size
}

void String::read(istream &in)
{
    char temphead[1024];
    in >> temphead;

    Node *k = list::from_string(temphead);
    Node *l = list::last(head);
    if (l != nullptr)
        l->next = k;
    else
        head = k;
}

ostream &operator<<(ostream &out, const String &s)
{
    s.print(out);
    return out;
}

istream &operator>>(istream &in, String &s)
{
    s.read(in);
    return in;
}

int String::indexOf(char c) const
{
    Node *f = list::find_char(head, c); // finds the character using the find_char method from list
    int k = list::index(head, f);       // runs the index method from list
    return k;
}

// index of a copy
int String::indexOf(const String &s) const
{
    if (s.head == nullptr) // checks if the head of the copy object is null.
        return 0;
    Node *f = list::find_list(head, s.head); //
    int k = list::index(head, f);
    return k;
}

// copy operator
bool String::operator==(const String &s) const
{
    return (list::compare(head, s.head) == 0);
}

// spaceship!
strong_ordering String::operator<=>(const String &s) const
{
    return (list::compare(head, s.head) <=> 0);
}

String String::reverse() const
{
    Node *r = list::reverse(head); // reverses the head with reverse method.
    String s("");                  // creates a new empty string object
    s.head = r;                    // sets the head of the new string object to the reverse of head.
    return s;                      // returns a reverse of head without actually changing what we currently have for head.
}

String String::operator+(const String &s) const
{
    String added("");
    added.head = list::append(head, s.head); // appends head to s.head and gives it to the newly create added.head
    return added;
}

String &String::operator+=(const String &s)
{
    Node *l = list::last(head);
    l->next = list::copy(s.head);
    return *this;
}
