











package dsa;

public class ComplBinTree_Vector extends BinTree_LinkedList implements ComplBinTree {
    private Vector T;


    public ComplBinTree_Vector() {
        T = new Vector_ExtArray();
        root = null;
    }


    public ComplBinTree_Vector(Sequence s) {
        this();
        if (null != s) while (!s.isEmpty()) addLast(s.removeFirst());
    }



    public BinTreePosition getRoot() {
        return T.isEmpty() ? null : posOfNode(0);
    }


    public boolean isEmpty() {
        return T.isEmpty();
    }


    public int getSize() {
        return T.getSize();
    }


    public int getHeight() {
        return isEmpty() ? -1 : getRoot().getHeight();
    }



    public BinTreePosition addLast(Object e) {
        BinTreePosition node = new ComplBinTreeNode_Rank(T, e);
        root = (BinTreePosition) T.getAtRank(0);
        return node;
    }


    public Object delLast() {
        if (isEmpty()) return null;
        if (1 == getSize()) root = null;
        return T.removeAtRank(T.getSize() - 1);
    }


    public BinTreePosition posOfNode(int i) {
        return (BinTreePosition)T.getAtRank(i);
    }
}
