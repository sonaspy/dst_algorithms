// author - sonaspy@outlook.com
// coding - utf_8

#include "../src/stddsa.h"

#define SIZE 1000000
using namespace std;
using namespace dsa;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    // srand(time(NULL));
    string s;
    clock_t startTime, endTime;
    int b[SIZE], n = SIZE;
    generate(b, b + n, [&]() { return rand(); });
    vector<int> a(b, b + n);
    btree<int> ax(512);
    startTime = clock();

    ax.build(a);

    endTime = clock();

    cout << "The elapsed time is: " << (endTime - startTime) * 1.0 / 1000 << "ms" << endl;
    return 0;
}
