// author - sonaspy@outlook.com
// coding - utf_8

#define SIZE 1000000
#include <bits/stdc++.h>
#include "stddsa.h"
#define test() freopen("in", "r", stdin)

using namespace std;
using namespace dsa;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    clock_t startTime, endTime;
    // srand(time(NULL));
    string s;
    skiplist<int, int> sk1(INT_MAX);
    while (cin >> s && s != "q")
    {
        startTime = clock();
        pair<int, int> p;
        for (int i = 0; i < SIZE; i++)
        {
            p = make_pair(i, 0);
            sk1.insert(p);
        }
        cout << sk1.level() << endl;
        endTime = clock();
        cout << "The elapsed time is: " << (double)(endTime - startTime) / 1000 << "ms" << endl;
        sk1.clear();
    }

    // sk1.print(cout);

    return 0;
}