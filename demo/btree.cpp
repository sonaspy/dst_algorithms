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
    startTime = clock();
    int nm = 1;
    int c = 0, c0 = 0;
    while (nm--)
    {
        int b[SIZE], n = SIZE;
        generate(b, b + n, [&]() { return rand() % 1000; });
        vector<int> a(b, b + n);
        btree<int> ax;
        ax.build(a);
        // for (int i = 0; i < 990; i++)
        // {
        //     ax.erase(a[i]);
        // }
        ax.printTree();
    }
    cout << c0 << " " << c << endl;
    endTime = clock();
    cout << "The run time is: " << (double)(endTime - startTime) / 1000 << "ms" << endl;
    return 0;
}