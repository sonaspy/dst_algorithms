// author - sonaspy@outlook.com
// coding - utf_8

#include "../v1/stddsa.h"

#define SIZE 100
using namespace std;
using namespace dsa;
int main(int argc, char const *argv[]) {
    /* code */
    // test();
    srand(time(NULL));
    string s;
    clock_t startTime, endTime;

    int b[SIZE], n = SIZE;
    generate(b, b + n, [&]() { return rand() % 100; });
    vector<int> a(b, b + n);
    rbtree<int> ax;
    ax.build(a);
    for (int i = 0; i < 80; i++)
        ax.erase(a[i]);
    ax.printhorizon();
    endTime = clock();
    cout << "The elapsed time is: " << (double)(endTime - startTime) / 1000
         << "ms" << endl;
    return 0;
}
