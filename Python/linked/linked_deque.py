# author - newguo@sonaspy.cn 
# coding - utf_8 
import sys
sys.path.append("../")
from doubly_linked_base import _DoublyLinkedBase
from myExceptions import Empty


class LinkedDeque(_DoublyLinkedBase):         # note the use of inheritance
    """Double-ended queue implementation based on a doubly linked list."""

    def first(self):
        """
        Return (but do not remove) the element at the front of the deque.
        Raise Empty exception if the deque is empty.
        """
        if self.is_empty():
            raise Empty("Deque is empty")
        return self._header._next._element

    def last(self):
        """
        Return (but do not remove) the element at the back of the deque.
        Raise Empty exception if the deque is empty.
        """
        if self.is_empty():
            raise Empty("Deque is empty")
        return self._trailer._prev._element

    def insert_first(self, e):
        """Add an element to the front of the deque."""
        self._insert_between(e, self._header, self._header._next)
    
    def insert_last(self, e):
        """Add an element to the back of the deque."""
        self._insert_between(e, self._tailer._prev, self._tailer)
    
    def delete_first(self):
        """
        Remove and return the element from the front of the deque.
        Raise Empty exception if the deque is empty.
        """
        if self.is_empty():
            raise Empty("Deque is empty")
        return self._delete_node(self._header._next)

    def delete_last(self):
        """
        Remove and return the element from the back of the deque.
        Raise Empty exception if the deque is empty.
        """
        if self.is_empty():
            raise Empty("Deque is empty")
        return self._delete_node(self._tailer._prev)
