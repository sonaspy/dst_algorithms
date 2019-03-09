












package  dsa;

public interface Edge {

    final static int UNKNOWN = 0;
    final static int TREE = 1;
    final static int CROSS = 2;
    final static int FORWARD = 3;
    final static int BACKWARD = 4;


    public Object getInfo();

    public Object setInfo(Object x);


    public Position getEPosInE();

    public Position getVPosInV(int i);

    public Position getEPosInI(int i);


    public int getType();
    public int setType(int t);
}
