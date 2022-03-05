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

void test_removeNonLetters(){
    char s1[] = "He  ll  o";
    char s2[] = "Hello";

    removeNonLetters(s1);

    ASSERT_STRING(s2, s1);
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

void test_removeExtraSpaces() {
    char s1[] = "Hel    lo  World";
    char s2[] = "Hel lo World";

    removeExtraSpaces(s1);

    ASSERT_STRING(s2, s1);
}



void test_tasks(){
    test_removeExtraSpaces();
    test_removeNonLetters();
}




