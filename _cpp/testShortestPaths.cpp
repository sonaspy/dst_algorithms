// test adjacencyWDigraph::shortestPaths */
#include <iostream>
#include "adjacencyWDigraph.h"
#include "adjacencyWGraph.h"

using namespace std;


void main(void)
{
   const int numberOfTypes = 2;
   // create a graph of each adjacency weighted type
   adjacencyWDigraph<int> *g[numberOfTypes];

   // input a test graph
   std::cout << "Enter number of vertices and edges" << std::endl;
   int n, e;
   std::cin >> n >> e;
   g[0] = new adjacencyWGraph<int>(n);
   g[1] = new adjacencyWDigraph<int>(n);
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

   // test shortestPaths
   int *dist = new int [n + 1];
   int *p = new int [n + 1];
   g[0]->shortestPaths(1, dist, p);
   std::cout << "The dist and p values for the undirected graph are" << std::endl;
   for (int i = 1; i <= n; i++)
      std::cout << dist[i] << " " << p[i] << std::endl;

   g[1]->shortestPaths(1, dist, p);
   std::cout << "\nThe dist and p values for the directed graph are" << std::endl;
   for (int i = 1; i <= n; i++)
      std::cout << dist[i] << " " << p[i] << std::endl;
}
