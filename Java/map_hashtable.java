












package dsa;

public class Map_HashTable implements Map {
    private Map[] A;
    private  int N;
    private final double maxLemda = 0.75;
    private int size;
    private EqualityTester T;


    public Map_HashTable() {
        this(0, new EqualityTesterDefault());
    }


    public Map_HashTable(int n, EqualityTester t) {
        T = t;
        N = p(n);
        A = new Map[N];
        for (int i = 0; i < N; i++) A[i] = new Map_DLNode(T);
        size = 0;
    }



    private int h(Object key) {
        return key.hashCode() % N;
    }


    private static boolean prime(int n) {
        for (int i = 3; i < 1 + Math.sqrt(n); i++)
            if (n  i
                    return true;
        }


private static int p(int n) {
        if (3 > n) n = 3;
        n = n | 1;
        while (!prime(n)) n += 2;
        return n;
    }



    public int getSize() {
        return size;
    }


    public boolean isEmpty() {
        return 0 == size;
    }


    public Object get(Object key) {
        return A[h(key)].get(key);
    }



    public Object put(Object key, Object value) {
        Object oldValue = A[h(key)].put(key, value);
        if (null == oldValue) {
            size++;
            if (size > N
        }
    return oldValue;
}


public Object remove(Object key) {
        Object oldValue = A[h(key)].remove(key);
        if (null != oldValue)  size--;
        return oldValue;
    }



    public Iterator entries() {
        List L = new List_DLNode();
        for (int i = 0; i < N; i++) {
            Iterator it = A[i].entries();
            while (it.hasNext()) L.insertLast(it.getNext());
        }
        return new IteratorElement(L);
    }


    private void rehash() {
        Iterator it = this.entries();
        N = p(N << 1);
        A = new Map[N];
        for (int i = 0; i < N; i++) A[i] = new Map_DLNode(T);
        while (it.hasNext()) {
            Entry e = (Entry)it.getNext();
            Object k = e.getKey();
            Object v = e.getValue();
            A[h(k)].put(k, v);
        }
    }
}