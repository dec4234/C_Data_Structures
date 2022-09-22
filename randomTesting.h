#include "stdio.h"
#include "stdlib.h"

void floatPrecision() {
    double x = 6.0 / 7.0;

    // Precision to 20 digits?
    printf("%.20f\n", x);
}

void listAllocation() {
    int *list = malloc(3 * sizeof(int));
    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    int *newlist = realloc(list, 4 * sizeof(int));
    newlist[3] = 4;
    list = newlist;

    printf("%i\n", list[2]);

    free(list);
}

void arrays() {
    int arr[3] = { [0 ... 2] = 1 };
    printf("%i %i %i", arr[0], arr[1], arr[2]);
}