// author - newguo@sonaspy.cn
// coding - utf_8

#include<iostream>
#include "myExceptions.h"

using namespace std;

int factorial(int N)
{
    int sum = 2;
    if (N < 1)
        throw illegalParameterValue("N must be >= 1");
    if(N <= 2)
        return N;
    else
        {
            for(int i = 3; i <= N; i++)
                sum *= i;
        }
    return sum;
}
