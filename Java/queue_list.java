











package dsa;

public class Queue_List implements Queue {
    protected Node head;
    protected Node tail;
    protected int size;


    public Queue_List() {
        head = tail = null;
        size = 0;
    }


    public int getSize() {
        return size;
    }


    public boolean isEmpty() {
        return (0 == size) ? true : false;
    }


    public void enqueue(Object obj) {
        Node node = new Node();
        node.setElem(obj);
        node.setNext(null);
        if (0 == size) head = node;
        else                 tail.setNext(node);
        tail = node;
        size++;
    }


    public Object dequeue() throws ExceptionQueueEmpty {
        if (0 == size)
            throw new ExceptionQueueEmpty("���⣺���п�");
        Object obj = head.getElem();
        head = head.getNext();
        size--;
        if (0 == size) tail = null;
        return obj;
    }


    public Object front() throws ExceptionQueueEmpty {
        if (isEmpty())
            throw new ExceptionQueueEmpty("���⣺���п�");
        return head.getElem();
    }


    public void Traversal() {
        Node  p = head;
        while (null != p) {
            System.out.print(p.getElem() + " ");
            p = p.getNext();
        }
    }
}