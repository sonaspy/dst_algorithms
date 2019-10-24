// author - sonaspy@outlook.com
// coding - utf_8

#define SIZE 1000000
#include "stddsa.h"
#include <algorithm>
#define test() freopen("in", "r", stdin)

int main(int argc, char const *argv[])
{
    /* code */
    //test();

    clock_t startTime, endTime;
    vector<int> v(SIZE);
    generate(v.begin(), v.end(), [&]() { return rand(); });
    startTime = clock();
    dsa::sort(v.begin(), v.end());
    endTime = clock();
    cout << "The elapsed time is: " << (double)(endTime - startTime) / 1000 << "ms" << endl;

    return 0;
}