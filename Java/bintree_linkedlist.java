











package dsa;

public class BinTree_LinkedList implements BinTree {
    protected BinTreePosition root;


    public BinTree_LinkedList() {
        this(null);
    }

    public BinTree_LinkedList(BinTreePosition r) {
        root = r;
    }



    public BinTreePosition getRoot() {
        return root;
    }


    public boolean isEmpty() {
        return null == root;
    }


    public int getSize() {
        return isEmpty() ? 0 : root.getSize();
    }


    public int getHeight() {
        return isEmpty() ? -1 : root.getHeight();
    }


    public Iterator elementsPreorder() {
        return root.elementsPreorder();
    }


    public Iterator elementsInorder() {
        return root.elementsInorder();
    }


    public Iterator elementsPostorder() {
        return root.elementsPostorder();
    }


    public Iterator elementsLevelorder() {
        return root.elementsLevelorder();
    }
}