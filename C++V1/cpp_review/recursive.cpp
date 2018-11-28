// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<iostream>

using namespace std;

template <class T>
void permutations(T list[], int k, int m){
    if(k == m){
        copy(list, list+m+1, ostream_iterator<int>(cout, " "));
        cout << endl;
        return;
    }
    else{
        for(int i = k; i <= m; i++){
            swap(list[k],list[i]);
            permutations(list, k+1, m);
            swap(list[k],list[i]);
        }
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    int a[] = {1,2,3,4,5,6,7,8,9};

    cout << "The permutations of 1 are" << endl;
    permutations(a, 0, 0);

    cout << "The permutations of 123 are" << endl;
    permutations(a, 0, 2);

    cout << "The permutations of 1234 are" << endl;
    permutations(a, 0, 5);
    return 0;
}