// author - sonaspy@outlook.com
// coding - utf_8

#include "../src/dsa.h"

#define SIZE 100
using namespace std;
using namespace dsa;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    srand(time(NULL));

    string s;
    clock_t startTime, endTime;
    int nm = 10;
    int c = 0, c0 = 0;
    int b[SIZE] = {9, 8, 7, 2, 3, 5, 6, 4}, n = SIZE;
    generate(b, b + n, [&]() { return rand(); });
    vector<int> a(b, b + n);
    // iota(a.begin(), a.end(), 1);
    rbtree<int> ax;
    ax.build(a);
    cout << ax.size() << endl;
    for (int i = 0; i < SIZE - 10; i++)
        ax.erase(a[i]);
    cout << ax.size() << endl;
    endTime = clock();
    // ax.printhorizon();
    cout << "The elapsed time is: " << (double)(endTime - startTime) / 1000 << "ms" << endl;
    return 0;
}