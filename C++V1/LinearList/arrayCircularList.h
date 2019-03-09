// arrayCircularList extended
#ifndef arrayCircularList_
#define arrayCircularList_

#include<iostream>
#include<sstream>
#include "linearList.h"
#include "myExceptions.h"
#include "changeLength1D.h"

template<class T>
class circularArrayList : public linearList<T>
{
public:
    // constructor, copy constructor and destructor
    circularArrayList(int initialCapacity = 10);
    circularArrayList(const circularArrayList<T>&);
    ~circularArrayList()
    {
        delete [] element;
    }

    // ADT methods
    bool empty() const
    {
        return first == -1;
    }
    int size() const
    {
        if (first == -1)
            return 0;
        else
            return (arrayLength + last - first) % arrayLength + 1;
    }
    T& get(int theIndex) const;
    int indexOf(const T& theElement) const;
    void erase(int theIndex);
    void insert(int theIndex, const T& theElement);
    void output(ostream& out) const;

    // additional method
    int capacity() const
    {
        return arrayLength;
    }

protected:
    void checkIndex(int theIndex) const;
    // throw illegalIndex if theIndex invalid
    T* element;            // 1D array to hold list elements
    int arrayLength;       // capacity of the 1D array
    int first;             // location of first element
    int last;              // location of last element
};

template<class T>
circularArrayList<T>::circularArrayList(int initialCapacity)
{
    // Constructor.
    if (initialCapacity < 1)
        {
            ostringstream s;
            s << "Initial capacity = " << initialCapacity << " Must be > 0";
            throw illegalParameterValue(s.str());
        }
    arrayLength = initialCapacity;
    element = new T[arrayLength];
    first = -1;   // list is empty
}

template<class T>
circularArrayList<T>::circularArrayList(const circularArrayList<T>& theList)
{
    // Copy constructor.
    arrayLength = theList.arrayLength;
    element = new T[arrayLength];
    first = theList.first;
    if (first == -1)
        return;   // theList is empty
    // non-empty list
    last = theList.last;
    int current = first;
    while (current != last)
        {
            element[current] = theList.element[current];
            current = (current + 1) % arrayLength;
        }
    element[current] = theList.element[current];
}

template<class T>
void circularArrayList<T>::checkIndex(int theIndex) const
{
    // Verify that theIndex is between 0 and size() - 1.
    int listSize = size();
    if (theIndex < 0 || theIndex >= listSize)
        {
            ostringstream s;
            s << "index = " << theIndex << " size = " << listSize;
            throw illegalIndex(s.str());
        }
}

template<class T>
T& circularArrayList<T>::get(int theIndex) const
{
    // Return element whose index is theIndex.
// Throw illegalIndex exception if no such element.
    checkIndex(theIndex);
    return element[(first + theIndex) % arrayLength];
}

template<class T>
int circularArrayList<T>::indexOf(const T& theElement) const
{
    // Return index of first occurrence of theElement.
// Return -1 if theElement not in list.
    int listSize = size();
    for (int i = 0; i < listSize; i++)
        if (element[(first + i) % arrayLength] == theElement)
            return i;
    return -1;
}

template<class T>
void circularArrayList<T>::erase(int theIndex)
{
    // Delete the element whose index is theIndex.
// Throw illegalIndex exception if no such element.
    checkIndex(theIndex);
    // no exception thrown, valid index, remove element
    if (size() == 1)
        {
            // list becomes empty
            element[first].~T();   // delete element
            first = -1;
            return;
        }
    // determine which side has fewer elements
    // and shift the smaller number of elements
    int listSize = size();
    if (theIndex <= (listSize - 1) / 2)
        {
            // shift elements theIndex - 1 ... 0
            for (int i = theIndex - 1; i >= 0; i--)
                element[(first + i + 1) % arrayLength]
                    = element[(first + i) % arrayLength];
            element[first].~T();    // delete
            first = (first + 1) % arrayLength;
        }
    else
        {
            // shift elements theIndex + 1 ... size() - 1
            for (int i = theIndex + 1; i < listSize; i++)
                element[(first + i - 1) % arrayLength]
                    = element[(first + i) % arrayLength];
            element[last].~T();   // delete
            last = (arrayLength + last - 1) % arrayLength;
        }
}

template<class T>
void circularArrayList<T>::insert(int theIndex, const T& theElement)
{
    // Insert theElement so that its index is theIndex.
    int listSize = size();
    if (theIndex < 0 || theIndex > listSize)
        {
            // invalid index
            ostringstream s;
            s << "index = " << theIndex << " size = " << listSize;
            throw illegalIndex(s.str());
        }
    // valid index, handle empty list as special case
    if (first == -1)
        {
            // insert into empty list
            first = last = 0;
            element[0] = theElement;
            return;
        }
    // insert into a nonempty list, make sure we have space
    if (listSize == arrayLength)
        {
            // no space, double capacity
            T* newArray = new T [2 * arrayLength];
            // copy elements into new array beginning at position  0
            int j = 0;   // position in newArray to copy to
            for (int i = first;
                    i != last; i = (i + 1) % arrayLength)
                newArray[j++] = element[i];
            newArray[j] = element[last];  // copy last element
            // switch to newArray and set first and last
            delete [] element;
            element = newArray;
            arrayLength *= 2;
            first = 0;
            last = j;
        }
    // create space for new element
    if (theIndex <= listSize / 2)
        {
            // shift elements 0 through theIndex - 1
            for (int i = 0; i < theIndex; i++)
                element[(arrayLength + first + i - 1) % arrayLength]
                    = element[(first + i) % arrayLength];
            first = (arrayLength + first - 1) % arrayLength;
        }
    else
        {
            // shift elements listSize - 1  ... theIndex
            for (int i = listSize - 1; i >= theIndex; i--)
                element[(first + i + 1) % arrayLength]
                    = element[(first + i) % arrayLength];
            last = (last + 1) % arrayLength;
        }
    // insert new element
    element[(first + theIndex) % arrayLength] = theElement;
}

template<class T>
void circularArrayList<T>::output(ostream& out) const
{
    // Put the list into the stream out.
    if (first == -1)
        return;   // list is empty
    // non-empty list
    int current = first;
    while (current != last)
        {
            cout << element[current]  << "  ";
            current = (current + 1) % arrayLength;
        }
    cout << element[current]  << "  ";
}

// overload <<
template <class T>
ostream& operator<<(ostream& out, const circularArrayList<T>& x)
{
    x.output(out);
    return out;
}





#endif
