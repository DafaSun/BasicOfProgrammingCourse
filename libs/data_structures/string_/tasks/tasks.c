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

void test_removeExtraSpaces_3() {
    char s1[] = "";
    char s2[] = "";

    removeExtraSpaces(s1);

    ASSERT_STRING(s1, s2);
}

void test_removeExtraSpaces() {
    test_removeExtraSpaces_1();
    test_removeExtraSpaces_2();
    test_removeExtraSpaces_3();
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

void test_transformStringDigitToStartInWord_4() {
    char s1[] = "";
    char s2[] = "";

    transformStringDigitToStartInWord(s1);

    ASSERT_STRING(s1, s2);
}

void test_transformStringDigitToStartInWord() {
    test_transformStringDigitToStartInWord_1();
    test_transformStringDigitToStartInWord_2();
    test_transformStringDigitToStartInWord_3();
    test_transformStringDigitToStartInWord_4();
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

void test_transformStringLetterToStartInWord_4() {
    char s1[] = "";
    char s2[] = "";

    transformStringLetterToStartInWord(s1);

    ASSERT_STRING(s1, s2);
}

void test_transformStringLetterToStartInWord() {
    test_transformStringLetterToStartInWord_1();
    test_transformStringLetterToStartInWord_2();
    test_transformStringLetterToStartInWord_3();
    test_transformStringLetterToStartInWord_4();
}

bool getWordReverse(char *rbegin, char *rend, WordDescriptor *word) {
    word->end = findNonSpaceReverse(rbegin, rend) + 1;

    if (*word->end == '\0')
        return false;

    word->begin = findSpaceReverse(word->begin, rend) + 1;

    return true;
}

void replaceDigitWithSpace(char *s) {
    char *end = getEndOfString(s);
    char *r = copy(s, end, _stringBuffer);
    *r = '\0';
    char *readPtr = _stringBuffer;
    char *recPtr = s;
    while (*readPtr != '\0') {
        if (isdigit(*readPtr)) {
            int digit = *readPtr - '0';
            for (int i = 0; i < digit; i++) {
                *recPtr = ' ';
                recPtr++;
            }
        } else {
            *recPtr = *readPtr;
            recPtr++;
        }
        readPtr++;
    }
    *recPtr = '\0';
}

void test_replaceDigitWithSpace_1() {
    char s1[MAX_STRING_SIZE] = "";
    char s2[] = "";

    replaceDigitWithSpace(s1);

    ASSERT_STRING(s1, s2);
}

void test_replaceDigitWithSpace_2() {
    char s1[MAX_STRING_SIZE] = "1abc4d";
    char s2[] = " abc    d";

    replaceDigitWithSpace(s1);

    ASSERT_STRING(s1, s2);
}

void test_replaceDigitWithSpace_3() {
    char s1[MAX_STRING_SIZE] = "1!2";
    char s2[] = " !  ";

    replaceDigitWithSpace(s1);

    ASSERT_STRING(s1, s2);
}

void test_replaceDigitWithSpace() {
    test_replaceDigitWithSpace_1();
    test_replaceDigitWithSpace_2();
    test_replaceDigitWithSpace_3();
}

int areWordsEqual(WordDescriptor w1, WordDescriptor w2) {
    long long sizeOfWord1 = w1.end - w1.begin;
    long long sizeOfWord2 = w2.end - w2.begin;

    if (sizeOfWord1 != sizeOfWord2)
        return sizeOfWord1 - sizeOfWord2;

    char *word1 = w1.begin;
    char *word2 = w2.begin;

    for (long long i = 0; i < sizeOfWord1; i++) {
        if (*word1 != *word2)
            return *word1 - *word2;
        word1++;
        word2++;
    }

    return 0;
}

void replace(char *source, char *w1, char *w2) {
    size_t w1Size = strlen_(w1);
    size_t w2Size = strlen_(w2);
    WordDescriptor word1 = {w1, w1 + w1Size};
    WordDescriptor word2 = {w2, w2 + w2Size};

    char *readPtr, *recPtr;
    if (w1Size >= w2Size) {
        readPtr = source;
        recPtr = source;
    } else {
        copy(source, getEndOfString(source), _stringBuffer);
        readPtr = _stringBuffer;
        recPtr = source;
    }
    WordDescriptor word;
    while (*readPtr == ' ') {
        *recPtr = ' ';
        recPtr++;
        readPtr++;
    }
    int r = getWord(readPtr, &word);
    while (r == 1) {
        if (areWordsEqual(word, word1) == 0) {
            recPtr = copy(word2.begin, word2.end, recPtr);
            readPtr += w1Size;
        } else {
            long long wordSize = word.end - word.begin;
            recPtr = copy(readPtr, readPtr + wordSize, recPtr);
            readPtr += wordSize;
        }
        while (*readPtr == ' ') {
            *recPtr = ' ';
            recPtr++;
            readPtr++;
        }
        r = getWord(word.end, &word);
    }
    *recPtr = '\0';
}

void test_replace_1() {
    char s1[MAX_STRING_SIZE] = "abc rek";
    char w1[] = "abc";
    char w2[] = "def";
    char s2[MAX_STRING_SIZE] = "def rek";

    replace(s1, w1, w2);

    ASSERT_STRING(s1, s2);
}

void test_replace_2() {
    char s1[MAX_STRING_SIZE] = "abcd rek";
    char w1[] = "abc";
    char w2[] = "def";
    char s2[MAX_STRING_SIZE] = "abcd rek";

    replace(s1, w1, w2);

    ASSERT_STRING(s1, s2);
}

void test_replace_3() {
    char s1[MAX_STRING_SIZE] = "";
    char w1[] = "abc";
    char w2[] = "def";
    char s2[MAX_STRING_SIZE] = "";

    replace(s1, w1, w2);

    ASSERT_STRING(s1, s2);
}

void test_replace_4() {
    char s1[MAX_STRING_SIZE] = "ab abc cd";
    char w1[] = "abc";
    char w2[] = "defg";
    char s2[MAX_STRING_SIZE] = "ab defg cd";

    replace(s1, w1, w2);

    ASSERT_STRING(s1, s2);
}

void test_replace_5() {
    char s1[MAX_STRING_SIZE] = "ab abc cd";
    char w1[] = "abc";
    char w2[] = "de";
    char s2[MAX_STRING_SIZE] = "ab de cd";

    replace(s1, w1, w2);

    ASSERT_STRING(s1, s2);
}

void test_replace_6() {
    char s1[MAX_STRING_SIZE] = "ab abc  cd abc hg  ";
    char w1[] = "abc";
    char w2[] = "defg";
    char s2[MAX_STRING_SIZE] = "ab defg  cd defg hg  ";

    replace(s1, w1, w2);

    ASSERT_STRING(s1, s2);
}

void test_replace() {
    test_replace_1();
    test_replace_2();
    test_replace_3();
    test_replace_4();
    test_replace_5();
    test_replace_6();
}

void isLexicographicallyOrdered(char *s) {


}

void test_tasks() {
    test_removeExtraSpaces();
    test_removeNonLetters();
    test_transformStringDigitToStartInWord();
    test_transformStringLetterToStartInWord();
    test_replaceDigitWithSpace();
    test_replace();
}




