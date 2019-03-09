











package dsa;

public class DFSReachableComponent extends DFS {

    public DFSReachableComponent(Graph g) {
        super(g);
    }


    protected Object visit(Vertex v, Object info) {
        ((Stack)info).push(v);
        return null;
    }


    public Object algorithm(Vertex s, Object info) {
        reset(s);
        Stack S = new Stack_Array();
        traverse(s, info);
        return null;
    }
}
