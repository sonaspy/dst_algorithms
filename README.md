# Data Structure and Algorithms


## Example 
![avatar](./demo/rbtree_demo_use00.png)
![avatar](./demo/rbtree_demo_use01.png)
![avatar](./demo/skiplist_rbtree_compare.png)
## lastest huffman implementation !
```
The Total optimal WPL is -> 230
t
freq is -> 9
code is -> " 111 "
e
freq is -> 6
code is -> " 010 "
o
freq is -> 5
code is -> " 000 "
a
freq is -> 4
code is -> " 1000 "
i
freq is -> 3
code is -> " 0011 "
n
freq is -> 3
code is -> " 0110 "
r
freq is -> 3
code is -> " 0111 "
m
freq is -> 2
code is -> " 10010 "
l
freq is -> 2
code is -> " 11011 "
f
freq is -> 2
code is -> " 11000 "
x
freq is -> 2
code is -> " 10100 "
u
freq is -> 2
code is -> " 0010 "
d
freq is -> 2
code is -> " 10110 "
F
freq is -> 1
code is -> " 101011 "
#
freq is -> 1
code is -> " 101110 "
L
freq is -> 1
code is -> " 101111 "
A
freq is -> 1
code is -> " 100111 "
=
freq is -> 1
code is -> " 110010 "
p
freq is -> 1
code is -> " 110011 "
c
freq is -> 1
code is -> " 110100 "
s
freq is -> 1
code is -> " 110101 "
*
freq is -> 1
code is -> " 100110 "
z
freq is -> 1
code is -> " 101010 "
🌲  HUFFMAN TREE  🌲
                                                               �                                                                 
                                               /                               \                                                 
                               �                                                               �                                 
                       /               \                                               /               \                         
               �                               �                               �                               �                 
           /       \                       /       \                       /       \                       /       \             
       o               �               e               �               �               �               �               t         
                     /   \                           /   \           /   \           /   \           /   \                       
                   u       i                       n       r       a       �       �       �       �       �                     
                                                                          / \     / \     / \     / \     / \                    
                                                                         m   �   x   �   d   �   f   �   �   l                   
                                                                            / \     / \     / \     / \ / \                      
                                                                            * A     z F     # L     = p c s                      
🌲  HUFFMAN TREE  🌲


```
This reporsitoriy including but not limited to the following content

- linkedChain
- linearList
- matrix
- greedy
- spanning tree
- dynamic programming
- divide and rule
- sorting
- tournamentTree
- heap
- graph
- balancedTree
- binaryTree
- searchTree
- queue
- stack
- rbtree
- hashing

```
C++ head file like this one
===========================
// abstract class dictionary
// abstract data type specification for dictionary data structure
// all methods are pure virtual functions
// K is key type and E is value type

#ifndef dictionary_
#define dictionary_

using namespace std;

template <class K, class E>
class dictionary
{
public:
  virtual ~dictionary() {}
  virtual bool empty() const = 0;
  // return true iff dictionary is empty
  virtual int size() const = 0;
  // return number of pairs in dictionary
  virtual pair<const K, E> *find(const K &) const = 0;
  // return pointer to matching pair
  virtual void erase(const K &) = 0;
  // remove matching pair
  virtual void insert(const pair<const K, E> &) = 0;
  // insert a (key, value) pair into the dictionary
};

#endif


```





@NewGuo,2018

