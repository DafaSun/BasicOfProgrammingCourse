//
// Created by Dasha on 02.03.2022.
//

#include "string_.h"

size_t strlen_(const char *begin) {
    char *end = begin;
    while (*end != '\0')
        end++;
    return end - begin;
}

void test_strlen_1() {
    char s[] = "Hello";

    assert (strlen_(s) == 5);
}

void test_strlen_2() {
    char s[] = "\tHello\t";

    assert (strlen_(s) == 7);
}

void test_strlen_() {
    test_strlen_1();
    test_strlen_2();
}

char *find(char *begin, char *end, int ch) {
    while (begin != end && *begin != ch)
        begin++;

    return begin;
}

void test_find_1() {
    char s[] = "Hello";

    assert (find(s, s + 3, 'e') == s + 1);
}

void test_find_2() {
    char s[] = "Hello";

    assert (find(s, s + 4, 'j') == s + 4);
}

void test_find() {
    test_find_1();
    test_find_2();
}

char *findNonSpace(char *begin) {
    while (*begin != '\0' && isspace(*begin) != 0)
        begin++;

    return begin;
}

void test_findNonSpace_1() {
    char s[] = "Hello";

    assert (findNonSpace(s + 3) == s + 3);
}

void test_findNonSpace_2() {
    char s[] = " \t \n ";

    assert (findNonSpace(s) == s + 5);
}

void test_findNonSpace() {
    test_findNonSpace_1();
    test_findNonSpace_2();
}

char *findSpace(char *begin) {
    while (*begin != '\0' && isspace(*begin) == 0)
        begin++;

    return begin;
}

void test_findSpace_1() {
    char s[] = "Hello";

    assert (findSpace(s + 3) == s + 5);
}

void test_findSpace_2() {
    char s[] = " \t \n ";

    assert (findSpace(s) == s);
}

void test_findSpace() {
    test_findSpace_1();
    test_findSpace_2();
}

char *findNonSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin != rend && isspace(*rbegin) != 0)
        rbegin--;

    return rbegin;
}

void test_findNonSpaceReverse_1() {
    char s[] = "Hello";

    assert (findNonSpaceReverse(s + 3, s) == s + 3);
}

void test_findNonSpaceReverse_2() {
    char s[] = " \t \n ";

    assert (findNonSpaceReverse(s + 4, s) == s);
}

void test_findNonSpaceReverse() {
    test_findNonSpaceReverse_1();
    test_findNonSpaceReverse_2();
}

char *findSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin != rend && isspace(*rbegin) == 0)
        rbegin--;

    return rbegin;
}

void test_findSpaceReverse_1() {
    char s[] = "Hello";

    assert (findSpaceReverse(s + 3, s) == s);
}

void test_findSpaceReverse_2() {
    char s[] = " \t \n ";

    assert (findSpaceReverse(s + 4, s) == s + 4);
}

void test_findSpaceReverse() {
    test_findSpaceReverse_1();
    test_findSpaceReverse_2();
}

int strcmp_(const char *lhs, const char *rhs) {
    while (*lhs != '\0' && *rhs != '\0' && *lhs == *rhs) {
        lhs++;
        rhs++;
    }

    return *lhs - *rhs;
}

void test_strcmp_1() {
    char s1[] = "Hello";
    char s2[] = "Hello";

    assert (strcmp_(s1, s2) == 0);
}

void test_strcmp_2() {
    char s1[] = "Hello";
    char s2[] = "Hi";

    assert (strcmp_(s1, s2) < 0);
}

void test_strcmp_3() {
    char s1[] = "Hi";
    char s2[] = "Hello";

    assert (strcmp_(s1, s2) > 0);
}

void test_strcmp_() {
    test_strcmp_1();
    test_strcmp_2();
    test_strcmp_3();
}

char *copy(const char *beginSource, const char *endSource, char *beginDestination) {
    memcpy(beginDestination, beginSource, endSource - beginSource);
    beginDestination = beginDestination - beginSource + endSource;
    return beginDestination;
}

void test_copy() {
    char s1[] = "Hello";
    char s2[4];
    char s3[] = "Hel";

    char *r = copy(s1, s1 + 3, s2);

    assert (*s2 == *s3);
    assert (*(s2 + 1) == *(s3 + 1));
    assert (*(s2 + 2) == *(s3 + 2));
    assert (r == s2 + 3);
}

char *copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int)) {
    while (beginSource != endSource) {
        if (f(*beginSource)) {
            *beginDestination = *beginSource;
            beginDestination++;
        }
        beginSource++;
    }

    return beginDestination;
}

int isZero(int a) {
    if (a == '0')
        return 1;
    else
        return 0;
}

void test_copyIf() {
    char s1[] = "0a0bc";
    char s2[2];
    char s3[] = "00";

    char *r = copyIf(s1, s1 + 3, s2, isZero);

    assert (*s2 == *s3);
    assert (*(s2 + 1) == *(s3 + 1));
    assert (r == s2 + 2);
}

char *copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int)) {
    while (rbeginSource != rendSource) {
        if (f(*rbeginSource))  {
            *beginDestination = *rbeginSource;
            beginDestination++;
        }
        rbeginSource--;
    }

    return beginDestination;
}

int isMoreG(int a) {
    if (a > 'g')
        return 1;
    else
        return 0;
}

void test_copyIfReverse() {
    char s1[] = "Hello";
    char s2[4];
    char s3[] = "ll";

    char *r = copyIfReverse(s1 + 3, s1, s2, isMoreG);

    assert (*s2 == *s3);
    assert (*(s2 + 1) == *(s3 + 1));
    assert (*r == *(s2 + 2));
}



void test() {
    test_strlen_();
    test_find();
    test_findNonSpace();
    test_findSpace();
    test_findNonSpaceReverse();
    test_findSpaceReverse();
    test_strcmp_();
    test_copy();
    test_copyIf();
    test_copyIfReverse();
}