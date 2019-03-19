// author - newguo@sonaspy.cn
// coding - utf_8

#include<iostream>
#include<cmath>
using namespace std;

int Ackerman(int i, int j)
{
    if(i == 1 && j >= 1)
        {
            int sum;
            sum = pow(2,j);
            return sum;
        }
    if(i >= 2 && j == 1)
        return Ackerman(i-1, 2);
    if(i >= 2 && j >= 2)
        return Ackerman(i-1, Ackerman(i, j- 1));
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}