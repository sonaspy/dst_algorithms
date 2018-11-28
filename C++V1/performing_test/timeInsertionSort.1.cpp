// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<iostream>
#include<ctime>
using namespace std;

template <class T>
void insertionSort(T a[], int n)
{ // Sort a[0:n-1] using the insertion sort method.
    for (int i = 1; i < n; i++)
    { // insert a[i] into a[0:i-1]
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

    int a[1000], step = 10;
    double clocksPerMillis = double(CLOCKS_PER_SEC) / 1000;
    // clock ticks per millisecond

    cout << "The worst-case time, in milliseconds, are" << endl;
    cout << "n \tRepetitions \t Total Ticks \tTime per Sort" << endl;

    // times for n = 0, 10, 20, ..., 100, 200, 300, ..., 1000
    for (int n = 0; n <= 1000; n += step)
    {
        // get time for size n
        long numberOfRepetitions = 0;
        clock_t startTime = clock();
        do
        {
            numberOfRepetitions++;

            // initialize with worst-case data
            for (int i = 0; i < n; i++)
                a[i] = n - i;

            insertionSort(a, n);
        } while (clock() - startTime < 1000);
        // repeat until enough time has elapsed

        double elapsedMillis = (clock() - startTime) / clocksPerMillis;

        cout << n << '\t' << numberOfRepetitions << '\t' << elapsedMillis
             << '\t' << elapsedMillis / numberOfRepetitions
             << endl;

        if (n == 100)
            step = 100;
    }

    int A[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    insertionSort(A,9);
    copy(A,A+9,ostream_iterator<int>(cout," "));
    return 0;
}