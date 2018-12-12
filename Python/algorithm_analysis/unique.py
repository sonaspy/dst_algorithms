# author - newguo@sonaspy.cn 
# coding - utf_8 

def unique1(S):
    """Return True if there are no duplicate elements in sequence S."""
    for j in range(len(S)):
        for k in range(j+1, len(S)):
            if S[j] == S[k]:
                return False
    return True

def unique2(S):
    """Return True if there are no duplicate elements in sequence S."""
    tmp = sorted(S)
    for j in range(1, len(S)):
        if S[j-1] == S[j]:
            return False
    return True