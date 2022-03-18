//
// Created by Dasha on 10.03.2022.
//

#ifndef MAIN_C_TIME_H
#define MAIN_C_TIME_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "../array/array.h"

//функция сортировки 1
typedef struct SortFunc {
    void (*sort )(int *a, size_t n); // указатель на функцию сортировки
    char name[64]; // имя сортировки, используемое при выводе
} SortFunc;

//функция сортировки
typedef struct SortFuncComp {
    long long (*sort )(int *a, size_t n); // указатель на функцию сортировки
    char name[64]; // имя сортировки, используемое при выводе
} SortFuncComp;

//функция генерации
typedef struct GeneratingFunc {
    void (*generate )(int *a, size_t n); // указатель на функцию генерации последоват.
    char name[64]; // имя генератора, используемое при выводе
} GeneratingFunc;

void
checkTime(void (*sortFunc )(int *, size_t), void (*generateFunc )(int *, size_t), size_t size, char *experimentName);

void timeExperiment();

void
checkTimeBig(void (*sortFunc )(int *, size_t), void (*generateFunc )(int *, size_t), size_t size, char *experimentName);

void timeExperimentBig();

void checkComps(long long (*sortFunc )(int *, size_t), void (*generateFunc )(int *, size_t), size_t size,
                char *experimentName);

void compsExperiment();

#endif //MAIN_C_TIME_H
