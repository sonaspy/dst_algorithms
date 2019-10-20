// author - sonaspy@outlook.com
// coding - utf_8

#define SIZE 100000
#include <bits/stdc++.h>
#define test() freopen("in", "r", stdin)
using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();

    clock_t startTime, endTime;
    list<int> l1;
    deque<int> d1;
    vector<int> v1;
    startTime = clock();

    for (int i = 0; i < SIZE; ++i)
        v1.push_back(i);
    for (int i = 0; i < SIZE; ++i)
        v1.pop_back();

    endTime = clock();

    cout << "The elapsed time is: " << (double)(endTime - startTime) / 1000 << "ms" << endl;

    return 0;
}
