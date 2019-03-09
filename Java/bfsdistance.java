











package dsa;

public class BFSDistance extends BFS {

    public BFSDistance(Graph g) {
        super(g);
    }


    protected Object visit(Vertex v, Object info)   {
        if (null == info)
            v.setDistance(0);
        else
            v.setDistance(((Vertex)info).getDistance() + 1);
        return null;
    }


    public Object algorithm(Vertex s, Object info) {
        reset(s);
        traverse(s, info);
        return null;
    }
}
