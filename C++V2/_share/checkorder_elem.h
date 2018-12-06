



template <typename T> struct CheckOrder {  
   T pred; int& u;
   CheckOrder ( int& unsorted, T& first ) : pred ( first ), u ( unsorted ) { }
   virtual void operator() ( T& e ) { if ( pred > e ) u++; pred = e; }
};
