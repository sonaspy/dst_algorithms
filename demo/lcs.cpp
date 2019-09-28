// author - sonaspy@outlook.com
// coding - utf_8

#include "../src/dsa.h"
#include <random>
#define SIZE 100

#define test() freopen("in", "r", stdin)

using namespace std;
using namespace dsa;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    srand(time(NULL));
    int b[SIZE];
    // generate(b, b + SIZE, [&]() { return rand() % 100; });
    vector<int> a(b, b + SIZE);
    iota(a.begin(), a.end(), 0);
    // reverse(a.begin(), a.end());
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(a.begin(), a.end(), default_random_engine(seed));
    // print_vector(a);

    _deque<int> dq;
    for (int i = 0; i < SIZE; i++)
        dq.push_back(i);
    for (int i = 0; i < SIZE / 2; i++)
        dq.pop_front();
    for (int i = 0; i < SIZE / 2; i++)
        dq.push_back(i);
    cout << dq.front() << endl;
    cout << dq.back() << endl;

    return 0;
}