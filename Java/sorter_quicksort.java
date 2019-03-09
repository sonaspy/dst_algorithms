













package dsa;

public class Sorter_Quicksort implements Sorter {
    private Comparator C;

    public Sorter_Quicksort() {
        this(new ComparatorDefault());
    }

    public Sorter_Quicksort(Comparator comp) {
        C = comp;
    }

    public void sort(Sequence s) {
        qsort(s, 0, s.getSize() - 1);
    }

    public void qsort(Sequence S, int lo, int hi) {
        if (lo >= hi)  return;
        int mi = createPivot(S, lo, hi);
        qsort(S, lo, mi - 1);
        qsort(S, mi + 1, hi);
    }

    public int createPivot(Sequence S, int lo, int hi) {
        while (lo < hi) {
            while ((lo < hi) && (C.compare(S.getAtRank(lo), S.getAtRank(hi)) <= 0)) hi--;
            swap(S, lo, hi);
            while ((lo < hi) && (C.compare(S.getAtRank(lo), S.getAtRank(hi)) <= 0)) lo++;
            swap(S, lo, hi);
        }
        return lo;
    }

    private void swap(Sequence S, int i, int j) {
        Object temp = S.getAtRank(i);
        S.replaceAtRank(i, S.getAtRank(j));
        S.replaceAtRank(j, temp);
    }
}