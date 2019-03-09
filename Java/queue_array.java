











package dsa;

public class Queue_Array implements Queue {
    public static final int CAPACITY = 1000;
    protected int capacity;
    protected Object[] Q;
    protected int f = 0;
    protected int r = 0;


    public Queue_Array() {
        this(CAPACITY);
    }


    public Queue_Array(int cap) {
        capacity = cap;
        Q = new Object[capacity];
    }


    public int getSize() {
        return (capacity - f + r) % capacity;
    }


    public boolean isEmpty() {
        return (f == r);
    }


    public void enqueue(Object obj) throws ExceptionQueueFull {
        if (getSize() == capacity - 1)
            throw new ExceptionQueueFull("Queue overflow.");
        Q[r] = obj;
        r = (r + 1) % capacity;
    }


    public Object dequeue() {
        Object elem;
        if (isEmpty())
            throw new ExceptionQueueEmpty("���⣺���п�");
        elem = Q[f];
        Q[f] = null;
        f = (f + 1) % capacity;
        return elem;
    }


    public Object front() throws ExceptionQueueEmpty {
        if (isEmpty())
            throw new ExceptionQueueEmpty("���⣺���п�");
        return Q[f];
    }


    public void Traversal() {
        for (int i = f; i < r; i++)
            System.out.print(Q[i] + " ");
        System.out.println();
    }
}