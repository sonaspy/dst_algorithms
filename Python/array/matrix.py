# author - newguo@sonaspy.cn 
# coding - utf_8 

matrix = [[0] * 10 for j in range(10)]
matrix[5][4] = 999

for j in range(10):
    print(matrix[j])