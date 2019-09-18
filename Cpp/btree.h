// author - sonaspy@outlook.com
// coding - utf_8

#ifndef __BTREE__
#define __BTREE__

#include "trees.h"
namespace dsa
{
template <typename T>
class btree
{
protected:
    int _size, _order;
    bnode<T> *_root, *_last;
    void __overfSolution(bnode<T> *opnv)
    {
        if (opnv->key.size() <= _order - 1)
            return;
        int s = _order / 2;
        bnode<T> *u = new bnode<T>();

        // right split [0 1 2 |<3>| 4 5]
        u->child.insert(u->child.begin(), opnv->child.begin() + s + 1, opnv->child.end());
        opnv->child.erase(opnv->child.begin() + s + 1, opnv->child.end());

        u->key.insert(u->key.begin(), opnv->key.begin() + s + 1, opnv->key.begin() + _order);
        opnv->key.erase(opnv->key.begin() + s + 1, opnv->key.begin() + _order);

        if (opnv->child.front())
        {
            for (int j = 0; j < _order - s; j++)
                u->child[j]->parent = u;
        }
        bnode<T> *p = opnv->parent;
        if (!p)
        {
            p = new bnode<T>();
            _root = p;
            p->child[0] = opnv;
            opnv->parent = p;
        }

        int r = upper_bound(p->key.begin(), p->key.end(), opnv->key[0]) - p->key.begin();
        p->key.insert(p->key.begin() + r, *(opnv->key.begin() + s));
        opnv->key.erase(opnv->key.begin() + s);
        p->child.insert(p->child.begin() + r + 1, u);
        u->parent = p;

        __overfSolution(p);
    }

    void __underfSolution(bnode<T> *opnv)
    {
        //cout << "s-1\n";
        if (!opnv)
            return;
        if ((_order - 1) / 2 <= opnv->key.size())
            return;
        //cout << "s-2\n";
        bnode<T> *p = opnv->parent;
        if (!p)
        {
            //cout << "s-3\n";
            if (opnv->key.empty() && opnv->child[0])
            {
                _root = opnv->child[0];
                _root->parent = nullptr;
                opnv->child[0] = nullptr;
                __release(opnv);
            }
            return;
        }
        int r = -1;
        //cout << "sp" << endl;
        while (p->child[++r] != opnv)
            ;
        if (0 < r)
        {
            bnode<T> *ls = p->child[r - 1];
            if ((_order - 1) / 2 < ls->key.size())
            {
                opnv->key.insert(opnv->key.begin(), p->key[r - 1]);
                p->key[r - 1] = ls->key.back();
                ls->key.pop_back();
                opnv->child.insert(opnv->child.begin(), ls->child.back());
                ls->child.pop_back();
                if (opnv->child[0])
                    opnv->child[0]->parent = opnv;
                //cout << "s1" << endl;
                return;
            }
        }
        if (r + 1 < p->child.size())
        {
            bnode<T> *rs = p->child[r + 1];
            if ((_order - 1) / 2 < rs->key.size())
            {
                //cout << "s2\n";
                opnv->key.insert(opnv->key.end(), p->key[r]);
                p->key[r] = rs->key.front();
                rs->key.erase(rs->key.begin());
                opnv->child.push_back(rs->child.front());
                rs->child.erase(rs->child.begin());
                if (opnv->child.back())
                    opnv->child.back()->parent = opnv;
                return;
            }
        }
        if (0 < r)
        {
            //cout << "s3\n";
            bnode<T> *ls = p->child[r - 1];
            ls->key.push_back(p->key[r - 1]);
            p->key.erase(p->key.begin() + r - 1);
            p->child.erase(p->child.begin() + r);

            ls->child.push_back(opnv->child.front());
            opnv->child.erase(opnv->child.begin());
            if (ls->child.back())
                ls->child.back()->parent = ls;
            ls->key.insert(ls->key.end(), opnv->key.begin(), opnv->key.end());
            ls->child.insert(ls->child.end(), opnv->child.begin(), opnv->child.end());
            for (auto &lsch : ls->child)
                if (lsch)
                    lsch->parent = ls;
            __release(opnv);
        }
        else
        {
            //cout << "s4\n";
            bnode<T> *rs = p->child[r + 1];
            rs->key.insert(rs->key.begin(), p->key[r]);
            p->key.erase(p->key.begin() + r);
            p->child.erase(p->child.begin() + r);

            rs->child.insert(rs->child.begin(), opnv->child.back());
            opnv->child.pop_back();

            if (rs->child.front())
                rs->child.front()->parent = rs;
            rs->key.insert(rs->key.begin(), opnv->key.begin(), opnv->key.end());
            rs->child.insert(rs->child.begin(), opnv->child.begin(), opnv->child.end());

            for (auto &rsch : rs->child)
                if (rsch)
                    rsch->parent = rs;

            __release(opnv);
        }
        __underfSolution(p);
        //cout << "end\n";
    }

    inline void _output_node(bnode<T> *opnv)
    {
        cout << " ( ";
        for (auto i : opnv->key)
            cout << i << " ";
        cout << ") ";
    }

    void __inorder(bnode<T> *opnv)
    {
        if (!opnv)
            return;
        int i;
        for (i = 0; i < opnv->key.size(); i++)
        {
            __inorder(opnv->child[i]);
            cout << opnv->key[i] << " -> ";
        }
        for (; i < opnv->child.size(); i++)
            __inorder(opnv->child[i]);
    }

public:
    btree<T>(int order = 3) : _order(order), _size(0)
    {
        _root = new bnode<T>();
    }
    ~btree()
    {
        this->clear();
    }
    inline void printTree()
    {
        bnode<T> *opnv = _root;
        queue<bnode<T> *> q, nexq;
        q.push(opnv);
        int le = 1;
        while (q.size())
        {
            printf("LeveL %d : ", le);
            while (q.size())
            {
                opnv = q.front(), q.pop();
                _output_node(opnv);
                for (auto chi : opnv->child)
                    if (chi)
                        nexq.push(chi);
            }
            cout << endl;
            le++;
            swap(q, nexq);
        }
    }
    inline void const clear()
    {
    }
    inline int const order() { return this->_order; }
    inline int const size() { return this->_size; }
    inline bnode<T> *root() { return this->_root; }
    inline bool const empty() { return !size(); }
    bnode<T> *search(const T &x)
    {
        bnode<T> *opnv = _root;
        _last = nullptr;
        while (opnv)
        {
            auto it = lower_bound(opnv->key.begin(), opnv->key.end(), x);
            int r = it - opnv->key.begin();
            if (it != opnv->key.end() && *it == x)
                return opnv;
            _last = opnv, opnv = opnv->child[r];
        }
        return nullptr;
    }
    void inorder()
    {
        __inorder(this->_root);
        cout << "nullptr\n";
    }
    void build(vector<T> &a)
    {
        for (auto &x : a)
            insert(x);
    }
    bool insert(const T &x)
    {
        bnode<T> *opnv = search(x);
        if (opnv)
            return 0;
        int r = upper_bound(_last->key.begin(), _last->key.end(), x) - _last->key.begin();
        _last->key.insert(_last->key.begin() + r, x);
        _last->child.insert(_last->child.begin() + r + 1, nullptr);
        _size++;
        __overfSolution(_last); // key size <= m - 1
        return true;
    }
    bool erase(const T &x)
    {
        bnode<T> *opnv = search(x);
        if (!opnv)
            return false;
        int r = lower_bound(opnv->key.begin(), opnv->key.end(), x) - opnv->key.begin();
        if (opnv->child.front())
        {
            bnode<T> *u = opnv->child[r + 1];
            while (u->child[0])
                u = u->child[0];
            opnv->key[r] = u->key[0];
            opnv = u, r = 0;
        }
        opnv->key.erase(opnv->key.begin() + r);
        opnv->child.erase(opnv->child.begin() + 1 + r);
        _size--;
        __underfSolution(opnv);
        return true;
    }
};
} // namespace dsa
#endif