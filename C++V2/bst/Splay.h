#include "BST.h"

#ifndef Splay_
#define Splay_

template <class T>
class Splay : public BST<T>
{
  protected:
    BinNodePosi(T) splay(BinNodePosi(T) v);

  public:
    BinNodePosi(T) & search(const T &e);
    BinNodePosi(T) insert(const T &e);
    bool remove(const T &e);
};

template <class T>
    BinNodePosi(T) & Splay<T>::search(const T &e)
{
    BinNodePosi(T) p = searchIn(_root, e, _hot = NULL);
    _root = splay(p ? p : _hot);
    return _root;
}

template <class NodePosi>
inline 
    void
    attachAsLChild(NodePosi p, NodePosi lc)
{
    p->lc = lc;
    if (lc)
        lc->parent = p;
}
template <class NodePosi>
inline 
    void
    attachAsRChild(NodePosi p, NodePosi rc)
{
    p->rc = rc;
    if (rc)
        rc->parent = p;
}

template <class T> 
BinNodePosi(T) Splay<T>::splay(BinNodePosi(T) v)
{ 
    if (!v)
        return NULL;
    BinNodePosi(T) p;
    BinNodePosi(T) g; 
    while ((p = v->parent) && (g = p->parent))
    {                                  
        BinNodePosi(T) gg = g->parent; 
        if (IsLChild(*v))
            if (IsLChild(*p))
            { 
                attachAsLChild(g, p->rc);
                attachAsLChild(p, v->rc);
                attachAsRChild(p, g);
                attachAsRChild(v, p);
            }
            else
            { 
                attachAsLChild(p, v->rc);
                attachAsRChild(g, v->lc);
                attachAsLChild(v, g);
                attachAsRChild(v, p);
            }
        else if (IsRChild(*p))
        { 
            attachAsRChild(g, p->lc);
            attachAsRChild(p, v->lc);
            attachAsLChild(p, g);
            attachAsLChild(v, p);
        }
        else
        { 
            attachAsRChild(p, v->lc);
            attachAsLChild(g, v->rc);
            attachAsRChild(v, g);
            attachAsLChild(v, p);
        }
        if (!gg)
            v->parent = NULL; 
        else                  
            (g == gg->lc)
                ? attachAsLChild(gg, v)
                : attachAsRChild(gg, v);
        updateHeight(g);
        updateHeight(p);
        updateHeight(v);

    } 
    if (p = v->parent)
    { 
        if (IsLChild(*v))
        {
            attachAsLChild(p, v->rc);
            attachAsRChild(v, p);
        }
        else
        {
            attachAsRChild(p, v->lc);
            attachAsLChild(v, p);
        }
        updateHeight(p);
        updateHeight(v);
    }
    v->parent = NULL;
    return v;

} 

template <class T>
bool Splay<T>::remove(const T &e)
{ 
    if (!_root || (e != search(e)->data))
        return false;         
    BinNodePosi(T) w = _root; 
    if (!HasLChild(*_root))
    { 
        _root = _root->rc;
        if (_root)
            _root->parent = NULL;
    }
    else if (!HasRChild(*_root))
    { 
        _root = _root->lc;
        if (_root)
            _root->parent = NULL;
    }
    else
    { 
        BinNodePosi(T) lTree = _root->lc;
        lTree->parent = NULL;
        _root->lc = NULL; 
        _root = _root->rc;
        _root->parent = NULL; 
        search(w->data);      
                              
        _root->lc = lTree;
        lTree->parent = _root; 
    }
    release(w->data);
    release(w);
    _size--; 
    if (_root)
        updateHeight(_root); 
    return true;             

} 

template <class T>
BinNodePosi(T) Splay<T>::insert(const T &e)
{ 
    if (!_root)
    {
        _size++;
        return _root = new BinNode<T>(e);
    } 
    if (e == search(e)->data)
        return _root; 
    _size++;
    BinNodePosi(T) t = _root; 
    if (_root->data < e)
    {                                                          
        t->parent = _root = new BinNode<T>(e, NULL, t, t->rc); 
        if (HasRChild(*t))
        {
            t->rc->parent = _root;
            t->rc = NULL;
        } 
    }
    else
    {                                                          
        t->parent = _root = new BinNode<T>(e, NULL, t->lc, t); 
        if (HasLChild(*t))
        {
            t->lc->parent = _root;
            t->lc = NULL;
        } 
    }
    updateHeightAbove(t); 
    return _root;         

} 

#endif
