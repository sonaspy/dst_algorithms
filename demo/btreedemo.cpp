// author - sonaspy@outlook.com
// coding - utf_8

#define SIZE 100
#include "../v1/stddsa.h"
#define test() freopen("in", "r", stdin)

using namespace std;
using namespace dsa;

int main(int argc, char const *argv[]) {
    /* code */
    // test();
    srand(time(NULL));
    int b[SIZE];
    generate(b, b + SIZE, [&]() { return rand() % 1000 + 10; });
    vector<int> a(b, b + SIZE);
    btree<int, 6> bt;
    for (int i = 0; i < SIZE; i++)
        bt.insert(a[i]);
    clock_t startTime, endTime;
    startTime = clock();

    // bt.inorder();
    cout << bt.size() << endl;

    endTime = clock();
    cout << "The elapsed time is: " << (double)(endTime - startTime) / 1000
         << "ms" << endl;
    return 0;
}