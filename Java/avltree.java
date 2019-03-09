
package dsa;

public class AVLTree extends BSTree implements Dictionary {

    public AVLTree() {
        super();
    }

    public AVLTree(BinTreePosition r) {
        super(r);
    }

    public AVLTree(BinTreePosition r, Comparator c) {
        super(r, c);
    }

    public Entry insert(Object key, Object value) {
        Entry e = super.insert(key, value);
        root = rebalance(lastV.getParent(), root);
        return e;
    }

    public Entry remove(Object key) {
        Entry e = super.remove(key);
        if (null != e)
            root = rebalance(lastV, root);
        return e;
    }

    protected static BinTreePosition rebalance(BinTreePosition z, BinTreePosition r) {
        if (null == z)
            return r;
        while (true) {
            if (!isBalanced(z))
                rotate(z);
            if (!z.hasParent())
                return z;
            z = z.getParent();
        }
    }

    protected static boolean isBalanced(BinTreePosition v) {
        if (null == v)
            return true;
        int lH = (v.hasLChild()) ? (v.getLChild().getHeight()) : -1;
        int rH = (v.hasRChild()) ? (v.getRChild().getHeight()) : -1;
        int deltaH = lH - rH;
        return (-1 <= deltaH) && (deltaH <= 1);
    }

    public static BinTreePosition rotate(BinTreePosition z) {
        BinTreePosition y = tallerChild(z);
        BinTreePosition x = tallerChild(y);
        boolean cType = z.isLChild();
        BinTreePosition p = z.getParent();
        BinTreePosition a, b, c;
        BinTreePosition t0, t1, t2, t3;
        if (y.isLChild()) {
            c = z;
            t3 = z.getRChild();
            if (x.isLChild()) {
                b = y;
                t2 = y.getRChild();
                a = x;
                t1 = x.getRChild();
                t0 = (BSTreeNode) x.getLChild();
            } else {
                a = y;
                t0 = y.getLChild();
                b = x;
                t1 = x.getLChild();
                t2 = (BSTreeNode) x.getRChild();
            }
        } else {
            a = z;
            t0 = z.getLChild();
            if (x.isRChild()) {
                b = y;
                t1 = y.getLChild();
                c = x;
                t2 = x.getLChild();
                t3 = (BSTreeNode) x.getRChild();
            } else {
                c = y;
                t3 = y.getRChild();
                b = x;
                t1 = x.getLChild();
                t2 = (BSTreeNode) x.getRChild();
            }
        }
        z.secede();
        y.secede();
        x.secede();
        if (null != t0)
            t0.secede();
        if (null != t1)
            t1.secede();
        if (null != t2)
            t2.secede();
        if (null != t3)
            t3.secede();
        a.attachL(t0);
        a.attachR(t1);
        b.attachL(a);
        c.attachL(t2);
        c.attachR(t3);
        b.attachR(c);
        if (null != p)
            if (cType)
                p.attachL(b);
            else
                p.attachR(b);
        return b;
    }

    protected static BinTreePosition tallerChild(BinTreePosition v) {
        int lH = v.hasLChild() ? v.getLChild().getHeight() : -1;
        int rH = v.hasRChild() ? v.getRChild().getHeight() : -1;
        if (lH > rH)
            return v.getLChild();
        if (lH < rH)
            return v.getRChild();
        if (v.isLChild())
            return v.getLChild();
        else
            return v.getRChild();
    }

    protected static BinTreePosition shorterChild(BinTreePosition v) {
        int lH = v.hasLChild() ? v.getLChild().getHeight() : -1;
        int rH = v.hasRChild() ? v.getRChild().getHeight() : -1;
        if (lH > rH)
            return v.getRChild();
        if (lH < rH)
            return v.getLChild();
        if (v.isLChild())
            return v.getRChild();
        else
            return v.getLChild();
    }
}
