// author - sonaspy@outlook.com
// coding - utf_8

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int fun()
{
    printf("%d", 1);
    return 1;
}
typedef int (*PF)();
void fun2(PF pf)
{
    (*pf)();
}
int gcd(int a, int b)
{
    if (a <= 0 || b <= 0)
        return -1;
    if (a == b)
        return a;
    else if (b < a)
        return gcd(a - b, b);
    else
        return gcd(b - a, a);
}
int _gcd(int a, int b)
{
    if (a % b == 0)
        return b;
    return _gcd(b, a % b);
}

int main(int argc, char const *argv[])
{
    /* code */
    srand(time(NULL));
    int a = rand() % 100, b = rand() % 100;
    printf("%d %d %d\n", a, b, _gcd(a, b));
    return 0;
}
