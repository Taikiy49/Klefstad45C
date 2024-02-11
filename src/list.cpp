#include "list.hpp"
#include <iostream>

using namespace std;
using list::Node;

// very weird syntaxing...
Node *list::from_string(const char *s)
{
    return (*s == '\0') ? nullptr : new Node{*s, from_string(&s[1])};
}

void list::free(Node *head)
{
    Node *current = head; // creates a new ptr that stores head.
    while (current != nullptr)
    {                               // while that ptr is not null...
        Node *next = current->next; // a new ptr will be equal to the next index in current.
        delete current;             // then we delete current so we can set current to a new value.
        current = next;             // current equals next and checks through the while loop once again.
    }
    head = nullptr;
}

void list::print(ostream &out, Node *head)
{
    for (Node *k = head; k != nullptr; k = k->next) // notice that we always define a Node ptr as the head in the for loop!
        out << k->data;
}

int list::length(Node *head)
{
    int i = 0;
    for (Node *k = head; k != nullptr; k = k->next)
        ++i;
    return i;
}

Node *list::copy(Node *head)
{
    if (!head)
        return nullptr; // if no value for head, return NULL
    Node *c = head->next;
    Node *n = new Node{head->data, nullptr}; // double check on what the Node constructor does!
    Node *newNode = n;                       // newNode points to n which is a new Node object
    for (; c != nullptr; n = n->next, c = c->next)
        n->next = new Node{c->data, nullptr};
    return newNode; // newNode is the copy of the orginal node...
}

int list::compare(Node *lhs, Node *rhs)
{
    Node *l = lhs;
    Node *r = rhs;
    for (int i = 0; l != nullptr && r != nullptr; l = l->next, r = r->next, ++i)
    {
        if (l->data != r->data)
            return (l->data - r->data);
        if (l == nullptr)
            return (r == nullptr) ? 0 : (-(r->data));
        return (l->data);
    }
}

int list::compare(Node *lhs, Node *rhs, int n)
{
    Node *l = lhs;
    Node *r = rhs;
    for (int i = 0; l != nullptr && r != nullptr && i < n; l = l->next, r = r->next, ++i)
    {
        if (l->data != r->data)
            return (l->data - r->data);
        if (i == n)
            return 0;
        if (l == nullptr)
            return (r == nullptr) ? 0 : (-(r->data)); // wtf is this...
        return (l->data);
    }
}

Node *list::reverse(Node *head)
{
    Node *r = nullptr; // this is the one that contains the reverse.
    Node *n = head;
    for (; n != nullptr; n = n->next)
        r = new Node{n->data, r}; // this is how to add the data in reverse?
    return r;
}

Node *list::append(Node *lhs, Node *rhs)
{
    if (lhs == nullptr)
        return list::copy(rhs); // if the left side is empty, you take the right side
    if (rhs == nullptr)
        return list::copy(lhs); // if the right side is empty, you take the left side

    Node *l = list::copy(lhs); // l takes the copy of lhs
    Node *r = list::copy(rhs); // r takes the copy of rhs
    Node *n = l;               // a new pointer n points to l

    for (; l->next != nullptr; l = l->next)
    {
    }            // this gets me to the last index before the nullptr
    l->next = r; // this adds the right hand side to the left hand side
    return n;    // finally returns n that has everything in the left hand side appended with right hand side
}

int list::index(Node *head, Node *node)
{
    if (head == nullptr)
        return -1; // if the head is NULL, you can't index is
    Node *b = head;
    for (int i = 0; b != nullptr; ++i, b = b->next)
        if (b == node)
            return i; // compares index in b to a singular node
    return -1;        // if node does not exist
}

Node *list::find_char(Node *head, char c)
{
    if (head == nullptr)
        return nullptr;
    return (head->data == c) ? head : find_char(head->next, c); // recursion to find the character!
}

// i dont like haystack and needle ;-;
Node *list::find_list(Node *haystack, Node *needle)
{
    if (needle == nullptr)
        return haystack;
    if (haystack == nullptr)
        return nullptr;

    for (Node *h = haystack; h != nullptr; h = h->next)
    {
        Node *s = h;
        Node *n = needle;
        for (; n != nullptr; s = s->next, n = n->next)
            if (s == nullptr || s->data != n->data)
                break;
        if (n == nullptr)
            return h;
        if (s == nullptr)
            break;
    }
    return nullptr;
}

Node *list::nth(Node *head, int n)
{
    if (head == nullptr)
        return nullptr;
    return (n == 0) ? head : list::nth(head->next, --n); // more recursion to find the nth node!
}

Node *list::last(Node *head)
{
    if (head == nullptr)
        return nullptr;
    return (head->next == nullptr) ? head : list::last(head->next); // recursion to find the last node!
}
