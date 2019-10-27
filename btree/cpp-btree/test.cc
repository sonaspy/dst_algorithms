// author - sonaspy@outlook.com
// coding - utf_8

#define SIZE 1000000
#include <bits/stdc++.h>
#include "btree_set.h"
#define test() freopen("in", "r", stdin)

using namespace std;
using namespace btree;
int main(int argc, char const *argv[]) {
    /* code */
    // test();
    btree_set<int, less<int>, allocator<int>, 512> bst;
    set<int> st;
    int b[SIZE], n;
    generate(b, b + SIZE, [&]() { return rand(); });
    vector<int> a(b, b + SIZE);
    clock_t startTime, endTime;
    for (int i = 0; i < SIZE; i++)
        bst.insert(a[i]);
    for (int i = 0; i < SIZE; i++)
        st.insert(a[i]);
    startTime = clock();

    for (int i = 0; i < SIZE; i++)
        bst.count(a[i]);

    endTime = clock();
    cout << "The elapsed time is: " << (double)(endTime - startTime) / 1000
         << "ms" << endl;

    return 0;
}