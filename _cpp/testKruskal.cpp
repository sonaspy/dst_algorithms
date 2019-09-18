// test graph::kruskal

#include <iostream>
#include "adjacencyWGraph.h"
#include "linkedWGraph.h"
#include "weightedEdge.h"

using namespace std;

void main(void)
{
   const int numberOfTypes = 2;
   // create a graph of each weighted undirected type
   graph<int>* g[numberOfTypes];
   int n = 7;
   g[0] = new adjacencyWGraph<int>(n);
   g[1] = new linkedWGraph<int>(n);

   // input a test graph
   std::cout << "Enter number of edges in 7 vertex graph" << std::endl;
   int e;
   std::cin >> e;
   for (int i = 1; i <= e; i++)
   {
      std::cout << "Enter weighted edge " << i << std::endl;
      int u, v, w;
      std::cin >> u >> v >> w;
      g[0]->insertEdge(new weightedEdge<int>(u, v, w));
      g[1]->insertEdge(new weightedEdge<int>(u, v, w));
   }

   std::cout << "The adjacency matrix is" << std::endl;
   g[0]->output(std::cout);
   std::cout << "\nThe linked lists are" << std::endl;
   g[1]->output(std::cout);

   // test kruskal
   weightedEdge<int> *edge = new weightedEdge<int> [n];
   std::cout << "Using cost-adjacency matrix" << std::endl;
   if (g[0]->kruskal(edge))
   {// found the spanning tree
      std::cout << "The min cost spanning tree edges are" << std::endl;
      for (int i = 0; i < n - 1; i++)
         std::cout << edge[i] << std::endl;
   }

   std::cout << "\nUsing linked-adjacency lists" << std::endl;
   if (g[1]->kruskal(edge))
   {// found the spanning tree
      std::cout << "The min cost spanning tree edges are" << std::endl;
      for (int i = 0; i < n - 1; i++)
         std::cout << edge[i] << std::endl;
   }
}
