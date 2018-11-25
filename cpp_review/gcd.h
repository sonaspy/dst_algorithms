// author - newguo@sonaspy.cn
// coding - utf_8

#include<iostream>

using namespace std;

int rgcd(int x, int y)
{
    return (y == 0) ? x : rgcd(y, x % y);
}