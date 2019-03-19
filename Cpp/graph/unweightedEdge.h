// edge in an unweighted graph

#ifndef unweightedEdge_
#define unweightedEdge_

#include "edge.h"
#include "myExceptions.h"

using namespace std;

class unweightedEdge: public edge<bool>
{
public:
    unweightedEdge(int V1, int V2)
    {
        v1 = V1;
        v2 = V2;
    }
    ~unweightedEdge();
    int vertex1() const
    {
        return v1;
    }
    int vertex2() const
    {
        return v2;
    }
    bool weight() const
    {
        return true;
    }
private:
    int v1, v2;
};

#endif
