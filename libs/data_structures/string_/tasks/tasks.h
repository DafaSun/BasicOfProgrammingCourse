//
// Created by Dasha on 05.03.2022.
//

#ifndef MAIN_C_TASKS_H
#define MAIN_C_TASKS_H

#include <stdio.h>
#include <ctype.h>
#include "../string_.h"
#include "assert_string.h"

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



void test_tasks();

#endif //MAIN_C_TASKS_H
