











package dsa;

public abstract class GraphTraverse {

    final static int UNDISCOVERED = 0;
    final static int DISCOVERED = 1;
    final static int VISITED = 2;
    final static int UNKNOWN = 0;
    final static int TREE = 1;
    final static int CROSS = 2;
    final static int FORWARD = 3;
    final static int BACKWARD = 4;


    protected Graph G;


    public GraphTraverse(Graph g) {
        G = g;
    }


    protected void reset(Vertex s) {
        for (Iterator it = G.vertices(); it.hasNext();) {
            Vertex v = (Vertex)it.getNext();
            v.setStatus(UNDISCOVERED);
            v.setDistance(Integer.MAX_VALUE);
        }
        for (Iterator it = G.edges(); it.hasNext();)
            ((Edge)it.getNext()).setType(UNKNOWN);
    }


    protected abstract Object visit(Vertex v, Object info);


    public abstract Object algorithm(Vertex s, Object info);


    protected abstract Object traverse(Vertex v, Object info);
}
