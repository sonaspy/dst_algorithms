// author - sonaspy@outlook.com
// coding - utf_8
#include "../src/stddsa.h"
#include <random>
#define SIZE 20
#define test() freopen("in", "r", stdin)

using namespace std;
using namespace dsa;

int MissingMax(int a[], int n)
{
    int i, j, max, missing = -1;

    for (i = 0; i < n; i++)
    {
        max = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] > a[max])
                max = j;
        }
        iter_swap(a + i, a + max);
        if (a[i] == missing)
            missing--;
    }
    return missing;
}

int main(int argc, char const *argv[])
{
    /* code */
    // srand(time(NULL));
    int b[SIZE], n;
    vector<int> a(b, b + SIZE);
    generate(b, b + SIZE, [&]() { return rand() % 100; });
    iota(a.begin(), a.end(), 0);

    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(a.begin(), a.end(), default_random_engine(seed));
    clock_t startTime, endTime;
    // a.erase(unique(a.begin(), a.end()), a.end());
    startTime = clock();
    quicksort(b, b + SIZE);
    print_vctor(b, b + SIZE);
    endTime = clock();

    cout << "The elapsed time is: " << (double)(endTime - startTime) / 1000 << "ms" << endl;
    return 0;
}