











package  dsa;

public class Edge_List implements Edge {

    protected   Object info;
    protected Position ePosInE;
    protected Position vPosInV[];
    protected Position ePosInI[];


    protected int type;


    public Edge_List(Graph G, Vertex_List u, Vertex_List v, Object x) {
        info = x;
        ePosInE = G.insert(this);
        vPosInV = new DLNode[2];
        vPosInV[0] = u.getVPosInV();
        vPosInV[1] = v.getVPosInV();
        ePosInI = new DLNode[2];
        ePosInI[0] = u.outEdges.insertLast(this);
        ePosInI[1] = v.inEdges.insertLast(this);
        type = UNKNOWN;
    }


    public Object getInfo() {
        return info;
    }

    public Object setInfo(Object x) {
        Object e = info;
        info = x;
        return e;
    }


    public Position getEPosInE() {
        return ePosInE;
    }

    public Position getVPosInV(int i)   {
        return vPosInV[i];
    }

    public Position getEPosInI(int i) {
        return ePosInI[i];
    }


    public int getType() {
        return type;
    }
    public int setType(int t) {
        int tt = type;
        type = t;
        return tt;
    }

}
