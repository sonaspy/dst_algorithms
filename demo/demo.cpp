// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>
#include "../newguo/__config.h"

#define test() freopen("in", "r", stdin)
using namespace std;
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    srand(time(NULL));
    // generate(b, b + SIZE, [&]() { return rand() % 100; });
    // iota(a.begin(), a.end(), 0);
    clock_t startTime, endTime;
    startTime = clock();

    endTime = clock();
    cout << "The elapsed time is: " << (double)(endTime - startTime) / 1000 << "ms" << endl;
    return 0;
}