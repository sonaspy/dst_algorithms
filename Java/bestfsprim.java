











package dsa;

public class BestFSPrim extends BestFS {

    public BestFSPrim(Graph g) {
        super(g);
    }


    protected void updateDistanceAfter(Vertex v) {
        for (Iterator it = v.outEdges(); it.hasNext();) {
            Edge e = (Edge)it.getNext();
            Vertex w = (Vertex)e.getVPosInV(1).getElem();
            int   weight = ((Integer)e.getInfo()).intValue();
            if (w.getDistance() > weight) {
                w.setDistance(weight);
                w.setBFSParent(v);
            }
        }
    }
}
