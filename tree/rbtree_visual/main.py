import sys
import pickle
import networkx as nx
import time
from rbtree import RBTree
from PyQt5 import QtWidgets
import random

from matplotlib.backends.backend_qt5agg import FigureCanvasQTAgg as FigureCanvas
from matplotlib.figure import Figure


class Window(QtWidgets.QDialog):

    def __init__(self, parent=None):
        super(Window, self).__init__(parent)
        self._init_tree_drawer()
        self._init_ui(self.tree_drawer.canvas)

    def _center(self):
        qr = self.frameGeometry()
        cp = QtWidgets.QDesktopWidget().availableGeometry().center()
        qr.moveCenter(cp)
        self.move(qr.topLeft())

    def _init_ui(self, canvas):
        self.setWindowTitle('Red-Black Tree | Alex Pulich, P3417')

        # controls
        # tree managing group
        tree_mng_groupbox = QtWidgets.QGroupBox("Tree managing")
        tree_mng_layout = QtWidgets.QHBoxLayout()

        key_label = QtWidgets.QLabel('Key:')
        self.key_input = QtWidgets.QLineEdit()
        self.add_btn = QtWidgets.QPushButton('Add')
        self.remove_btn = QtWidgets.QPushButton('Remove')
        self.search_btn = QtWidgets.QPushButton('Search')
        self.gen_btn = QtWidgets.QPushButton('Gen')
        self.timer_label = QtWidgets.QLabel('Search time: XXX sec')

        self.add_btn.clicked.connect(self._add_btn_handler)
        self.remove_btn.clicked.connect(self._remove_btn_handler)
        self.search_btn.clicked.connect(self._search_btn_handler)
        self.gen_btn.clicked.connect(self._gen_btn_handler)

        tree_mng_layout.addWidget(key_label)
        tree_mng_layout.addWidget(self.key_input)
        tree_mng_layout.addWidget(self.add_btn)
        tree_mng_layout.addWidget(self.remove_btn)
        tree_mng_layout.addWidget(self.search_btn)
        tree_mng_layout.addWidget(self.gen_btn)
        tree_mng_layout.addWidget(self.timer_label)

        tree_mng_groupbox.setLayout(tree_mng_layout)

        # import/export group
        io_groupbox = QtWidgets.QGroupBox("Export/Import")
        io_layout = QtWidgets.QHBoxLayout()

        self.export_btn = QtWidgets.QPushButton('Export')
        self.import_btn = QtWidgets.QPushButton('Import')

        io_layout.addWidget(self.export_btn)
        io_layout.addWidget(self.import_btn)

        self.import_btn.clicked.connect(self._import_btn_handler)
        self.export_btn.clicked.connect(self._export_btn_handler)

        io_groupbox.setLayout(io_layout)

        # set the main layout
        layout = QtWidgets.QVBoxLayout()
        # layout.addWidget(self.toolbar)
        layout.addWidget(canvas)
        controls_layout = QtWidgets.QHBoxLayout()
        controls_layout.addWidget(tree_mng_groupbox)
        controls_layout.addWidget(io_groupbox)
        layout.addLayout(controls_layout)
        self.setLayout(layout)
        self._center()

    def _init_tree_drawer(self):
        self.tree_drawer = TreeDrawer()

    def _add_btn_handler(self):
        if len(self.key_input.text()) == 0:
            return
        try:
            key = int(self.key_input.text())
            self.tree_drawer.insert(key)
            self.key_input.clear()
        except ValueError:
            self._show_error('Int expected', 'The key should be a number!')

    def _remove_btn_handler(self):
        if len(self.key_input.text()) == 0:
            return
        try:
            key = int(self.key_input.text())
            self.tree_drawer.remove(key)
            self.key_input.clear()
        except ValueError:
            self._show_error('Int expected', 'The key should be a number!')

    def _search_btn_handler(self):
        if len(self.key_input.text()) == 0:
            return

        key = None
        try:
            key = int(self.key_input.text())
            start_time = time.time()
            self.tree_drawer.search(key)
            exec_time = time.time() - start_time
            self.key_input.clear()
            self.timer_label.setText('Search time: %f sec' % exec_time)
        except ValueError:
            self._show_error('Int expected', 'The key should be a number!')

    def _gen_btn_handler(self):
        if len(self.key_input.text()) == 0:
            return

        key = None
        try:
            key = int(self.key_input.text())
            elems = []
            for i in range(0, key):
                elems.append(random.randint(0, 1000000))
            self.tree_drawer.tree = RBTree(elems)
            self.tree_drawer.plot()
        except ValueError:
            self._show_error('Int expected', 'The key should be a number!')

    def _export_btn_handler(self):
        fname = QtWidgets.QFileDialog.getSaveFileName(self, 'Export RBTree', 'mytree.rbtree',
                                                      'Red-Black Tree files (*.rbtree)')[0]
        if fname:
            with open(fname, 'wb') as f:
                pickle.dump(self.tree_drawer.tree, f)

    def _import_btn_handler(self):
        fname = QtWidgets.QFileDialog.getOpenFileName(self, 'Import RBTree', '',
                                                      'Red-Black Tree files (*.rbtree)')[0]
        if fname:
            with open(fname, 'rb') as f:
                self.tree_drawer.tree = pickle.load(f)
            self.tree_drawer.plot()

    def _show_error(self, title, message):
        msg = QtWidgets.QMessageBox()
        msg.setIcon(QtWidgets.QMessageBox.Critical)
        msg.setWindowTitle(title)
        msg.setText(message)
        msg.setStandardButtons(QtWidgets.QMessageBox.Ok)
        msg.exec_()
        self.key_input.clear()


class TreeDrawer:

    def __init__(self):
        self.tree = RBTree()
        self.figure = Figure()
        self.canvas = FigureCanvas(self.figure)

        pass

    def insert(self, key):
        self.tree.insert(key)
        self.plot()

    def remove(self, key):
        self.tree.delete(key)
        self.plot()

    def search(self, key):
        node = self.tree.get_node(key)
        if node:
            node_path = self.tree.get_path(node)
            self.plot(self._color_search_path(node_path))

    def plot(self, search_colors=None):
        self.figure.clear()
        ax = self.figure.add_subplot(111)
        ax.clear()

        if self.tree.root:

            g = nx.Graph()

            pos = self._get_pos_list(self.tree)
            nodes = [x.key for x in self._preorder(self.tree)]
            edges = self._get_edge_list(self.tree)
            labels = {x: x for x in nodes}
            if search_colors is None:
                colors = []
                try:
                    colors = self._get_color_list(self.tree)
                except AttributeError:
                    pass
            else:
                colors = search_colors

            g.add_nodes_from(nodes)
            g.add_edges_from(edges)

            max_len = len(str(self.tree.get_max().key))
            size = max_len * 200
            if len(colors) > 0:
                nx.draw_networkx_nodes(
                    g, pos, node_size=size, node_color=colors, ax=ax)
                nx.draw_networkx_edges(g, pos, ax=ax)
                nx.draw_networkx_labels(
                    g, pos, labels, font_color='w', ax=ax, font_size=8)
            else:
                nx.draw_networkx_nodes(
                    g, pos, node_size=size, node_color='r', ax=ax)
                nx.draw_networkx_edges(g, pos, ax=ax)
                nx.draw_networkx_labels(g, pos, labels, ax=ax, font_size=8)

        ax.axis('off')

        self.canvas.draw()

    def _color_search_path(self, path):
        nodes = [x.key for x in self._preorder(self.tree)]
        colors = self._get_color_list(self.tree)
        for p in path:
            try:
                pos = nodes.index(p)
                colors[pos] = 'g'
            except ValueError:
                pass
        return colors

    def _get_pos_list(self, tree):
        return self._get_pos_list_from(tree, tree.root, {}, (0, 0), 1.0)

    def _get_pos_list_from(self, tree, node, poslst, coords, gap):
        positions = poslst

        if node and node.key == tree.root.key:
            positions[node.key] = (0, 0)
            positions = self._get_pos_list_from(
                tree, tree.root.left, positions, (0, 0), gap)
            positions = self._get_pos_list_from(
                tree, tree.root.right, positions, (0, 0), gap)
            return positions
        elif node:
            if node.parent.right and node.parent.right.key == node.key:
                new_coords = (coords[0] + gap, coords[1] - 1)
                positions[node.key] = new_coords
            else:
                new_coords = (coords[0] - gap, coords[1] - 1)
                positions[node.key] = new_coords

            positions = self._get_pos_list_from(
                tree, node.left, positions, new_coords, gap / 2)
            positions = self._get_pos_list_from(
                tree, node.right, positions, new_coords, gap / 2)
            return positions
        else:
            return positions

    def _get_edge_list(self, tree):
        return self._get_edge_list_from(tree, tree.root, [])

    def _get_edge_list_from(self, tree, node, edgelst):
        edges = edgelst

        if node and node.key == tree.root.key:
            if node.left:
                edges.append((node.key, node.left.key))
                edges = self._get_edge_list_from(tree, node.left, edges)
            if node.right:
                edges.append((node.key, node.right.key))
                edges = self._get_edge_list_from(tree, node.right, edges)

            return edges

        elif node:
            if node.left:
                edges.append((node.key, node.left.key))
            if node.right:
                edges.append((node.key, node.right.key))

            edges = self._get_edge_list_from(tree, node.left, edges)
            edges = self._get_edge_list_from(tree, node.right, edges)
            return edges

        else:
            return edges

    def _preorder(self, tree, *args):
        if len(args) == 0:
            elements = []
            node = tree.root
        else:
            node = tree
            elements = args[0]

        elements.append(node)

        if node.left:
            self._preorder(node.left, elements)
        if node.right:
            self._preorder(node.right, elements)

        return elements

    def _get_color_list(self, tree):
        nodelist = self._preorder(tree)
        colorlist = []
        for node in nodelist:
            if node.color:
                colorlist.append(node.color)

        return colorlist


if __name__ == '__main__':
    app = QtWidgets.QApplication(sys.argv)

    main = Window()
    main.show()

    sys.exit(app.exec_())