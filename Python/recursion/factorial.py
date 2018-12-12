# author - newguo@sonaspy.cn
# coding - utf_8
def factorial(n):
    if n == 0:
        return 1
    else:
        return n * factorial(n-1)