











package dsa;

public class ComparatorLexicographic implements Comparator {
    public int compare(Object a, Object b) throws ClassCastException {
        int   ax = ((Point2D) a).getX();
        int   ay = ((Point2D) a).getY();
        int   bx = ((Point2D) b).getX();
        int   by = ((Point2D) b).getY();
        return (ax != bx) ? (ax - bx) : (ay - by);
    }
}