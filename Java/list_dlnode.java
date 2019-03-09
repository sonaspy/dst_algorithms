











package dsa;

public class List_DLNode implements List {
    protected int numElem;
    protected DLNode header, trailer;


    public List_DLNode() {
        numElem = 0;
        header = new DLNode(null, null, null);
        trailer = new DLNode(null, header, null);
        header.setNext(trailer);
    }



    protected DLNode checkPosition(Position p) throws ExceptionPositionInvalid {
        if (null == p)
            throw new ExceptionPositionInvalid("���⣺���ݸ�List_DLNode��λ����null");
        if (header == p)
            throw new ExceptionPositionInvalid("���⣺ͷ�ڵ��ڱ�λ�÷Ƿ�");
        if (trailer == p)
            throw new ExceptionPositionInvalid("���⣺β����ڱ�λ�÷Ƿ�");
        DLNode temp = (DLNode)p;
        return temp;
    }



    public int getSize() {
        return numElem;
    }


    public boolean isEmpty() {
        return (numElem == 0);
    }


    public Position first() throws ExceptionListEmpty {
        if (isEmpty())
            throw new ExceptionListEmpty("���⣺�б��");
        return header.getNext();
    }


    public Position last()  throws ExceptionListEmpty {
        if (isEmpty())
            throw new ExceptionListEmpty("���⣺�б��");
        return trailer.getPrev();
    }


    public Position getPrev(Position p)
    throws ExceptionPositionInvalid, ExceptionBoundaryViolation {
        DLNode v = checkPosition(p);
        DLNode prev = v.getPrev();
        if (prev == header)
            throw new ExceptionBoundaryViolation("���⣺��ͼԽ���б�ǰ��");
        return prev;
    }


    public Position getNext(Position p)
    throws ExceptionPositionInvalid, ExceptionBoundaryViolation {
        DLNode v = checkPosition(p);
        DLNode next = v.getNext();
        if (next == trailer)
            throw new ExceptionBoundaryViolation("���⣺��ͼԽ���б���");
        return next;
    }


    public Position insertBefore(Position p, Object element)
    throws ExceptionPositionInvalid {
        DLNode v = checkPosition(p);
        numElem++;
        DLNode newNode = new DLNode(element, v.getPrev(), v);
        v.getPrev().setNext(newNode);
        v.setPrev(newNode);
        return newNode;
    }


    public Position insertAfter(Position p, Object element)
    throws ExceptionPositionInvalid {
        DLNode v = checkPosition(p);
        numElem++;
        DLNode newNode = new DLNode(element, v, v.getNext());
        v.getNext().setPrev(newNode);
        v.setNext(newNode);
        return newNode;
    }


    public Position insertFirst(Object e) {
        numElem++;
        DLNode newNode = new DLNode(e, header, header.getNext());
        header.getNext().setPrev(newNode);
        header.setNext(newNode);
        return newNode;
    }


    public Position insertLast(Object e) {
        numElem++;
        DLNode newNode = new DLNode(e, trailer.getPrev(), trailer);
        if (null == trailer.getPrev())   System.out.println("!!!Prev of trailer is NULL!!!");
        trailer.getPrev().setNext(newNode);
        trailer.setPrev(newNode);
        return newNode;
    }


    public Object remove(Position p)
    throws ExceptionPositionInvalid {
        DLNode v = checkPosition(p);
        numElem--;
        DLNode vPrev = v.getPrev();
        DLNode vNext = v.getNext();
        vPrev.setNext(vNext);
        vNext.setPrev(vPrev);
        Object vElem = v.getElem();
        v.setNext(null);
        v.setPrev(null);
        return vElem;
    }


    public Object removeFirst() {
        return remove(header.getNext());
    }


    public Object removeLast() {
        return remove(trailer.getPrev());
    }


    public Object replace(Position p, Object obj)
    throws ExceptionPositionInvalid {
        DLNode v = checkPosition(p);
        Object oldElem = v.getElem();
        v.setElem(obj);
        return oldElem;
    }


    public Iterator positions() {
        return new IteratorPosition(this);
    }


    public Iterator elements() {
        return new IteratorElement(this);
    }
}
