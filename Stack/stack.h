// abstract class stack
// abstract data type specification for stack data structure
// all methods are pure virtual functions

#ifndef stack_
#define stack_

using namespace std;

template <class T>
class stack
{
public:
  virtual ~stack() {}
  virtual bool empty() const = 0;
  // return true iff stack is empty
  virtual int size() const = 0;
  // return number of elements in stack
  virtual T &top() = 0;
  // return reference to the top element
  virtual void pop() = 0;
  // remove the top element
  virtual void push(const T &theElement) = 0;
  // insert theElement at the top of the stack
  
 /*  virtual void input(const stack<T>& s) = 0 : 
  //Input a stack from bottom to top;
  virtual string toString() = 0 : 
  //Return the stack elements, as a string, from bottom to top;
  virtual void split(stack<T> & a, stack<T>& b) = 0 : 
  //Split a stack into the stacks a and b.Stack a contains the bottom - half elements, and stack b contains the remaining elements.
  virtual void combine(stacK<T> & a, stack<T>& b) = 0 : 
  //Combine the stacks a and b into a single stack.The elements in the combined stack are the result of placing stack b on top of stack a.
*/
};
#endif
