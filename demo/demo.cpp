// author - sonaspy@outlook.com
// coding - utf_8

#define SIZE 10000
#include <bits/stdc++.h>
#define test() freopen("in", "r", stdin)
using namespace std;

class cl1
{
public:
    int m1, m2;
};

class cl2 : public cl1
{
    int fun() { return m1; }
};

int main(int argc, char const *argv[])
{
    /* code */
    //test();

    clock_t startTime, endTime;

    cout << "The elapsed time is: " << (double)(endTime - startTime) / 1000 << "ms" << endl;

    return 0;
}
