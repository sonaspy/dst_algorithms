// test graph::findPath

#include <iostream>
#include "graph.h"
#include "adjacencyWDigraph.h"
#include "adjacencyDigraph.h"
#include "adjacencyWGraph.h"
#include "adjacencyGraph.h"
#include "linkedWDigraph.h"
#include "linkedDigraph.h"
#include "linkedWGraph.h"
#include "linkedGraph.h"
#include "weightedEdge.h"
#include "unweightedEdge.h"

using namespace std;

void main(void)
{
   int numberOfTypes = 4;
   // create a graph of each type
   graph<bool>* g[4];
   graph<int>* h[4];
   g[0] = new adjacencyGraph(7);
   g[1] = new adjacencyDigraph(7);
   g[2] = new linkedGraph(7);
   g[3] = new linkedDigraph(7);
   h[0] = new adjacencyWGraph<int>(7);
   h[1] = new adjacencyWDigraph<int>(7);
   h[2] = new linkedWGraph<int>(7);
   h[3] = new linkedWDigraph<int>(7);
   int n = 7;   // number of vertices

   // input a test graph
   std::cout << "Enter number of edges in graph" << std::endl;
   int e, u, v, w;
   std::cin >> e;
   for (int i = 1; i <= e; i++)
   {
      std::cout << "Enter weighted edge " << i << std::endl;
      std::cin >> u >> v >> w;
      for (int j = 0; j < numberOfTypes; j++)
      {
         g[j]->insertEdge(new unweightedEdge(u, v));
         h[j]->insertEdge(new weightedEdge<int>(u, v, w));
      }
   }

   // output the test graphs
   for (int i = 0; i < numberOfTypes; i++)
   {
      std::cout << "Graph " << i << " is" << std::endl;
      std::cout << "Number of Vertices = " << g[i]->numberOfVertices() << std::endl;
      std::cout << "Number of Edges = " << g[i]->numberOfEdges() << std::endl;
      g[i]->output(std::cout);
      std::cout << std::endl << std::endl;
   }
   for (int i = 0; i < numberOfTypes; i++)
   {
      std::cout << "Graph " << i + numberOfTypes << " is" << std::endl;
      std::cout << "Number of Vertices = " << h[i]->numberOfVertices() << std::endl;
      std::cout << "Number of Edges = " << h[i]->numberOfEdges() << std::endl;
      h[i]->output(std::cout);
      std::cout << std::endl << std::endl;
   }

   // test findPath on all graph types
   for (int i = 0; i < numberOfTypes; i++)
   {
      int* path = g[i]->findPath(1, 3);
      if (path == NULL)
         std::cout << "No path from 1 to 3" << std::endl;
      else
      {
         std::cout << "Path from 1 to 3 is ";
         copy(path + 1, path + path[0] + 2, ostream_iterator<int>(std::cout, "  "));
         std::cout << std::endl;
      }

      path = g[i]->findPath(4, 6);
      if (path == NULL)
         std::cout << "No path from 4 to 6" << std::endl;
      else
      {
         std::cout << "Path from 4 to 6 is ";
         copy(path + 1, path + path[0] + 2, ostream_iterator<int>(std::cout, "  "));
         std::cout << std::endl;
      }

      path = g[i]->findPath(1, 6);
      if (path == NULL)
         std::cout << "No path from 1 to 6" << std::endl;
      else
      {
         std::cout << "Path from 1 to 6 is ";
         copy(path + 1, path + path[0] + 2, ostream_iterator<int>(std::cout, "  "));
         std::cout << std::endl;
      }
   }
   for (int i = 0; i < numberOfTypes; i++)
   {
      int* path = h[i]->findPath(1, 3);
      if (path == NULL)
         std::cout << "No path from 1 to 3" << std::endl;
      else
      {
         std::cout << "Path from 1 to 3 is ";
         copy(path + 1, path + path[0] + 2, ostream_iterator<int>(std::cout, "  "));
         std::cout << std::endl;
      }

      path = h[i]->findPath(4, 6);
      if (path == NULL)
         std::cout << "No path from 4 to 6" << std::endl;
      else
      {
         std::cout << "Path from 4 to 6 is ";
         copy(path + 1, path + path[0] + 2, ostream_iterator<int>(std::cout, "  "));
         std::cout << std::endl;
      }

      path = h[i]->findPath(1, 6);
      if (path == NULL)
         std::cout << "No path from 1 to 6" << std::endl;
      else
      {
         std::cout << "Path from 1 to 6 is ";
         copy(path + 1, path + path[0] + 2, ostream_iterator<int>(std::cout, "  "));
         std::cout << std::endl;
      }
   }
}
