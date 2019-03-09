











package  dsa;

public class Dictionary_DLNode implements Dictionary {
    private List L;
    private EqualityTester T;


    public Dictionary_DLNode() {
        this(new EqualityTesterDefault());
    }


    public Dictionary_DLNode(EqualityTester t) {
        L = new List_DLNode();
        T = t;
    }



    public int getSize() {
        return L.getSize();
    }


    public boolean isEmpty() {
        return L.isEmpty();
    }


    public Entry find(Object key) {
        Iterator P = L.positions();
        while (P.hasNext()) {
            Position pos = (Position)P.getNext();
            Entry entry = (EntryDefault) pos.getElem();
            if (T.isEqualTo(entry.getKey(), key))  return entry;
        }
        return null;
    }


    public Iterator findAll(Object key) {
        List  list = new List_DLNode();
        Iterator P = L.positions();
        while (P.hasNext()) {
            Position pos = (Position)P.getNext();
            Entry entry = (EntryDefault) pos.getElem();
            if (T.isEqualTo(entry.getKey(), key))
                list.insertLast(entry);
        }
        return new IteratorElement(list);
    }


    public Entry insert(Object key, Object value) {
        Entry entry = new EntryDefault(key, value);
        L.insertFirst(entry);
        return entry;
    }


    public Entry remove(Object key) {
        Iterator P = L.positions();
        while (P.hasNext()) {
            Position pos = (Position)P.getNext();
            Entry entry = (EntryDefault) pos.getElem();
            if (T.isEqualTo(entry.getKey(), key)) {
                Entry oldEntry = entry;
                L.remove(pos);
                return oldEntry;
            }
        }
        return null;
    }


    public Iterator entries() {
        return new IteratorElement(L);
    }
}