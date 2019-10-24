// author - sonaspy@outlook.com
// coding - utf_8

#define SIZE 10
#include "stddsa.h"

#define test() freopen("in", "r", stdin)

int main(int argc, char const *argv[])
{
    /* code */
    //test();

    clock_t startTime, endTime;
    startTime = clock();
    vector<int> v(10, 3);
    dsa::sort(v.begin(), v.end());
    endTime = clock();
    cout << "The elapsed time is: " << (double)(endTime - startTime) / 1000 << "ms" << endl;

    return 0;
}