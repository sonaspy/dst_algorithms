// author - sonaspy@outlook.com
// coding - utf_8

#define SIZE 1000000
#include "stddsa.h"
#include <bits/stdc++.h>
#define test() freopen("in", "r", stdin)

int main(int argc, char const *argv[])
{
    /* code */
    //test();

    clock_t startTime, endTime;
    vector<int> v(SIZE);
    generate(v.begin(), v.end(), [&]() { return rand(); });
    std::list<int> stdl;
    dsa::list<int> dsal;
    dsa::slist<int> dsasl;
    dsa::skiplist<int, int> sk(INT_MAX);
    std::map<int, int> mp;
    startTime = clock();

    for (int i = 0; i < SIZE; ++i)
        stdl.push_front(i);

    endTime = clock();
    cout << "The elapsed time is: " << (double)(endTime - startTime) / 1000 << "ms" << endl;

    return 0;
}