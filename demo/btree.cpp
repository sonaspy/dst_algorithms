// author - sonaspy@outlook.com
// coding - utf_8

#include "../src/dsa.h"

#define SIZE 1000
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
    btree<int> ax(3);
    startTime = clock();
    // while (cin >> s && s != "q")
    // {
    // cout << ax.size() << endl;
    ax.build(a);
    cout << ax.size() << endl;
    // ax.inorder();
    // ax.printTree();
    cout << ax.search(a[0]) << endl;
    endTime = clock();
    cout << "The elapsed time is: " << (double)(endTime - startTime) / 1000 << "ms" << endl;
    return 0;
}
