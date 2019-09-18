// author - sonaspy@outlook.com
// coding - utf_8
#ifndef __SPLAYTREE___
#define __SPLAYTREE___

namespace dsa
{
template <class T>
class spltree : public bstree<T>
{
protected:
    binode<T> *__splay(binode<T> *opnv)
    {
        if (!opnv)
            return nullptr;
        binode<T> *p, *g, *gg;
        while (1)
        {
            if (!opnv->parent)
                break;
            p = opnv->parent;
            if (!p->parent)
                break;
            g = p->parent;
            gg = g->parent;
            if (opnv->is_l())
            {
                if (p->is_l())
                    this->__attAsL(g, p->rc), this->__attAsL(p, opnv->rc), this->__attAsR(p, g), this->__attAsR(opnv, p);
                else
                    this->__attAsL(p, opnv->rc), this->__attAsR(g, opnv->lc), this->__attAsL(opnv, g), this->__attAsR(opnv, p);
            }
            else if (p->is_r())
                this->__attAsR(g, p->lc), this->__attAsR(p, opnv->lc), this->__attAsL(p, g), this->__attAsL(opnv, p);
            else
                this->__attAsR(p, opnv->lc), this->__attAsL(g, opnv->rc), this->__attAsR(opnv, g), this->__attAsL(opnv, p);
            if (!gg)
                opnv->parent = nullptr;
            else
                g == gg->lc ? this->__attAsL(gg, opnv) : this->__attAsR(gg, opnv);
            bintree<T>::__updateheight(g), bintree<T>::__updateheight(p), bintree<T>::__updateheight(opnv);
        }
        p = opnv->parent;
        if (p)
        {
            if (opnv->is_l())
                this->__attAsL(p, opnv->rc), this->__attAsR(opnv, p);
            else
                this->__attAsR(p, opnv->lc), this->__attAsL(opnv, p);
            bintree<T>::__updateheight(p), bintree<T>::__updateheight(opnv);
        }
        opnv->parent = nullptr;
        return opnv;
    }

public:
    void build(vector<T> &a)
    {
        for (auto data : a)
            insert(data);
        this->__update_status();
    }
    binode<T> *search(const T &e)
    {
        this->_last = nullptr;
        binode<T> *p = this->__search(this->_root, e);
        this->_root = __splay(p ? p : this->_last);
        return this->_root;
    }
    bool insert(const T &x)
    {
        if (!this->_root)
        {
            this->_size++;
            this->_root = new binode<T>(x);
            return true;
        }
        binode<T> *w = search(x), *t;
        if (w->val == x)
            return false;
        this->_size++;
        t = this->_root;
        if (this->_root->val < x)
        {
            t->parent = (this->_root = new binode<T>(x, nullptr, t, t->rc));
            if (t->has_r())
            {
                t->rc->parent = this->_root;
                t->rc = nullptr;
            }
        }
        else
        {
            t->parent = (this->_root = new binode<T>(x, nullptr, t->lc, t));
            if (t->has_l())
            {
                t->lc->parent = this->_root;
                t->lc = nullptr;
            }
        }
        this->__updateheightabove(t);
        return true;
    }

    bool erase(const T &x)
    {
        if (!this->_root || (x != search(x)->val))
            return 0;
        binode<T> *w = this->_root, *t, *lt;
        if (!(this->_root->has_l()))
        {
            this->_root = this->_root->rc;
            if (this->_root)
                this->_root->parent = nullptr;
        }
        else if (!(this->_root->has_r()))
        {
            this->_root = this->_root->lc;
            if (this->_root)
                this->_root->parent = nullptr;
        }
        else
        {
            lt = this->_root->lc;
            lt->parent = nullptr;
            this->_root->lc = nullptr;
            this->_root = this->_root->rc;
            this->_root->parent = nullptr;

            search(w->val);
            this->_root->lc = lt;
            lt->parent = this->_root;
        }
        __release(w);
        this->_size--;
        if (this->_root)
            bintree<T>::__updateheight(this->_root);
        return true;
    }
};
} // namespace dsa

#endif