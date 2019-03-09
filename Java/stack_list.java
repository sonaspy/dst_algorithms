











package dsa;

public class Stack_List implements Stack {
    protected Node top;
    protected int size;


    public Stack_List() {
        top = null;
        size = 0;
    }


    public int getSize() {
        return size;
    }


    public boolean isEmpty() {
        return (top == null) ? true : false;
    }


    public void push(Object elem) {
        Node v = new Node(elem, top);
        top = v;
        size++;
    }


    public Object top() throws ExceptionStackEmpty {
        if (isEmpty())
            throw new ExceptionStackEmpty("���⣺ջ��");
        return top.getElem();
    }


    public Object pop() throws ExceptionStackEmpty {
        if (isEmpty())
            throw new ExceptionStackEmpty("���⣺ջ��");
        Object temp = top.getElem();
        top = top.getNext();
        size--;
        return temp;
    }
}