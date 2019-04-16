/******************************************************************************************

 ******************************************************************************************/

#pragma once

template <typename T> //复制列表中自位置p起的n项（assert: p为合法位置，且至少有n-1个后继节点）
List<T>::List ( ListNodePosi(T) p, int n ) { copyNodes ( p, n ); }

template <typename T> //整体复制列表L
List<T>::List ( List<T> const& L ) { copyNodes ( L.first(), L._size ); }

template <typename T> //复制L中自第r项起的n项（assert: r+n <= L._size）
List<T>::List ( List<T> const& L, int r, int n ) { copyNodes ( L[r], n ); }