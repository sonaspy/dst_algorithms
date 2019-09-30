// author - sonaspy@outlook.com
// coding - utf_8

#include "../src/dsa.h"

#define SIZE 20
using namespace std;
using namespace dsa;
int CheckBST(binode_ptr<int> T, int K);
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    srand(time(NULL));
    string s;
    clock_t startTime, endTime;
    int nm = 10;
    int c = 0, c0 = 0;
    int b[SIZE], n = SIZE;
    generate(b, b + n, [&]() { return rand() % 100; });
    vector<int> a(b, b + n);
    // iota(a.begin(), a.end(), 1);
    avltree<int> ax;
    ax.build(a);
    int K = 4;
    int out = CheckBST(ax.root(), K);
    if (out < 0)
        printf("No.  Height = %d\n", -out);
    else
        printf("Yes.  Key = %d\n", out);
    endTime = clock();
    ax.printhorizon();
    cout << "The elapsed time is: " << (double)(endTime - startTime) / 1000 << "ms" << endl;
    return 0;
}
int isbst = 1, id = 0, val, preval = -1, res;
int CheckBST(binode_ptr<int> T, int K)
{
    static binode_ptr<int> root = T;
    if (!T)
        return -1;
    int h, h1, h2;
    h1 = CheckBST(T->lc, K);
    val = T->val;
    if (!(val > preval))
        isbst = 0;
    if (++id == K)
        res = val;
    preval = val;
    h2 = CheckBST(T->rc, K);
    h = 1 + (h1 > h2 ? h1 : h2);
    if (T != root)
        return h;
    return isbst ? res : -h;
}