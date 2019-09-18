// author - sonaspy@outlook.com
// coding - utf_8

#define SIZE 20
#include <bits/stdc++.h>
#include "dsa.h"
#define test() freopen("in", "r", stdin)
using namespace dsa;
using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();

    srand(time(NULL));
    int n, m, a1, a2, d;
    n = SIZE;
    vector<vector<int>> g(n, vector<int>(n, INF_VAL));
    //g[0][1] = 3, g[0][2] = 8, g[2][4] = 10, g[2][1] = 4, g[1][3] = 9, g[3][5] = 6, g[1][4] = 6, g[4][5] = 9;

    //dg.init(g);

    vector<int> ord;
    // cout << "toporder : ";
    // output_vec(ord);

    clock_t startTime, endTime;
    startTime = clock();
    char tt, *ps;
    while ((tt = getchar()) != '0')
    {
        dGraph dg;
        dg.rand_init(n, 10, 11);
        cout << "acyclic " << dg.acyclic() << endl;
        cout << "num of edge is -> " << dg.esize() << endl;
        cin >> a1;
        while (a1 != -1)
        {
            dg.getCycle(a1);
            cin >> a1;
        }
        //dg.get_keyaction();
        //cout << dg.istoporder(ord) << endl;
    }

    endTime = clock();
    cout << "The run time is: " << (double)(endTime - startTime) / 1000 << "ms" << endl;

    return 0;
}