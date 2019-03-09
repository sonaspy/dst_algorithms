











package dsa;

public class IteratorPosition implements Iterator {
    private List list;
    private Position nextPosition;


    public IteratorPosition() {
        list = null;
    }


    public IteratorPosition(List L) {
        list = L;
        if (list.isEmpty())
            nextPosition = null;
        else
            nextPosition = list.first();
    }


    public boolean hasNext() {
        return (nextPosition != null);
    }


    public Object getNext() throws ExceptionNoSuchElement {
        if (!hasNext()) throw new ExceptionNoSuchElement("���⣺û����һλ��");
        Position currentPosition = nextPosition;
        if (currentPosition == list.last())
            nextPosition = null;
        else
            nextPosition = list.getNext(currentPosition);
        return currentPosition;
    }
}