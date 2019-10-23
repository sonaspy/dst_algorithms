#ifndef __DICTIONARY__
#define __DICTIONARY__

using namespace std;

template <class K, class E>
class dictionary
{
public:
    virtual ~dictionary() {}
    virtual bool empty() = 0;
    // return true iff dictionary is empty

    virtual int size() = 0;
    // return number of pairs in dictionary

    virtual pair<K, E> *get(K &) = 0;
    // return pointer to matching pair

    virtual void erase(K &) = 0;
    // remove matching pair

    virtual void insert(pair<K, E> &) = 0;
    // insert a (key, value) pair into the dictionary
};
#endif
