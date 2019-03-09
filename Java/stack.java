











package dsa;

public interface Stack {
    public int getSize();
    public boolean isEmpty();
    public Object top() throws ExceptionStackEmpty;
    public void push (Object ele);
    public Object pop() throws ExceptionStackEmpty;
}