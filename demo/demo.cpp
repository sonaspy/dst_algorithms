// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>
#define test() freopen("in", "r", stdin)
using namespace std;

#define SIZE 20

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    srand(time(NULL));
    int b[SIZE];
    generate(b, b + SIZE, [&]() { return rand() % 100; });
    vector<int> a(b, b + SIZE);
    // iota(a.begin(), a.end(), 0);
    clock_t startTime, endTime;
    startTime = clock();
    set<int> aaa;
    aaa.insert(10);
    set<int>::iterator it = aaa.begin();
    it++;

    endTime = clock();
    cout << "The elapsed time is: " << (double)(endTime - startTime) / 1000 << "ms" << endl;
    return 0;
}