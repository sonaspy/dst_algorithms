// author - sonaspy@outlook.com
// coding - utf_8
#include "../src/dsa.h"
#include <random>
#define SIZE 20
#define test() freopen("in", "r", stdin)

using namespace std;
using namespace dsa;

int main(int argc, char const *argv[])
{
    /* code */
    srand(time(NULL));
    int b[SIZE];
    // generate(b, b + SIZE, [&]() { return rand() % 10; });
    vector<int> a(b, b + SIZE);
    iota(a.begin(), a.end(), 0);

    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(a.begin(), a.end(), default_random_engine(seed));
    clock_t startTime, endTime;
    // a.erase(unique(a.begin(), a.end()), a.end());

    startTime = clock();
    // doubleselectsort(a.begin(), a.end());
    __Union un(8);
    // for (int i = 0; i < 7; i++)
    //     un.unite(i, i + 1);
    for (int i = 7; i > 0; i--)
        un.unite(i - 1, i);
    endTime = clock();
    print_vector(un.__union_arr);
    cout << is_sorted(a.begin(), a.end()) << endl;
    cout << "The elapsed time is: " << (double)(endTime - startTime) / 1000 << "ms" << endl;
    return 0;
}