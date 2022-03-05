//
// Created by Dasha on 05.03.2022.
//

#include "tasks.h"

char *getEndOfString(char *s) {
    while (*s != '\0')
        s++;
    return s;
}

void removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';
}

void test_removeNonLetters_1() {
    char s1[] = "He  ll  o";
    char s2[] = "Hello";

    removeNonLetters(s1);

    ASSERT_STRING(s1, s2);
}

void test_removeNonLetters_2() {
    char s1[] = "";
    char s2[] = "";

    removeNonLetters(s1);

    ASSERT_STRING(s1, s2);
}

void test_removeNonLetters_3() {
    char s1[] = "Hello";
    char s2[] = "Hello";

    removeNonLetters(s1);

    ASSERT_STRING(s1, s2);
}

void test_removeNonLetters_4() {
    char s1[] = "  \t \n ";
    char s2[] = "";

    removeNonLetters(s1);

    ASSERT_STRING(s1, s2);
}

void test_removeNonLetters() {
    test_removeNonLetters_1();
    test_removeNonLetters_2();
    test_removeNonLetters_3();
    test_removeNonLetters_4();
}

void removeExtraSpaces(char *s) {
    char *iRead = s;
    while ((isspace(*iRead) == 0) && (*iRead != '\0'))
        iRead++;
    iRead++;
    char *iWrite = iRead++;
    while (*iRead != '\0') {
        if ((isspace(*iRead)) && (isspace(*(iRead - 1)) == 0)) {
            *iWrite = ' ';
            iWrite++;
        } else if (isspace(*iRead) == 0) {
            *iWrite = *iRead;
            iWrite++;
        }
        iRead++;
    }
    *iWrite = '\0';
}

void test_removeExtraSpaces_1() {
    char s1[] = "Hel    lo  World";
    char s2[] = "Hel lo World";

    removeExtraSpaces(s1);

    ASSERT_STRING(s1, s2);
}

void test_removeExtraSpaces_2() {
    char s1[] = " \t  ";
    char s2[] = " ";

    removeExtraSpaces(s1);

    ASSERT_STRING(s1, s2);
}

void test_removeExtraSpaces() {
    test_removeExtraSpaces_1();
    test_removeExtraSpaces_2();
}




void test_tasks() {
    test_removeExtraSpaces();
    test_removeNonLetters();
}




