//
// Created by Dasha on 05.03.2022.
//

#ifndef MAIN_C_TASKS_H
#define MAIN_C_TASKS_H

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <assert.h>
#include "assert_string.h"
#include "../string_.h"

typedef struct WordDescriptor {
    char *begin; // позиция начала слова
    char *end; // позиция первого символа, после последнего символа слова
} WordDescriptor;

//возвращает указатель на конец строки s - ноль-символ.
char *getEndOfString(char *s);

//удаляет из строки s все пробельные символы.
void removeNonLetters(char *s);

//сокращает количество пробелов между словами данного предложения s до одного.
void removeExtraSpaces(char *s);

//возвращает значение 0, если слово не было считано, в противном случае возвращает значение 1 и в переменную word типа WordDescriptor записывает позиции начала слова из строки, начинающейся по указателю beginSearch, и первого символа после конца слова.
int getWord(char *beginSearch, WordDescriptor *word);

//преобразовывает слово word так, чтобы цифры слова были перенесены в начало слова и изменяет порядок следования цифр в слове на обратный, а буквы – в конец слова, без изменения порядка следования.
void digitToStart(WordDescriptor word);

//преобразовывает строку с началом в beginString так, чтобы каждого цифры слова были перенесены в начало слова и изменяет порядок следования цифр в слове на обратный, а буквы – в конец слова, без изменения порядка следования.
void transformStringDigitToStartInWord(char *beginString);

//преобразовывает слово word так, чтобы цифры слова были перенесены в начало слова и изменяет порядок следования цифр в слове на обратный, а буквы – в конец слова, без изменения порядка следования.
void letterToStart(WordDescriptor word);

//преобразовывает строку таким образом, чтобы цифры каждого слова были перенесены в конец слова без изменения порядка следования их в слове, а буквы – в начало.
void transformStringLetterToStartInWord(char *beginString);

//возвращает значение 0, если слово не было считано, в противном случае возвращает значение 1 и в переменную word типа WordDescriptor записывает позиции начала слова из строки, начинающейся по указателю rbegin и заканчивающейся по указателю rend не включительно, и первого символа после конца слова.
bool getWordReverse(char *rbegin, char *rend, WordDescriptor *word);

//преобразовывает строку s, заменяя каждую цифру соответствующим ей числом пробелов.
void replaceDigitWithSpace(char *s);

//возвращает 1, если слова w1 и w2 - одинаковые, и 0 - противном случае.
int areWordsEqual(WordDescriptor w1, WordDescriptor w2);

//заменяет все вхождения слова 𝑤1 на слово 𝑤2 в строке по указателю source.
void replace ( char * source , char * w1 , char * w2 ) ;

//возвращает 1, если слова данной строки упорядочены лексикографически, и 0 - в противном случае.
bool isLexicographicallyOrdered(char *s);


void test_tasks();

#endif //MAIN_C_TASKS_H
