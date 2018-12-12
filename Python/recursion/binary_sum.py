# author - newguo@sonaspy.cn 
# coding - utf_8 

def binary_sum(S, start, stop):
    if start >= stop:
        return 0
    elif start + 1 == stop:
        return S[start]
    else:
        mid = (start + stop) // 2
        return binary_sum(S, start, mid) + binary_sum(S, mid, stop)