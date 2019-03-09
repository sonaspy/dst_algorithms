











package dsa;

public interface BinTreePosition extends Position {

    public boolean hasParent();

    public BinTreePosition getParent();

    public void setParent(BinTreePosition p);


    public boolean isLeaf();


    public boolean isLChild();


    public boolean hasLChild();

    public BinTreePosition getLChild();

    public void setLChild(BinTreePosition c);


    public boolean isRChild();

    public boolean hasRChild();

    public BinTreePosition getRChild();

    public void setRChild(BinTreePosition c);


    public int getSize();

    public void updateSize();


    public int getHeight();

    public void updateHeight();


    public int getDepth();

    public void updateDepth();


    public BinTreePosition getPrev();


    public BinTreePosition getSucc();



    public BinTreePosition secede();


    public BinTreePosition attachL(BinTreePosition c);


    public BinTreePosition attachR(BinTreePosition c);


    public Iterator elementsPreorder();


    public Iterator elementsInorder();


    public Iterator elementsPostorder();


    public Iterator elementsLevelorder();
}