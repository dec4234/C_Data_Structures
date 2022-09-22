#include "stdio.h"
#include "stdlib.h"

void input() {
    char str[100];
    int i;

    printf("Input\n");
    scanf("%s %i", str, &i);

    printf("\nYour string: %s\n", str);
    printf("Your int: %i\n", i);
}