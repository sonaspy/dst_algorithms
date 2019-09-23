// author -sonaspy@outlook.com
// coding - utf_8

#include "../src/functions.h"
#define test() freopen("in", "r", stdin)
using namespace std;
using namespace dsa;
#define SIZE 1000000
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    //srand(time(NULL));
    int b[SIZE];
    //generate(b, b + SIZE, [&]() { return rand() % 100; });
    vector<int> a(b, b + SIZE);
    iota(a.begin(), a.end(), 0);
    clock_t startTime, endTime;
    startTime = clock();
    __lower_bound(a.begin(), a.end(), rand() % 10000);
    endTime = clock();
    cout << "The elapsed time is: " << (double)(endTime - startTime) / 1000 << "ms" << endl;
    return 0;
}