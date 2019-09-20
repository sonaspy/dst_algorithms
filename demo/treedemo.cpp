// author - sonaspy@outlook.com
// coding - utf_8

#include "../src/dsa.h"

#define SIZE 10000
using namespace std;
using namespace dsa;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    srand(time(NULL));
    int b[SIZE], n = SIZE;
    generate(b, b + n, [&]() { return rand(); });
    vector<int> a(b, b + n);
    a.erase(unique(a.begin(), a.end()), a.end());
    string s;
    clock_t startTime, endTime;
    startTime = clock();

    avltree<int> ax;
    ax.build(a);
    cout << ax.root() << endl;
    cout << ax.size() << endl;
    cout << ax.balanced() << endl;
    // for (int i = 0; i < 8000; i++)
    // {
    //     cout << a[i] << endl;
    //     ax.erase(a[i]);
    // }
    cout << ax.size() << endl;
    endTime = clock();
    cout << "The run time is: " << (double)(endTime - startTime) / 1000 << "ms" << endl;
    return 0;
}