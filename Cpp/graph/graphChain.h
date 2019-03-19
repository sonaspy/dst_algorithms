// Extension of chain to include a method to erase by matching element field
// This class is for use by the linked graph classes

#ifndef graphChain_
#define graphChain_

#include "chainWithIterator.h"
#include "chainNode.h"

using namespace std;

template <class T>
class graphChain : public chain<T>
{
public:
    T *eraseElement(int theVertex)
    {
        // Delete node with element == theVertex. Return pointer to
        // deleted element. Return NULL if no matching element.
        chainNode<T> *walk = firstNode,
                      *prewalk = NULL; // one behind walk
        // search for match
        while (walk != NULL && walk->element != theVertex)
            {
                prewalk = walk;
                walk = walk->next;
            }
        if (walk == NULL) // no match
            return NULL;
        // match found in node walk
        T *theElement = &walk->element; // save matching element
        // remove walk from chain
        if (prewalk != NULL)
            prewalk->next = walk->next;
        else
            firstNode = walk->next; // walk is first node
        delete walk;
        listSize--;
        return theElement;
    }
};
#endif
