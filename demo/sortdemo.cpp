// author - sonaspy@outlook.com
// coding - utf_8
#include "../cpp/dsa.h"

#define SIZE 50
#define test() freopen("in", "r", stdin)

using namespace std;
using namespace dsa;

int main(int argc, char const *argv[])
{
    /* code */
    srand(time(NULL));
    int b[SIZE];
    generate(b, b + SIZE, [&]() { return rand() % 1000; });
    vector<int> a(b, b + SIZE);
    a.erase(unique(a.begin(), a.end()), a.end());
    clock_t startTime, endTime;
    startTime = clock();
    cout << *kth_element(a.begin(), a.end() - 1, 3) << endl;
    quicksort(a.begin(), a.end());
    output_vec(a);
    endTime = clock();
    cout << "The run time is: " << (double)(endTime - startTime) / 1000 << "ms" << endl;
    cout << is_sorted(a.begin(), a.end()) << endl;
    return 0;
}