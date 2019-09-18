// author - sonaspy@outlook.com
// coding - utf_8
#include "dsa.h"

#define SIZE 1000
#define test() freopen("in", "r", stdin)

using namespace std;
using namespace dsa;

int main(int argc, char const *argv[])
{
    /* code */
    srand(time(NULL));
    int b[SIZE];
    generate(b, b + SIZE, [&]() { return rand(); });
    vector<int> a(b, b + SIZE);
    clock_t startTime, endTime;
    startTime = clock();
    mergeSort(a.begin(), a.end());
    endTime = clock();
    cout << "The run time is: " << (double)(endTime - startTime) / 1000 << "ms" << endl;
    cout << is_sorted(a.begin(), a.end()) << endl;
    return 0;
}