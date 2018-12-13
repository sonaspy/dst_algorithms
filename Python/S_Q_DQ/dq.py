# author - newguo@sonaspy.cn 
# coding - utf_8

from collections import deque

list1 = [k*k for k in range(11)]

dq = deque(list1, 11)

dq.rotate(4)

for i in range(10):
    print(dq[i])

'''k = 10
obj = None
len(dq)
dq.append(obj)
dq.appendleft(obj)
dq.pop()
dq.popleft()
dq.clear()
dq.remove(obj)
dq.rotate(k)  -> k steps
dq.count(obj)'''