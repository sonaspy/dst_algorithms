// test linked representation of a weighted graph

#include <iostream>
#include "linkedWGraph.h"
#include "weightedEdge.h"

using namespace std;

void main(void)
{
   linkedWGraph<int> g(4);
   std::cout << "Number of Vertices = " << g.numberOfVertices() << std::endl;
   std::cout << "Number of Edges = " << g.numberOfEdges() << std::endl;
   std::cout << std::endl;

   g.insertEdge(new weightedEdge<int>(2, 4, 1));
   g.insertEdge(new weightedEdge<int>(1, 3, 2));
   g.insertEdge(new weightedEdge<int>(2, 1, 3));
   g.insertEdge(new weightedEdge<int>(1, 4, 4));
   g.insertEdge(new weightedEdge<int>(4, 2, 5));
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
   std::cout << "Edges incident to vertex 4" << std::endl;
   vertexIterator<int>* gi = g.iterator(4);
   pair<int,int>* thePair;
   while((thePair = gi->next()) != NULL)
      std::cout << thePair->first << " " << thePair->second << std::endl;
}
