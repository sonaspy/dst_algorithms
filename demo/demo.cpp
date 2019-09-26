// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>
#include "../src/algorithms.h"
#define test() freopen("in", "r", stdin)
using namespace std;
using namespace dsa;

#define SIZE 9
int b[SIZE] = {92, 81, 58, 21, 57, 45, 161, 38, 117}, m = 13, pos;

inline int hash1(int key)
{
    return key % 13;
}
inline int hash2(int key)
{
    return key % 11 + 1;
}
struct
{
    short a;
    float b;
} v1;
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    srand(time(NULL));
    // generate(b, b + SIZE, [&]() { return rand() % 100; });
    vector<int> a(b, b + SIZE), table(m, -1);
    // iota(a.begin(), a.end(), 0);
    clock_t startTime, endTime;
    startTime = clock();

    for (auto key : a)
    {
        for (int i = 0; table[pos] != -1; i++)
        {
            pos = (hash1(key) + i * hash2(key)) % 13;
        }
        table[pos] = key;
    }
    print_vector(table);
    cout << v1.b << endl;

    endTime = clock();
    cout << "The elapsed time is: " << (double)(endTime - startTime) / 1000 << "ms" << endl;
    return 0;
}