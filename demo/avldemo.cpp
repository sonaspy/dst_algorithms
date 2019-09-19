// author - sonaspy@outlook.com
// coding - utf_8

#include "../cpp/dsa.h"

#define SIZE 10
using namespace std;
using namespace dsa;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    srand(time(NULL));
    int b[SIZE], n = SIZE;
    generate(b, b + n, [&]() { return rand() % 100; });
    vector<int> a(b, b + n);
    string s;
    iota(b, b + n, 1);
    clock_t startTime, endTime;
    startTime = clock();

    bstree<int> ax;
    ax.build(a);
    cout << ax.size() << endl;
    ax.printTreeHorizon();
    ax.erase(a[3]);
    ax.printTreeHorizon();

    endTime = clock();
    cout << "The run time is: " << (double)(endTime - startTime) / 1000 << "ms" << endl;
    return 0;
}