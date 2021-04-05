
#include "Row.h"

namespace LinAlg {
    Row::Row() = default;

    Row::Row(int inWidth, int inVal) {
        mSize = inWidth;
        mRow = std::vector<int>(inWidth, inVal);
    }

    Row& Row::operator=(const Row& rhs) = default;

    int& Row::operator[](size_t i) {
        return mRow[i];
    }

    const int& Row::operator[](size_t i) const {
        return mRow[i];
    }

    std::ostream& operator<<(std::ostream& os, const Row& r) {
        for (int i = 0; i < r.size(); ++i) {
            os << r.mRow[i] << ' ';
        }
        return os;
    }

    Row Row::operator+(const Row& rhs) {
        int newWidth = (mSize < rhs.mSize ? mSize : rhs.mSize);
        Row newRow(mSize, 0);
        for (int i = 0; i < newWidth; ++i) {
            newRow[i] = mRow[i] + rhs.mRow[i];
        }
        return newRow;
    }

    Row Row::operator-(const Row& rhs) {
        int newWidth = (mSize < rhs.mSize ? mSize : rhs.mSize);
        Row newRow(mSize, 0);
        for (int i = 0; i < newWidth; ++i) {
            newRow[i] = mRow[i] - rhs.mRow[i];
        }
        return newRow;
    }

    Row Row::operator*(int k) {
        Row newRow(mSize, 0);
        for (int i = 0; i < mSize; i++) {
            newRow[i] = mRow[i] * k;
        }
        return newRow;
    }

}