// circular array implementation of a queue
// derives from the ADT queue

#ifndef arrayQueue_
#define arrayQueue_

#include "queue.h"
#include "myExceptions.h"
#include <sstream>

using namespace std;

template <class T>
class arrayQueue : public queue<T>
{
public:
    arrayQueue(int initialCapacity = 10);
    ~arrayQueue()
    {
        delete[] queue;
    }
    bool empty() const
    {
        return theFront == theBack;
    }
    int size() const
    {
        return (theBack - theFront + capacity) % capacity;
    }
    T &front()
    {
        // return front element
        if (theFront == theBack)
            throw queueEmpty();
        return queue[(theFront + 1) % capacity];
    }
    T &back()
    {
        // return theBack element
        if (theFront == theBack)
            throw queueEmpty();
        return queue[theBack];
    }
    void pop()
    {
        // remove theFront element
        if (theFront == theBack)
            throw queueEmpty();
        theFront = (theFront + 1) % capacity;
        queue[theFront].~T(); // destructor for T
    }
    void push(const T &theElement);

private:
    int theFront;    // 1 counterclockwise from theFront element
    int theBack;     // position of theBack element
    int capacity; // queue capacity
    T *queue;        // element array
};

template <class T>
arrayQueue<T>::arrayQueue(int initialCapacity)
{
    // Constructor.
    if (initialCapacity < 1)
        {
            ostringstream s;
            s << "Initial capacity = " << initialCapacity << " Must be > 0";
            throw illegalParameterValue(s.str());
        }
    capacity = initialCapacity;
    queue = new T[capacity];
    theFront = 0;
    theBack = 0;
}

template <class T>
void arrayQueue<T>::push(const T &theElement)
{
    // Add theElement to queue.
    // increase array length if necessary
    if ((theBack + 1) % capacity == theFront)
        {
            // double array length
            // allocate a new array
            T *newQueue = new T[2 * capacity];
            // copy elements into new array
            int start = (theFront + 1) % capacity;
            if (start < 2)
                // no wrap around
                copy(queue + start, queue + start + capacity - 1, newQueue);
            else
                {
                    // queue wraps around
                    copy(queue + start, queue + capacity, newQueue);
                    copy(queue, queue + theBack + 1, newQueue + capacity - start);
                }
            // switch to newQueue and set theFront and theBack
            theFront = 2 * capacity - 1;
            theBack = capacity - 2; // queue size capacity - 1
            capacity *= 2;
            queue = newQueue;
        }
    // put theElement at the theBack of the queue
    theBack = (theBack + 1) % capacity;
    queue[theBack] = theElement;
}

#endif
