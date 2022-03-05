//
// Created by Dasha on 05.03.2022.
//

#ifndef MAIN_C_ASSERT_STRING_H
#define MAIN_C_ASSERT_STRING_H

#include <ctype.h>
#include "../string_.h"
#define ASSERT_STRING(expected, got) assertString ( expected , got , __FILE__ , __FUNCTION__ , __LINE__ )

void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName,
                  int line);

#endif //MAIN_C_ASSERT_STRING_H
