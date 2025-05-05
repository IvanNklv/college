#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>

template <typename T>
class Matrix {
public:
    Matrix(size_t rows = 2, size_t cols = 2);
    Matrix(size_t rows, size_t cols, T value);
    Matrix(const Matrix& other);
    Matrix(Matrix&& other) noexcept;
    ~Matrix();

    T GetElement(size_t row, size_t col) const;
    size_t GetRowsCount() const;
    size_t GetColsCount() const;

    void FillByRandom();
    void FillByValue(T value);

    T& operator()(size_t row, size_t col);
    T* operator[](size_t row);

    Matrix operator+(const Matrix& other) const;
    Matrix operator*(const T mult) const;
    Matrix& operator=(const Matrix& other);
    Matrix& operator=(Matrix&& other) noexcept;

    void Print() const;

private:
    void Destroy();

    T** m_pdata;
    size_t m_rows;
    size_t m_cols;
};