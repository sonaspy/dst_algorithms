












package  dsa;

public interface Graph {

    public int vNumber();
    public int eNumber();


    public Iterator vertices();
    public Iterator vPositions();


    public Iterator edges();
    public Iterator ePositions();


    public boolean areAdjacent(Vertex u, Vertex v);

    public Edge edgeFromTo(Vertex u, Vertex v);


    public Vertex remove(Vertex v);

    public Edge remove(Edge e);

    public Position insert(Vertex v);

    public Position insert(Edge e);
}