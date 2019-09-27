// author - sonaspy@outlook.com
// coding - utf_8

#define SIZE 100
#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

void fun()
{
    printf("%p\n", fun);
}
typedef void (*PF)();
void fun2(PF pf)
{
    printf("%p\n", pf);
    printf("%p\n", &pf);
}

int main(int argc, char const *argv[])
{
    /* code */
    PF pf = fun;
    fun2(pf);
    printf("%p\n", pf);
    printf("%p\n", &pf);
    return 0;
}
