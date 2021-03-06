//
// Created by Dasha on 05.02.2022.
//

#ifndef COURSE_VECTOR_H
#define COURSE_VECTOR_H

#include <stdio.h>
#include <stdbool.h>

typedef struct vector {
    int *data; // указатель на элементы вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
} vector;

//возвращает структуру-дескриптор вектор из n значений.
vector createVector(size_t n);

//изменяет количество памяти, выделенное под хранение элементов вектора v, на newCapacity.
void reserve(vector *v, size_t newCapacity);

//удаляет элементы из вектора v, но не освобождает выделенную память.
void clear(vector *v);

//освобождает память, выделенную под неиспользуемые элементы вектора v.
void shrinkToFit(vector *v);

//освобождает память, выделенную вектору v.
void deleteVector(vector *v);

//проверяет на то, является ли вектор v пустым.
bool isEmpty(vector *v);

//проверяет на то, является ли вектор v полным.
bool isFull(vector *v);

//возвращает i-ый элемент вектора v.
int getVectorValue(vector *v, size_t i);

//добавляет элемент x в конец вектора v.
void pushBack(vector *v, int x);

//удаляет последний элемент из вектора v.
void popBack(vector *v);

//возвращает указатель на index-ый элемент вектора v.
int *atVector(vector *v, size_t index);

//возвращает указатель на последний элемент вектора v.
int *back(vector *v);

//возвращает указатель на первый элемент вектора v.
int *front(vector *v);

#endif //COURSE_VECTOR_H
