#include "list.hpp"
#include <iostream>


using namespace std;
using list::Node;


// very weird syntaxing...
Node *list::from_string(const char *s)
{
   // this will keep running until the from_string method hits the nullptr.
   return (*s == '\0') ? nullptr : new Node{*s, from_string(&s[1])};
}


void list::free(Node *head)
{
   for (Node *current = head; current != nullptr;)
   {
       Node *next = current->next; // creates a new node that takes the next index. we need this as a placeholder.
       delete current;             // now we delete current.
       current = next;             // and current becomes the next index. this will continue until current hits a nullptr!
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
   for (Node *k = head; k != nullptr; k = k->next, ++i){}
   return i;
}


Node *list::copy(Node *head)
{
   if (head == nullptr)
       return nullptr; // if no value for head, return NULL
   Node *c = head->next;
   Node *n = new Node{head->data, nullptr};
   Node *newNode = n; // this is to prevent memory leak!
   for (; c != nullptr; n = n->next, c = c->next)
       n->next = new Node{c->data, nullptr};
   return newNode;
}


int list::compare(Node *lhs, Node *rhs)
{
   Node *l = lhs;
   Node *r = rhs;
   for (int i = 0; l != nullptr && r != nullptr; l = l->next, r = r->next, ++i)
       if (l->data != r->data)
           return (l->data - r->data);
   if (l == nullptr)
       return (r == nullptr) ? 0 : (-(r->data)); // if left is null and right is null, it will return 0.
   return (l->data);                             // if left is null and right is not null, it will return the negative value of data r.
}


int list::compare(Node *lhs, Node *rhs, int n)
{
   Node *l = lhs;
   Node *r = rhs;
   int i;
   for (i = 0; l != nullptr && r != nullptr && i < n; l = l->next, r = r->next, ++i)
       if (l->data != r->data)
           return (l->data - r->data);
   if (i == n)
       return 0;
   if (l == nullptr)
       return (r == nullptr) ? 0 : -(r->data);
   return (l->data);
}


Node *list::reverse(Node *head)
{
   Node *r = nullptr;
   Node *n = head;
   for (; n != nullptr; n = n->next)
       r = new Node{n->data, r}; //  oh yeah cuz this just adds the data to the head (which is the front!) everytime
   return r;
}


Node *list::append(Node *lhs, Node *rhs)
{
   if (lhs == nullptr) return rhs;
   if (rhs == nullptr) return lhs;
   Node *l = lhs;
   Node *r = rhs;
   Node *n = l;


   for (; l != nullptr; l = l->next){} // this gets me to the last index before the nullptr
   l->next = r; // then we add the entire right hand side to l!
   return n;    // n is the pointer to l. this is to prevent memory leak once again!
}


int list::index(Node *head, Node *node)
{
   if (head == nullptr)
       return -1; // if the head is null, returns -1
   Node *b = head;
   for (int i = 0; b != nullptr; b = b->next, ++i)
       if (b == node)
           return i; // make sure you have i in the for loop because you're trying to find the index.
   return -1;
}


Node *list::find_char(Node *head, char c){
   if (head==nullptr) return nullptr;
   for (Node *k = head; k != nullptr; k = k->next)
       if (k->data == c) return k;
   return nullptr;
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
   return (n == 0) ? head : list::nth(head->next, --n); // if n becomes 0, it stops
}


Node *list::last(Node *head)
{
   if (head == nullptr)
       return nullptr;
   return (head->next == nullptr) ? head : list::last(head->next); // if it hits the nullptr it stops
}
