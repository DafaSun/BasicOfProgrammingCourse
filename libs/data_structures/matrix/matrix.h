//
// Created by Dasha on 02.02.2022.
//

#ifndef COURSE_MATRIX_H
#define COURSE_MATRIX_H
#include <stdio.h>

typedef struct matrix {
    int ** values ; // элементы матрицы
    int nRows ; // количество рядов
    int nCols ; // количество столбцов
    } matrix ;

typedef struct position {
    int rowIndex ;
    int colIndex ;
    } position ;

//возвращает матрицу размером nRows на nCols, размещенную в динамической памяти.
matrix getMemMatrix(int nRows, int nCols);

//
matrix *getMemArrayOfMatrices(int nMatrices,
                              int nRows, int nCols);


#endif //COURSE_MATRIX_H
