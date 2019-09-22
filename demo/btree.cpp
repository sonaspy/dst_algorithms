// author - sonaspy@outlook.com
// coding - utf_8

#include "../src/dsa.h"

#define SIZE 100000
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
    generate(b, b + n, [&]() { return rand(); });
    vector<int> a(b, b + n);
    btree<int> ax(512);
    startTime = clock();
    // while (cin >> s && s != "q")
    // {
    // cout << ax.size() << endl;
    ax.build(a);
    cout << ax.size() << endl;
    // ax.inorder();
    // ax.printTree();
    sort(a.begin() + SIZE - 10, a.end());
    for (int i = 0; i < SIZE - 2; i++)
    {
        ax.erase(a[i]);
    }
    sort(a.begin() + SIZE - 10, a.end());
    for (int i = SIZE - 2; i < SIZE; i++)
    {
        cout << a[i] << " -> ";
    }
    cout << endl;
    ax.inorder();
    cout << ax.search(a[0]) << endl;
    endTime = clock();
    cout << "The run time is: " << (double)(endTime - startTime) / 1000 << "ms" << endl;
    return 0;
}
