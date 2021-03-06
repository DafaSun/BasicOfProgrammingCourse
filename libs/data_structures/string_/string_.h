//
// Created by Dasha on 02.03.2022.
//

#ifndef MAIN_C_STRING__H
#define MAIN_C_STRING__H

#define MAX_STRING_SIZE 100
#define MAX_N_WORDS_IN_STRING 100
#define MAX_WORD_SIZE 20

#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <memory.h>

typedef struct WordDescriptor {
    char *begin; // позиция начала слова
    char *end; // позиция первого символа, после последнего символа слова
} WordDescriptor;

typedef struct BagOfWords {
    WordDescriptor words[MAX_N_WORDS_IN_STRING];
    size_t size;
} BagOfWords;

char _stringBuffer [MAX_STRING_SIZE + 1];
BagOfWords _bag ;
BagOfWords _bag2 ;

//возвращает длину строки, первый элемент которой расположен в ячейке по указателю begin.
size_t strlen_(const char *begin);

//возвращает указатель на первый элемент с кодом ch, расположенным на ленте памяти между адресами begin и end не включая end.
char *find(char *begin, char *end, int ch);

//возвращает указатель на первый символ, отличный от пробельных, расположенный на ленте памяти, начиная с begin и заканчивая ноль-символом. Если символ не найден, возвращается адрес первого ноль-символа.
char *findNonSpace(char *begin);

//возвращает указатель на первый пробельный символ, расположенный на ленте памяти начиная с адреса begin или на первый ноль-символ.
char *findSpace(char *begin);

//возвращает указатель на первый справа символ, отличный от пробельных, расположенный на ленте памяти, начиная с rbegin (последний символ строки, за которым следует ноль-символ) и заканчивая rend (адрес символа перед началом строки). Если символ не найден, возвращается адрес rend.
char *findNonSpaceReverse(char *rbegin, const char *rend);

//возвращает указатель на первый пробельный символ справа, расположенный на ленте памяти, начиная с rbegin и заканчивая rend. Если символ не найден, возвращается адрес rend.
char *findSpaceReverse(char *rbegin, const char *rend);

// возвращает отрицательное значение, если lhs118 располагается до rhs в лексикографическом порядке (как в словаре), значение 0, если lhs и rhs равны, иначе – положительное значение.
int strcmp_(const char *lhs, const char *rhs);

//возвращает указатель на следующий свободный фрагмент памяти в destination, записывает по адресу beginDestination фрагмент памяти, начиная с адреса beginSource до endSource.
char *copy(const char *beginSource, const char *endSource, char *beginDestination);

// возвращает указатель на следующий свободный для записи фрагмент в памяти, записывает по адресу beginDestination элементы из фрагмента памяти начиная с beginSource заканчивая endSource, удовлетворяющие функции-предикату f.
char *copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int));

//возвращает значение beginDestination по окончанию работы функции, записывает по адресу beginDestination элементы из фрагмента памяти начиная с rbeginSource заканчивая rendSource, удовлетворяющие функции-предикату f.
char *copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int));

void test_string();

#endif //MAIN_C_STRING__H
