# author - newguo@sonaspy.cn 
# coding - utf_8 
import os


def disk_usage(path):
    """Return the number of bytes used by a file/folder and any descendents."""
    total = os.path.getsize(path)
    if os.path.isdir(path):
        for filename in os.listdir(path):
            childPath = os.path.join(path, filename)
            total += disk_usage(childPath)
    print("{0:<7}".format(total), path)
    return total


print(disk_usage("../"))