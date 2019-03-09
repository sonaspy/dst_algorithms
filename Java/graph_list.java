











package dsa;

public class Graph_List implements Graph {

    protected List E;
    protected List V;


    public Graph_List() {
        E = new List_DLNode();
        V = new List_DLNode();
    }


    protected List getE() {
        return E;
    }
    protected List getV() {
        return V;
    }


    public int vNumber() {
        return V.getSize();
    }
    public int eNumber() {
        return E.getSize();
    }


    public Iterator vertices() {
        return V.elements();
    }
    public Iterator vPositions() {
        return V.positions();
    }


    public Iterator edges() {
        return E.elements();
    }
    public Iterator ePositions() {
        return E.positions();
    }


    public boolean areAdjacent(Vertex u, Vertex v) {
        return (null != edgeFromTo(u, v));
    }

    public Edge edgeFromTo(Vertex u, Vertex v) {
        for (Iterator it = u.outEdges(); it.hasNext();) {
            Edge e = (Edge)it.getNext();
            if (v == e.getVPosInV(1).getElem())
                return e;
        }
        return null;
    }


    public Vertex remove(Vertex v) {
        while (0 < v.outDeg())
            remove((Edge)(((Vertex_List)v).outEdges.first()).getElem());
        while (0 < v.inDeg())
            remove((Edge)(((Vertex_List)v).inEdges.first()).getElem());
        return (Vertex)V.remove(v.getVPosInV());
    }

    public Edge remove(Edge e) {
        ((Vertex_List)e.getVPosInV(0).getElem()).outEdges.remove(e.getEPosInI(0));
        ((Vertex_List)e.getVPosInV(1).getElem()).inEdges.remove(e.getEPosInI(1));
        return (Edge)E.remove(e.getEPosInE());
    }


    public Position insert(Vertex v) {
        return V.insertLast(v);
    }

    public Position insert(Edge e) {
        return E.insertLast(e);
    }
}
