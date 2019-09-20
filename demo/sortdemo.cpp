// author - sonaspy@outlook.com
// coding - utf_8
#include "../src/dsa.h"

#define SIZE 10
#define test() freopen("in", "r", stdin)

using namespace std;
using namespace dsa;

int main(int argc, char const *argv[])
{
    /* code */
    srand(time(NULL));
    int b[SIZE];
    generate(b, b + SIZE, [&]() { return rand() % 100; });
    vector<int> a(b, b + SIZE);
    //iota(a.begin(), a.end(), 0);
    //a.erase(unique(a.begin(), a.end()), a.end());
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(a.begin(), a.end(), default_random_engine(seed));
    clock_t startTime, endTime;
    startTime = clock();
    //output_vec(a);
    //cout << *kth_element(a.begin(), a.end(), 2000) << endl;
    //sort(a.begin(), a.end());
    //cout << a[400] << endl;
    tableSort(b, b + SIZE);
    endTime = clock();
    cout << is_sorted(b, b + SIZE) << endl;
    cout << "The run time is: " << (double)(endTime - startTime) / 1000 << "ms" << endl;
    return 0;
}