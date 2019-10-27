// author - sonaspy@outlook.com
// coding - utf_8

#include "../v1/stddsa.h"
#include "../src/cpp-btree/btree_set.h"
#define SIZE 1000000
using namespace std;

int main(int argc, char const *argv[]) {
    /* code */
    // test();
    // srand(time(NULL));
    string s;
    clock_t startTime, endTime;
    int b[SIZE], n = SIZE;
    generate(b, b + n, [&]() { return rand(); });
    vector<int> a(b, b + n);
    dsa::btree<int, 256> ax;
    btree::btree_set<int> bs;

    startTime = clock();
    for (int i = 0; i < SIZE; i++)
        bs.insert(a[i]);
    endTime = clock();

    cout << "The elapsed time is: " << (endTime - startTime) * 1.0 / 1000
         << "ms" << endl;
    return 0;
}
