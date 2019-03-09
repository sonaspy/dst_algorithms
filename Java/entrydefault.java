











package  dsa;

public class EntryDefault implements Entry {
    protected Object key;
    protected Object value;


    public EntryDefault(Object k, Object v) {
        key = k;
        value = v;
    }



    public Object getKey() {
        return key;
    }

    public Object setKey(Object k) {
        Object oldK = key;
        key = k;
        return oldK;
    }


    public Object getValue() {
        return value;
    }

    public Object setValue(Object v) {
        Object oldV = value;
        value = v;
        return oldV;
    }
}