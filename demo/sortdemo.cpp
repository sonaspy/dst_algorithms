// author - sonaspy@outlook.com
// coding - utf_8
#include "../v1/stddsa.h"
#include <random>
#define SIZE 6
#define test() freopen("in", "r", stdin)

using namespace std;
using namespace dsa;

int main(int argc, char const *argv[]) {
    /* code */
    // srand(time(NULL));
    int b[SIZE] = {46, 79, 56, 38, 40, 84}, n;
    // generate(b, b + SIZE, [&]() { return rand(); });
    vector<int> a(b, b + SIZE);

    // unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    // shuffle(a.begin(), a.end(), default_random_engine(seed));
    clock_t startTime, endTime;
    startTime = clock();
    make_heap(a.begin(), a.end());
    // cout << *__min_in_rotateArray(a.begin(), a.end()) << endl;
    print_vector(a.begin(), a.end());
    endTime = clock();
    // cout << is_sorted(a.begin(), a.end()) << endl;
    cout << "The elapsed time is: " << (double)(endTime - startTime) / 1000
         << "ms" << endl;
    return 0;
}