











package dsa;

public class BinTreeNode implements BinTreePosition {
    protected Object element;
    protected BinTreePosition parent;
    protected BinTreePosition lChild;
    protected BinTreePosition rChild;
    protected   int size;
    protected int height;
    protected int depth;


    public BinTreeNode() {
        this(null, null, true, null, null);
    }

    public BinTreeNode(
        Object e,
        BinTreePosition p,
        boolean asLChild,
        BinTreePosition l,
        BinTreePosition r) {
        size = 1;
        height = depth = 0;
        parent = lChild = rChild = null;
        element = e;
        if (null != p)
            if (asLChild)  p.attachL(this);
            else              p.attachR(this);
        if (null != l) attachL(l);
        if (null != r) attachR(r);
    }



    public Object getElem() {
        return element;
    }


    public Object setElem(Object obj) {
        Object bak = element;
        element = obj;
        return bak;
    }



    public boolean hasParent() {
        return null != parent;
    }

    public BinTreePosition getParent() {
        return parent;
    }

    public void setParent(BinTreePosition p) {
        parent = p;
    }


    public boolean isLeaf() {
        return !hasLChild() && !hasRChild();
    }



    public boolean isLChild() {
        return (hasParent() && this == getParent().getLChild())  ? true : false;
    }


    public boolean hasLChild() {
        return null != lChild;
    }

    public BinTreePosition getLChild() {
        return lChild;
    }

    public void setLChild(BinTreePosition c) {
        lChild = c;
    }



    public boolean isRChild() {
        return (hasParent() && this == getParent().getRChild())  ? true : false;
    }

    public boolean hasRChild() {
        return null != rChild;
    }

    public BinTreePosition getRChild() {
        return rChild;
    }

    public void setRChild(BinTreePosition c) {
        rChild = c;
    }


    public int getSize() {
        return size;
    }

    public void updateSize() {
        size = 1;
        if (hasLChild())  size += getLChild().getSize();
        if (hasRChild())  size += getRChild().getSize();
        if (hasParent())  getParent().updateSize();
    }


    public int getHeight() {
        return height;
    }

    public void updateHeight() {
        height = 0;
        if (hasLChild())  height = Math.max(height, 1 + getLChild().getHeight());
        if (hasRChild())  height = Math.max(height, 1 + getRChild().getHeight());
        if (hasParent())  getParent().updateHeight();
    }


    public int getDepth() {
        return depth;
    }

    public void updateDepth() {
        depth = hasParent() ? 1 + getParent().getDepth() : 0;
        if (hasLChild())  getLChild().updateDepth();
        if (hasRChild())  getRChild().updateDepth();
    }


    public BinTreePosition getPrev() {
        if (hasLChild())  return findMaxDescendant(getLChild());
        if (isRChild())   return getParent();
        BinTreePosition v = this;
        while (v.isLChild()) v = v.getParent();
        return v.getParent();
    }


    public BinTreePosition getSucc() {
        if (hasRChild())  return findMinDescendant(getRChild());
        if (isLChild())   return getParent();
        BinTreePosition v = this;
        while (v.isRChild()) v = v.getParent();
        return v.getParent();
    }



    public BinTreePosition secede() {
        if (null != parent)  {
            if (isLChild())   parent.setLChild(null);
            else                 parent.setRChild(null);
            parent.updateSize();
            parent.updateHeight();
            parent = null;
            updateDepth();
        }
        return this;
    }


    public BinTreePosition attachL(BinTreePosition c) {
        if (hasLChild())  getLChild().secede();
        if (null != c) {
            c.secede();
            lChild = c;
            c.setParent(this);
            updateSize();
            updateHeight();
            c.updateDepth();
        }
        return this;
    }


    public BinTreePosition attachR(BinTreePosition c) {
        if (hasRChild())  getRChild().secede();
        if (null != c) {
            c.secede();
            rChild = c;
            c.setParent(this);
            updateSize();
            updateHeight();
            c.updateDepth();
        }
        return this;
    }


    public Iterator elementsPreorder() {
        List list = new List_DLNode();
        preorder(list, this);
        return list.elements();
    }


    public Iterator elementsInorder() {
        List list = new List_DLNode();
        inorder(list, this);
        return list.elements();
    }


    public Iterator elementsPostorder() {
        List list = new List_DLNode();
        postorder(list, this);
        return list.elements();
    }


    public Iterator elementsLevelorder() {
        List list = new List_DLNode();
        levelorder(list, this);
        return list.elements();
    }



    protected static BinTreePosition findMinDescendant(BinTreePosition v) {
        if (null != v)
            while (v.hasLChild())   v = v.getLChild();
        return v;
    }


    protected static BinTreePosition findMaxDescendant(BinTreePosition v) {
        if (null != v)
            while (v.hasRChild()) v = v.getRChild();
        return v;
    }


    protected static void preorder(List list, BinTreePosition v) {
        if (null == v) return;
        list.insertLast(v);
        preorder(list, v.getLChild());
        preorder(list, v.getRChild());
    }


    protected static void inorder(List list, BinTreePosition v) {
        if (null == v) return;
        inorder(list, v.getLChild());
        list.insertLast(v);
        inorder(list, v.getRChild());
    }


    protected static void postorder(List list, BinTreePosition v) {
        if (null == v) return;
        postorder(list, v.getLChild());
        postorder(list, v.getRChild());
        list.insertLast(v);
    }


    protected static void levelorder(List list, BinTreePosition v) {
        Queue_List  Q = new Queue_List();
        Q.enqueue(v);
        while (!Q.isEmpty()) {
            BinTreePosition u = (BinTreePosition) Q.dequeue();
            list.insertLast(u);
            if (u.hasLChild())   Q.enqueue(u.getLChild());
            if (u.hasRChild())   Q.enqueue(u.getRChild());
        }
    }
}