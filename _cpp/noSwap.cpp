// incorrect swap method

#include<iostream>

using namespace std;

void swap(int x, int y)
{// swap the integers x and y
   int temp = x;
   x = y;
   y = temp;
}

// test the swap function
int main()
{
   int a = 2;
   int b = 3;
   

   // output the values
   std::cout << "Before swapping, a = " << a << " b = " << b << std::endl;

   // swap a and b
   swap(a,b);

   // output the new values
   std::cout << "After swapping, a = " << a << " b = " << b << std::endl;
   return 0;
}
