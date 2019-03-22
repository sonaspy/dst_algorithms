
// convert a string into a nonnegative int that depends on all
// characters of the string

#include <iostream>
#include <string>

using namespace std;


int stringToInt(string s)
{// Convert s into a nonnegative int that depends on all
 // characters of s.
   int length = (int) s.length();   // number of characters in s
   int answer = 0;
   if (length % 2 == 1)
   {// length is odd
      answer = s.at(length - 1);
      length--;
   }

   // length is now even
   for (int i = 0; i < length; i += 2)
   {// do two characters at a time
      answer += s.at(i);
      answer += ((int) s.at(i + 1)) << 8;
   }

   return (answer < 0) ? -answer : answer;
}

// test program 
void main(void)
{
    string s = "abc";
    std::cout << s << " = " << stringToInt(s) << std::endl;

    s = "abcde";
    std::cout << s << " = " << stringToInt(s) << std::endl;
}
