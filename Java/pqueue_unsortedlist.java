











package dsa;

public class PQueue_UnsortedList implements PQueue {
    private List L;
    private Comparator C;


    public PQueue_UnsortedList() {
        this(new ComparatorDefault(), null);
    }


    public PQueue_UnsortedList(Comparator c) {
        this(c, null);
    }


    public PQueue_UnsortedList(Sequence s) {
        this(new ComparatorDefault(), s);
    }


    public PQueue_UnsortedList(Comparator c, Sequence s) {
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
        Position minPos = L.first();
        Position curPos = L.getNext(minPos);
        while (null != curPos)
            if (0 < C.compare(minPos.getElem(), curPos.getElem()))
                minPos = curPos;
        return (Entry) minPos.getElem();
    }


    public Entry insert(Object key, Object obj) throws ExceptionKeyInvalid {
        Entry entry = new EntryDefault(key, obj);
        L.insertLast(entry);
        return(entry);
    }


    public Entry delMin() throws ExceptionPQueueEmpty {
        if (L.isEmpty())
            throw new ExceptionPQueueEmpty("���⣺���ȶ��п�");
        Position minPos = L.first();
        Iterator it = L.positions();
        while (it.hasNext()) {
            Position curPos = (Position) (it.getNext());
            if (0 <  C.compare(
                        ((Entry)(minPos.getElem())).getKey(),
                        ((Entry)(curPos.getElem())).getKey())
               )
                minPos = curPos;
        }
        return (Entry) L.remove(minPos);
    }
}