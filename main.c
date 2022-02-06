# include <stdio.h>
#include <assert.h>
# include <stdint.h>
# include "libs/data_structures/vector/vector.h"

void test_pushBack_emptyVector() {
    vector v = createVector(0);
    assert(isEmpty(&v) == 1);
    pushBack(&v, 3);
    assert(v.size == 1);
    assert(v.capacity == 1);
}

void test_pushBack_fullVector() {
    vector v = createVector(1);
    pushBack(&v, 1);
    assert(isFull(&v) == 1);
    pushBack(&v, 5);
    assert(isFull(&v) == 1);
    assert(isEmpty(&v) == 0);
    assert(v.size == 2);
    assert(v.capacity == 2);
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);
    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
}

void test_atVector_notEmptyVector() {
    vector v = createVector(3);
    pushBack(&v, 1);
    pushBack(&v, 4);
    assert(atVector(&v, 2)==v.data+2*sizeof(int));
}

void test_atVector_requestToLastElement() {
    vector v = createVector(3);
    pushBack(&v, 1);
    pushBack(&v, 4);
    pushBack(&v, 9);
    assert(atVector(&v, 3)==v.data+3*sizeof(int));
}

void test_back_oneElementInVector() {
    vector v = createVector(1);
    pushBack(&v, 1);
    assert(back(&v)==v.data+1*sizeof(int));
}

void test_front_oneElementInVector() {
    vector v = createVector(1);
    pushBack(&v, 1);
    assert(front(&v)==v.data+1*sizeof(int));
}

void test() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
    test_back_oneElementInVector();
    test_front_oneElementInVector();
}

int main() {
    test();

    return 0;
}

