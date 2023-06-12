#include <stdio.h>
#include "DynamicArray.h"

int main() {
    struct DynamicArray darr;

    initialize_dynamic_array(&darr);
    printf("daar size: %d\n", size(&darr));
    printf("darr capacity: %d\n", capacity(&darr));
    printf("darr empty: %d\n", empty(&darr));

    for (int i = 0; i < 4; ++i) {
        push_back(&darr, i);
    }
    for (int i = 0; i < size(&darr); ++i) {
        printf("darr elem at %d : %d \n", i, at(&darr, i));
    }

    printf("\n");

    insert(&darr, 3, 19);
    insert(&darr, size(&darr), 20);
    for (int i = 0; i < size(&darr); ++i) {
        printf("darr elem at %d : %d \n", i, at(&darr, i));
    }

    struct DynamicArray darr2;

    printf("\n");


    reserve(&darr, 10);
    printf("daar size: %d\n", size(&darr));
    printf("darr capacity: %d\n", capacity(&darr));
    printf("darr empty: %d\n", empty(&darr));

    printf("\n");

    initialize_dynamic_array(&darr2);
    reserve(&darr2, 8);
    printf("daar2 size: %d\n", size(&darr2));
    printf("darr2 capacity: %d\n", capacity(&darr2));
    printf("darr2 empty: %d\n", empty(&darr2));

    return 0;
}
