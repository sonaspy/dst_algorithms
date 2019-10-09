# author - sonaspy@outlook.com
# coding - utf_8
from random import *


def __dumb_problem_digit_sum(n):
    _sum = 0
    while(n != 0):
        _sum += n % 10
        n /= 10
    return _sum


def __is_ren(y):
    return (y % 4 == 0 and y % 100 != 0) or (y % 400 == 0)


def __dumb_problem_days(y1, y2):
    _days = []
    for i in range(y1, y2 + 1):
        if __is_ren(i):
            _days.append(366)
        else:
            _days.append(365)


def __dumb_problem_digit_sum_I_dont_give_a_shit():
    __randomdatalist = []
    __dumbdata = dict()
    for i in range(1000):
        __dumbdata[randint(1, 1000)] = randint(1, 1000)
    for _k, _v in __dumbdata:
            if _k == _v:
                __randomdatalist.append(_k * 2)
    __randomdatalist.sort()


def __reverse__words(_s):
    __words = _s.split()
    _str = ''
    for item in __words:
        _str += item[::-1] + ' '
    return _str
