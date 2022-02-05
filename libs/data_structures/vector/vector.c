//
// Created by Dasha on 05.02.2022.
//

#include "vector.h"
#include <stdlib.h>
#include <malloc.h>

vector createVector(size_t n) {
    int *a = calloc(n, sizeof(int));
    if (a == NULL) {
        fprintf(stderr, "bad alloc ");
        exit(1);
    }
    vector v = {a, 0, n};
    return v;
}

void reserve(vector *v, size_t newCapacity) {
    if (newCapacity == 0)
        v->data = NULL;
    else {
        if (newCapacity < v->size)
            v->size = newCapacity;
        int *a = realloc(v->data, newCapacity);
        if (a == NULL) {
            fprintf(stderr, "bad alloc ");
            exit(1);
        }
        realloc(v->data, newCapacity);
    }
    v->capacity=newCapacity;
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    free(v->data + v->size);
}

void deleteVector(vector *v) {
    free(v->data);
}

bool isEmpty(vector *v) {
    return v->size == 0;
}

bool isFull(vector *v) {
    return v->size == v->capacity;
}

int getVectorValue(vector *v, size_t i) {
    return *(v->data + i * sizeof(int));
}

void pushBack(vector *v, int x) {
    if (v->size == v->capacity){
        if (v->capacity == 0)
            reserve(v, 1);
        else
            reserve(v, v->capacity * 2);
    }
    *(v->data + v->size * sizeof(int)) = x;
    v->size++;
}

void popBack(vector *v) {
    if (v->size == 0) {
        fprintf(stderr, "bad alloc ");
        exit(1);
    }
    v->size--;
}

