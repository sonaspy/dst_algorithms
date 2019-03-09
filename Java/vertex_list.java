











package  dsa;

public class Vertex_List implements Vertex {

    protected Object info;
    protected Position vPosInV;
    protected List outEdges;
    protected List inEdges;
    protected int status;
    protected int dStamp;
    protected int fStamp;
    protected int distance;
    protected Vertex bfsParent;


    public Vertex_List(Graph G, Object x) {
        info = x;
        vPosInV = G.insert(this);
        outEdges = new List_DLNode();
        inEdges = new List_DLNode();
        status = UNDISCOVERED;
        dStamp = fStamp = Integer.MAX_VALUE;
        distance = Integer.MAX_VALUE;
        bfsParent = null;
    }


    public Object getInfo() {
        return info;
    }

    public Object setInfo(Object x) {
        Object e = info;
        info = x;
        return e;
    }


    public int outDeg() {
        return outEdges.getSize();
    }
    public int inDeg() {
        return inEdges.getSize();
    }


    public Iterator inEdges() {
        return inEdges.elements();
    }
    public Iterator inEdgePositions() {
        return inEdges.positions();
    }
    public Iterator outEdges() {
        return outEdges.elements();
    }
    public Iterator outEdgePositions() {
        return outEdges.positions();
    }


    public Position getVPosInV() {
        return vPosInV;
    }


    public int getStatus() {
        return status;
    }
    public int setStatus(int s) {
        int ss = status;
        status = s;
        return ss;
    }


    public int getDStamp() {
        return dStamp;
    }
    public int setDStamp(int s) {
        int ss = dStamp;
        dStamp = s;
        return ss;
    }
    public int getFStamp() {
        return fStamp;
    }
    public int setFStamp(int s) {
        int ss = fStamp;
        fStamp = s;
        return ss;
    }


    public int getDistance() {
        return distance;
    }
    public int setDistance(int s) {
        int ss = distance;
        distance = s;
        return ss;
    }


    public Vertex getBFSParent() {
        return bfsParent;
    }
    public Vertex setBFSParent(Vertex s) {
        Vertex ss = bfsParent;
        bfsParent = s;
        return ss;
    }
}
