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

void test_swapRowsWithMaxAndMinElement() {
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

void test_sortColsByMinElement() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    9, 11, 11,
                    11, 11, 11,
                    11, 2, 11,
                    11, 11, 4,
                    11, 11, 11,
            },
            5, 3
    );
    matrix m2 = createMatrixFromArray(
            (int[]) {
                    11, 11, 9,
                    11, 11, 11,
                    2, 11, 11,
                    11, 4, 11,
                    11, 11, 11,
            },
            5, 3
    );

    sortColsByMinElement(m1);

    assert(areTwoMatricesEqual(m1, m2) == 1);

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_getSquareOfMatrixIfSymmetric_1() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    9, 11, 7,
                    11, 2, 11,
                    11, 3, 4,
            },
            3, 3
    );
    matrix m2 = createMatrixFromArray(
            (int[]) {
                    9, 11, 7,
                    11, 2, 11,
                    11, 3, 4,
            },
            3, 3
    );

    sortColsByMinElement(m1);

    assert(areTwoMatricesEqual(m1, m2) == 1);

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_getSquareOfMatrixIfSymmetric_2() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    9, 11, 1,
                    11, 2, 11,
                    1, 11, 4,
            },
            3, 3
    );
    matrix m2 = createMatrixFromArray(
            (int[]) {
                    203, 132, 134,
                    132, 246, 77,
                    134, 77, 138,
            },
            3, 3
    );

    sortColsByMinElement(m1);

    assert(areTwoMatricesEqual(m1, m2) == 1);

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_getSquareOfMatrixIfSymmetric() {
    test_getSquareOfMatrixIfSymmetric_1();
    test_getSquareOfMatrixIfSymmetric_2();
}


void testOfTheTasks() {
    test_swapRowsWithMaxAndMinElement();
    test_sortRowsByMaxElement();
//    test_sortColsByMinElement();
//    test_getSquareOfMatrixIfSymmetric();

}

void test_getMemMatrix() {
    matrix m = getMemMatrix(5, 5);

    assert (sizeof(m) != 0);

    freeMemMatrix(m);
}

void test_getMemArrayOfMatrices() {
    matrix *ms = getMemArrayOfMatrices(2, 5, 5);

    assert (sizeof(*ms) != 0);

    freeMemMatrices(ms, 2);
}


void testOfTheFunction() {
    test_getMemMatrix();
    test_getMemArrayOfMatrices();
}

int main() {
    testOfTheFunction();

    return 0;
}




