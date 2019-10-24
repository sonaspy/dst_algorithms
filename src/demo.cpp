// author - sonaspy@outlook.com
// coding - utf_8

#define SIZE 100000
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
    dsa::slist<int> dsasl(v.begin(), v.end());
    dsa::skiplist<int, int> sk(INT_MAX);
    std::map<int, int> mp;
    std::list<int> stdl(v.begin(), v.end());

    startTime = clock();

        endTime = clock();
    cout << "The elapsed time is: " << (double)(endTime - startTime) / 1000 << "ms" << endl;

    return 0;
}