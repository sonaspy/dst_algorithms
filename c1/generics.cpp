// author - sonaspy@zju.edu.cn
// coding - utf_8

#include <iostream>

template <class T>
T sum(const T data[], int size, T s = 0) {
    for (int i = 0; i < size; ++i) s += data[i];
    return s;
}

enum Days { SUN, MON, TUE, WED, THU, FRI, SAT };

inline Days operator++(Days d) {
    return static_cast<Days>((static_cast<int>(d) + 1) % 7);
}

std::ostream& operator<<(std::ostream& out, const Days& d) {
    switch (d) {
        case SUN:
            out << "SUN";
            break;
        default:
            out << "1";
    }
    return out;
}

int main(int argc, char const* argv[]) {
    Days d = SUN, e;
    e = ++d;
    std::cout << d << " " << e << std::endl;
}