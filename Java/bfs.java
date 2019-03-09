











package dsa;

public abstract class BFS extends GraphTraverse {

    public BFS(Graph g) {
        super(g);
    }


    protected Object traverse(Vertex s, Object info) {
        if (UNDISCOVERED != s.getStatus())  return null;
        Queue Q = new Queue_List();
        s.setStatus(DISCOVERED);
        Q.enqueue(s);
        visit(s, null);
        while (!Q.isEmpty()) {
            Vertex v = (Vertex)Q.dequeue();
            for (Iterator it = v.outEdges(); it.hasNext();) {
                Edge e = (Edge)it.getNext();
                Vertex u = (Vertex)e.getVPosInV(1).getElem();
                if (UNDISCOVERED == u.getStatus()) {
                    e.setType(TREE);
                    u.setStatus(DISCOVERED);
                    Q.enqueue(u);
                    visit(u, v);
                } else {
                    e.setType(CROSS);
                }
            }
            v.setStatus(VISITED);
        }
        return null;
    }
}
