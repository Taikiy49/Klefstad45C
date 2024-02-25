#ifndef INT_ARRAY_HPP
#define INT_ARRAY_HPP

#include <iomainip>
#include <iostream>
#include <sstream>
#include <utility>

class Array{
public:
    // construct zero-length array
    Array() : len{0}, buf{nullptr}{}

    //construct array of given length.
    explicit Array(int len) : len(len), buf{new int[len]}{}

    //copy & move constructors... still have to implement them
    Array(const Array &other);
    Array(Array &&other) noexcept;

    //swaps 2 arrays
    //friend function?
    friend void swap(Array &lhs, Array &rhs) noexcept{
        swap(lhs.len, rhs.len);
        swap(lhs.buf, rhs.buf);
    }

    // copy and move assignment... implemenet later as well. 
    Array &operator=(const Array &other);
    Array &operator=(Array &&other) noexcept;

    // destructor
    ~Array(){}

    // get the length of the array
    int length() const{
        return len;
    }

    // get a particular element of the array.
    int &operator[](int index){
        return buf[index];
    }

    const int &operator[](int index) const{
        return buf[index];
    }

    // set every element of the array to 'val'
    void fill(int val);

private:
    int len;
    int *buf;

    bool in_bounds(int index) const{
        return index >= 0 && index < len;
    }
};

// print array to out in a single line
inline ostream &operator<<(ostream &out, const Array &array){
    stringstream temp;
    temp << setprecision(2) << fixed << right;
    for (int i=0; i < array.length(); ++i)
        temp << setw(8) << array[i];

    out << temp.str();
    return out;
}

// read array from 'in'
inline istream &operator>>(istream &in, Array &array){
    for (int i=0; i < array.length(); ++i){
        in >> array[i];
    }
    return in;
}

#endif