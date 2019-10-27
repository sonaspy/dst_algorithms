// author - sonaspy@outlook.com
// coding - utf_8

#define SIZE 500000
#include "/Library/Developer/CommandLineTools/usr/include/c++/v1/map"

#define test() freopen("in", "r", stdin)
using namespace std;

int main(int argc, char const *argv[]) {
    /* code */
    // test();

    clock_t startTime, endTime;

    startTime = clock();
    short i;
    map<int, int> mp;
    mp.insert({1, 1});
    endTime = clock();

    // cout << "The elapsed time is: " << (double)(endTime - startTime) / 1000
    //      << "ms" << endl;

    return 0;
}
