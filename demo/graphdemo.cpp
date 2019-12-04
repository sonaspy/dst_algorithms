// author - sonaspy@outlook.com
// coding - utf_8

#define SIZE 15

#include "../v1/stddsa.h"
#define test() freopen("in", "r", stdin)
using namespace dsa;
using namespace std;

int main(int argc, char const *argv[]) {
    /* code */
    // test();

    srand(time(NULL));
    int n, m, a1, a2, d;
    n = SIZE;
    vector<vector<int>> g(n, vector<int>(n, INF_VAL));
    g[0][1] = 15, g[0][2] = 17, g[2][4] = 8, g[2][5] = 33, g[1][3] = 10,
    g[3][6] = g[4][6] = g[7][13] = g[11][13] = g[12][13] = 0,
    g[5][7] = 30, g[6][8] = 15, g[8][9] = 10, g[8][10] = 20,
    g[9][11] = 40, g[10][12] = 25, g[13][14] = 20;

    clock_t startTime, endTime;
    startTime = clock();
    dGraph dg;
    dg.init(g);
    cout << "acyclic " << dg.acyclic() << endl;
    cout << "num of edge is -> " << dg.esize() << endl;
    dg.get_keyaction();
    
    endTime = clock();
    cout << "The elapsed time is: " << (double)(endTime - startTime) / 1000
         << "ms" << endl;

    return 0;
}