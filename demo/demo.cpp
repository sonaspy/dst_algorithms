// author - sonaspy@outlook.com
// coding - utf_8

#define SIZE 5
#include <bits/stdc++.h>
#include "../v1/stddsa.h"
#define test() freopen("in", "r", stdin)
using namespace std;
using namespace dsa;

int main(int argc, char const *argv[]) {
    /* code */
    // test();

    clock_t startTime, endTime;

    startTime = clock();
    off_t i = 1;


    vector<int> v(11,0);
    v[5] = 9;
    print_vector(v.begin(), v.end());
    copy_backward(v.begin() + 5, v.end(), v.end() + 1);
    v.resize(12);
    v[5] = 99;
    print_vector(v.begin(), v.end());
    endTime = clock();

    // cout << "The elapsed time is: " << (double)(endTime - startTime) / 1000
    //      << "ms" << endl;

    return 0;
}
