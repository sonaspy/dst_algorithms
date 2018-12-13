# author - newguo@sonaspy.cn
# coding - utf_8

import collections


def count(data, target):
    n = 0
    for item in data:
        if item == target:               # found a match
            n += 1
    return n


def fibonacci1():
    a = 0
    b = 1
    while True:             # keep going...
        yield a               # report value, a, during this pass
        future = a + b
        a = b                 # this will be next value reported
        b = future            # and subsequently this


def fibonacci(num):
    n, a, b = 0, 0, 1
    while n < num:
        yield a
        a, b = b, a+b
        n += 1


def compute_gpa(grades, points={'A+': 4.0, 'A': 4.0, 'A-': 3.67, 'B+': 3.33,
                                'B': 3.0, 'B-': 2.67, 'C+': 2.33, 'C': 2.0,
                                'C': 1.67, 'D+': 1.33, 'D': 1.0, 'F': 0.0}):
    num_courses = 0
    total_points = 0
    for g in grades:
        if g in points:                      # a recognizable grade
            num_courses += 1
            total_points += points[g]
    return total_points / num_courses


def contains(data, target):
    for item in data:
        if item == target:               # found a match
            return True
    return False


def scale(data, factor):
    for j in range(len(data)):
        data[j] *= factor


def range(start, stop=None, step=1):
    if stop is None:
        stop = start
        start = 0


def sum1(values):
    if not isinstance(values, collections.Iterable):
        raise TypeError('parameter must be an iterable type')
    total = 0
    for v in values:
        if not isinstance(v, (int, float)):
            raise TypeError('elements must be numeric')
        total = total + v
    return total


def sum2(values):
    total = 0
    for v in values:
        total += v
    return total


def factors1(n):             # traditional function that computes factors
    results = []              # store factors in a new list
    for k in range(1, n+1):
        if n % k == 0:          # divides evenly, thus k is a factor
            results.append(k)     # add k to the list of factors
    return results            # return the entire list


def factors2(n):             # generator that computes factors
    for k in range(1, n+1):
        if n % k == 0:          # divides evenly, thus k is a factor
            yield k               # yield this factor as next result


def factors3(n):             # generator that computes factors
    k = 1
    while k * k < n:          # while k < sqrt(n)
        if n % k == 0:
            yield k
            yield n // k
        k += 1
    if k * k == n:            # special case if n is perfect square
        yield k


for f in fibonacci(10):
    print(f)
