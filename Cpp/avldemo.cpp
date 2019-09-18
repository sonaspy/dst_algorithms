// author - sonaspy@outlook.com
// coding - utf_8

#include "dsa.h"

#define SIZE 7
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

    rbtree<int> ax;
    ax.build(a);
    cout << ax.size() << endl;
    ax.printTreeHorizon();
    // while (cin >> n && n != 0)
    // {

    //     cin >> s;
    //     while (s != "q")
    //     {
    //         if (s[0] == 'v')
    //             ax.printTreeVertical();
    //         else
    //             ax.printTreeHorizon();
    //         cin >> s;
    //     }
    // }

    endTime = clock();
    cout << "The run time is: " << (double)(endTime - startTime) / 1000 << "ms" << endl;
    return 0;
}