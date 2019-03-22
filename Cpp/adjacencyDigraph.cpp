// test adjacency matrix representation of an unweighted digraph

#include <iostream>
#include "adjacencyDigraph.h"
#include "unweightedEdge.h"

using namespace std;

void main(void)
{
   adjacencyDigraph g(4);
   std::cout << "Number of Vertices = " << g.numberOfVertices() << std::endl;
   std::cout << "Number of Edges = " << g.numberOfEdges() << std::endl;
   std::cout << std::endl;

   g.insertEdge(new unweightedEdge(2, 4));
   g.insertEdge(new unweightedEdge(1, 3));
   g.insertEdge(new unweightedEdge(2, 1));
   g.insertEdge(new unweightedEdge(1, 4));
   g.insertEdge(new unweightedEdge(4, 2));
   std::cout << "The graph is" << std::endl;
   std::cout << "Number of Vertices = " << g.numberOfVertices() << std::endl;
   std::cout << "Number of Edges = " << g.numberOfEdges() << std::endl;
   std::cout << g << std::endl;
   std::cout << std::endl;

   g.eraseEdge(2,1);
   std::cout << "The graph after deleting (2,1) is" << std::endl;
   std::cout << "Number of Vertices = " << g.numberOfVertices() << std::endl;
   std::cout << "Number of Edges = " << g.numberOfEdges() << std::endl;
   std::cout << g << std::endl;

   std::cout << "existsEdge(3,1) = " << g.existsEdge(3,1) << std::endl;
   std::cout << "existsEdge(1,3) = " << g.existsEdge(1,3) << std::endl;
   std::cout << "inDegree(3) = " << g.inDegree(3) << std::endl;
   std::cout << "outDegree(1) = " << g.outDegree(1) << std::endl;
   std::cout << "Number of Vertices = " << g.numberOfVertices() << std::endl;
   std::cout << "Number of Edges = " << g.numberOfEdges() << std::endl;
   std::cout << std::endl;

   // test iterator
   std::cout << "Vertices adjacenct to vertex 4" << std::endl;
   vertexIterator<bool>* gi = g.iterator(4);
   pair<int,bool>* thePair;
   while((thePair = gi->next()) != NULL)
      std::cout << thePair->first << std::endl;
}
