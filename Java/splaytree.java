












package dsa;

public class SplayTree extends BSTree implements Dictionary {

    public SplayTree() {
        super();
    }
    public SplayTree(BinTreePosition r) {
        super(r);
    }
    public SplayTree(BinTreePosition r, Comparator c) {
        super(r, c);
    }



    public Entry find(Object key) {
        if (isEmpty()) return null;
        BSTreeNode u = binSearch((BSTreeNode)root, key, C);
        root = moveToRoot(u);
        return (0 == C.compare(key, u.getKey())) ? (Entry)u.getElem() : null;
    }


    public Entry insert(Object key, Object value) {
        Entry e = super.insert(key, value);
        root = moveToRoot(lastV);
        return e;
    }


    public Entry remove(Object key) {
        Entry e = super.remove(key);
        if (null != e && null != lastV)  root = moveToRoot(lastV);
        return e;
    }



    protected static BinTreePosition moveToRoot(BinTreePosition z) {
        while (z.hasParent())
            if (!z.getParent().hasParent())
                if (z.isLChild()) z = zig(z);
                else                    z = zag(z);
            else if (z.isLChild())
                if (z.getParent().isLChild()) z = zigzig(z);
                else                                      z = zigzag(z);
            else if (z.getParent().isLChild()) z = zagzig(z);
            else                                      z = zagzag(z);
        return z;
    }




    protected static BinTreePosition zig(BinTreePosition v) {
        if (null != v && v.isLChild()) {
            BinTreePosition p = v.getParent();
            BinTreePosition g = p.getParent();
            boolean asLChild = p.isLChild();
            v.secede();
            BinTreePosition c = v.getRChild();
            if (null != c) p.attachL(c.secede());
            p.secede();
            v.attachR(p);
            if (null != g)
                if (asLChild)  g.attachL(v);
                else              g.attachR(v);
        }
        return v;
    }




    protected static BinTreePosition zag(BinTreePosition v) {
        if (null != v && v.isRChild()) {
            BinTreePosition p = v.getParent();
            BinTreePosition g = p.getParent();
            boolean asLChild = p.isLChild();
            v.secede();
            BinTreePosition c = v.getLChild();
            if (null != c) p.attachR(c.secede());
            p.secede();
            v.attachL(p);
            if (null != g)
                if (asLChild)  g.attachL(v);
                else              g.attachR(v);
        }
        return v;
    }




    protected static BinTreePosition zigzig(BinTreePosition v) {
        if (null != v && v.isLChild() && v.hasParent() && v.getParent().isLChild()) {
            BinTreePosition p = v.getParent();
            BinTreePosition g = p.getParent();
            BinTreePosition s = g.getParent();
            boolean asLChild = g.isLChild();
            g.secede();
            p.secede();
            v.secede();
            BinTreePosition c;
            c = p.getRChild();
            if (null != c)   g.attachL(c.secede());
            c = v.getRChild();
            if (null != c)   p.attachL(c.secede());
            p.attachR(g);
            v.attachR(p);
            if (null != s)
                if (asLChild)  s.attachL(v);
                else              s.attachR(v);
        }
        return v;
    }




    protected static BinTreePosition zagzag(BinTreePosition v) {
        if (null != v && v.isRChild() && v.hasParent() && v.getParent().isRChild()) {
            BinTreePosition p = v.getParent();
            BinTreePosition g = p.getParent();
            BinTreePosition s = g.getParent();
            boolean asLChild = g.isLChild();
            g.secede();
            p.secede();
            v.secede();
            BinTreePosition c;
            c = p.getLChild();
            if (null != c)   g.attachR(c.secede());
            c = v.getLChild();
            if (null != c)   p.attachR(c.secede());
            p.attachL(g);
            v.attachL(p);
            if (null != s)
                if (asLChild)  s.attachL(v);
                else              s.attachR(v);
        }
        return v;
    }




    protected static BinTreePosition zigzag(BinTreePosition v) {
        if (null != v && v.isLChild() && v.hasParent() && v.getParent().isRChild()) {
            BinTreePosition p = v.getParent();
            BinTreePosition g = p.getParent();
            BinTreePosition s = g.getParent();
            boolean asLChild = g.isLChild();
            g.secede();
            p.secede();
            v.secede();
            BinTreePosition c;
            c = v.getLChild();
            if (null != c)   g.attachR(c.secede());
            c = v.getRChild();
            if (null != c)   p.attachL(c.secede());
            v.attachL(g);
            v.attachR(p);
            if (null != s)
                if (asLChild)  s.attachL(v);
                else              s.attachR(v);
        }
        return v;
    }




    protected static BinTreePosition zagzig(BinTreePosition v) {
        if (null != v && v.isRChild() && v.hasParent() && v.getParent().isLChild()) {
            BinTreePosition p = v.getParent();
            BinTreePosition g = p.getParent();
            BinTreePosition s = g.getParent();
            boolean asLChild = g.isLChild();
            g.secede();
            p.secede();
            v.secede();
            BinTreePosition c;
            c = v.getRChild();
            if (null != c)   g.attachL(c.secede());
            c = v.getLChild();
            if (null != c)   p.attachR(c.secede());
            v.attachR(g);
            v.attachL(p);
            if (null != s)
                if (asLChild)  s.attachL(v);
                else              s.attachR(v);
        }
        return v;
    }
}