











package dsa;

public class Stack_Array implements Stack {
    public static final int CAPACITY = 1024;
    protected int capacity;
    protected Object[] S;
    protected int top = -1;


    public Stack_Array() {
        this(CAPACITY);
    }


    public Stack_Array(int cap) {
        capacity = cap;
        S = new Object[capacity];
    }


    public int getSize() {
        return (top + 1);
    }


    public boolean isEmpty() {
        return (top < 0);
    }


    public void push(Object obj) throws ExceptionStackFull {
        if (getSize() == capacity)
            throw new ExceptionStackFull("���⣺ջ���");
        S[++top] = obj;
    }


    public Object top() throws ExceptionStackEmpty {
        if (isEmpty())
            throw new ExceptionStackEmpty("���⣺ջ��");
        return S[top];
    }


    public Object pop() throws ExceptionStackEmpty {
        Object elem;
        if (isEmpty())
            throw new ExceptionStackEmpty("���⣺ջ��");
        elem = S[top];
        S[top--] = null;
        return elem;
    }
}