# author - sonaspy@outlook.com
# coding - utf_8


def isprime(n):
    if n < 2:
        return False
    border = int(n ** 0.5 + 1)
    for i in range(2, border):
        if n % i == 0:
            return False
    return True


def printSomePattern(n):
    c = n
    for i in range(0, n-1):
        print(' ' * (c-1), end='')
        print('*' * ((n - c + 1) * 2 - 1))
        c -= 1
    c = 1
    for i in range(0, n):
        print(' ' * (c-1), end='')
        print('*' * ((n - c + 1) * 2 - 1))
        c += 1


printSomePattern(4)

for i in range(1, 101):
    if isprime(i):
        print(i, end=' ')
'''
   *
  ***
 *****
*******
 *****
  ***
   *
2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97 % 
'''
