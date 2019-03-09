











package dsa;

public class Sequence_DLNode extends List_DLNode implements Sequence {

    protected void checkRank(int r, int n)
    throws ExceptionBoundaryViolation {
        if (r < 0 || r >= n)
            throw new ExceptionBoundaryViolation("���⣺�Ƿ�����" + r + "��Ӧ������[0, " + n + ")");
    }


    public Position rank2Pos(int r) throws ExceptionBoundaryViolation {
        DLNode node;
        checkRank(r, getSize());
        if (r <= getSize()  2) {
            node = header.getNext( );
            for (int i = 0; i < r; i++) node = node.getNext();
        } else {
            node = trailer.getPrev();
            for (int i = 1; i < getSize() - r; i++)   node = node.getPrev();
        }
        return node;
    }


    public int pos2Rank(Position p) throws ExceptionPositionInvalid {
        DLNode   node = header.getNext();
        int      r = 0;
        while (node != trailer) {
            if (node == p) return(r);
            node = node.getNext();
            r++;
        }
        throw new ExceptionPositionInvalid("���⣺��Ϊ������λ�ò���������");
    }


    public Object getAtRank(int r) throws ExceptionBoundaryViolation {
        checkRank(r, getSize());
        return rank2Pos(r).getElem();
    }


    public Object replaceAtRank(int r, Object obj) throws ExceptionBoundaryViolation {
        checkRank(r, getSize());
        return replace(rank2Pos(r), obj);
    }


    public Object insertAtRank(int r, Object obj)   throws ExceptionBoundaryViolation {
        checkRank(r, getSize() + 1);
        if (getSize() == r)  insertLast(obj);
        else                       insertBefore(rank2Pos(r), obj);
        return obj;
    }


    public Object removeAtRank(int r) throws ExceptionBoundaryViolation {
        checkRank(r, getSize());
        return remove(rank2Pos(r));
    }
}