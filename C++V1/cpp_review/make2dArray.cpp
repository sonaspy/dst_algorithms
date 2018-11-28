// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<iostream>
#include"make2dArrayCatch.h"

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    int **a;
    make2dArrayCatch(a,2,2);
    a[0][0] = 1;
    a[0][1] = 2;
    a[1][0] = 3;
    a[1][1] = 4;
    cout << a[0][0] << ' ' << a[0][1] << endl;
    cout << a[0][0] << ' ' << a[1][1] << endl;
    return 0;
}