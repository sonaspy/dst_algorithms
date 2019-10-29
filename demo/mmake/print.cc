#include <iostream>
template <class T>
class Print {
  public:
    void print();
};

template <class T>
void Print<T>::print() {
    std::cout << 1;
}