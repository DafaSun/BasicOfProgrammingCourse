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

int getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return 0;

    word->end = findSpace(word->begin);

    return 1;
}

void digitToStart(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end,
                                 _stringBuffer);

    char *recPosition = copyIfReverse(endStringBuffer - 1, _stringBuffer - 1, word.begin, isdigit);

    copyIf(_stringBuffer, endStringBuffer, recPosition, isalpha);

}

void transformStringDigitToStartInWord(char *beginString) {
    char *beginSearch = beginString;
    WordDescriptor word;

    while (getWord(beginSearch, &word)) {
        digitToStart(word);
        beginSearch = word.end;
    }
}

void test_transformStringDigitToStartInWord_1() {
    char s1[] = "abc2347";
    char s2[] = "7432abc";

    transformStringDigitToStartInWord(s1);

    ASSERT_STRING(s1, s2);
}

void test_transformStringDigitToStartInWord_2() {
    char s1[] = "abc2347hg";
    char s2[] = "7432abchg";

    transformStringDigitToStartInWord(s1);

    ASSERT_STRING(s1, s2);
}

void test_transformStringDigitToStartInWord_3() {
    char s1[] = "abc2347 kl876fr";
    char s2[] = "7432abc 678klfr";

    transformStringDigitToStartInWord(s1);

    ASSERT_STRING(s1, s2);
}

void test_transformStringDigitToStartInWord() {
    test_transformStringDigitToStartInWord_1();
    test_transformStringDigitToStartInWord_2();
    test_transformStringDigitToStartInWord_3();
}

void letterToStart(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end,
                                 _stringBuffer);

    char *recPosition = copyIf(_stringBuffer, endStringBuffer, word.begin, isalpha);

    copyIf(_stringBuffer, endStringBuffer, recPosition, isdigit);
}

void transformStringLetterToStartInWord(char *beginString) {
    char *beginSearch = beginString;
    WordDescriptor word;

    while (getWord(beginSearch, &word)) {
        letterToStart(word);
        beginSearch = word.end;
    }
}

void test_transformStringLetterToStartInWord_1() {
    char s1[] = "d7432abc";
    char s2[] = "dabc7432";

    transformStringLetterToStartInWord(s1);

    ASSERT_STRING(s1, s2);
}

void test_transformStringLetterToStartInWord_2() {
    char s1[] = "123abc456";
    char s2[] = "abc123456";

    transformStringLetterToStartInWord(s1);

    ASSERT_STRING(s1, s2);
}

void test_transformStringLetterToStartInWord_3() {
    char s1[] = "a2347bc kl876fr";
    char s2[] = "abc2347 klfr876";

    transformStringLetterToStartInWord(s1);

    ASSERT_STRING(s1, s2);
}

void test_transformStringLetterToStartInWord() {
    test_transformStringLetterToStartInWord_1();
    test_transformStringLetterToStartInWord_2();
    test_transformStringLetterToStartInWord_3();
}


void test_tasks() {
    test_removeExtraSpaces();
    test_removeNonLetters();
    test_transformStringDigitToStartInWord();
    test_transformStringLetterToStartInWord();
}




