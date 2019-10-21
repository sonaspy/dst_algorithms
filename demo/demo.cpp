// author - sonaspy@outlook.com
// coding - utf_8

#define SIZE 500000
#include <bits/stdc++.h>
#define test() freopen("in", "r", stdin)
using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();

    clock_t startTime, endTime;

    startTime = clock();
    char c = 'A';

    endTime = clock();
    bitset<1> b(0);
    cout << b << endl;
    cout << __checksum<1>(b, 1) << endl;
    cout << "The elapsed time is: " << (double)(endTime - startTime) / 1000 << "ms" << endl;

    return 0;
}
