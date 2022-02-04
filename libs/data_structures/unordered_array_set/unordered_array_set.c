//
// Created by Dasha on 13.12.2021.
//

#include "unordered_array_set.h"
# include <assert.h>
#include <malloc.h>
# include <stdio.h>
#include <stdlib.h>
# include <stdbool.h>
# include "../../algorithms/array/array.h"

unordered_array_set unordered_array_set_create(size_t capacity) {
    return (unordered_array_set) {malloc(sizeof(int) * capacity), 0, capacity};
}

// добавляет элемент value в множество set
void unordered_array_set_insert(unordered_array_set *set, int value) {
    assert(set->size < set->capacity);
    if (linearSearch_(set->data, set->size, value) < 0)
        append_(&set->data[set->size], &set->size, value);
}

static void unordered_array_set_shrinkToFit(unordered_array_set *a) {
    if (a->size != a->capacity) {
        a->data = (int *) realloc(a->data, sizeof(int) * a->size);
        a->capacity = a->size;
    }
}

// возвращает множество, состоящее из элементов массива a размера size
unordered_array_set unordered_array_set_create_from_array(const int *a, size_t size, size_t capacity) {
    unordered_array_set set = unordered_array_set_create(capacity);
    for (int i = 0; i < size; i++)
        unordered_array_set_insert(&set, a[i]);
    return set;
}

// возвращает позицию элемента в множестве, если значение value имеется в множестве set, иначе - n
int unordered_array_set_in(unordered_array_set *set, int value) {
    return linearSearch_(set->data, set->size, value);
}

//возвращает 1 если subset является подмножеством set, и 0 - в ином случае.
int unordered_array_set_isSubset(unordered_array_set subset, unordered_array_set set) {
    if (subset.size == 0)
        return 1;
    if (set.size < subset.size)
        return 0;
    for (int i = 0; i < subset.size; i++)
        if (linearSearch_(set.data, set.size, subset.data[i]) == set.size)
            return 0;
    return 1;
}

int comp(const void *a, const void *b) {
    int *p1 = (int *) a;
    int *p2 = (int *) b;
    if (p1 == p2)
        return 0;
    else if (p1 < p2)
        return -1;
    else
        return 1;
}

// возвращает значение ’истина’, если элементы множеств set1 и set2 равны иначе - ’ложь’
bool unordered_array_set_isEqual(unordered_array_set set1, unordered_array_set set2) {
    assert(set1.size == set2.size);
    qsort(&set1.data, set1.size, sizeof(int), comp);
    qsort(&set2.data, set2.size, sizeof(int), comp);
    for (int i = 0; i < set1.size; i++)
        if (set1.data[i] != set2.data[i])
            return 0;
    return 1;
}

// возбуждает исключение, если в множество по адресу set нельзя вставить элемент
void unordered_array_set_isAbleAppend(unordered_array_set *set) {
    assert(set->size < set->capacity);
}

// удаляет элемент value из множества set
void unordered_array_set_deleteElement(unordered_array_set *set, int value) {
    size_t pos = linearSearch_(set->data, set->size, value);
    if (pos >= set->size) {
        set->data[pos] = set->data[set->size - 1];
        set->size--;
    }
}

// возвращает объединение множеств set1 и set2
unordered_array_set unordered_array_set_union(unordered_array_set set1, unordered_array_set set2) {
    assert(set1.capacity == set2.capacity);
    unordered_array_set set = unordered_array_set_create_from_array(set1.data, set1.capacity, set1.capacity);
    for (int i = 0; i < set2.size; i++)
        if (linearSearch_(set.data, set.size, set2.data[i]) != set.size) {
            set.data[set.size] = set2.data[i];
            set.size++;
        }
    return set;
}

// возвращает пересечение множеств set1 и set2
unordered_array_set unordered_array_set_intersection(unordered_array_set set1, unordered_array_set set2) {
    assert(set1.capacity == set2.capacity);
    unordered_array_set set = unordered_array_set_create(set1.capacity);
    for (int i = 0; i < set1.size; i++)
        if (linearSearch_(set2.data, set2.size, set1.data[i]) != set2.size)
            unordered_array_set_insert(&set, set1.data[i]);
    return set;
}

// возвращает разность множеств set1 и set2
unordered_array_set unordered_array_set_difference(unordered_array_set set1, unordered_array_set set2) {
    assert(set1.capacity == set2.capacity);
    unordered_array_set set = unordered_array_set_create(set1.capacity);
    for (int i = 0; i < set1.size; i++)
        if (linearSearch_(set2.data, set2.size, set1.data[i]) == set2.size)
            unordered_array_set_insert(&set, set1.data[i]);
    return set;
}

// возвращает симметрическую разность множеств set1 и set2
unordered_array_set unordered_array_set_symmetricDifference(unordered_array_set set1, unordered_array_set set2) {
    assert(set1.capacity == set2.capacity);
    unordered_array_set set = unordered_array_set_create(set1.capacity);
    set = unordered_array_set_intersection(unordered_array_set_difference(set1, set2),
                                           unordered_array_set_difference(set2, set1));
    return set;
}

// возвращает дополнение до универсума множества set
unordered_array_set unordered_array_set_complement(unordered_array_set set, unordered_array_set universumSet) {
    return unordered_array_set_difference(universumSet, set);
}

// вывод множества set
void unordered_array_set_print(unordered_array_set set) {
    printf("{");
    for (size_t i = 0; i < set.size; i++)
        printf("%d, ", set.data[i]);
    if (set.size == 0)
        printf("}");
    else
        printf("\b\b}");
}

// освобождает память, занимаемую множеством set
void unordered_array_set_delete(unordered_array_set set) {
    free(set.data);
}
