// author - sonaspy@outlook.com
// coding - utf_8
#ifndef __STR__
#define __STR__
#include <bits/stdc++.h>
using namespace std;
namespace dsa
{

int str_cmp(const char *str1, const char *str2)
{
    //not! while(*str1++==*str2++)
    while (*str1 == *str2)
    {
        if (*str1 == '\0')
            break;
        str1++, str2++;
    }
    return *str1 - *str2;
}
// s(len) -> n  ,  p(len) -> m
// O(mn)
bool str_if_match(string s, string p)
{
    for (auto i = s.begin(); i < s.end() - p.size() + 1; i++)
    {
        auto j = p.begin();
        for (auto walk = i; j < p.end(); walk++, j++)
            if (*j != *walk)
                break;
        if (j == p.end())
            return 1;
    }
    return 0;
}
string str_add(string s1, string s2)
{
    int carry = 0;
    auto i = s1.rbegin(), j = s2.rbegin();
    string res;
    while (i != s1.rend() || j != s2.rend())
    {
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
} // namespace dsa
#endif