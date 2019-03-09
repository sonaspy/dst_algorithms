











package dsa;

public class PQueue_SortedList implements PQueue {
    private List L;
    private Comparator C;


    public PQueue_SortedList() {
        this(new ComparatorDefault(), null);
    }


    public PQueue_SortedList(Comparator c) {
        this(c, null);
    }


    public PQueue_SortedList(Sequence s) {
        this(new ComparatorDefault(), s);
    }


    public PQueue_SortedList(Comparator c, Sequence s) {
        L = new List_DLNode();
        C = c;
        if (null != s)
            while (!s.isEmpty()) {
                Entry e = (Entry)s.removeFirst();
                insert(e.getKey(), e.getValue());
            }
    }


    public int getSize() {
        return L.getSize();
    }


    public boolean isEmpty() {
        return L.isEmpty();
    }


    public Entry getMin() throws ExceptionPQueueEmpty {
        if (L.isEmpty())
            throw new ExceptionPQueueEmpty("���⣺���ȶ��п�");
        return (Entry) L.last();
    }


    public Entry insert(Object key, Object obj) throws ExceptionKeyInvalid {
        Entry entry = new EntryDefault(key, obj);
        if (L.isEmpty()
                || (0 > C.compare(((Entry) (L.first().getElem())).getKey(), entry.getKey())))
            L.insertFirst(entry);
        else {
            Position curPos = L.last();
            while (0 > C.compare(((Entry)(curPos.getElem())).getKey(), entry.getKey()))
                curPos = L.getPrev(curPos);
            L.insertAfter(curPos, entry);
        }
        return(entry);
    }


    public Entry delMin() throws ExceptionPQueueEmpty {
        if (L.isEmpty())
            throw new ExceptionPQueueEmpty("���⣺���ȶ��п�");
        return (Entry) L.remove(L.last());
    }
}