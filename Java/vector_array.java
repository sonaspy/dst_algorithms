











package dsa;

public class Vector_Array implements Vector {
    private final int N = 1024;
    private int n = 0;
    private Object[] A;


    public Vector_Array() {
        A = new Object[N];
        n = 0;
    }


    public int getSize() {
        return n;
    }


    public boolean isEmpty() {
        return (0 == n) ? true : false;
    }


    public Object getAtRank(int r)
    throws ExceptionBoundaryViolation {
        if (0 > r || r >= n) throw new ExceptionBoundaryViolation("���⣺��Խ��");
        return A[r];
    }


    public Object replaceAtRank(int r, Object obj)
    throws ExceptionBoundaryViolation {
        if (0 > r || r >= n) throw new ExceptionBoundaryViolation("���⣺��Խ��");
        Object bak = A[r];
        A[r] = obj;
        return bak;
    }


    public Object insertAtRank(int r, Object obj)
    throws ExceptionBoundaryViolation {
        if (0 > r || r > n)  throw new ExceptionBoundaryViolation("���⣺��Խ��");
        if (n >= N) throw new ExceptionBoundaryViolation("���⣺�������");
        for (int i = n; i > r; i--) A[i] = A[i-1];
        A[r] = obj;
        n++;
        return obj;
    }


    public Object removeAtRank(int r)
    throws ExceptionBoundaryViolation {
        if (0 > r || r >= n) throw new ExceptionBoundaryViolation("���⣺��Խ��");
        Object bak = A[r];
        for (int i = r; i < n; i++) A[i] = A[i+1];
        n--;
        return bak;
    }
}