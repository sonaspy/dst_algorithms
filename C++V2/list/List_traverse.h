
#pragma once

template <typename T> void List<T>::traverse ( void ( 
{  for ( ListNodePosi(T) p = header->succ; p != trailer; p = p->succ ) visit ( p->data );  }

template <typename T> template <typename VST>  
void List<T>::traverse ( VST& visit )  
{  for ( ListNodePosi(T) p = header->succ; p != trailer; p = p->succ ) visit ( p->data );  }