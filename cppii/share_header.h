#pragma once
#include <stdlib.h>
#include <time.h>
#include "list.h"
#include "vector.h"
template <typename T>
struct CheckOrder
{ //Function object: determines whether a T class object is locally ordered
    T pred;
    int &u;
    CheckOrder(int &unsorted, T &first) : pred(first), u(unsorted) {}
    virtual void operator()(T &e)
    {
        if (pred > e)
            u++;
        pred = e;
    }
};

template <typename T>
void checkOrder(List<T> &L)
{                                                         // judge whether the list is in overall order
    int unsorted = 0;                                     // reverse counter
    L.traverse(CheckOrder<T>(unsorted, L.first()->data)); // traversal
    if (0 < unsorted)
        printf("Unsorted with %d adjacent disordered pair(s)\n", unsorted);
    else
        printf("Sorted\n");
    printf("DISORDERED = %d\n", L.disordered());
}
template <typename T>
void checkOrder(Vector<T> &V)
{                                              // judge whether the vector is in overall order
    int unsorted = 0;                          //Reverse counter
    V.traverse(CheckOrder<T>(unsorted, V[0])); //To traverse
    if (0 < unsorted)
        printf("Unsorted with %d adjacent disordered pair(s)\n", unsorted);
    else
        printf("Sorted\n");
}

template <typename T>
static bool lt(T *a, T *b) { return lt(*a, *b); } //less than

template <typename T>
static bool lt(T &a, T &b) { return a < b; } //less than

template <typename T>
static bool eq(T *a, T *b) { return eq(*a, *b); } //equal

template <typename T>
static bool eq(T &a, T &b) { return a == b; } //equal

template <typename T>
struct Crc
{ // function object: accumulates the characteristics of T class objects (such as the sum) in order to verify the collection of objects
    T &c;
    Crc(T &crc) : c(crc) {}
    virtual void operator()(T &e) { c += e; } // assuming that T can be added directly
};

template <typename T>
void crc(List<T> &L)
{ //Statistical list characteristics (sum of all elements)
    T crc = 0;
    L.traverse(Crc<T>(crc)); //Traversal is performed with CRC as the basic operation
    printf("CRC =");
    print(crc);
    printf("\n"); //The characteristics obtained by output statistics
}

template <typename T>
void crc(Vector<T> &V)
{
    T crc = 0;
    V.traverse(Crc<T>(crc));
    printf("CRC =");
    print(crc);
    printf("\n");
}

template <typename T>
struct Decrease //Function object: decrement a T class object
{
    virtual void operator()(T &e) { e--; }
}; //Suppose T can be decremented directly or is overloaded--

template <typename T>
void decrease(List<T> &L) //Unify the elements in the decrement list
{
    L.traverse(Decrease<T>());
} //Decrease<T>() is the basic operation to traverse

template <typename T>
void decrease(Vector<T> &V) //Unify the elements of the decreasing vector
{
    V.traverse(Decrease<T>());
} //Decrease<T>() is the basic operation to traverse

template <typename T>
struct Double //Function object: multiply a t-class object
{
    virtual void operator()(T &e) { e *= 2; }
}; //Let's say that T can be directly multiplied

template <typename T>
void double(Vector<T> &V) //Unify the elements of the doubling vector
{
    V.traverse(Double<T>());
} //Iterate over Double<T>() as the base operation

template <typename T>
struct Half //Function object: halve a T class object
{
    virtual void operator()(T &e) { e /= 2; }
}; //Let's say that T can be cut in half

template <typename T>
void half(List<T> &L) //Unify the elements in the halving list
{
    L.traverse(Half<T>());
} //Traversal is performed with Half<T>() as the basic operation

template <typename T>
struct Increase //Function object: increments a T class object
{
    virtual void operator()(T &e) { e++; }
}; //Suppose T can be incremented directly or is overloaded++

template <typename T>
void increase(List<T> &L) //Unifying the elements of an increasing list
{
    L.traverse(Increase<T>());
} //Iterate through the base operation Increase<T>()

template <typename T>
struct Hailstone
{ //Function object: converts a t-class object according to the Hailstone rule
    virtual void operator()(T &e)
    {                 //Let's say T can do the arithmetic directly
        int step = 0; //Number of steps required to convert
        while (1 != e)
        { //Press odd and even to convert gradually to 1
            (e % 2) ? e = 3 *e + 1 : e /= 2;
            step++;
        }
        e = step; //Returns the number of steps taken by the conversion
    }
};

template <typename T>
void increase(Vector<T> &V) //Uniformly increasing elements of a vector
{
    V.traverse(Increase<T>());
} //Iterate through the base operation Increase<T>()

static int dice(int range) { return rand() % range; }               //Take the random integer in [0, range)
static int dice(int lo, int hi) { return lo + rand() % (hi - lo); } //Take a random integer in [lo, hi)
static float dice(float range) { return rand() % (1000 * (int)range) / (float)1000.; }
static double dice(double range) { return rand() % (1000 * (int)range) / (double)1000.; }
static char dice(char range) { return (char)(32 + rand() % 96); }



#include <typeinfo>

template <typename T>
struct Cleaner
{
    static void clean(T x)
    { //It's a recursive basis
#ifdef _DEBUG
        static int n = 0;
        if (7 > strlen(typeid(T).name()))
        { //Complex types are ignored and only primitive types are printed
            printf("\t<%s>[%d]=", typeid(T).name(), ++n);
            print(x);
            printf(" purged\n");
        }
#endif
    }
};

template <typename T>
struct Cleaner<T *>
{
    static void clean(T *x)
    {
        if (x)
        {
            delete x;
        } //If it contains Pointers, recursively release them
#ifdef _DEBUG
        static int n = 0;
        printf("\t<%s>[%d] released\n", typeid(T *).name(), ++n);
#endif
    }
};

template <typename T>
void release(T x) { Cleaner<T>::clean(x); }
