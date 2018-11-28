// abstract class indexedBSTree
// abstract data type specification for indexed binary search trees
// all methods are pure virtual functions
// K is key type and E is value type

#ifndef indexedBSTree_
#define indexedBSTree_

#include "bsTree.h"

using namespace std;

template <class K, class E>
class indexedBSTree : public bsTree<K, E>
{
public:
  virtual pair<const K, E> *get(int) const = 0;
  // return pointer to pair with given index
  virtual void delete (int) = 0;
  // delete pair with given index
};


/*
 * 
 *
 *  AbstractDataType dIndexedBSTree
{
   instances
      same as for indexedBSTree except that the keys need not be distinct
   operations
      find(k): return the pair with key k
      find(index): return the indexth pair
      insert(p): insert pair p into the search tree
      erase(k): delete the pair with key k and return it
      erase(index): delete the indexth pair
      ascend(): output all pairs in nondecreasing order of key
}
 * 
 * 
 * 
 */

#endif
