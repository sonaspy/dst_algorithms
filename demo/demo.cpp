// author - sonaspy@outlook.com
// coding - utf_8

#define SIZE 50000000
#include <bits/stdc++.h>
#define test() freopen("in", "r", stdin)
using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();

    clock_t startTime, endTime;
    vector<int> v1(SIZE);

    startTime = clock();
    auto end = v1.end();
    for (auto i = v1.begin(); i != end; i++)
        ;
    endTime = clock();

    cout << "The elapsed time is: " << (double)(endTime - startTime) / 1000 << "ms" << endl;

    return 0;
}
