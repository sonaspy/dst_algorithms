











package dsa;

public class Node implements Position {
    private Object element;
    private Node next;


    public Node() {
        this(null, null);
    }

    public Node(Object e, Node n) {
        element = e;
        next = n;
    }



    public Object getElem() {
        return element;
    }


    public Object setElem(Object e) {
        Object oldElem = element;
        element = e;
        return oldElem;
    }



    public Node getNext() {
        return next;
    }



    public void setNext(Node newNext) {
        next = newNext;
    }
}