// author - sonaspy@outlook.com
// coding - utf_8

#define SIZE 1000000
#include <bits/stdc++.h>
#include "stddsa.h"
#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[]) {
    /* code */
    // test();
    dsa::btree<int> bs(8);
    // int b[SIZE], n;
    // generate(b, b + SIZE, [&]() { return rand(); });
    // vector<int> a(b, b + SIZE);
    clock_t startTime, endTime;

    for (int i = 0; i < SIZE; i++)
        bs.insert(i);
    startTime = clock();
    for (int i = 0; i < SIZE - 30; ++i)
        bs.erase(i);
    endTime = clock();
    cout << "The elapsed time is: " << (double)(endTime - startTime) / 1000
         << "ms" << endl;
    return 0;
}