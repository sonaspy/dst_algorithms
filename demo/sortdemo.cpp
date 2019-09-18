// author - sonaspy@outlook.com
// coding - utf_8
#include "../cpp/dsa.h"

#define SIZE 1
#define test() freopen("in", "r", stdin)

using namespace std;
using namespace dsa;

int main(int argc, char const *argv[])
{
    /* code */
    srand(time(NULL));
    int b[SIZE];
    generate(b, b + SIZE, [&]() { return rand() % 10000; });
    vector<int> a(b, b + SIZE);
    a.erase(unique(a.begin(), a.end()), a.end());
    clock_t startTime, endTime;
    startTime = clock();
    make_heap(a.begin(), a.end());
    cout << __isheap(a.begin(), a.end()) << endl;
    endTime = clock();
    cout << is_sorted(a.begin(), a.end()) << endl;
    cout << "The run time is: " << (double)(endTime - startTime) / 1000 << "ms" << endl;
    return 0;
}