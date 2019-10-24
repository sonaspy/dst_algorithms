// author - sonaspy@outlook.com
// coding - utf_8

#define SIZE 10
#include "stddsa.h"
#include <deque>

#define test() freopen("in", "r", stdin)

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    std::deque<int> vs;
    dsa::deque<int> vd;
    clock_t startTime, endTime;
    startTime = clock();
    dsa::skiplist<int, int> sk(INT_MAX);
    for (int i = 0; i < SIZE; i++)
        sk.insert(i, 200);
    endTime = clock();
    cout << "The elapsed time is: " << (double)(endTime - startTime) / 1000 << "ms" << endl;

    return 0;
}