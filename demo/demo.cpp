// author - sonaspy@outlook.com
// coding - utf_8

#define SIZE 500000
#include <bits/stdc++.h>
#define test() freopen("in", "r", stdin)
using namespace std;
class cl1
{
protected:
    void func() {}
};

class cl2 : public cl1
{
    using cl1::func;
    void f()
    {
        func();
    }
};
class cl3 : public cl2
{
    using cl1::func;
    void ff()
    {
        func();
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();

    clock_t startTime, endTime;

    startTime = clock();
    char c = 'A';

    endTime = clock();

    cout << "The elapsed time is: " << (double)(endTime - startTime) / 1000 << "ms" << endl;

    return 0;
}
