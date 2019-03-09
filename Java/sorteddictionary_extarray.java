











package dsa;

public class SortedDictionary_ExtArray implements SortedDictionary {
    Vector   S;
    Comparator C;


    public SortedDictionary_ExtArray() {
        this(new ComparatorDefault());
    }


    public SortedDictionary_ExtArray(Comparator comp) {
        S = new Vector_ExtArray();
        C = comp;
    }






    private static int binSearch(Vector s, Comparator c, Object key, int lo, int hi) {
        if (lo > hi) return lo;
        int mi = (lo + hi) >> 1;
        Entry e = (Entry)s.getAtRank(mi);
        int flag = c.compare(key, e.getKey());
        if (flag < 0) return binSearch(s, c, key, lo, mi - 1);
        else if (flag > 0) return binSearch(s, c, key, mi + 1, hi);
        else return mi;
    }



    public int getSize() {
        return S.getSize();
    }


    public boolean isEmpty() {
        return S.isEmpty();
    }


    public Entry find(Object key) {
        int k = binSearch(S, C, key, 0, S.getSize() - 1);
        if (0 > k || k >= S.getSize() || (0 != C.compare(key, ((Entry)S.getAtRank(k)).getKey())))
            return null;
        return (Entry) S.getAtRank(k);
    }


    public Iterator findAll(Object key) {
        List L = new List_DLNode();
        int k = binSearch(S, C, key, 0, S.getSize() - 1);
        if (0 > k || k >= S.getSize() || (0 != C.compare(key, ((Entry)S.getAtRank(k)).getKey())))
            return new IteratorElement(L);
        L.insertFirst(S.getAtRank(k));
        int lo = k;
        while (0 <= --lo) {
            if (0 != C.compare(key, ((Entry)S.getAtRank(lo)).getKey())) break;
            L.insertFirst(S.getAtRank(lo));
        }
        int hi = k;
        while (++hi < S.getSize()) {
            if (0 != C.compare(key, ((Entry)S.getAtRank(hi)).getKey())) break;
            L.insertLast(S.getAtRank(hi));
        }
        return new IteratorElement(L);
    }


    public Entry insert(Object key, Object value) {
        Entry e = new EntryDefault(key, value);
        if (S.isEmpty())  return (Entry) S.insertAtRank(0, e);
        return (Entry) S.insertAtRank(binSearch(S, C, key, 0, S.getSize() - 1), e);
    }


    public Entry remove(Object key) {
        int k = binSearch(S, C, key, 0, S.getSize() - 1);
        if (0 > k || k >= S.getSize() || (0 != C.compare(key, ((Entry)S.getAtRank(k)).getKey())))
            return null;
        return (Entry) S.removeAtRank(k);
    }


    public Iterator entries() {
        List L = new List_DLNode();
        for (int i = 0; i < S.getSize(); i++)
            L.insertLast(S.getAtRank(i));
        return new IteratorElement(L);
    }



    public Entry first() {
        return (S.isEmpty()) ? null : (Entry) S.getAtRank(0);
    }


    public Entry last() {
        return (S.isEmpty()) ? null : (Entry) S.getAtRank(S.getSize() - 1);
    }


    public Iterator successors(Object key) {
        List L = new List_DLNode();
        int k = binSearch(S, C, key, 0, S.getSize() - 1);
        if (0 > k || k >= S.getSize() || (0 != C.compare(key, ((Entry)S.getAtRank(k)).getKey())))
            return new IteratorElement(L);
        while (0 <= --k)
            if (0 != C.compare(key, ((Entry)S.getAtRank(k)).getKey()))  break;
        while (S.getSize() > ++k)
            L.insertLast(S.getAtRank(k));
        return new IteratorElement(L);
    }


    public Iterator predecessors(Object key) {
        List L = new List_DLNode();
        int k = binSearch(S, C, key, 0, S.getSize() - 1);
        if (0 > k || k >= S.getSize() || (0 != C.compare(key, ((Entry)S.getAtRank(k)).getKey())))
            return new IteratorElement(L);
        while (S.getSize() > ++k)
            if (0 != C.compare(key, ((Entry)S.getAtRank(k)).getKey()))  break;
        while (0 <= --k)
            L.insertLast(S.getAtRank(k));
        return new IteratorElement(L);
    }
}