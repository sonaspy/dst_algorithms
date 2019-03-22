// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <vector>
#define test() freopen("in", "r", stdin)

using namespace std;

vector<int> v;

template <long long i = 1>
class Fibonacci
{
  public:
    enum
    {
        value = Fibonacci<i - 1>::value + Fibonacci<i - 2>::value
    };
};

template <>
class Fibonacci<2>
{
  public:
    enum
    {
        value = 1
    };
};
template <>
class Fibonacci<1>
{
  public:
    enum
    {
        value = 1
    };
};




template <int p, int i>
struct PrimeMagicCube
{
    enum
    {
        answer = p % i && PrimeMagicCube<p, i - 1>::answer
    };
};
template <int p>
struct PrimeMagicCube<p, 1>
{
    enum
    {
        answer = 1
    };
};
template <int i>
struct Number
{
    Number<i - 1> a; //  递归定义数值对象
    enum
    {
        answer = PrimeMagicCube<i, i - 1>::answer
    };
    void IsPrime()
    { //  先降序输出全部素数，后升序输出全部数值素性序列
        if (answer)
            v.push_back(i);
        a.IsPrime(); //  递归调用，计算下一数值的素性
    }
};

template <>
struct Number<2>
{
    enum
    {
        answer = 1
    };
    void IsPrime()
    {
        v.push_back(2);
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    //test();

    Number<> a;
    a.IsPrime();
    for(auto i : v) cout << i << " ";
    return 0;
}

