











package dsa;

public class PQueue_Heap implements PQueue {
    private ComplBinTree H;
    private Comparator comp;


    public PQueue_Heap() {
        this(new ComparatorDefault(), null);
    }


    public PQueue_Heap(Comparator c) {
        this(c, null);
    }


    public PQueue_Heap(Sequence S) {
        this(new ComparatorDefault(), S);
    }


    public PQueue_Heap(Comparator c, Sequence s) {
        comp = c;
        H = new ComplBinTree_Vector(s);
        if (!H.isEmpty()) {
            for (int i = H.getSize()  2 - 1; i >= 0; i--)
                percolateDown(H.posOfNode(i));
        }
    }



    public int getSize() {
        return H.getSize();
    }


    public boolean isEmpty() {
        return H.isEmpty();
    }


    public Entry getMin() throws ExceptionPQueueEmpty {
        if (isEmpty()) throw new ExceptionPQueueEmpty("���⣺���ȶ���Ϊ��");
        return (Entry) H.getRoot().getElem();
    }


    public Entry insert(Object key, Object obj) throws ExceptionKeyInvalid  {
        checkKey(key);
        Entry entry = new EntryDefault(key, obj);
        percolateUp(H.addLast(entry));
        return entry;
    }


    public Entry delMin() throws ExceptionPQueueEmpty  {
        if (isEmpty()) throw new ExceptionPQueueEmpty("���⣺���ȶ���Ϊ��");
        Entry min = (Entry)H.getRoot().getElem();
        if (1 == getSize())
            H.delLast();
        else {
            H.getRoot().setElem(((ComplBinTreeNode_Rank)H.delLast()).getElem());
            percolateDown(H.getRoot());
        }
        return min;
    }



    protected void checkKey(Object key) throws ExceptionKeyInvalid {
        try {
            comp.compare(key, key);
        } catch (Exception e) {
            throw new ExceptionKeyInvalid("�޷��ȽϹؼ���");
        }
    }


    protected Object key(BinTreePosition v) {
        return ((Entry)(v.getElem())).getKey();
    }



    protected void swapParentChild(BinTreePosition u, BinTreePosition v) {
        Object temp = u.getElem();
        u.setElem(v.getElem());
        v.setElem(temp);
    }


    protected void percolateUp(BinTreePosition v) {
        BinTreePosition root = H.getRoot();
        while (v != H.getRoot()) {
            BinTreePosition p = v.getParent();
            if (0 >= comp.compare(key(p), key(v))) break;
            swapParentChild(p, v);
            v = p;
        }
    }


    protected void percolateDown(BinTreePosition v) {
        while (v.hasLChild()) {
            BinTreePosition smallerChild = v.getLChild();
            if (v.hasRChild() && 0 < comp.compare(key(v.getLChild()), key(v.getRChild())))
                smallerChild = v.getRChild();
            if (0 <= comp.compare(key(smallerChild), key(v))) break;
            swapParentChild(v, smallerChild);
            v = smallerChild;
        }
    }
}