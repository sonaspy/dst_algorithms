

#include "../list/List.h"
template <class T> class Stack: public List<T>
{
public:
    void push ( T const& e )
    {
        insertAsLast ( e );
    }
    T pop()
    {
        return remove ( last() );
    }
    T& top()
    {
        return last()->data;
    }
};
