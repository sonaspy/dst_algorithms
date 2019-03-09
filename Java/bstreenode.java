











package dsa;

public class BSTreeNode extends BinTreeNode implements BinTreePosition, Entry {

    public BSTreeNode() {
        super();
    }

    public BSTreeNode(
        Object e,
        BinTreePosition p,
        boolean asLChild,
        BinTreePosition l,
        BinTreePosition r) {
        super(e, p, asLChild, l, r);
    }



    public Object getKey() {
        return ((Entry)getElem()).getKey();
    }


    public Object setKey(Object k) {
        return ((Entry)getElem()).setKey(k);
    }


    public Object getValue() {
        return ((Entry)getElem()).getValue();
    }


    public Object setValue(Object v) {
        return ((Entry)getElem()).setValue(v);
    }
}