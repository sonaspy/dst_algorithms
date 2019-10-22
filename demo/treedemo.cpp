// author - sonaspy@outlook.com
// coding - utf_8

#include "../v1/stddsa.h"

#define SIZE 10000
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
    // generate(b, b + n, [&]() { return rand(); });
    vector<int> a(b, b + n);
    iota(a.begin(), a.end(), 1);
    rbtree<int> ax;
    ax.build(a);
    cout << ax.size() << endl;
    ax.printhorizon();
    endTime = clock();
    cout << "The elapsed time is: " << (double)(endTime - startTime) / 1000 << "ms" << endl;
    return 0;
}
