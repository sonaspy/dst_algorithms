# author - newguo@sonaspy.cn 
# coding - utf_8 

def fibonacci():
  a, b = 0, 1
  while True:
    yield a
    a, b = b, a+b
