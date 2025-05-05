#include "Matrix.h"
#include <iostream>
template <typename T>
Matrix<T>::Matrix(size_t rows, size_t cols)
    : m_rows(rows), m_cols(cols), m_pdata(new T* [rows]) {
    for (size_t i = 0; i < rows; ++i) {
        m_pdata[i] = new T[cols];
    }
}

template <typename T>
Matrix<T>::Matrix(size_t rows, size_t cols, T value)
    : Matrix(rows, cols) {
    FillByValue(value);
}

template <typename T>
Matrix<T>::Matrix(const Matrix& other)
    : m_rows(other.m_rows), m_cols(other.m_cols), m_pdata(new T* [other.m_rows]) {
    for (size_t i = 0; i < m_rows; ++i) {
        m_pdata[i] = new T[m_cols];
        for (size_t j = 0; j < m_cols; ++j) {
            m_pdata[i][j] = other.m_pdata[i][j];
        }
    }
}

template <typename T>
Matrix<T>::Matrix(Matrix&& other) noexcept
    : m_rows(other.m_rows), m_cols(other.m_cols), m_pdata(other.m_pdata) {
    other.m_rows = 0;
    other.m_cols = 0;
    other.m_pdata = nullptr;
}

template <typename T>
Matrix<T>::~Matrix() {
    Destroy();
}

template <typename T>
void Matrix<T>::Destroy() {
    for (size_t i = 0; i < m_rows; ++i) {
        delete[] m_pdata[i];
    }
    delete[] m_pdata;
    m_pdata = nullptr;
}

template <typename T>
T Matrix<T>::GetElement(size_t row, size_t col) const {
    return m_pdata[row][col];
}

template <typename T>
size_t Matrix<T>::GetRowsCount() const {
    return m_rows;
}

template <typename T>
size_t Matrix<T>::GetColsCount() const {
    return m_cols;
}

template <typename T>
void Matrix<T>::FillByRandom() {
    srand((unsigned)time(0));
    for (size_t i = 0; i < m_rows; ++i)
        for (size_t j = 0; j < m_cols; ++j)
            m_pdata[i][j] = rand() % 100;
}

template <typename T>
void Matrix<T>::FillByValue(T value) {
    for (size_t i = 0; i < m_rows; ++i)
        for (size_t j = 0; j < m_cols; ++j)
            m_pdata[i][j] = value;
}

template <typename T>
T& Matrix<T>::operator()(size_t row, size_t col) {
    return m_pdata[row][col];
}

template <typename T>
T* Matrix<T>::operator[](size_t row) {
    return m_pdata[row];
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& other) const {
    Matrix<T> result(m_rows, m_cols);
    for (size_t i = 0; i < m_rows; ++i)
        for (size_t j = 0; j < m_cols; ++j)
            result.m_pdata[i][j] = m_pdata[i][j] + other.m_pdata[i][j];
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const T mult) const {
    Matrix<T> result(m_rows, m_cols);
    for (size_t i = 0; i < m_rows; ++i)
        for (size_t j = 0; j < m_cols; ++j)
            result.m_pdata[i][j] = m_pdata[i][j] * mult;
    return result;
}

template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& other) {
    if (this != &other) {
        Destroy();
        m_rows = other.m_rows;
        m_cols = other.m_cols;
        m_pdata = new T * [m_rows];
        for (size_t i = 0; i < m_rows; ++i) {
            m_pdata[i] = new T[m_cols];
            for (size_t j = 0; j < m_cols; ++j)
                m_pdata[i][j] = other.m_pdata[i][j];
        }
    }
    return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::operator=(Matrix<T>&& other) noexcept {
    if (this != &other) {
        Destroy();
        m_rows = other.m_rows;
        m_cols = other.m_cols;
        m_pdata = other.m_pdata;

        other.m_pdata = nullptr;
        other.m_rows = 0;
        other.m_cols = 0;
    }
    return *this;
}

template <typename T>
void Matrix<T>::Print() const {
    for (size_t i = 0; i < m_rows; ++i) {
        for (size_t j = 0; j < m_cols; ++j)
            std::cout << m_pdata[i][j] << " ";
        std::cout << "\n";
    }
}