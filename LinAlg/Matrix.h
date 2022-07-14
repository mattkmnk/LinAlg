#pragma once

#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H

#include <vector>
#include "Row.h"

namespace LinAlg {
    class Matrix {
    public:
        Matrix() = default;
        Matrix(int inRows, int inCols, int inVal);
        Matrix(const Matrix& rhs);
        Matrix(std::initializer_list<std::initializer_list<int>>);

        Matrix& operator=(const Matrix& rhs) = default;

        void print() const;

        void transpose();

        int det() const;

        int getRows() const { return mRows; }
        int getCols() const { return mCols; }

        Row& operator[](size_t i);
        const Row& operator[](size_t i) const;

        Matrix operator+(const Matrix& rhs);
        Matrix& operator+=(const Matrix& rhs);

        Matrix operator-(const Matrix& rhs);
        Matrix& operator-=(const Matrix& rhs);

        Matrix operator*(int k);
        Matrix& operator*=(int k);


    private:
        void resize(int inRows, int inCols, int inVal);
        friend int calcDet(const Matrix& inM);

        std::vector<Row> mMatrix;
        int mRows{}, mCols{};
    };

}

#endif //MATRIX_MATRIX_H
