











package dsa;

public interface PQueue {

    public int getSize();


    public boolean isEmpty();


    public Entry getMin() throws ExceptionPQueueEmpty;


    public Entry insert(Object key, Object obj) throws ExceptionKeyInvalid;


    public Entry delMin() throws ExceptionPQueueEmpty;
}