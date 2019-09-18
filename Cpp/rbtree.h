// author - sonaspy@outlook.com
// coding - utf_8

#ifndef __RB_TREE__
#define __RB_TREE__

#include "avltree.h"
namespace dsa
{

template <typename T>
class rbtree : public avltree<T>
{
    // in rbtree the memver 'height' is blk height
protected:
#define _blk(opnv) ((!(opnv) || (opnv)->color == blk))
#define _red(opnv) (!_blk(opnv))
#define set_blk(opnv) (((opnv) ? (opnv->color = blk) : 0))
#define set_red(opnv) (((opnv) ? (opnv->color = red) : 0))

    void __print_horizon(binode<T> *opnv, int root_x, int root_y, int interval)
    {
        if (!opnv)
            return;
        int left_child = root_y - interval, right_child = root_y + interval;
        string tp = to_string(opnv->val);
        tp += opnv->color == red ? "🔴" : "⚫️";
        if (tp.size() == 2)
            tp.push_back(' ');
        this->disp_buf[root_x][root_y] = tp;
        if (opnv->lc)
            this->disp_buf[root_x + 1][root_y - (interval + 1) / 2] = " / ";
        if (opnv->rc)
            this->disp_buf[root_x + 1][root_y + (interval + 1) / 2] = " \\ ";
        __print_horizon(opnv->lc, root_x + 2, left_child, (interval >> 1));
        __print_horizon(opnv->rc, root_x + 2, right_child, (interval >> 1));
    }

    static inline void __alterheight(binode<T> *&opnv)
    {
        opnv->height = max(_height(opnv->lc), _height(opnv->rc));
        opnv->height += _blk(opnv) ? 1 : 0;
    }
    static inline bool _blk_altered(binode<T> *&opnv)
    {
        return _height(opnv->lc) == _height(opnv->rc) &&
                       opnv->height == _red(opnv)
                   ? _height(opnv->lc)
                   : _height(opnv->lc) + 1;
    }
    void __double_red_solution(binode<T> *opnv)
    {
        binode<T> *p, *g, *u;
        while ((p = opnv->parent) && _red(p))
        {
            g = p->parent;
            u = opnv->uncle();
            if (u && _red(u))
            {
                set_blk(u);
                set_blk(p);
                set_red(g);
                opnv = g;
                continue;
            }
            if (p->is_l() && opnv->is_r())
            {
                this->__rotate_right(p);
                swap(opnv, p);
            }
            else if (p->is_r() && opnv->is_l())
            {
                this->__rotate_left(p);
                swap(opnv, p);
            }
            set_blk(p);
            set_red(g);
            p->is_l() ? this->__rotate_left(g) : this->__rotate_right(g);
        }
        set_blk(this->_root);
    }
    void __double_blk_solution(binode<T> *x)
    {
    }

public:
    bool insert(const T &x)
    {
        binode<T> *&w = this->search(x);
        if (w)
            return false;
        w = new binode<T>(x, this->_last, nullptr, nullptr, red);
        this->_size++;
        __double_red_solution(w);
        return true;
    }
    void printrb()
    {
        if (!this->_root)
            return;
        printf("🌲\n");
        if (this->_size > (1 << 8) - 1)
        {
            cout << " Too Many Node !\n";
            return;
        }
        this->disp_buf = vector<vector<string>>(40, vector<string>(MAXCOL, string(3, ' ')));
        __print_horizon(this->_root, 0, pow(2, this->_root->height) - 1, pow(2, this->_root->height - 1));
        int n = this->_root->height * 2 + 1, i, j, breadth = pow(2, this->_root->height + 1) + 1;
        for (i = 0; i < n; ++i)
        {
            for (j = 0; j < breadth; ++j)
                cout << this->disp_buf[i][j];
            cout << endl;
        }
        printf("🌲\n");
    }
    bool erase(const T &x)
    {
        binode<T> *&opnv = search(x);
        if (!opnv)
            return false;
        binode<T> *r = this->__erase_at(opnv, this->_last);
        if (--this->_size == 0)
            return true;
        if (!this->_last)
        {
            this->_root->color = blk;
            __alterheight(this->_root);
            return true;
        }
        if (_blk_altered(this->_last))
            return true;
        if (_red(r))
        {
            r->color = blk;
            r->height++;
            return true;
        }
        __double_blk_solution(r);
        return true;
    }
    void build(vector<T> &a)
    {
        for (auto &x : a)
            insert(x);
        bintree<T>::__update_status();
    }
};
} // namespace dsa
#endif