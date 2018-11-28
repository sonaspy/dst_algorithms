// author - newguo@sonaspy.cn 
// coding - utf_8 

#include <iostream>
#include "myExceptions.h"
using namespace std;

template <class T>
int indexOfMax(T a[], int n){
    if (n <= 0)
        throw illegalParameterValue("n must be > 0");

    int indexOfMax = 0;
    for (int i = 1; i < n; i++)
        if (a[indexOfMax] < a[i])
            indexOfMax = i;
    return indexOfMax;
}

int main(int argc, char const *argv[])
{
    /* code */
    int a[6] = {1, 4, 2, 5, 6, 3};

    // output the array elements
    cout << "a[0:5] = ";
    copy(a, a + 6, ostream_iterator<int>(cout, " "));
    cout << endl;

    // test the function indexOfMax
    cout << "max(a,1) = " << a[indexOfMax(a, 1)] << endl;
    cout << "max(a,3) = " << a[indexOfMax(a, 3)] << endl;
    cout << "max(a,6) = " << a[indexOfMax(a, 6)] << endl;
    return 0;
}