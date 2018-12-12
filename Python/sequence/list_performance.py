# author - newguo@sonaspy.cn 
# coding - utf_8 
import sys
from time import time

try:
    maxN = int(sys.argv[1])
except:
    maxN = 1e7

def compute_average(n):
    """Perform n appends to an empty list and return average time elapsed."""
    data = [] 
    start = time()
    for k in range(n):
        data.append(None)
    end = time()
    return (end - start) / n
n = 10
while n <= maxN:
    print('Average of {0:.3f} for n {1}'.format(compute_average(n)*1000000, n))
    n *= 10

