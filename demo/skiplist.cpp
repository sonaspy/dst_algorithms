// author - sonaspy@outlook.com
// coding - utf_8

#define SIZE 100000
#include <bits/stdc++.h>
#include "../v1/stddsa.h"
#define test() freopen("in", "r", stdin)

using namespace std;
using namespace dsa;

skiplist<int, int> sk(INT_MAX);
set<int> st;
pair<int, int> p;
clock_t startTime, endTime;

void performance_compare(int _size)
{
    cout << "The Test Case's Data Size is -> " << _size << ", The Data is Sorted" << endl;
    cout << "Iteration is -> 50 " << endl;
    vector<int> a(_size);
    iota(a.begin(), a.end(), 0);

    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(a.begin(), a.end(), default_random_engine(seed));

    double erase_time = 0, insert_time = 0, count_time = 0;
    int n = 50, count = 1;
    while (n--)
    {
        startTime = clock();
        for (int i = 0; i < SIZE; i++)
        {
            p = make_pair(a[i], 0);
            st.insert(a[i]);
        }
        endTime = clock();
        insert_time += (double)(endTime - startTime);

        startTime = clock();
        for (int i = 0; i < SIZE; i++)
        {
            if (!st.count(a[i]))
                count = 0;
        }
        endTime = clock();
        count_time += (double)(endTime - startTime);

        startTime = clock();
        for (int i = 0; i < SIZE; i++)
        {
            st.erase(a[i]);
        }
        endTime = clock();
        erase_time += (double)(endTime - startTime);
    }
    cout << st.size() << endl;
    cout << "The average insert time for rbtree is: " << insert_time / 50000 << "ms" << endl;
    cout << "The average count time for rbtree is: " << (count ? count_time / 50000 : 0) << "ms" << endl;
    cout << "The average erase time for rbtree is: " << erase_time / 50000 << "ms" << endl;

    n = 50, erase_time = 0, insert_time = 0, count_time = 0;
    count = 1;
    while (n--)
    {
        startTime = clock();
        for (int i = 0; i < SIZE; i++)
        {
            p = make_pair(a[i], 0);
            sk.insert(p);
        }
        endTime = clock();
        insert_time += (double)(endTime - startTime);

        startTime = clock();
        for (int i = 0; i < SIZE; i++)
        {
            if (!sk.count(a[i]))
                count = 0;
        }
        endTime = clock();
        count_time += (double)(endTime - startTime);

        startTime = clock();
        for (int i = 0; i < SIZE; i++)
        {
            sk.erase(a[i]);
        }
        endTime = clock();
        erase_time += (double)(endTime - startTime);
    }
    cout << sk.size() << endl;
    cout << "The average insert time for skiplist is: " << insert_time / 50000 << "ms" << endl;
    cout << "The average count time for skiplist is: " << (count ? count_time / 50000 : 0) << "ms" << endl;
    cout << "The average erase time for skiplist is: " << erase_time / 50000 << "ms" << endl;
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    srand(time(NULL));

    performance_compare(SIZE);

    return 0;
}