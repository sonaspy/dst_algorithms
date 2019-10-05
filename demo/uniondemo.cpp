// author - sonaspy@outlook.com
// coding - utf_8
#include "../src/dsa.h"
#include <random>
#define SIZE 10
#define test() freopen("in", "r", stdin)

using namespace std;
using namespace dsa;

int main(int argc, char const *argv[])
{
    /* code */
    srand(time(NULL));
    int b[SIZE] = {-1, 2, -4, 2, 3, -3, 5, 6, 9, -2}, n;
    // generate(b, b + SIZE, [&]() { return rand() % 20 - 10; });
    vector<int> a(b, b + SIZE);
    // iota(a.begin(), a.end(), 0);
    __Union su;
    su.__union_arr = a;
    print_vector(a);
    su.unite(4,6);
    print_vector(su.__union_arr);
    // unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    // shuffle(a.begin(), a.end(), default_random_engine(seed));
    clock_t startTime, endTime;

    startTime = clock();

    endTime = clock();
    cout << "The elapsed time is: " << (double)(endTime - startTime) / 1000 << "ms" << endl;
    return 0;
}