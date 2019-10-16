// author - sonaspy@outlook.com
// coding - utf_8

#define SIZE 10000
#include <bits/stdc++.h>
#define test() freopen("in", "r", stdin)
using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    vector<int> v, a;
    string s, s1;
    clock_t startTime, endTime;
    __wrap_iter<int *> it;
    for (int i = 0; i < SIZE; i++)
    {
        v.push_back(i);
    }
    v.erase(v.begin(), v.end());
    endTime = clock();

    cout << "The elapsed time is: " << (double)(endTime - startTime) / 1000 << "ms" << endl;

    return 0;
}
