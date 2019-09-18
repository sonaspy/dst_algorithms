// author - sonaspy@outlook.com
// coding - utf_8
#include "../cpp/dsa.h"

#define SIZE 10000
#define test() freopen("in", "r", stdin)

using namespace std;
using namespace dsa;
// template <class Iter>
// void quickSort(Iter* left, Iter* right)
// {
//     if (left >= right)
//         return;
//     Iter *mid = left;
//     mid = partition(left + 1, right, bind2nd(less<int>(), *mid));
//     iter_swap(mid - 1, left);
//     quickSort(left, mid - 1);
//     quickSort(mid, right);
// }
int main(int argc, char const *argv[])
{
    /* code */
    srand(time(NULL));
    int b[SIZE];
    generate(b, b + SIZE, [&]() { return rand(); });
    vector<int> a(b, b + SIZE);
    clock_t startTime, endTime;
    startTime = clock();
    merge_sort(a.begin(), a.end());
    endTime = clock();
    cout << "The run time is: " << (double)(endTime - startTime) / 1000 << "ms" << endl;
    cout << is_sorted(a.begin(), a.end()) << endl;
    return 0;
}