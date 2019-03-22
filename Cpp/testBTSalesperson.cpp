// test adjacencyWDigraph::btSalesperson, backtracking algorithm

#include <iostream>
#include <iterator>
#include "adjacencyWDigraph.h"
#include "adjacencyWGraph.h"
#include "weightedEdge.h"

using namespace std;

void main(void)
{
   const int numberOfTypes = 2;
   // create a graph of each adjacency weighted type
   adjacencyWDigraph<int> *g[numberOfTypes];

   // input a test graph
   std::cout << "Enter number of vertices and edges"<< std::endl;
   int n, e;
   std::cin >> n >> e;
   g[0] = new adjacencyWGraph<int>(n, 100);
   g[1] = new adjacencyWDigraph<int>(n, 100);
   for (int i = 1; i <= e; i++)
   {
      std::cout << "Enter weighted edge " << i << std::endl;
      int u, v, w;
      std::cin >> u >> v >> w;
      g[0]->insertEdge(new weightedEdge<int>(u, v, w));
      g[1]->insertEdge(new weightedEdge<int>(u, v, w));
   }

   std::cout << "The weighted undirected graph is" << std::endl;
   g[0]->output(std::cout);
   std::cout << "\nThe weighted digraph is" << std::endl;
   g[1]->output(std::cout);

   // test btSalesperson
   int *p = new int [n + 1];
   std::cout << "\nThe length of the shortest tour is "
        << g[0]->btSalesperson(p) << std::endl;
   std::cout << "The shortest tour is ";
   copy(p + 1, p + n + 1, ostream_iterator<int>(std::cout, "  "));
   std::cout << std::endl;

   std::cout << "\nThe length of the shortest tour is "
        << g[1]->btSalesperson(p) << std::endl;
   std::cout << "The shortest tour is ";
   copy(p + 1, p + n + 1, ostream_iterator<int>(std::cout, "  "));
   std::cout << std::endl;
}
