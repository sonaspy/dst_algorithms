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
    char *pArray[] = {"How", "are", "you"};
    int num = sizeof(pArray) / sizeof(char *);
    printf("Total string numbers = %d\n", num);
    return 0;
}