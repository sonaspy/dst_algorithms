# author - newguo@sonaspy.cn
# coding - utf_8


def f2c(tpf):
    tpc = 0.0
    tpc = (tpf - 32) / 1.8
    return tpc


def buck2yuan(dollar):
    return dollar * 7.0905


def function3():
    str = input()
    for s in str:
        print(s, end=' ')
    print()
