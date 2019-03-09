











package dsa;

public class IteratorElement implements Iterator {
    private List list;
    private Position nextPosition;


    public IteratorElement() {
        list = null;
    }


    public IteratorElement(List L) {
        list = L;
        if (list.isEmpty())
            nextPosition = null;
        else
            nextPosition = list.first();
    }


    public boolean hasNext() {
        return (null != nextPosition);
    }


    public Object getNext() throws ExceptionNoSuchElement {
        if (!hasNext()) throw new ExceptionNoSuchElement("���⣺û����һԪ��");
        Position currentPosition = nextPosition;
        if (currentPosition == list.last())
            nextPosition = null;
        else
            nextPosition = list.getNext(currentPosition);
        return currentPosition.getElem();
    }
}