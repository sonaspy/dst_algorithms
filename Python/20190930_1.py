# author - sonaspy@outlook.com
# coding - utf_8

from random import *

commodityList = []


def ranstr(num):
    H = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789'
    salt = ''
    for i in range(num):
        salt += choice(H)
    return salt


for i in range(1000):
    newgood = dict()
    newgood["name"] = ranstr(randint(1, 10))
    newgood["price"] = randint(100, 3000)
    commodityList.append(newgood)

totalasset = int(input("Please input your total asset\n"))

_id = 0

for i in commodityList:
    print(_id, end=' ')
    print(i)
    _id += 1

_choice = int(input("Please make your choice, input id\n"))

if commodityList[_choice]['price'] > totalasset:
        print("purchase failed")
else:
    print("purchase successful, now your asset val is ")
    print(totalasset - commodityList[_choice]['price'])
