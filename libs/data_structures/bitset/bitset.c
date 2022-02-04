//
// Created by Dasha on 13.12.2021.
//

#include "bitset.h"
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

bitset bitset_create(uint32_t maxValue) {
    assert(maxValue < 32);
    return (bitset) {0, maxValue};
}

bool bitset_checkValue(bitset set, uint32_t x) {
    return x >= 0 && x <= set.maxValue;
}

bool bitset_in(bitset set, uint32_t x) {
    assert(bitset_checkValue(set, x));
    return set.values >> x & 1;
}

void bitset_insert(bitset *set, uint32_t x) {
    assert(bitset_checkValue(*set, x));
    set->values |= 1 << x;
}

bitset bitset_intersection(bitset set1, bitset set2) {
    return (bitset) {set1.values & set2.values, set1.maxValue};
}

bitset bitset_union(bitset set1, bitset set2) {
    assert(set1.maxValue == set2.maxValue);
    return (bitset) {set1.values | set2.values, set1.maxValue};
}

bitset bitset_difference(bitset set1, bitset set2) {
    return (bitset) {set1.values & ~set2.values, set1.maxValue};
}

bitset bitset_symmetricDifference(bitset set1, bitset set2) {
    assert(set1.maxValue == set2.maxValue);
    return (bitset) {set1.values ^ set2.values, set1.maxValue};
}

void bitset_clean(bitset *set) {
    static const int MAX_SIZE = sizeof(uint32_t) * 8;
    uint32_t shift = MAX_SIZE - set->maxValue;
    set->values <<= shift;
    set->values >>= shift;
}

bool bitset_isEqual(bitset set1, bitset set2) {
    assert(set1.maxValue == set2.maxValue);
    bitset_clean(&set1);
    bitset_clean(&set2);
    return set1.values == set2.values;
}

bool bitset_isSubset(bitset subset, bitset set) {
    bitset_clean(&subset);
    bitset_clean(&set);
    return (subset.values & set.values) == subset.values;
}

void bitset_deleteElement(bitset *set, uint32_t x) {
    set->values &= ~(1 << x);
}

bitset bitset_complement(bitset set) {
    return (bitset) {~set.values, set.maxValue};
}

bitset bitset_createFromArray(int *a, size_t n, uint32_t maxValue) {
    bitset set = bitset_create(maxValue);
    for (int i = 0; i < n; i++) {
        bitset_insert(&set, a[i]);
    }
    return set;
}

void bitset_print(bitset set) {
    printf("{");
    bool isEmpty = true;
    for (int i = 0; i <= set.maxValue; i++) {
        if (bitset_in(set, i)) {
            printf("%d, ", i);
            isEmpty = false;
        }
    }
    if (isEmpty)
        printf("}\n");
    else
        printf("\b\b}\n");
}
