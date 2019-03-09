











package dsa;

public interface Queue {
    public int getSize();
    public boolean isEmpty();
    public Object front()
    throws ExceptionQueueEmpty;
    public void enqueue (Object obj)
    throws ExceptionQueueFull;
    public Object dequeue()
    throws ExceptionQueueEmpty;
    public void Traversal();
}