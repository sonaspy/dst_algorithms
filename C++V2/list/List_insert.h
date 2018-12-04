#pragma once

template <typename T>
Posi(T) List<T>::insertAsFirst(T const &e)
{
    _size++;
    return header->insertAsSucc(e);
}

template <typename T>
Posi(T) List<T>::insertAsLast(T const &e)
{
    _size++;
    return trailer->insertAsPred(e);
}

template <typename T>
Posi(T) List<T>::insertA(Posi(T) p, T const &e)
{
    _size++;
    return p->insertAsSucc(e);
}

template <typename T>
Posi(T) List<T>::insertB(Posi(T) p, T const &e)
{
    _size++;
    return p->insertAsPred(e);
}