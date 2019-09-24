// author - sonaspy@outlook.com
// coding - utf_8

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    /* code */
    int m = 10, n = 10;
    char *pArray[] = {"How", "are", "you"};
    int num = sizeof(pArray) / sizeof(char *);
    printf("Total string numbers = %d\n", num);
    int *p = (int *)malloc(m * n * sizeof(int));
    int i = p[1 + 2];
    return 0;
}