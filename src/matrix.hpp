#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "array.hpp"

template <typename T>
class Matrix{
public:
    Matrix();
    Matrix(int rows, int cols);

    Array<T> &operator[](int row);
    const Array<T> &operator[](int row) const;

    int num_rows() const;
    int num_cols() const;

    void fill(const T &val);

    template <typename Fn>
    void fill_with_fn(Fn, fn);

private:
    int rows, cols;
    Array<Array<T>> data;
};

template <typename T>
std::ostream &operator<<(std::ostream &out, const Matrix<T> &matrix);

template <typename T>
std::istream &operator>>(std::istream &in, Matrix <T> &matrix);

#endif