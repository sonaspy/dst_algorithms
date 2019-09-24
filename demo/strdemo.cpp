// author - sonaspy@outlook.com
// coding - utf_8

#define SIZE 300000
#include "../src/dsa.h"

#define test() freopen("in", "r", stdin)

using namespace std;
using namespace dsa;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    // srand(time(NULL));
    char b[SIZE], a[SIZE / 100];
    generate(b, b + SIZE, [&]() { return rand() % 127 + 32; });
    clock_t startTime, endTime;
    startTime = clock();
    string s(b, b + SIZE), p(s.begin() + SIZE - 1000, s.begin() + SIZE - 900);
    cout << str_match(s, p) << endl;

    endTime = clock();
    cout << "The elapsed time is: " << (double)(endTime - startTime) / 1000 << "ms" << endl;

    return 0;
}