// author - sonaspy@outlook.com
// coding - utf_8

#define SIZE 100
#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

int fact(int n)
{
    int s = 1;
    for (int i = 2; i <= n; i++)
        s *= i;
    return s;
}
double sinx(double x)
{
    double fraction = 0.000001, ans = 0, cur = 1;
    int i = 0, flag = 1, rev = 1;
    if (x < 0)
        x = -x, rev = -rev;

    while (abs(x) > M_PI)
        x -= M_PI * 2;
    if (x < 0)
        x = -x, rev = -rev;
    if (x > M_PI_2)
        x = M_PI - x;

    for (; abs(cur) >= fraction; ++i, flag = -flag)
    {
        cur = 1.0 * flag * pow(x, 2 * i + 1) / fact(2 * i + 1);
        ans += cur;
    }
    return rev == -1 ? -ans : ans;
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    srand(time(NULL));

    cout << char(*("sadad" + 2) + 2);
    return 0;
}