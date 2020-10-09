// author - sonaspy@zju.edu.cn
// coding - utf_8

#include <bits/stdc++.h>

enum class Permission { Yes, No };

enum class AnswerClassEnum : int { Yes, No = 5, Maybe = 10 };

int main(int argc, char const *argv[]) {
    int localvar = 100;

    int localvar2 = 200;

    /*
    - [] is Capture list
    - ()is Function Argument provider
    - {} is lambda Implementation
    The capture list [] is used to make local scope variables available to the
    lambda functions without passing them explicitly inside the parameter
    argument lists.
    = in capture list, which means all local scope variables are available
    inside the lambda functions
    use C++ reference & mechanism to pass local scope variable by reference and
    change the values. These changes shall be reflected globally.
    */
    // explicit return
    std::function<int(int)> lambdaFn = [localvar, localvar2](int value) -> int {
        std::cout << "Hello World" << std::endl;
        return value + 1;
    };

    int retLambda = lambdaFn(100);

    std::function<int(int)> fxsquare = [=](int x) -> int { return x * x; };
    int retValue = fxsquare(10);

    std::function<int(int, int)> fxsquare2 = [&](int x, int y) -> int {
        int xsquare = [](int x) { return x * x; }(x);
        int ysquare = [](int y) { return y * y; }(y);
        int twoxy = [](int x, int y) { return 2 * x * y; }(x, y);
        return xsquare + ysquare + twoxy;
    };
    int retValue2 = fxsquare2(5, 3);
    
    double d = 1.2;
    const int &b = d;
}