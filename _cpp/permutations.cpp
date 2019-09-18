// output all permutations of n elements

#include <iostream>
#include <algorithm> // has copy

using namespace std;

template<class T>
void permutations(T list[], int k, int m)
{// Generate all permutations of list[k:m].
 // Assume k <= m.
   int i;
   if (k == m) {// list[k:m] has one permutation, output it
                  copy(list, list+m+1,
                       ostream_iterator<T>(std::cout, ""));
                  std::cout << std::endl;
                }
   else  // list[k:m] has more than one permutation
         // generate these recursively 
         for (i = k; i <= m; i++)
         {
            swap(list[k], list[i]);
            permutations(list, k+1, m);
            swap(list[k], list[i]);
         }
}

int main()
{
   char a[] = {'1', '2', '3', '4'};

   std::cout << "The permutations of 1 are" << std::endl;
   permutations(a, 0, 0);

   std::cout << "The permutations of 123 are" << std::endl;
   permutations(a, 0, 2);

   std::cout << "The permutations of 1234 are" << std::endl;
   permutations(a, 0, 3);
   return 0;
}
