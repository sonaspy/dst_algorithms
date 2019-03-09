











package dsa;

public class Vector_ExtArray implements Vector {
    private int N = 8;
    private int n;
    private Object A[];


    public Vector_ExtArray()   {
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
        if (N <= n) {
            N
            Object   B[] = new Object[N];
            for (int i = 0; i < n; i++) B[i] = A[i];
            A = B;
        }
        for (int i = n; i > r; i--) A[i] = A[i-1];
        A[r] = obj;
        n++;
        return obj;
    }


    public Object removeAtRank(int r)
    throws ExceptionBoundaryViolation {
        if (0 > r || r >= n) throw new ExceptionBoundaryViolation("���⣺��Խ��");
        Object bak = A[r];
        for (int i = r; i < n - 1; i++)  A[i] = A[i+1];
        n--;
        return bak;
    }
}