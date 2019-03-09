











package dsa;

public interface SortedDictionary extends Dictionary {

    public Entry first();


    public Entry last();


    public Iterator successors(Object key);


    public Iterator predecessors(Object key);
}