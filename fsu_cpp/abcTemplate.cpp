// template function with value parameters to compute
// an expression

#include<iostream>

using namespace std;

template<class T>
T abc(T a, T b, T c)
{
   return a + b * c;
}

int main()
{
   std::cout << abc(2,3,4) << std::endl;
   return 0;
}

