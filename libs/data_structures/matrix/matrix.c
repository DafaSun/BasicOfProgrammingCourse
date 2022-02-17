//
// Created by Dasha on 02.02.2022.
//

#include "matrix.h"
#include <malloc.h>

matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);
    for (int i = 0; i < nRows; i++)
        values[i] = (int *) malloc(sizeof(int) * nCols);
    return (matrix) {values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(int nMatrices,
                              int nRows, int nCols) {
    matrix *ms = (matrix *) malloc(sizeof(matrix) * nMatrices);
    for (int i = 0; i < nMatrices; i++)
        ms[i] = getMemMatrix(nRows, nCols);
    return ms;
}

void freeMemMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++)
        free(m.values[i]);
    free(m.values);
}

void freeMemMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        freeMemMatrix(ms[i]);
}

void inputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; i++)
            scanf("%d", &m.values[i][j]);
}

void inputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        inputMatrix(ms[i]);
}

void outputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; i++)
            printf("%d", m.values[i][j]);
}

void outputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        outputMatrix(ms[i]);
}

void swapRows(matrix m, int i1, int i2) {
    int t = *m.values[i1];
    *m.values[i1] = *m.values[i2];
    *m.values[i2] = t;
}

void swapColumns(matrix m, int j1, int j2) {
    for (int i = 0; i < m.nRows; i++) {
        int t = m.values[i][j1];
        m.values[i][j1] = m.values[i][j2];
        m.values[i][j2] = t;
    }
}

void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(int *, int)) {
    int resultOfCriteria[m.nRows];
    for (int i = 0; i < m.nRows; ++i)
        resultOfCriteria[i] = criteria(m.values[i], m.nCols);
    for (int i = 1; i < m.nRows; i++) {
        int t = resultOfCriteria[i];
        int j = i;
        while (j > 0 && resultOfCriteria[j - 1] > t) {
            resultOfCriteria[j] = resultOfCriteria[j - 1];
            swapRows(m, j, j - 1);
            j--;
        }
        resultOfCriteria[j] = t;
    }
}

void insertionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int *, int)) {
    int resultOfCriteria[m.nCols];
    for (int i = 0; i < m.nCols; ++i) {
        int a[m.nRows];
        for (int j = 0; j < m.nRows; ++j)
            a[j] = m.values[j][i];
        resultOfCriteria[i] = criteria(&a[i], m.nRows);
    }
    for (int i = 1; i < m.nRows; i++) {
        int t = resultOfCriteria[i];
        int j = i;
        while (j > 0 && resultOfCriteria[j - 1] > t) {
            resultOfCriteria[j] = resultOfCriteria[j - 1];
            swapRows(m, j, j - 1);
            j--;
        }
        resultOfCriteria[j] = t;
    }
}

bool isSquareMatrix(matrix m) {
    return m.nRows == m.nCols;
}

bool areTwoMatricesEqual(matrix m1, matrix m2) {
    if ((m1.nRows != m2.nRows) || (m1.nCols != m2.nCols))
        return false;
    for (int i = 0; i < m1.nRows; i++)
        for (int j = 0; j < m1.nCols; j++)
            if (m1.values[i][j] != m2.values[i][j])
                return false;
    return true;
}

bool isEMatrix(matrix m) {
    if (isSquareMatrix(m) == false)
        return false;
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++) {
            if (i == j) {
                if (m.values[i][j] != 1)
                    return false;
            } else if (m.values[i][j] != 0)
                return false;
        }
    return true;
}

bool isSymmetricMatrix(matrix m) {
    if (isSquareMatrix(m) == false)
        return false;
    for (int i = 0; i < m.nRows; i++)
        for (int j = i + 1; j < m.nCols; j++)
            if (m.values[i][j] != m.values[j][i])
                return false;
    return true;
}

void swapElements(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void transposeSquareMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++)
        for (int j = i + 1; j < m.nCols; j++)
            if (i != j)
                swapElements(&m.values[i][j], &m.values[j][i]);
}

position getMinValuePos(matrix m) {
    int rowIndexOfMinValue = 0;
    int colIndexOfMinValue = 0;
    for (int i = 0; i < m.nRows; ++i)
        for (int j = 0; j < m.nCols; ++j)
            if (m.values[i][j] < m.values[rowIndexOfMinValue][colIndexOfMinValue]) {
                rowIndexOfMinValue = i;
                colIndexOfMinValue = j;
            }
    return (position) {rowIndexOfMinValue, colIndexOfMinValue};
}

position getMaxValuePos(matrix m) {
    int rowIndexOfMaxValue = 0;
    int colIndexOfMaxValue = 0;
    for (int i = 0; i < m.nRows; ++i)
        for (int j = 0; j < m.nCols; ++j)
            if (m.values[i][j] > m.values[rowIndexOfMaxValue][colIndexOfMaxValue]) {
                rowIndexOfMaxValue = i;
                colIndexOfMaxValue = j;
            }
    return (position) {rowIndexOfMaxValue, colIndexOfMaxValue};
}

matrix createMatrixFromArray(const int *a, int nRows, int nCols) {
    matrix m = getMemMatrix(nRows, nCols);
    int k = 0;
    for (int i = 0; i < nRows; i++)
        for (int j = 0; j < nCols; j++)
            m.values[i][j] = a[k++];
    return m;
}

matrix *createArrayOfMatrixFromArray(const int *values, size_t nMatrices, size_t nRows, size_t nCols) {
    matrix *ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);
    int l = 0;
    for (int k = 0; k < nMatrices; k++)
        for (int i = 0; i < nRows; i++)
            for (int j = 0; j < nCols; j++)
                ms[k].values[i][j] = values[l++];
    return ms;
}

void swapRowsWithMaxAndMinElement(matrix m) {
    position posMaxValue = getMaxValuePos(m);
    position posMinValue = getMinValuePos(m);
    swapRows(m, posMaxValue.rowIndex, posMinValue.rowIndex);
}

int getMax(int *a, int n) {
    int max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}

void sortRowsByMaxElement(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, getMax);
}