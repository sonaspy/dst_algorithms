# author - sonaspy@outlook.com / New Guo
# coding - utf_8

# 1.
n = eval(input())
stus = list(map(int, input().split()))
i = 0
for score in stus:
    if score < 60:
        stus[i] = 60
    print(score, end=' ')
    i += 1


# 2.
n = eval(input())
stus = list(map(int, input().split()))
stus.sort()
top3 = stus[:3]
average_3 = sum(top3) / 3
average = sum(stus) / len(stus)


#3.
ops = input().split()
n1 = int(ops[0])
n2 = int(ops[2])
if ops[1] == "+":
    print(n1 + n2)
elif ops[1] == "-":
    print(n1 - n2)
elif ops[1] == "*":
    print(n1 * n2)
if ops[1] == "/":
    print(n1 / n2)

#4.
l1 = [11, 22, 33]
l2 = [22, 33, 44]
st1 = set(l1)
st2 = set(l2)
print(st1.intersection(st2))
print(st1.difference(st2))
print(st2.difference(st1))
print(st1.symmetric_difference(st2))
