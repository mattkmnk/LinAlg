
#include "Matrix.h"

#include <iostream>
#include <cassert>

namespace LinAlg {

    Matrix::Matrix(int inRows, int inCols, int inVal = 0) {
        resize(inRows, inCols, inVal);
    }

    Matrix::Matrix(const Matrix& rhs) {
        mRows = rhs.mRows;
        mCols = rhs.mCols;
        mMatrix = rhs.mMatrix;
    }

    Matrix::Matrix(std::initializer_list<std::initializer_list<int>> inList) {
        auto it = inList.begin();
        resize(inList.size(), it->size(), 0);
        for (int i = 0; i < mRows; i++, ++it) {
            auto iit = it->begin();
            for (int j = 0; j < mCols; j++, ++iit) {
                mMatrix[i][j] = *iit;
            }
        }
    }

    void Matrix::resize(int inRows, int inCols, int inVal = 0) {
        mRows = inRows;
        mCols = inCols;
        mMatrix.resize(mRows, Row(mCols, inVal));
    }

    void Matrix::print() const {
        std::cout << "Matrix (" << mRows << " x " << mCols << ")\n";
        for (int i = 0; i < mRows; i++) {
            for (int j = 0; j < mCols; j++) {
                std::cout.width(2);
                std::cout << mMatrix[i][j] << " ";
            }
            std::cout << '\n';
        }
    }

    void Matrix::transpose() {
        /* Transpose of a matrix is a new matrix whose rows and rows were swapped,
         * that is rows are the columns of the original matrix
         */
        Matrix newMatrix(mCols, mRows);
        for(int i = 0; i < mRows; ++i) {
            for(int j = 0; j < mCols ; ++j) {
                newMatrix[j][i] = mMatrix[i][j];
            }
        }
        *this = newMatrix;
    }

    Matrix subMatrix(const Matrix& inM, int n, int r) {
        Matrix newMatrix(n, n, 0);
        int ci = 0;
        for(int i = 0; i < inM.getRows(); ++i) {
            if(i != r) {
                int cj = 0;
                for(int j = 0; j < inM.getCols(); ++j) {
                    if (j != 0) {
                        newMatrix[ci][cj] = inM[i][j];
                        cj++;
                    }
                }
                ci++;
            }
        }
        return newMatrix;
    }


    int calcDet(const Matrix& inM) {
        /* Matrix 2 x 2
         * | a b |
         * | c d |
         * Determinant =
         * a * d - b * c
         */
        if(inM.mRows == 2) {
            return (inM[0][0] * inM[1][1]) - (inM[0][1] * inM[1][0]);
        }

        /* Matrix n x n for n > 2
         * | 11 12 13 |
         * | 21 22 23 |
         * | 31 32 33 |
         *
         * (-1)^(1 + 1) * 11 * det(A) + (-1)^(2 + 1) * 21 * det(B) + (-1)^(3 + 1) * 31 * det(C)
         * Where
         * |  A  | |  B  | |  C  |
         * |22 23| |12 13| |12 13|
         * |32 33| |32 33| |22 23|
         *
         * Pick a row/column of the matrix, find all minors and multiply each of them with the
         * corresponding matrix entry and (-1)^(i + j) where i and j describes position of the value in matrix
         * Repeat until matrix is of size 2
         *
         * Minor is a determinant of matrix of size n - 1 formed by deleting one row and one column
         * from some larger matrix (we are deleting column 1 and rows corresponding to individual values)
         */
        int actDet = 0;
        for(int i = 0; i < inM.mRows; ++i) {
            //subMatrix(inM, inM.getRows() - 1, i).print();
            actDet += inM[i][0] * (i % 2 == 0 ? 1 : -1) * calcDet(subMatrix(inM, inM.getRows() - 1, i));
        }
        return actDet;
    }

    int Matrix::det() const {
        return calcDet(*this);
    }

    Row& Matrix::operator[](size_t i) {
        return mMatrix[i];
    }

    const Row& Matrix::operator[](size_t i) const {
        return mMatrix[i];
    }

    Matrix Matrix::operator+(const Matrix& rhs) {
        /* Two matrices may be added only if they have the same dimension
         * Addition is accomplished by adding corresponding elements
         * | 1 2 |   | 3 4 |   | 1 + 3   2 + 4 |   | 4  6|
         * | 5 6 | + | 7 8 | = | 5 + 7   6 + 8 | = |12 14|
         * | 2 1 |   | 4 3 |   | 2 + 4   1 + 3 |   | 6  4|
         */
        assert(mRows == rhs.mRows);
        assert(mCols == rhs.mCols);

        Matrix newMatrix(mRows, mCols);
        for (size_t i = 0; i < mRows; ++i) {
            newMatrix[i] = mMatrix[i] + rhs[i];
        }
        return newMatrix;
    }

    Matrix& Matrix::operator+=(const Matrix& rhs) {
        *this = *this + rhs;
        return *this;
    }

    Matrix Matrix::operator-(const Matrix& rhs) {
        /* Two matrices may be subtracted only if they have the same dimension
         * Addition is accomplished by adding corresponding elements
         * | 1 2 |   | 3 4 |   | 1 - 3   2 - 4 |   | -2 -2 |
         * | 5 6 | - | 7 8 | = | 5 - 7   6 - 8 | = | -2 -2 |
         * | 2 1 |   | 4 3 |   | 2 - 4   1 - 3 |   | -2 -2 |
         */
        assert(mRows == rhs.mRows);
        assert(mCols == rhs.mCols);

        Matrix newMatrix(mRows, mCols);
        for (size_t i = 0; i < mRows; ++i) {
            newMatrix[i] = mMatrix[i] - rhs[i];
        }
        return newMatrix;
    }

    Matrix& Matrix::operator-=(const Matrix& rhs) {
        *this = *this - rhs;
        return *this;
    }

    Matrix Matrix::operator*(int k) {
        Matrix newMatrix(mRows, mCols);
        for (int i = 0; i < mRows; ++i) {
            newMatrix[i] = mMatrix[i] * k;
        }
        return newMatrix;
    }

    Matrix& Matrix::operator*=(int k) {
        *this = *this * k;
        return *this;
    }





}