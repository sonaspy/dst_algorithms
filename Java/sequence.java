











package dsa;

public interface Sequence extends Vector, List {

    public Position rank2Pos(int r)
    throws ExceptionBoundaryViolation;


    public int pos2Rank(Position p)
    throws ExceptionPositionInvalid;
}