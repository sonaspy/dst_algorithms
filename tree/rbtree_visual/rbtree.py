import collections


class Node:
    """A Red-Black-Tree node"""

    def __init__(self, key):
        self.left = None
        self.right = None
        self.parent = None
        self.key = key
        self.color = 'r'


class RBTree:
    """A Red-Black-Tree"""

    def __init__(self, *args):
        self.root = None

        if len(args) == 1:
            if isinstance(args[0], collections.Iterable):
                for x in args[0]:
                    self.insert(x)
            else:
                raise TypeError(str(args[0]) + " is not iterable")

    def get_node(self, key, *args):
        """Returns a node by key. Second optional param is a node to start searching from"""

        if len(args) == 0:
            start = self.root
        else:
            start = args[0]

        if not start:
            return None
        if key == start.key:
            return start
        elif key > start.key:
            return self.get_node(key, start.right)
        else:
            return self.get_node(key, start.left)

    def get_path(self, node):
        """Returns a path-list of keys from root to taken node"""

        curr = node
        lst = [curr.key]
        while curr.parent is not None:
            curr = curr.parent
            lst.append(curr.key)

        return reversed(lst)

    def insert(self, key, *args):
        """Insert a node with key"""

        if not isinstance(key, int):
            raise TypeError(str(key) + " is not an int")
        else:
            if not self.root:
                self.root = Node(key)
                self.root.color = 'k'
            elif len(args) == 0:
                if not self.get_node(key):
                    self.insert(key, self.root)
            else:
                child = Node(key)
                parent = args[0]
                if child.key > parent.key:
                    if not parent.right:
                        parent.right = child
                        child.parent = parent
                        if parent.color == 'r':
                            self._insert_case_one(child)
                    else:
                        self.insert(key, parent.right)
                else:
                    if not parent.left:
                        parent.left = child
                        child.parent = parent
                        if parent.color == 'r':
                            self._insert_case_one(child)
                    else:
                        self.insert(key, parent.left)

    def _insert_case_one(self, child):
        """
        if child is at the root, recolors it black,
        else goes into the second case
        """
        if not child.parent:
            self.root.color = 'k'
        else:
            self._insert_case_two(child)

    def _insert_case_two(self, child):
        """
        If child's parent is black - ok,
        else goes into the third case
        """
        if child.parent.color == 'r':
            self._insert_case_three(child)

    def _insert_case_three(self, child):
        """
        If child's parent and uncle are red, recolors the parent and the uncle black
        and child's grandpa red
        Then start with the first case on grandpa to validate the tree (grandgrandpa may be also red)
        Otherwise goes into the fourth case
        """

        parent = child.parent
        grand_node = parent.parent

        if grand_node.left == parent:
            uncle = grand_node.right
        else:
            uncle = grand_node.left

        if uncle and uncle.color == 'r':
            grand_node.color = 'r'
            parent.color = 'k'
            uncle.color = 'k'
            self._insert_case_one(grand_node)
        else:
            self._insert_case_four(child)

    def _insert_case_four(self, child):
        """
        If child's parent is red and child's uncle is black
        and parent is a left child of the grandpa,
        the child is the right child of the parent or vice versa
        makes tree rotations around parent and goes into the fifth child
        """
        parent = child.parent
        grand_node = parent.parent
        if grand_node.left == parent:
            uncle = grand_node.right
        else:
            uncle = grand_node.left

        if grand_node.left == parent and parent.right == child:
            self._rotate_left(parent)
            child = child.left
        elif grand_node.right == parent and parent.left == child:
            self._rotate_right(parent)
            child = child.right

        self._insert_case_five(child)

    def _insert_case_five(self, child):
        """
        If child's parent is red and uncle is black and the parent
        is the left child of the grandpa and the child is the left child of the parent,
        or vice versa
        makes tree rotations around the grandpa
        """
        parent = child.parent
        grand_node = parent.parent
        if grand_node.left == parent:
            uncle = grand_node.right
        else:
            uncle = grand_node.left

        if parent.left == child:
            grand_node.color = 'r'
            parent.color = 'k'
            self._rotate_right(grand_node)
        elif parent.right == child:
            grand_node.color = 'r'
            parent.color = 'k'
            self._rotate_left(grand_node)

    def _rotate_left(self, pivot):
        """
        left tree rotations around pivot
        """
        old_root = pivot
        parent = old_root.parent

        new_root = old_root.right
        temp = new_root.right
        old_root.right = new_root.left

        if old_root.right:
            old_root.right.parent = old_root
        new_root.left = old_root
        old_root.parent = new_root

        if parent is None:
            self.root = new_root
            self.root.parent = None
        else:
            if parent.right and parent.right.key == old_root.key:
                parent.right = new_root
                new_root.parent = parent
            elif parent.left and parent.left.key == old_root.key:
                parent.left = new_root
                new_root.parent = parent

    def _rotate_right(self, pivot):
        """
        right tree rotation around pivot
        """
        if not pivot.left:
            pass
        else:
            old_root = pivot
            parent = old_root.parent

            new_root = old_root.left
            temp = new_root.left
            old_root.left = new_root.right

            if (old_root.left):
                old_root.left.parent = old_root

            new_root.right = old_root
            old_root.parent = new_root

            if parent is None:
                self.root = new_root
                self.root.parent = None
            else:
                if parent.right and parent.right.key == old_root.key:
                    parent.right = new_root
                    new_root.parent = parent
                elif parent.left and parent.left.key == old_root.key:
                    parent.left = new_root
                    new_root.parent = parent

    # def get_element_count(self, *args):
    #     """
    #     Counts the number of elements in a tree
    #     """
    #     if len(args) == 0:
    #         node = self.root
    #     else:
    #         node = args[0]
    #
    #     left = 0
    #     right = 0
    #
    #     if node:
    #         if node.left:
    #             left = self.get_element_count(node.left)
    #         if node.right:
    #             right = self.get_element_count(node.right)
    #
    #         return 1 + left + right
    #     else:
    #         return 0

    def delete(self, key):
        node = self.get_node(key, self.root)
        if node:
            if node == self.root:
                self.root = None
            elif not (node.left or node.right):
                if node.parent:
                    self._delete_leaf(node)

            elif not (node.left and node.right):
                self._delete_leaf_parent(node)

            else:
                self._delete_node(node)

    def _delete_node(self, node):
        if self.get_height(node.left) > self.get_height(node.right):
            to_switch = self.get_max(node.left)
            self._switch_nodes(node, to_switch)

            if not (to_switch.right or to_switch.left):
                to_delete = self.get_max(node.left)
                self._delete_leaf(to_delete)
            else:
                to_delete = self.get_max(node.left)
                self._delete_leaf_parent(to_delete)
        else:
            to_switch = self.get_min(node.right)
            self._switch_nodes(node, to_switch)

            if not (to_switch.right or to_switch.left):
                to_delete = self.get_min(node.right)
                self._delete_leaf(to_delete)
            else:
                to_delete = self.get_min(node.right)
                self._delete_leaf_parent(to_delete)

    def get_height(self, *args):
        if len(args) == 0:
            node = self.root
        else:
            node = args[0]

        if not node or (not node.left and not node.right):
            return 0
        else:
            return 1 + max(self.get_height(node.left), self.get_height(node.right))

    def get_max(self, *args):
        if len(args) == 0:
            node = self.root
        else:
            node = args[0]

        if not node.right:
            return node
        else:
            return self.get_max(node.right)

    def get_min(self, *args):
        if len(args) == 0:
            node = self.root
        else:
            node = args[0]

        if not node.left:
            return node
        else:
            return self.get_min(node.left)

    def _switch_nodes(self, node1, node2):
        switch1 = node1
        switch2 = node2
        temp_key = switch1.key

        if switch1.key == self.root.key:
            self.root.key = node2.key
            switch2.key = temp_key

        elif switch2.key == self.root.key:
            switch1.key = self.root.key
            self.root.key = temp_key
        else:
            switch1.key = node2.key
            switch2.key = temp_key

    def _delete_leaf_parent(self, node):
        par_node = node.parent
        node_color = node.color
        if node.left:
            child_color = node.left.color
        else:
            child_color = node.right.color

        if node.key == self.root.key:
            if node.right:
                self.root = node.right
                self.root.color = 'k'
                node.right = None
                new_node = node.right
            else:
                self.root = node.left
                self.root.color = 'k'
                node.left = None
                new_node = node.left

        else:
            if par_node.right == node:
                if node.right:
                    par_node.right = node.right
                    par_node.right.parent = par_node
                    node.right = None
                    if node_color == 'k' and child_color == 'r':
                        par_node.right.color = 'k'

                else:
                    par_node.right = node.left
                    par_node.right.parent = par_node
                    node.left = None
                    if node_color == 'k' and child_color == 'r':
                        par_node.right.color = 'k'

                new_node = par_node.right

            else:

                if node.right:
                    par_node.left = node.right
                    par_node.left.parent = par_node
                    node.right = None
                    if node_color == 'k' and child_color == 'r':
                        par_node.left.color = 'k'
                else:
                    par_node.left = node.left
                    par_node.left.parent = par_node
                    node.left = None
                    if node_color == 'k' and child_color == 'r':
                        par_node.left.color = 'k'

                new_node = par_node.left

        del node

        if node_color == 'k' and child_color == 'k':
            self._delete_case_one(new_node, par_node)

    def _delete_leaf(self, node):
        par_node = node.parent
        node_color = node.color
        new_node = None

        if par_node:
            if par_node.left == node:
                par_node.left = None
                new_node = None
            else:
                par_node.right = None
                new_node = None

            del node

        new_parent = par_node

        if node_color == 'k':
            self._delete_case_one(new_node, new_parent)

    def _delete_case_one(self, child, parent):
        if parent:
            self._delete_case_two(child, parent)

    def _delete_case_two(self, child, parent):
        node = child
        par_node = parent
        sib_node = None

        if par_node.left == node:
            sib_node = par_node.right
        elif par_node.right == node:
            sib_node = par_node.left

        if sib_node and sib_node.color == 'r':
            sib_node.color = 'k'
            par_node.color = 'r'
            if par_node.left == node:
                self._rotate_left(par_node)
            else:
                self._rotate_right(par_node)

        self._delete_case_three(node, par_node)

    def _delete_case_three(self, child, parent):
        node = child
        par_node = parent
        sib_node = None

        if par_node.left == node:
            sib_node = par_node.right
        elif par_node.right == node:
            sib_node = par_node.left

        if (sib_node and sib_node.color == 'k') or (not sib_node):
            sib_color = 'k'
        else:
            sib_color = 'r'

        if (sib_node and sib_node.left and sib_node.left.color == 'k') or (not sib_node or not sib_node.left):
            sib_left_color = 'k'
        else:
            sib_left_color = 'r'

        if (sib_node and sib_node.right and sib_node.right.color == 'k') or (not sib_node or not sib_node.right):
            sib_right_color = 'k'
        else:
            sib_right_color = 'r'

        if par_node.color == 'k' and sib_color == 'k' and sib_left_color == 'k' and sib_right_color == 'k':
            if sib_node:
                sib_node.color = 'r'
            self._delete_case_one(
                par_node, par_node.parent if par_node.parent else None)
        else:
            self._delete_case_four(node, par_node)

    def _delete_case_four(self, child, parent):
        node = child
        par_node = parent
        sib_node = None

        if par_node.left == node:
            sib_node = par_node.right
        elif par_node.right == node:
            sib_node = par_node.left

        if (sib_node and sib_node.color == 'k') or (not sib_node):
            sib_color = 'k'
        else:
            sib_color = 'r'

        if (sib_node and sib_node.left and sib_node.left.color == 'k') or (not sib_node or not sib_node.left):
            sib_left_color = 'k'
        else:
            sib_left_color = 'r'

        if ((sib_node and sib_node.right and sib_node.right.color == 'k') or (not sib_node or not sib_node.right)):
            sib_right_color = 'k'
        else:
            sib_right_color = 'r'

        if par_node.color == 'r' and sib_color == 'k' and sib_left_color == 'k' and sib_right_color == 'k':
            sib_node.color = 'r'
            par_node.color = 'k'
        else:
            self._delete_case_five(node, par_node)

    def _delete_case_five(self, child, parent):
        node = child
        par_node = parent
        sib_node = None

        if par_node.left == node:
            sib_node = par_node.right
        elif par_node.right == node:
            sib_node = par_node.left

        if (sib_node and sib_node.color == 'k') or (not sib_node):
            sib_color = 'k'
        else:
            sib_color = 'r'

        if (sib_node and sib_node.left and sib_node.left.color == 'k') or (not sib_node or not sib_node.left):
            sib_left_color = 'k'
        else:
            sib_left_color = 'r'

        if (sib_node and sib_node.right and sib_node.right.color == 'k') or (not sib_node or not sib_node.right):
            sib_right_color = 'k'
        else:
            sib_right_color = 'r'

        if sib_color == 'k':

            if par_node.left == node and sib_right_color == 'k' and sib_left_color == 'r':
                sib_node.color = 'r'
                sib_node.left.color = 'k'
                self._rotate_right(sib_node)
            elif par_node.right == node and sib_left_color == 'k' and sib_right_color == 'r':
                sib_node.color = 'r'
                sib_node.right.color = 'k'
                self._rotate_left(sib_node)

        self._delete_case_six(node, par_node)

    def _delete_case_six(self, child, parent):
        node = child
        par_node = parent
        sib_node = None

        if par_node.left == node:
            sib_node = par_node.right
        elif par_node.right == node:
            sib_node = par_node.left

        if (sib_node and sib_node.color == 'k') or (not sib_node):
            sib_color = 'k'
        else:
            sib_color = 'r'

        if (sib_node and sib_node.left and sib_node.left.color == 'k') or (not sib_node or not sib_node.left):
            sib_left_color = 'k'
        else:
            sib_left_color = 'r'

        if (sib_node and sib_node.right and sib_node.right.color == 'k') or (not sib_node or not sib_node.right):
            sib_right_color = 'k'
        else:
            sib_right_color = 'r'

        if par_node.left == node and sib_color == 'k' and sib_right_color == 'r':
            sib_node.color = par_node.color
            par_node.color = 'k'
            sib_node.right.color = 'k'
            self._rotate_left(par_node)
        elif par_node.right == node and sib_color == 'k' and sib_left_color == 'r':
            sib_node.color = par_node.color
            par_node.color = 'k'
            sib_node.left.color = 'k'
            self._rotate_right(par_node)
