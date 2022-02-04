//
// Created by Dasha on 13.12.2021.
//

#include "ordered_array_set.h"
# include <stdint.h >
# include <assert.h >
# include <stdio.h >
#include <stdlib.h>
# include <stdbool.h >
# include "../../algorithms/array/array.h"

// возвращает пустое множество, в которое можно вставить capacity элементов
ordered_array_set ordered_array_set_create(size_t capacity) {
    return (ordered_array_set) {malloc(sizeof(int) * capacity), 0, capacity};
}

static void ordered_array_set_shrinkToFit(ordered_array_set *a) {
    if (a->size != a->capacity) {
        a->data = (int *) realloc(a->data, sizeof(int) * a->size);
        a->capacity = a->size;
    }
}

int cmp(const void *a, const void *b) {
    int *p1 = (int *) a;
    int *p2 = (int *) b;
    if (p1 == p2)
        return 0;
    else if (p1 < p2)
        return -1;
    else
        return 1;
}

// добавляет элемент value в множество set
void ordered_array_set_insert(ordered_array_set *set, int value) {
    if (binarySearch_(set->data, set->size, value) == SIZE_MAX) {
        size_t i = 0;
        while (value < set->data[i])
            i++;
        size_t n = set->size;
        for (n = n; n > i; n--)
            set->data[n] = set->data[n - 1];
        set->data[i] = value;
    }
}

// возвращает множество, состоящее из элементов массива a размера size
ordered_array_set ordered_array_set_create_from_array(const int *a, size_t size) {
    ordered_array_set set = ordered_array_set_create(size);
    for (int i = 0; i < size; i++)
        ordered_array_set_insert(&set, a[i]);
    ordered_array_set_shrinkToFit(&set);
    return set;
}

// возвращает значение позицию элемента в множестве, если значение value имеется в множестве set, иначе - n
size_t ordered_array_set_in(ordered_array_set *set, int value) {
    return binarySearch_(set->data, set->size, value);
}

// возвращает значение ’истина’, если элементы множеств set1 и set2 равны иначе - ’ложь’
bool ordered_array_set_isEqual(ordered_array_set set1, ordered_array_set set2) {
    assert(set1.size == set2.size);
    for (int i = 0; i < set1.size; i++)
        if (set1.data[i] != set2.data[i])
            return 0;
    return 1;
}

// возвращает значение ’истина’, если subset является подмножеством set иначе - ’ложь’
bool ordered_array_set_isSubset(ordered_array_set subset, ordered_array_set set) {
    for (int i = 0; i < subset.size; i++)
        if (ordered_array_set_in(&set, subset.data[i]) == SIZE_MAX)
            return 0;
    return 1;
}

// возбуждает исключение, если в множество по адресу set нельзя вставить элемент
void ordered_array_set_isAbleAppend(ordered_array_set *set) {
    assert(set->size < set->capacity);
}

// удаляет элемент value из множества set
void ordered_array_set_deleteElement(ordered_array_set *set, int value) {
    size_t pos = binarySearch_(set->data, set->size, value);
    if (pos != SIZE_MAX)
        deleteByPosSaveOrder_(set->data, &set->size, pos);
}

// возвращает объединение множеств set1 и set2
ordered_array_set ordered_array_set_union(ordered_array_set set1, ordered_array_set set2) {
    ordered_array_set set = ordered_array_set_create_from_array(set1.data, set1.size);
    for (int i = 0; i < set2.size; i++)
        ordered_array_set_insert(&set, set2.data[i]);
    return set;
}

// возвращает пересечение множеств set1 и set2
ordered_array_set ordered_array_set_intersection(ordered_array_set set1, ordered_array_set set2) {
    ordered_array_set set = ordered_array_set_create_from_array(set1.data, set1.size);
    for (size_t i = set.size; i > 0; i--)
        if (ordered_array_set_in(&set2, set.data[i - 1]) == 0)
            ordered_array_set_deleteElement(&set, set.data[i - 1]);
    return set;
}

// возвращает разность множеств set1 и set2
ordered_array_set ordered_array_set_difference(ordered_array_set set1, ordered_array_set set2) {
    ordered_array_set set = ordered_array_set_create_from_array(set1.data, set1.size);
    for (size_t i = set.size; i > 0; i--)
        if (ordered_array_set_in(&set2, set.data[i - 1]) == 1)
            ordered_array_set_deleteElement(&set, set.data[i - 1]);
    return set;
}

// возвращает симметрическую разность множеств set1 и set2
ordered_array_set ordered_array_set_symmetricDifference(ordered_array_set set1, ordered_array_set set2) {
    return ordered_array_set_union(ordered_array_set_difference(set1, set2), ordered_array_set_difference(set2, set1));
}

// возвращает дополнение до универсума universumSet множества set
ordered_array_set ordered_array_set_complement(ordered_array_set set, ordered_array_set universumSet) {
    ordered_array_set set0 = ordered_array_set_create(set.capacity);
    set0 = ordered_array_set_difference(universumSet, set);
    return set0;
}

// вывод множества set
void ordered_array_set_print(ordered_array_set set) {
    printf("{");
    for (size_t i = 0; i < set.size; i++)
        printf("%d, ", set.data[i]);
    if (set.size == 0)
        printf("}");
    else
        printf("\b\b}");
}

// освобождает память, занимаемую множеством set
void ordered_array_set_delete(ordered_array_set set) {
    free(set.data);
}
