
#pragma once

#ifndef MATRIX_ROW_H
#define MATRIX_ROW_H

#include <vector>
#include <valarray>
#include <iostream>

namespace LinAlg {
    class Row {
    public:
        Row();

        Row(int inWidth, int inVal);

        Row& operator=(const Row& rhs);

        int& operator[](size_t i);
        const int& operator[](size_t i) const;

        Row operator+(const Row& rhs);
        Row operator-(const Row& rhs);
        Row operator*(int k);

        int size() const { return mSize; }


        friend std::ostream& operator<<(std::ostream& os, const Row& r);

    private:
        std::vector<int> mRow;
        int mSize{};
    };
}


#endif //MATRIX_ROW_H
