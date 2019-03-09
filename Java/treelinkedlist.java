











package dsa;

public class TreeLinkedList implements Tree {
    private Object element;
    private TreeLinkedList parent, firstChild, nextSibling;


    public TreeLinkedList() {
        this(null, null, null, null);
    }


    public TreeLinkedList(Object e, TreeLinkedList p, TreeLinkedList c, TreeLinkedList s) {
        element = e;
        parent = p;
        firstChild = c;
        nextSibling = s;
    }



    public Object getElem() {
        return element;
    }



    public Object setElem(Object obj) {
        Object bak = element;
        element = obj;
        return bak;
    }


    public TreeLinkedList getParent() {
        return parent;
    }


    public TreeLinkedList getFirstChild() {
        return firstChild;
    }


    public TreeLinkedList getNextSibling() {
        return nextSibling;
    }


    public int getSize() {
        int   size = 1;
        TreeLinkedList subtree = firstChild;
        while (null != subtree) {
            size += subtree.getSize();
            subtree = subtree.getNextSibling();
        }
        return size;
    }


    public int getHeight() {
        int   height = -1;
        TreeLinkedList subtree = firstChild;
        while (null != subtree) {
            height = Math.max(height, subtree.getHeight());
            subtree = subtree.getNextSibling();
        }
        return height + 1;
    }


    public int getDepth() {
        int   depth = 0;
        TreeLinkedList p = parent;
        while (null != p) {
            depth++;
            p = p.getParent();
        }
        return depth;
    }
}
