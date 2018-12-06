

typedef enum { UNDISCOVERED, DISCOVERED, VISITED } VStatus;  
typedef enum { UNDETERMINED, TREE, CROSS, FORWARD, BACKWARD } EType;  

template <class Tv, class Te>  
class Graph {  
private:
   void reset() {  
      for ( int i = 0; i < n; i++ ) {  
         status ( i ) = UNDISCOVERED; dTime ( i ) = fTime ( i ) = -1;  
         parent ( i ) = -1; priority ( i ) = INT_MAX;  
         for ( int j = 0; j < n; j++ )  
            if ( exists ( i, j ) ) type ( i, j ) = UNDETERMINED;  
      }
   }
   void BFS ( int, int& );  
   void DFS ( int, int& );  
   void BCC ( int, int&, Stack<int>& );  
   bool TSort ( int, int&, Stack<Tv>
   template <class PU> void PFS ( int, PU );  
public:
 
   int n;  
   virtual int insert ( Tv const& ) = 0;  
   virtual Tv remove ( int ) = 0;  
   virtual Tv& vertex ( int ) = 0;  
   virtual int inDegree ( int ) = 0;  
   virtual int outDegree ( int ) = 0;  
   virtual int firstNbr ( int ) = 0;  
   virtual int nextNbr ( int, int ) = 0;  
   virtual VStatus& status ( int ) = 0;  
   virtual int& dTime ( int ) = 0;  
   virtual int& fTime ( int ) = 0;  
   virtual int& parent ( int ) = 0;  
   virtual int& priority ( int ) = 0;  
 
   int e;  
   virtual bool exists ( int, int ) = 0;  
   virtual void insert ( Te const&, int, int, int ) = 0;  
   virtual Te remove ( int, int ) = 0;  
   virtual EType & type ( int, int ) = 0;  
   virtual Te& edge ( int, int ) = 0;  
   virtual int& weight ( int, int ) = 0;  
 
   void bfs ( int );  
   void dfs ( int );  
   void bcc ( int ); 
   void PFS(int s, PU prioUpdater) ;
   Stack<Tv>
   void prim ( int );  
   void dijkstra ( int );  
   template <class PU> void pfs ( int, PU );
};

template <class Tv, class Te>
void Graph<Tv, Te>::bfs(int s)
{
   reset();
   int clock = 0;
   int v = s;
   do
      if (UNDISCOVERED == status(v))
         BFS(v, clock);
   while ( (v = (++v % n)) != s);
}


template <class Tv, class Te>
void Graph<Tv, Te>::BFS(int v, int &clock)
{
   Queue<int> Q;
   status(v) = DISCOVERED;
   Q.enqueue(v);
   while (!Q.empty())
   {
      int v = Q.dequeue();
      dTime(v) = ++clock;
      for (int u = firstNbr(v); - 1 < u; u = nextNbr(v, u))
         if (UNDISCOVERED == status(u))
         {
            status(u) = DISCOVERED;
            Q.enqueue(u);
            type(v, u) = TREE;
            parent(u) = v;
         }
         else
            type(v, u) = CROSS;
      // finish
      status(v) = VISITED;
   }
}

template <class Tv, class Te>
void Graph<Tv, Te>::dijkstra(int s)
{
   reset();
   priority(s) = 0;
   for (int i = 0; i < n; i++)
   {
      status(s) = VISITED;
      if (-1 != parent(s))
         type(parent(s), s) = TREE;
      for (int j = firstNbr(s); - 1 < j; j = nextNbr(s, j))
         if ((status(j) == UNDISCOVERED) && (priority(j) > priority(s) + weight(s, j)))
         {
            priority(j) = priority(s) + weight(s, j);
            parent(j) = s;
         }
      for (int shortest = INT_MAX, j = 0; j < n; j++)
         if ((status(j) == UNDISCOVERED) && (shortest > priority(j)))
         {
            shortest = priority(j);
            s = j;
         }
   }
}

template <class Tv, class Te>
void Graph<Tv, Te>::prim(int s)
{
   reset();
   priority(s) = 0;
   for (int i = 0; i < n; i++)
   {
      status(s) = VISITED;
      if (-1 != parent(s))
         type(parent(s), s) = TREE;
      for (int j = firstNbr(s); - 1 < j; j = nextNbr(s, j))
         if ((status(j) == UNDISCOVERED) && (priority(j) > weight(s, j)))
         {
            priority(j) = weight(s, j);
            parent(j) = s;
         }
      for (int shortest = INT_MAX, j = 0; j < n; j++)
         if ((status(j) == UNDISCOVERED) && (shortest > priority(j)))
         {
            shortest = priority(j);
            s = j;
         }
   }
}

template <class Tv, class Te>
template <class PU>
void Graph<Tv, Te>::pfs(int s, PU prioUpdater)
{
   reset();
   int v = s;
   do
      if (UNDISCOVERED == status(v))
         PFS(v, prioUpdater);
   while (s != (v = (++v % n)));
}

template <class Tv, class Te>
template <class PU>
void Graph<Tv, Te>::PFS(int s, PU prioUpdater)
{
   priority(s) = 0;
   status(s) = VISITED;
   parent(s) = -1;
   while (1)
   {
      for (int w = firstNbr(s); - 1 < w; w = nextNbr(s, w))
         prioUpdater(this, s, w);
      for (int shortest = INT_MAX, w = 0; w < n; w++)
         if (UNDISCOVERED == status(w))
            if (shortest > priority(w))
            {
               shortest = priority(w);
               s = w;
            }
      if (VISITED == status(s))
         break;
      status(s) = VISITED;
      type(parent(s), s) = TREE;
   }
}

template <class Tv, class Te>
void Graph<Tv, Te>::dfs(int s)
{
   reset();
   int clock = 0;
   int v = s;
   do
      if (UNDISCOVERED == status(v))
         DFS(v, clock);
   while (s != (v = (++v % n)));
}


template <class Tv, class Te>
void Graph<Tv, Te>::DFS(int v, int &clock)
{
   dTime(v) = ++clock;
   status(v) = DISCOVERED;
   for (int u = firstNbr(v); - 1 < u; u = nextNbr(v, u))
      switch (status(u))
      {
      case UNDISCOVERED:
         type(v, u) = TREE;
         parent(u) = v;
         DFS(u, clock);
         break;
      case DISCOVERED:
         type(v, u) = BACKWARD;
         break;
      default:
         type(v, u) = (dTime(v) < dTime(u)) ? FORWARD : CROSS;
         break;
      }
   status(v) = VISITED;
   fTime(v) = ++clock;
}