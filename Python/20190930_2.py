# author - sonaspy@outlook.com
# coding - utf_8

from random import *

randomdatalist = []


def random_str(num):
    H = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789'
    salt = ''
    for i in range(num):
        salt += choice(H)
    return salt


for i in range(1000):
    newgood = dict()
    newgood["data1"] = random_str(randint(1, 10))
    newgood["data2"] = randint(100, 3000)
    randomdatalist.append(newgood)

page_id = int(input("Please input your desirable page id\n"))


for i in range(10):
    print(page_id, end=': ')
    print(randomdatalist[i])
    page_id += 1
