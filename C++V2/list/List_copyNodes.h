

#pragma once

template <typename T>
void List<T>::copyNodes(Posi(T) p, int n)
{
    init();
    while (n--)
    {
        insertAsLast(p->data);
        p = p->succ;
    }
}