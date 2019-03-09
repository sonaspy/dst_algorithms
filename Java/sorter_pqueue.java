











package dsa;

public class Sorter_PQueue implements Sorter {
    private Comparator C;

    public Sorter_PQueue() {
        this(new ComparatorDefault());
    }

    public Sorter_PQueue(Comparator comp) {
        C = comp;
    }

    public void sort(Sequence S) {
        Sequence T = new Sequence_DLNode();
        while (!S.isEmpty()) {
            Object e = S.removeFirst();
            T.insertLast(new EntryDefault(e, e));
        }
        PQueue pq = new PQueue_Heap(C, T);
        while(!pq.isEmpty()) {
            S.insertLast(pq.delMin().getValue());
            System.out.println("\t:\t" + S.last().getElem());
        }
    }
}