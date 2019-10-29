import os
import re
import sys
import fileinput

fileList = os.listdir(r"../")
pat = "#include \"dst_.*\.hpp\""
# for fileName in fileList:
#     i = 1

for line in fileinput.input("../algo.hpp", backup='.bak', inplace=True):
    print(10)
