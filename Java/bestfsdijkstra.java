











package dsa;

public class BestFSDijkstra extends BestFS {

    public BestFSDijkstra(Graph g) {
        super(g);
    }


    protected void updateDistanceAfter(Vertex v) {
        for (Iterator it = v.outEdges(); it.hasNext();) {
            Edge e = (Edge)it.getNext();
            Vertex w = (Vertex)e.getVPosInV(1).getElem();
            int   weight = ((Integer)e.getInfo()).intValue();
            if (w.getDistance() > v.getDistance() + weight) {
                w.setDistance(v.getDistance() + weight);
                w.setBFSParent(v);
            }
        }
    }
}
