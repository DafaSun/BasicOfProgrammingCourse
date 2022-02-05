# include <stdio.h>
# include <stdint.h>
# include "libs/data_structures/vector/vector.h"

int main() {
    vector v = createVector(5);
    reserve(&v, SIZE_MAX);

    return 0;
}

