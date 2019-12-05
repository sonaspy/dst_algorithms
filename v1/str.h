// author - sonaspy@outlook.com
// coding - utf_8
#ifndef __STR__
#define __STR__
#include <string>
using namespace std;
namespace dsa {

int str_cmp(const char *str1, const char *str2) {
    // not! while(*str1++==*str2++)
    while (*str1 == *str2) {
        if (*str1 == '\0')
            break;
        str1++, str2++;
    }
    return *str1 - *str2;
}

// s(len) -> n  ,  p(len) -> m
// O(mn)

int __str_match(string &s, string &p) {
    for (auto i = s.begin(); i < s.end() - p.size() + 1; i++) {
        auto j = p.begin();
        for (auto walk = i; j < p.end(); walk++, j++)
            if (*j != *walk)
                break;
        if (j == p.end())
            return i - s.begin();
    }
    return s.size();
}

string big_num_addition(string &s1, string &s2) {
    int carry = 0;
    auto i = s1.rbegin(), j = s2.rbegin();
    string res;
    while (i != s1.rend() || j != s2.rend()) {
        int a = i != s1.rend() ? *(i++) - '0' : 0;
        int b = j != s2.rend() ? *(j++) - '0' : 0;
        int tmp = a + b + carry;
        carry = tmp / 10;
        res = to_string(int64_t(tmp % 10)) + res;
    }
    if (carry)
        res = to_string(int64_t(carry)) + res;
    return res;
}

int __kmp_str_match(string &s, string &p) {
    int m = p.size(), j = 0, t, n = s.size(), i = 0;
    vector<int> next(m, 0);
    t = next[0] = -1;
    while (j < m - 1) {
        if (t < 0 || p[j] == p[t]) {
            ++j, ++t;
            next[j] = p[j] != p[t] ? t : next[t];
        } else
            t = next[t];
    }

    j = 0, i = 0;
    while (j < m && i < n) {
        if (j < 0 || s[i] == p[j])
            ++i, ++j;
        else
            j = next[j];
    }
    return i - j;
}

bool str_match(string &s, string &p) {
    int _size = s.size() * p.size();
    if (_size < 1e7)
        return __str_match(s, p) != s.size();
    return __kmp_str_match(s, p) != s.size();
}

} // namespace dsa
#endif