











package dsa;

public interface Tree {

    public Object getElem();

    public Object setElem(Object obj);


    public TreeLinkedList getParent();


    public TreeLinkedList getFirstChild();


    public TreeLinkedList getNextSibling();


    public int getSize();


    public int getHeight();


    public int getDepth();
}