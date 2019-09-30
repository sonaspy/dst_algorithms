// author - sonaspy@outlook.com
// coding - utf_8

#include "../src/dsa.h"

#define SIZE 20
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
    int b[SIZE], n = SIZE;
    generate(b, b + n, [&]() { return rand() % 100; });
    vector<int> a(b, b + n);
    // iota(a.begin(), a.end(), 1);
    avltree<int> ax;
    ax.build(a);
    endTime = clock();
    ax.printhorizon();
    cout << "The elapsed time is: " << (double)(endTime - startTime) / 1000 << "ms" << endl;
    return 0;
}
