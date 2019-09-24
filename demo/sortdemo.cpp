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
    srand(time(NULL));
    int b[SIZE];
    generate(b, b + SIZE, [&]() { return rand(); });
    vector<int> a(b, b + SIZE);
    // iota(a.begin(), a.end(), 0);

    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    //shuffle(a.begin(), a.end(), default_random_engine(seed));
    clock_t startTime, endTime;
    startTime = clock();
    //cout << *kth_element(a.begin(), a.end(), 2000) << endl;
    quicksort(a.begin(), a.end());
    //a.erase(unique(a.begin(), a.end()), a.end());
    //output_vec(a);
    //cout << a[400] << endl;

    endTime = clock();
    cout << is_sorted(a.begin(), a.end()) << endl;
    cout << "The elapsed time is: " << (double)(endTime - startTime) / 1000 << "ms" << endl;
    return 0;
}