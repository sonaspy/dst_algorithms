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
    unordered_set<bnode<T> *> _memoryOfNode;

    void __overfSolution(bnode<T> *v)
    {
        if (v->key.size() <= _order - 1)
            return;
        int s = _order / 2;
        bnode<T> *u = new bnode<T>();

        // right split [0 1 2 |<3>| 4 5]
        u->child.insert(u->child.begin(), v->child.begin() + s + 1, v->child.end());
        v->child.erase(v->child.begin() + s + 1, v->child.end());

        u->key.insert(u->key.begin(), v->key.begin() + s + 1, v->key.begin() + _order);
        v->key.erase(v->key.begin() + s + 1, v->key.begin() + _order);

        if (v->child.front())
        {
            for (int j = 0; j < _order - s; j++)
                u->child[j]->parent = u;
        }
        bnode<T> *p = v->parent;
        if (!p)
        {
            p = new bnode<T>();
            _root = p;
            p->child[0] = v;
            v->parent = p;
        }

        int r = upper_bound(p->key.begin(), p->key.end(), v->key[0]) - p->key.begin();
        p->key.insert(p->key.begin() + r, *(v->key.begin() + s));
        v->key.erase(v->key.begin() + s);
        p->child.insert(p->child.begin() + r + 1, u);
        u->parent = p;

        __overfSolution(p);
    }

    void __underfSolution(bnode<T> *v)
    {
        //cout << "s-1\n";
        if (!v)
            return;
        if ((_order - 1) / 2 <= v->key.size())
            return;
        //cout << "s-2\n";
        bnode<T> *p = v->parent;
        if (!p)
        {
            //cout << "s-3\n";
            if (v->key.empty() && v->child[0])
            {
                _root = v->child[0];
                _root->parent = nullptr;
                v->child[0] = nullptr;
                _memoryOfNode.erase(v);
                delete v;
            }
            return;
        }
        int r = -1;
        //cout << "sp" << endl;
        while (p->child[++r] != v)
            ;
        if (0 < r)
        {
            bnode<T> *ls = p->child[r - 1];
            if ((_order - 1) / 2 < ls->key.size())
            {
                v->key.insert(v->key.begin(), p->key[r - 1]);
                p->key[r - 1] = ls->key.back();
                ls->key.pop_back();
                v->child.insert(v->child.begin(), ls->child.back());
                ls->child.pop_back();
                if (v->child[0])
                    v->child[0]->parent = v;
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
                v->key.insert(v->key.end(), p->key[r]);
                p->key[r] = rs->key.front();
                rs->key.erase(rs->key.begin());
                v->child.push_back(rs->child.front());
                rs->child.erase(rs->child.begin());
                if (v->child.back())
                    v->child.back()->parent = v;
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

            ls->child.push_back(v->child.front());
            v->child.erase(v->child.begin());
            if (ls->child.back())
                ls->child.back()->parent = ls;
            ls->key.insert(ls->key.end(), v->key.begin(), v->key.end());
            ls->child.insert(ls->child.end(), v->child.begin(), v->child.end());
            for (auto &lsch : ls->child)
                if (lsch)
                    lsch->parent = ls;
            _memoryOfNode.erase(v);
            delete v;
        }
        else
        {
            //cout << "s4\n";
            bnode<T> *rs = p->child[r + 1];
            rs->key.insert(rs->key.begin(), p->key[r]);
            p->key.erase(p->key.begin() + r);
            p->child.erase(p->child.begin() + r);

            rs->child.insert(rs->child.begin(), v->child.back());
            v->child.pop_back();

            if (rs->child.front())
                rs->child.front()->parent = rs;
            rs->key.insert(rs->key.begin(), v->key.begin(), v->key.end());
            rs->child.insert(rs->child.begin(), v->child.begin(), v->child.end());

            for (auto &rsch : rs->child)
                if (rsch)
                    rsch->parent = rs;

            _memoryOfNode.erase(v);
            delete v;
        }
        __underfSolution(p);
        //cout << "end\n";
    }

    inline void _output_node(bnode<T> *v)
    {
        cout << " ( ";
        for (auto i : v->key)
            cout << i << " ";
        cout << ") ";
    }

    void __inorder(bnode<T> *root)
    {
        if (!root)
            return;
        int i;
        for (i = 0; i < root->key.size(); i++)
        {
            __inorder(root->child[i]);
            cout << root->key[i] << " -> ";
        }
        for (; i < root->child.size(); i++)
            __inorder(root->child[i]);
    }

public:
    btree<T>(int order = 3) : _order(order), _size(0)
    {
        _root = new bnode<T>();
        _memoryOfNode.insert(_root);
    }
    ~btree()
    {
        this->clear();
    }
    inline void printTree()
    {
        bnode<T> *v = _root;
        queue<bnode<T> *> q, nexq;
        q.push(v);
        int le = 1;
        while (q.size())
        {
            printf("LeveL %d : ", le);
            while (q.size())
            {
                v = q.front(), q.pop();
                _output_node(v);
                for (auto chi : v->child)
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
        for (auto &ptr : _memoryOfNode)
            delete ptr;
        _memoryOfNode.clear();
    }
    inline int const order() { return this->_order; }
    inline int const size() { return this->_size; }
    inline bnode<T> *root() { return this->_root; }
    inline bool const empty() { return !size(); }
    bnode<T> *search(const T &x)
    {
        bnode<T> *v = _root;
        _last = nullptr;
        while (v)
        {
            auto it = lower_bound(v->key.begin(), v->key.end(), x);
            int r = it - v->key.begin();
            if (it != v->key.end() && *it == x)
                return v;
            _last = v, v = v->child[r];
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
        bnode<T> *v = search(x);
        if (v)
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
        bnode<T> *v = search(x);
        if (!v)
            return false;
        int r = lower_bound(v->key.begin(), v->key.end(), x) - v->key.begin();
        if (v->child.front())
        {
            bnode<T> *u = v->child[r + 1];
            while (u->child[0])
                u = u->child[0];
            v->key[r] = u->key[0];
            v = u, r = 0;
        }
        v->key.erase(v->key.begin() + r);
        v->child.erase(v->child.begin() + 1 + r);
        _size--;
        __underfSolution(v);
        return true;
    }
};
} // namespace dsa
#endif