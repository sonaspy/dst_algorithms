











package dsa;

public class ComplBinTreeNode_Rank extends BinTreeNode implements BinTreePosition {
    private Vector T;
    private int rank;
    private Object element;


    public ComplBinTreeNode_Rank (Vector t, Object obj) {
        element = obj;
        T = t;
        rank = T.getSize();
        T.insertAtRank(rank, this);
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
        return (0 != rank) ? true : false;
    }

    public BinTreePosition getParent() {
        return hasParent() ? (BinTreePosition) T.getAtRank((rank - 1)  2) : null;
    }


    public boolean hasLChild() {
        return (1 + rank
        public BinTreePosition getLChild() {
            return hasLChild() ? (BinTreePosition) (T.getAtRank(1 + rank
            public boolean hasRChild() {
                return (2 + rank
                public BinTreePosition getRChild() {
                    return hasRChild() ? (BinTreePosition) (T.getAtRank(2 + rank
                    public int getSize() {
                        int   size = 1;
                        if (hasLChild())  size += getLChild().getSize();
                        if (hasRChild())  size += getRChild().getSize();
                        return size;
                    }
                    public int getHeight()  {
                        int hL = hasLChild() ? getLChild().getHeight() : -1;
                        int hR = hasRChild() ? getRChild().getHeight() : -1;
                        return 1 + Math.max(hL, hR);
                    }
                    public int getDepth()   {
                        return hasParent() ? 1 + getParent().getDepth() : 0;
                    }
                }