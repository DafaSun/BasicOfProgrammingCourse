//
// Created by Dasha on 02.02.2022.
//

#ifndef COURSE_MATRIX_H
#define COURSE_MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <math.h>

typedef struct matrix {
    int **values; // элементы матрицы
    int nRows; // количество рядов
    int nCols; // количество столбцов
} matrix;

typedef struct position {
    int rowIndex; // номер ряда
    int colIndex; // номер столбца
} position;

//возвращает матрицу размером nRows на nCols, размещенную в динамической памяти.
matrix getMemMatrix(int nRows, int nCols);

//возвращает указатель на нулевую матрицу массива из nMatrices матриц размером nRows на nCols, размещенного в динамической памяти.
matrix *getMemArrayOfMatrices(int nMatrices,
                              int nRows, int nCols);

//освобождает память, выделенную под хранение матрицы m.
void freeMemMatrix(matrix m);

//освобождает память, выделенную под хранение массива ms из nMatrices матриц.
void freeMemMatrices(matrix *ms, int nMatrices);

//ввод матрицы m.
void inputMatrix(matrix m);

//ввод массива из nMatrices матриц, хранящегося по адресу ms.
void inputMatrices(matrix *ms, int nMatrices);

//вывод матрицы m.
void outputMatrix(matrix m);

//вывод массива из nMatrices матриц, хранящегося по адресу ms.
void outputMatrices(matrix *ms, int nMatrices);

//обмен строк с порядковыми номерами i1 и i2 в матрице m.
void swapRows(matrix m, int i1, int i2);

//обмен колонок с порядковыми номерами j1 и j2 в матрице m.
void swapColumns(matrix m, int j1, int j2);

//выполняет сортировку вставками строк матрицы m по неубыванию значения функции criteria применяемой для строк
void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(int *, int));

//выполняет сортировку вставками столбцов матрицы m по неубыванию значения функции criteria применяемой для столбцов.
void insertionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int *, int));

//возвращает значение ’истина’, если матрица m является квадратной, ложь – в противном случае.
bool isSquareMatrix(matrix m);

//возвращает значение ’истина’, если матрицы m1 и m2 равны, ложь – в противном случае.
bool areTwoMatricesEqual(matrix m1, matrix m2);

//возвращает значение ’истина’, если матрица m является единичной, ложь – в противном случае.
bool isEMatrix(matrix m);

//возвращает значение ’истина’, если матрица m является симметричной, ложь – в противном случае.
bool isSymmetricMatrix(matrix m);

//транспонирует квадратную матрицу m.
void transposeSquareMatrix(matrix m);

//возвращает позицию минимального элемента матрицы m.
position getMinValuePos(matrix m);

//возвращает позицию максимального элемента матрицы m.
position getMaxValuePos(matrix m);

//возвращает матрицу, размера nRows на nCols, построенного из элементов массива a, размещенную в динамической памяти.
matrix createMatrixFromArray(const int *a, int nRows, int nCols);

//возвращает указатель на нулевую матрицу массива из nMatrices матриц, размещенных в динамической памяти, построенных из элементов массива a.
matrix *createArrayOfMatrixFromArray(const int *values, size_t nMatrices, size_t nRows, size_t nCols);

//обменивает местами строки матрицы m, в которых находятся максимальный и минимальный элементы.
void swapRowsWithMaxAndMinElement(matrix m);

//возвращает наибольший по значению элемент в массиве a размера n.
int getMax(int *a, int n);

//упорядочивает строки матрицы m по неубыванию наибольших элементов строк.
void sortRowsByMaxElement(matrix m);

//возвращает наименьший по значению элемент в массиве a размера n.
int getMin(int *a, int n);

//упорядочивает столбцы матрицы m по неубыванию минимальных элементов столбцов.
void sortColsByMinElement(matrix m);

//возвращает матрицу, равную произведению матрицы m1 на матрицу m2.
matrix mulMatrices(matrix m1, matrix m2);

//обращает все элементы матрицы m в ноль.
void makeZeroMatrix(matrix m);

//если данная квадратная матрица m симметрична, то заменить m ее квадратом.
void getSquareOfMatrixIfSymmetric(matrix *m);

//возвращает значение ’истина’, если в массиве а размера n нет одинаковых элементов, ложь – в противном случае.
bool isUnique(long long *a, int n);

//возращает сумму всех элементов массива а размера n.
long long getSum(int *a, int n);

//если среди сумм элементов строк матрицы m нет равных, то транспонировать матрицу m.
void transposeIfMatrixHasNotEqualSumOfRows(matrix m);

//возвращает значение ’истина’, если матрицы m1 и m2 является взаимно обратными, ложь – в противном случае.
bool isMutuallyInverseMatrices(matrix m1, matrix m2);

//возвращает минимальное значение из a и b.
int min(int a, int b);

//возращает сумму максимальных элементов всех псевдодиагоналей матрицы m.
long long findSumOfMaxesOfPseudoDiagonal(matrix m);

//возращает минимальный элемент матрицы m в выделенной области (над максимальным элементом).
int getMinInArea(matrix m);

//возвращает расстояние от точки до начала координат, массив а размера n содержит координаты точки в n-мерном пространстве.
float getDistance(int *a, int n);

//выполняет сортировку вставками строк матрицы m по неубыванию значения функции criteria применяемой для строк.
void insertionSortRowsMatrixByRowCriteriaF(matrix m, float (*criteria)(int *, int));

//упорядочивает точки по неубыванию их расстояний до начала координат, матрица m содержит содержит координаты m.nRows точек в m.nCols-мерном пространстве.
void sortByDistances(matrix m);

//возвращает количество уникальных элементов в массиве а размера n.
int countNUnique(long long *a, int n);

//возвращает количество строк прямоугольной матрицы m с равными суммами их элементов.
int countEqClassesByRowsSum(matrix m);

//возвращает количество элементов матрицы m, больших суммы остальных элементов своего столбца.
int getNSpecialElement(matrix m);

//возвращает позицию крайнего левого минималного элемента матрицы m.
position getLeftMin(matrix m);

//заменяет предпоследнюю строку матрицы m первым из столбцов, в котором находится минимальный элемент матрицы m.
void swapPenultimateRow(matrix m, int n);

//возвращает значение ’истина’, если массив а размера n отсортирован по неубыванию, ложь – в противном случае.
bool isNonDescendingSorted(int *a, int n);

//возвращает значение ’истина’, если все строки матрицы m отсортированы по неубыванию, ложь – в противном случае.
bool hasAllNonDescendingRows(matrix m);

//возвращает количество матриц в массиве ms размера nMatrix, строки которых упорядочены по неубыванию элементов
int countNonDescendingRowsMatrices(matrix *ms, int nMatrix);

#endif //COURSE_MATRIX_H
