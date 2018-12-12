# author - newguo@sonaspy.cn 
# coding - utf_8 

import ctypes        # provides low-level arrays


class DynamicArray:
    """A dynamic array class akin to a simplified Python list."""
    def __init__(self):
        """Create an empty array."""
        self._curSize = 0
        self._capacity = 1
        self._A = self._make_array(self._capacity)
    
    def __len__(self):
        """Return number of elements stored in the array."""
        return self._curSize

    def __getitem__(self, k):
        """Return element at index k."""
        if not 0<= k <= self._curSize:
            raise IndexError("invalid Index!")
        return  self._A[k]
    
    def append(self, obj):
        """Add object to end of the array."""
        if self._curSize == self._capacity:
            self._resize()
        self._A[self._curSize] =obj
        self._curSize += 1

    def _resize(self):
        """Resize internal array to capacity c."""
        B = self._make_array()
        for k in range(self._curSize):
            B[k] = self._A[k]
        self._A = B
        self._capacity *= 2

    def _make_array(self):
        """Return new array with capacity c."""
        return (2 * self._capacity * ctypes.py_object)()

    def insert(self, k, value):
        """Insert value at index k, shifting subsequent values rightward."""
        # (for simplicity, we assume 0 <= k <= n in this verion)
        if self._curSize == self._capacity:
            self._resize()
        for j in range(k, self._curSize, -1):
            self._A[j+1] = self._A[j]
        self._A[k] = value
        self._curSize += 1

    def remove(self, value):
        """Remove first occurrence of value (or raise ValueError)."""
        # note: we do not consider shrinking the dynamic array in this version
        for k in range(self._curSize):
            if self._A[k] == value:
                for j in range(k, self._curSize - 1, -1):
                    self._A[j] = self._A[j+1]
                self._A[self._curSize-1] = None
                self._curSize -= 1
        raise ValueError("Not Found")
