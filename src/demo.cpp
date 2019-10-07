// author - sonaspy@outlook.com
// coding - utf_8

#define SIZE 100
#include "alloc.h"
#include <iostream>
#define test() freopen("in", "r", stdin)
void f()
{
}
void (*___FUNCCCCC)();
using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    ___FUNCCCCC = f;
    printf("%p\n", f);
    printf("%p\n", &___FUNCCCCC);
    printf("%ld\n", __null);

    return 0;
}