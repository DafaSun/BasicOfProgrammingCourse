#include <stdio.h>
# include <assert.h>
#include "libs/data_structures/matrix/matrix.h"

void test_swapRowsWithMaxAndMinElement_1() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    9, 3, 3,
                    2, 2, 2,
                    4, 3, 1,
                    2, 3, 4,
                    3, 2, 2,
            },
            5, 3
    );
    matrix m2 = createMatrixFromArray(
            (int[]) {
                    4, 3, 1,
                    2, 2, 2,
                    9, 3, 3,
                    2, 3, 4,
                    3, 2, 2,
            },
            5, 3
    );

    swapRowsWithMaxAndMinElement(m1);

    assert(areTwoMatricesEqual(m1, m2) == 1);

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_swapRowsWithMaxAndMinElement_2() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    9, 3, 0,
                    2, 2, 2,
                    2, 3, 1,
                    3, 2, 2,
                    4, 3, 1,
            },
            5, 3
    );
    matrix m2 = createMatrixFromArray(
            (int[]) {
                    9, 3, 0,
                    2, 2, 2,
                    2, 3, 1,
                    3, 2, 2,
                    4, 3, 1,
            },
            5, 3
    );

    swapRowsWithMaxAndMinElement(m1);

    assert(areTwoMatricesEqual(m1, m2) == 1);

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_swapRowsWithMaxAndMinElement(){
   test_swapRowsWithMaxAndMinElement_1();
    test_swapRowsWithMaxAndMinElement_2();
}

void test_sortRowsByMaxElement() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    9, 0, 0,
                    2, 0, 0,
                    0, 3, 0,
                    5, 0, 0,
                    4, 0, 0,
            },
            5, 3
    );
    matrix m2 = createMatrixFromArray(
            (int[]) {
                    2, 0, 0,
                    0, 3, 0,
                    4, 0, 0,
                    5, 0, 0,
                    9, 0, 0,
            },
            5, 3
    );

    sortRowsByMaxElement(m1);

    assert(areTwoMatricesEqual(m1, m2) == 1);

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test() {
    test_swapRowsWithMaxAndMinElement();
    test_sortRowsByMaxElement();
}


int main() {
    test();

    return 0;
}




