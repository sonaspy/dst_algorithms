# author - newguo@sonaspy.cn 
# coding - utf_8 

def insertion_sort(A):
    """Sort list of comparable elements into nondecreasing order."""
    for k in range(1, len(A)):
        cur = A[k]
        j = k
        while 0 < j and cur < A[j-1]:
            A[j] = A[j-1]
            j -= 1
        A[j] = cur