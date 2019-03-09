











package dsa;

public interface Deque {
    public int getSize();
    public boolean isEmpty();
    public Object first() throws ExceptionQueueEmpty;
    public Object last() throws ExceptionQueueEmpty;
    public void insertFirst(Object obj);
    public void insertLast(Object obj);
    public Object removeFirst() throws ExceptionQueueEmpty;
    public Object removeLast() throws ExceptionQueueEmpty;
    public void Traversal();
}