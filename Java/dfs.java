











package dsa;

public abstract class DFS extends GraphTraverse {

    protected static int clock = 0;


    public DFS(Graph g) {
        super(g);
    }


    protected Object traverse(Vertex v, Object info) {
        if (UNDISCOVERED != v.getStatus())  return null;
        v.setDStamp(clock++);
        v.setStatus(DISCOVERED);
        visit(v, info);
        for (Iterator it = v.outEdges(); it.hasNext();) {
            Edge e = (Edge)it.getNext();
            Vertex u = (Vertex)e.getVPosInV(1).getElem();
            switch (u.getStatus()) {
            case  UNDISCOVERED :
                e.setType(TREE);
                traverse(u, info);
                break;
            case  DISCOVERED :
                e.setType(BACKWARD);
                break;
            default :
                if (u.getDStamp() < v.getDStamp())
                    e.setType(CROSS);
                else
                    e.setType(FORWARD);
                break;
            }
        }
        v.setFStamp(clock++);
        v.setStatus(VISITED);
        return null;
    }
}
