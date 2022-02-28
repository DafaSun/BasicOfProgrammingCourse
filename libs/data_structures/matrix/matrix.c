//
// Created by Dasha on 02.02.2022.
//

#include "matrix.h"

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
        for (int j = 0; j < m.nCols; j++)
            scanf("%d", &m.values[i][j]);
}

void inputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        inputMatrix(ms[i]);
}

void outputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            printf("%d", m.values[i][j]);
}

void outputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        outputMatrix(ms[i]);
}

void swapRows(matrix m, int i1, int i2) {
    for (int j = 0; j < m.nCols; j++) {
        int t = m.values[i1][j];
        m.values[i1][j] = m.values[i2][j];
        m.values[i2][j] = t;
    }
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
    for (int i = 0; i < m.nRows; i++)
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

//void insertionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int *, int)) {
//    int resultOfCriteria[m.nCols];
//    for (int i = 0; i < m.nCols; i++) {
//        int a[m.nRows];
//        for (int j = 0; j < m.nRows; j++)
//            a[j] = m.values[j][i];
//        resultOfCriteria[i] = criteria(a, m.nRows);
//    }
//    for (int i = 1; i < m.nRows; i++) {
//        int t = resultOfCriteria[i];
//        int j = i;
//        while (j > 0 && resultOfCriteria[j - 1] > t) {
//            resultOfCriteria[j] = resultOfCriteria[j - 1];
//            swapColumns(m, j, j - 1);
//            j--;
//        }
//        resultOfCriteria[j] = t;
//    }
//}

void selectionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int *, int)) {
    int criteriaValues[m.nCols];
    int b[m.nRows];
    for (int i = 0; i < m.nCols; i++) {
        for (int j = 0; j < m.nRows; j++)
            b[j] = m.values[j][i];
        criteriaValues[i] = criteria(b, m.nRows);
    }

    for (int i = 0; i < m.nCols; i++) {
        int minIndex = i;
        for (int j = i + 1; j < m.nCols; j++) {
            if (criteriaValues[j] < criteriaValues[minIndex])
                minIndex = j;
        }
        if (minIndex != i) {
            swapColumns(m, minIndex, i);
            criteriaValues[minIndex] = criteriaValues[i];
        }
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
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            if (m.values[i][j] < m.values[rowIndexOfMinValue][colIndexOfMinValue]) {
                rowIndexOfMinValue = i;
                colIndexOfMinValue = j;
            }
    return (position) {rowIndexOfMinValue, colIndexOfMinValue};
}

position getMaxValuePos(matrix m) {
    int rowIndexOfMaxValue = 0;
    int colIndexOfMaxValue = 0;
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++){
            if (m.values[i][j] > m.values[rowIndexOfMaxValue][colIndexOfMaxValue]) {
                rowIndexOfMaxValue = i;
                colIndexOfMaxValue = j;
            }
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

int getMin(int *a, int n) {
    int min = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] < min)
            min = a[i];
    return min;
}

void sortColsByMinElement(matrix m) {
    selectionSortColsMatrixByColCriteria(m, getMin);
}

void makeZeroMatrix(matrix *m) {
    for (int i = 0; i < m->nRows; i++)
        for (int j = 0; j < m->nCols; j++)
            m->values[i][j] = 0;
}

matrix mulMatrices(matrix m1, matrix m2) {
    if (m1.nCols != m2.nRows) {
        fprintf(stderr, "cannot be multiplied ");
        exit(1);
    }
    matrix m = getMemMatrix(m1.nRows, m2.nCols);
    makeZeroMatrix(&m);
    int n = m1.nCols;
    for (int i = 0; i < m1.nRows; i++)
        for (int j = 0; j < m2.nCols; j++)
            for (int k = 0; k < n; k++)
                m.values[i][j] += m1.values[k][j] * m2.values[i][k];
    return m;
}

void getSquareOfMatrixIfSymmetric(matrix *m) {
    if (isSymmetricMatrix(*m) == true)
        *m = mulMatrices(*m, *m);
}

int comp(const void *a, const void *b) {
    int *p1 = (int *) a;
    int *p2 = (int *) b;
    if (p1 == p2)
        return 0;
    else if (p1 < p2)
        return 1;
    else
        return -1;
}

bool isUnique(long long *a, int n) {
    qsort(a, n, sizeof(int), comp);
    for (int i = 0; i < n - 1; i++)
        if (a[i] == a[i + 1])
            return false;
    return true;
}

long long getSum(int *a, int n) {
    long long sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    return sum;
}

void transposeIfMatrixHasNotEqualSumOfRows(matrix m) {
    long long sumElementInTheRow[m.nRows];
    for (int i = 0; i < m.nRows; i++)
        sumElementInTheRow[i] = getSum(m.values[i], m.nCols);
    if (isUnique(sumElementInTheRow, m.nRows) == true)
        transposeSquareMatrix(m);
}

bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    return isEMatrix(mulMatrices(m1, m2));
}

int min(int a, int b) {
    if (a < b)
        return a;
    else
        return b;
}

long long findSumOfMaxesOfPseudoDiagonal(matrix m) {
    int n = min(m.nRows, m.nCols);
    int elementsOfPseudoDiagonal[n];
    long long sum = 0;
    for (int i = 1; i < m.nCols; i++) {
        int j = 0;
        int k = i;
        int ii = 0;
        while ((j < m.nRows) && (k < m.nCols)) {
            elementsOfPseudoDiagonal[ii] = m.values[j][k];
            ii++;
            j++;
            k++;
        }
        sum += getMax(elementsOfPseudoDiagonal, ii);
    }
    for (int i = 1; i < m.nRows; i++) {
        int j = i;
        int k = 0;
        int ii = 0;
        while ((j < m.nRows) && (k < m.nCols)) {
            elementsOfPseudoDiagonal[ii] = m.values[j][k];
            ii++;
            j++;
            k++;
        }
        sum += getMax(elementsOfPseudoDiagonal, ii);

    }
    return sum;
}

int getMinInArea(matrix m) {
    position maxValuePos = getMaxValuePos(m);
    int min =m.values[maxValuePos.rowIndex] [maxValuePos.colIndex];
    int leftBorder = maxValuePos.colIndex-1;
    int rightBorder = maxValuePos.colIndex-1;
    for (int i = maxValuePos.rowIndex-1; i >= 0; i--) {
        int j = leftBorder;
        while (j <= rightBorder) {
            int p = m.values[i][j];
            if (p < min)
                min = p;
            j++;
        }
        if (leftBorder > 0)
            leftBorder--;
        if (rightBorder < m.nCols - 1)
            rightBorder++;
    }
    return min;
}

float getDistance(int *a, int n) {
    double d = 0;
    for (int i = 0; i < n; i++)
        d += pow(a[i], 2);
    return sqrt(d);
}

void insertionSortRowsMatrixByRowCriteriaF(matrix m, float (*criteria)(int *, int)) {
    float resultOfCriteria[m.nRows];
    for (int i = 0; i < m.nRows; i++)
        resultOfCriteria[i] = criteria(m.values[i], m.nCols);
    for (int i = 1; i < m.nRows; i++) {
        float t = resultOfCriteria[i];
        int j = i;
        while (j > 0 && resultOfCriteria[j - 1] > t) {
            resultOfCriteria[j] = resultOfCriteria[j - 1];
            swapRows(m, j, j - 1);
            j--;
        }
        resultOfCriteria[j] = t;
    }
}

void sortByDistances(matrix m) {
    insertionSortRowsMatrixByRowCriteriaF(m, getDistance);
}

int cmp(const void *a, const void *b) {
    int *p1 = (int *) a;
    int *p2 = (int *) b;
    if (p1 == p2)
        return 0;
    else if (p1 < p2)
        return 1;
    else
        return -1;
}

int countNUnique(long long *a, int n) {
    qsort(a, n, sizeof(int), cmp);
    long long e = a[0];
    int count = 1;
    for (int i = 1; i < n; i++)
        if (a[i] != e) {
            count++;
            e = a[i];
        }
    return count;
}

int countEqClassesByRowsSum(matrix m) {
    long long sumOfElementOfRow[m.nRows];
    for (int i = 0; i < m.nRows; i++)
        sumOfElementOfRow[i] = getSum(m.values[i], m.nCols);
    int c=countNUnique(sumOfElementOfRow, m.nRows);
    return c;
}

int getNSpecialElement(matrix m) {
    int elementsOfCol[m.nRows];
    int count = 0;
    for (int i = 0; i < m.nCols; i++) {
        for (int j = 0; j < m.nRows; j++)
            elementsOfCol[j] = m.values[j][i];
        int max = getMax(elementsOfCol, m.nRows);
        if (getSum(elementsOfCol, m.nRows) - max < max)
            count++;
    }
    return count;
}

position getLeftMin(matrix m) {
    position minPos = getMinValuePos(m);
    if (minPos.colIndex > 0) {
        int min = m.values[m.nRows, m.nCols];
        for (int j = 0; j < m.nCols; j++)
            for (int i = 0; i < m.nRows; i++)
                if (m.values[i][j] == min)
                    return (position) {i, j};
    }
    return minPos;
}

void swapPenultimateRow(matrix m) {
    int colWithLeftMin[m.nRows];
    position leftMinPos = getLeftMin(m);
    for (int i = 0; i < m.nRows; i++)
        colWithLeftMin[i] = m.values[i][leftMinPos.colIndex];
    for (int i = 0; i < m.nCols; i++)
        m.values[m.nRows - 2][i] = colWithLeftMin[i];
}

bool isNonDescendingSorted(int *a, int n) {
    for (int i = 1; i < n; i++)
        if (a[i] < a[i - 1])
            return false;
    return true;
}

bool hasAllNonDescendingRows(matrix m) {
    for (int i = 0; i < m.nRows; i++)
        if (isNonDescendingSorted(m.values[i], m.nCols) == false)
            return false;
    return true;
}

int countNonDescendingRowsMatrices(matrix *ms, int nMatrix) {
    int count = 0;
    for (int i = 0; i < nMatrix; i++)
        if (hasAllNonDescendingRows(ms[i]) == true)
            count++;
    return count;
}

int countValues(const int *a, int n, int value) {
    int count = 0;
    for (int i = 0; i < n; i++)
        if (a[i] == value)
            count++;
    return count;
}

int countZeroRows(matrix m) {
    int count = 0;
    for (int i = 0; i < m.nRows; i++)
        if (countValues(m.values[i], m.nCols, 0) == m.nCols)
            count++;
    return count;
}

void printMatrixWithMaxZeroRows(matrix *ms, int nMatrix) {
    int maxZeroRows = 0;
    for (int i = 0; i < nMatrix; i++) {
        int countZeroRowsInMatrix = countZeroRows(ms[i]);
        if (countZeroRowsInMatrix > maxZeroRows)
            maxZeroRows = countZeroRowsInMatrix;
    }
    for (int i = 0; i < nMatrix; i++)
        if (countZeroRows(ms[i]) == maxZeroRows)
            outputMatrix(ms[i]);
}


int maxAbsInArray(int *a, int n) {
    float maxAbs = abs(a[0]);
    for (int i = 1; i < n; i++) {
        float absOfElement = abs(a[i]);
        if (absOfElement > maxAbs)
            maxAbs = absOfElement;
    }
    return maxAbs;
}

int maxAbsInMatrix(matrix m) {
    float maxAbs = maxAbsInArray(m.values[0], m.nCols);
    for (int i = 1; i < m.nRows; i++) {
        float maxAbsInRow = maxAbsInArray(m.values[i], m.nCols);
        if (maxAbsInRow > maxAbs)
            maxAbs = maxAbsInRow;
    }
}

void printMatrixFWithMinMaxAbs(matrix *ms, int nMatrix) {
    float minMaxAbs = maxAbsInMatrix(ms[0]);
    for (int i = 1; i < nMatrix; i++) {
        float maxAbs = maxAbsInMatrix(ms[i]);
        if (maxAbs < minMaxAbs)
            minMaxAbs = maxAbs;
    }
    for (int i = 0; i < nMatrix; i++)
        if (maxAbsInMatrix(ms[i]) == minMaxAbs)
            outputMatrix(ms[i]);
}