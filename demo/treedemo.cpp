// author - sonaspy@outlook.com
// coding - utf_8

#include "../src/dsa.h"

#define SIZE 500
using namespace std;
using namespace dsa;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    srand(time(NULL));
    int b[SIZE], n = SIZE;
    generate(b, b + n, [&]() { return rand() % 1000; });
    vector<int> a(b, b + n);
    a.erase(unique(a.begin(), a.end()), a.end());
    string s;
    clock_t startTime, endTime;
    startTime = clock();

    rbtree<int> ax;
    cout << ax.root() << endl;
    ax.build(a);
    cout << ax.size() << endl;
    for (int i = 0; i < 480; i++)
    {
        cout << a[i] << endl;
        ax.erase(a[i]);
    }
    cout << ax.size() << endl;
    ax.printhorizon();
    cout << ax.isrbtree() << endl;
    endTime = clock();
    cout << "The run time is: " << (double)(endTime - startTime) / 1000 << "ms" << endl;
    return 0;
}