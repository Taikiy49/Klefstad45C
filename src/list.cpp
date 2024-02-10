#include "list.hpp"
#include <iostream>

using namespace std;
using list::Node;

// very weird syntaxing...
Node list::from_string(const char *s)
{
    return (*s == '\0') ? nullptr : new Node{*s, from_string(&s[1])};
}

void list::free(Node *head)
{
    Node *current = head; // creates a new ptr that stores head.
    while (current != nullptr)
    {                               // while that ptr is not null...
        Node *next = current->next; // a new ptr will be equal to the next index in current.
        delete current              // then we delete current so we can set current to a new value.
            current = next;         // current equals next and checks through the while loop once again.
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
    Node *n = new Node(head->data, nullptr); // double check on what the Node constructor does!
    Node *newNode = n;
    for (; c != nullptr; n = n->next, c = c->next)
        n->next = new Node(c->data, nullptr);
    return newNode;
}