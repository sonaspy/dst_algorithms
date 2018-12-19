
package  dsa;

public interface Vertex {
    
   final static int UNDISCOVERED = 0; 
   final static int DISCOVERED = 1; 
   final static int VISITED = 2; 

   public Object getInfo();
    
   public Object setInfo(Object x);

    
   public int outDeg();
   public int inDeg();

    
   public Iterator inEdges();
   public Iterator inEdgePositions();
   public Iterator outEdges();
   public Iterator outEdgePositions();

    
   public Position getVPosInV();

    
   public int getStatus();
   public int setStatus(int s);

    
   public int getDStamp();
   public int setDStamp(int s);
   public int getFStamp();
   public int setFStamp(int s);

    
   public int getDistance();
   public int setDistance(int s);

    
   public Vertex getBFSParent();
   public Vertex setBFSParent(Vertex s);
}
