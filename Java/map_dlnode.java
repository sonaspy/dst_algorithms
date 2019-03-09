











package  dsa;

public class Map_DLNode implements Map {
    private List L;
    private EqualityTester T;


    public Map_DLNode() {
        this(new EqualityTesterDefault());
    }


    public Map_DLNode(EqualityTester t) {
        L = new List_DLNode();
        T = t;
    }



    public int getSize() {
        return L.getSize();
    }


    public boolean isEmpty() {
        return L.isEmpty();
    }


    public Object get(Object key) {
        Iterator P = L.positions();
        while (P.hasNext()) {
            Position pos = (Position)P.getNext();
            Entry entry = (EntryDefault) pos.getElem();
            if (T.isEqualTo(entry.getKey(), key))  return entry.getValue();
        }
        return null;
    }



    public Object put(Object key, Object value)  {
        Iterator P = L.positions();
        while (P.hasNext()) {
            Position pos = (Position)P.getNext();
            Entry entry = (EntryDefault) pos.getElem();
            if (T.isEqualTo(entry.getKey(), key)) {
                Object oldValue = entry.getValue();
                L.replace(pos, new EntryDefault(key, value));
                return oldValue;
            }
        }
        L.insertFirst(new EntryDefault(key, value));
        return null;
    }


    public Object remove(Object key) {
        Iterator P = L.positions();
        while (P.hasNext()) {
            Position pos = (Position)P.getNext();
            Entry entry = (EntryDefault) pos.getElem();
            if (T.isEqualTo(entry.getKey(), key)) {
                Object oldValue = entry.getValue();
                L.remove(pos);
                return oldValue;
            }
        }
        return null;
    }


    public Iterator entries() {
        return new IteratorElement(L);
    }
}