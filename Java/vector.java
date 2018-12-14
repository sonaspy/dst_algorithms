
package dsa;

public interface Vector {
    
   public int getSize();

    
   public boolean isEmpty();

    
   public Object getAtRank(int r)
   throws ExceptionBoundaryViolation;

    
   public Object replaceAtRank(int r, Object obj)
   throws ExceptionBoundaryViolation;

    
   public Object insertAtRank(int r, Object obj)
   throws ExceptionBoundaryViolation;

    
   public Object removeAtRank(int r)
   throws ExceptionBoundaryViolation;
}