// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<iostream>
#include<algorithm>
#include<numeric>

using namespace std;

template <class T>
T sum(T a[], int n){
    T sum = 0;
    return accumulate(a, a+n, sum);
}
template <class T>
T product(T a[], int n){
    T sum = 1;
    return accumulate(a, a+n, sum, multiplies<T>());
}

template <class T>
void permutations(T list[], int k, int m){
    do{
        copy(list, list+m+1, ostream_iterator<T>(cout, " "));
        cout << endl;
    }while(next_permutation(list,list+m+1));
}

int main(int argc, char const *argv[])
{
    /* code */
    char a[] = {'A', 'B', 'C', 'D'};

    cout << "The permutations of 1 are" << endl;
    permutations(a, 0, 0);

    cout << "The permutations of 123 are" << endl;
    permutations(a, 0, 2);

    cout << "The permutations of 1234 are" << endl;
    permutations(a, 0, 3);
    return 0;
}