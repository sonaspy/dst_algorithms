// author - sonaspy@outlook.com
// coding - utf_8
#include "../src/dsa.h"

#define SIZE 1000000
#define test() freopen("in", "r", stdin)

using namespace std;
using namespace dsa;

int main(int argc, char const *argv[])
{
    /* code */
    //srand(time(NULL));
    int b[SIZE];
    generate(b, b + SIZE, [&]() { return rand(); });
    vector<int> a(b, b + SIZE);
    a.erase(unique(a.begin(), a.end()), a.end());
    clock_t startTime, endTime;
    startTime = clock();
    //output_vec(a);
    sort(a.begin(), a.end());
    //output_vec(a);
    endTime = clock();
    cout << is_sorted(a.begin(), a.end()) << endl;
    cout << "The run time is: " << (double)(endTime - startTime) / 1000 << "ms" << endl;
    return 0;
}