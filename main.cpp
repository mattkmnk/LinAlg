#include <iostream>
#include "LinAlg/Matrix.h"
#include <chrono>
#include <iomanip>

int main() {

    LinAlg::Matrix m1 = {{1, 2, 3, 4, 1, 5},
                         {5, 6, 6, 8, 2, 5},
                         {9, 5, 11, 12, 1, 5},
                         {13, 14, 15, 16, 1, 5},
                         {1, 2, 1, 1, 3, 5},
                         {1, 1, 1, 1, 1, 5}};

    LinAlg::Matrix m2 = {{1, 2},
                         {3, 4},
                         {5, 6}};

    std::cout << m1.det();
    m2.transpose();
    m2.print();

    return 0;
}
