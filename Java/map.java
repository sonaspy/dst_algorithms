











package  dsa;

public interface Map {

    public int getSize();


    public boolean isEmpty();


    public Object get(Object key);



    public Object put(Object key, Object value);


    public Object remove(Object key);


    public Iterator entries();
}