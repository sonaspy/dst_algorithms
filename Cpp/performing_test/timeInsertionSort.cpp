// author - newguo@sonaspy.cn
// coding - utf_8

#include<iostream>
#include<ctime>
using namespace std;

template <class T>
void insertionSort(T a[], int n)
{
    // Sort a[0:n-1] using the insertion sort method.
    for (int i = 1; i < n; i++)
        {
            // insert a[i] into a[0:i-1]
            T t = a[i];
            int j;
            for (j = i - 1; j >= 0 && t < a[j]; j--)
                a[j + 1] = a[j];
            a[j + 1] = t;
        }
}

int main(int argc, char const *argv[])
{
    /* code */
    int a[1500], step = 10;
    double cPerMills = double(CLOCKS_PER_SEC) / 1000;
    // clock ticks per millisecond
    cout << "The worst-case time, in milliseconds, are" << endl;
    cout << "n \t Time" << endl;
    // times for n = 0, 10, 20, ..., 100, 200, 300, ..., 1000
    for(int n = 0; n <= 1500; n += step)
        {
            // initial the array with worst case occasion
            for(int i = 0; i < n; i++)
                a[i] = n - i;
            clock_t  start_  = clock();
            insertionSort(a, n);
            double times_ = (clock() - start_) / cPerMills;
            cout << n << '\t' << times_ << endl;
            if(n == 100)
                step = 100;
        }
    int A[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    insertionSort(A,9);
    copy(A,A+9,ostream_iterator<int>(cout," "));
    return 0;
}