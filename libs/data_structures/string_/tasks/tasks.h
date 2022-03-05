//
// Created by Dasha on 05.03.2022.
//

#ifndef MAIN_C_TASKS_H
#define MAIN_C_TASKS_H

#include <stdio.h>
#include <ctype.h>
#include "../string_.h"
#include "assert_string.h"

//возвращает указатель на конец строки s - ноль-символ.
char * getEndOfString ( char * s );

//удаляет из строки s все пробельные символы.
void removeNonLetters ( char * s );

//сокращает количество пробелов между словами данного предложения s до одного.
void removeExtraSpaces(char *s);

void test_tasks();

#endif //MAIN_C_TASKS_H
