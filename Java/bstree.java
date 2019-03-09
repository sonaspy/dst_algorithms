












package dsa;

public class BSTree extends BinTree_LinkedList implements Dictionary {

    protected Comparator C;
    protected BinTreePosition lastV;


    public BSTree() {
        this(null, new ComparatorDefault());
    }

    public BSTree(BinTreePosition r) {
        this(r, new ComparatorDefault());
    }

    public BSTree(BinTreePosition r, Comparator c) {
        root = r;
        C = c;
    }



    public Entry find(Object key) {
        if (isEmpty()) return null;
        BSTreeNode u = binSearch((BSTreeNode)root, key, C);
        return (0 == C.compare(key, u.getKey())) ? (Entry)u.getElem() : null;
    }


    public Iterator findAll(Object key) {
        List s = new List_DLNode();
        finAllNodes((BSTreeNode)root, key, s, C);
        return s.elements();
    }



    public Entry insert(Object key, Object value) {
        Entry e = new EntryDefault(key, value);
        if (isEmpty()) {
            lastV = root = new BSTreeNode(e, null, true, null, null);
        } else {
            BSTreeNode p = (BSTreeNode)root;
            boolean asLeftChild;
            while(true) {
                p = binSearch(p, key, C);
                if (C.compare(key, p.getKey()) < 0) {
                    asLeftChild = true;
                    break;
                } else if (C.compare(key, p.getKey()) > 0) {
                    asLeftChild = false;
                    break;
                } else if (!p.hasLChild()) {
                    asLeftChild = true;
                    break;
                } else if (!p.hasRChild()) {
                    asLeftChild = false;
                    break;
                } else
                    p = (BSTreeNode)p.getLChild();
            }
            lastV = new BSTreeNode(e, p, asLeftChild, null, null);
        }
        return e;
    }



    public Entry remove(Object key) {
        if (isEmpty()) return null;
        BinTreePosition v = binSearch((BSTreeNode)root, key, C);
        if (0 != C.compare(key, ((BSTreeNode)v).getKey())) return null;
        if (v.hasLChild()) {
            BinTreePosition w = v.getPrev();
            w.setElem(v.setElem(w.getElem()));
            v = w;
        }
        lastV = v.getParent();
        BinTreePosition u = v.hasLChild() ? v.getLChild() : v.getRChild();
        if (null == lastV) {
            if (null != u) u.secede();
            root = u;
        } else {
            if (v.isLChild()) {
                v.secede();
                lastV.attachL(u);
            } else {
                v.secede();
                lastV.attachR(u);
            }
        }
        return (Entry) v.getElem();
    }


    public Iterator entries() {
        List list = new List_DLNode();
        concatenate(list, (BSTreeNode)root);
        return list.elements();
    }






    protected static BSTreeNode binSearch(BSTreeNode v, Object key, Comparator c) {
        BSTreeNode  u = v;
        while (true) {
            int comp = c.compare(key, u.getKey());
            if (comp < 0)
                if (u.hasLChild())
                    u = (BSTreeNode)u.getLChild();
                else
                    return u;
            else if (comp > 0)
                if (u.hasRChild())
                    u = (BSTreeNode)u.getRChild();
                else
                    return u;
            else
                return u;
        }
    }



    protected static void finAllNodes(BSTreeNode v, Object k, List s, Comparator c) {
        if (null == v) return;
        int comp = c.compare(k, v.getKey());
        if (0 >= comp) finAllNodes((BSTreeNode)v.getLChild(), k, s, c);
        if (0 == comp) s.insertLast(v);
        if (0 <= comp) finAllNodes((BSTreeNode)v.getRChild(), k, s, c);
    }


    protected static void concatenate(List list, BSTreeNode v) {
        if (null == v) return;
        concatenate(list, (BSTreeNode) v.getLChild());
        list.insertLast(v.getElem());
        concatenate(list, (BSTreeNode) v.getRChild());
    }
}