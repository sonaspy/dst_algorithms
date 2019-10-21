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
    string s = "01101100000000000000000";
    bitset<32> b(s);
    cout << b.to_ulong() << endl;

    cout << "The elapsed time is: " << (double)(endTime - startTime) / 1000 << "ms" << endl;

    return 0;
}
