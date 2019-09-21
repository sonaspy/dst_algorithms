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

    string s;
    clock_t startTime, endTime;
    int nm = 1;
    int c = 0, c0 = 0;
    int b[SIZE], n = SIZE;
    generate(b, b + n, [&]() { return rand() % 1000; });
    vector<int> a(b, b + n);
    a.erase(unique(a.begin(), a.end()), a.end());
    startTime = clock();
    // for (int i = 0; i < 990; i++)
    // {
    //     ax.erase(a[i]);
    // }
    // while (cin >> s && s != "q")
    // {
    btree<int> ax(2);
    ax.build(a);
    cout << ax.size() << endl;
    for (int i = 0; i < SIZE - 10; i++)
    {
        ax.erase(a[i]);
    }
    ax.printTree();
    cout << ax.size() << endl;
    cout << ax.search(a[0]) << endl;
    // }
    endTime = clock();
    cout << "The run time is: " << (double)(endTime - startTime) / 1000 << "ms" << endl;
    return 0;
}
