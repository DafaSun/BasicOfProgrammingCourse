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
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    free(v->data + v->size);
}

void deleteVector(vector *v){
    free(v->data);
}