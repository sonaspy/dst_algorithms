
// test adjacencyGraph::maxProfitBBMaxClique

#include <iostream>
#include <iterator>
#include "adjacencyGraph.h"
#include "unweightedEdge.h"

using namespace std;

void main(void)
{
   // input a test graph
   std::cout << "Enter number of vertices and edges" << std::endl;
   int n, e;
   std::cin >> n >> e;
   adjacencyGraph g(n);

   for (int i = 1; i <= e; i++)
   {
      std::cout << "Enter edge " << i << std::endl;
      int u, v;
      std::cin >> u >> v;
      g.insertEdge(new unweightedEdge(u, v));
   }
   std::cout << "The undirected graph is" << std::endl;
   g.output(std::cout);

   int *c = new int [n + 1];
   std::cout << "The max clique size is " << g.maxProfitBBMaxClique(c) << std::endl;
   std::cout << "The vertex selection vector is ";
   copy(c + 1, c + n + 1, ostream_iterator<int>(std::cout, "  "));
   std::cout << std::endl;
}
