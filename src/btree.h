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
    int _size, _order; // _order [2,512]
    bnode_ptr<T> _root, _last;
    unordered_set<bnode_ptr<T>> __memoryofbnode;
#define K_MAX (2 * _order - 1)
#define K_MIN (_order - 1)
#define C_MAX (2 * _order)
#define C_MIN (_order)
#define overflow(p) (((p)->keysize == K_MAX))
#define underflow(p) (((p)->keysize == K_MIN))
    inline bnode_ptr<T> __new_bnode(bool isleaf = true)
    {
        bnode_ptr<T> v = new bnode<T>(isleaf);
        v->keysize = 0;
        v->key.resize(K_MAX);
        v->child.resize(C_MAX);
        fill(v->child.begin(), v->child.end(), nullptr);
        __memoryofbnode.insert(v);
        return v;
    }
    inline void __release(bnode_ptr<T> &v)
    {
        __memoryofbnode.erase(v);
        delete v;
        v = nullptr;
    }
    inline void _output_node(bnode_ptr<T> v)
    {
        cout << " [ ";
        for (int i = 0; i < v->keysize; i++)
            cout << v->key[i] << " ";
        cout << "(" << v->keysize << ")";
        cout << "] ";
    }
    void __inorder(bnode_ptr<T> _root)
    {
        if (!_root)
            return;
        int i;
        for (i = 0; i < _root->keysize; i++)
        {
            __inorder(_root->child[i]);
            cout << _root->key[i] << " -> ";
        }
        for (; i < _root->keysize + 1; i++)
            __inorder(_root->child[i]);
    }
    void __nonfull_insert(bnode_ptr<T> v, const T &val)
    {
        int idx = __upper_bound(v->key.begin(), v->key.begin() + v->keysize, val) - v->key.begin();
        if (v->isleaf)
        {
            v->key.insert(v->key.begin() + idx, val);
            v->keysize++;
            v->key.pop_back();
        }
        else
        {
            if (overflow(v->child[idx]))
            {
                __overfSolution(v, idx);
                idx += (val > v->key[idx] ? 1 : 0);
            }
            __nonfull_insert(v->child[idx], val);
        }
    }
    void __overfSolution(bnode_ptr<T> p, int c_idx)
    {
        bnode_ptr<T> oldnode = p->child[c_idx];
        bnode_ptr<T> node = __new_bnode(oldnode->isleaf);
        node->keysize = K_MIN;
        copy(oldnode->key.begin() + C_MIN, oldnode->key.begin() + C_MIN + K_MIN, node->key.begin());
        if (!oldnode->isleaf)
            copy(oldnode->child.begin() + C_MIN, oldnode->child.begin() + C_MIN * 2, node->child.begin());
        p->key.insert(p->key.begin() + c_idx, oldnode->key[K_MIN]);
        p->keysize++;
        p->child.insert(p->child.begin() + c_idx + 1, node);
        oldnode->keysize = K_MIN;
        p->child.pop_back();
        p->key.pop_back();
    }
    void __erase(bnode_ptr<T> v, const T &val)
    {
        int _pos = __lower_bound(v->key.begin(), v->key.begin() + v->keysize, val) - v->key.begin();
        if (v->isleaf)
        {
            if (v->key[_pos] == val)
            {
                v->key.erase(v->key.begin() + _pos);
                v->keysize--;
                v->key.resize(K_MAX);
            }
        }
        else
        {
            bnode_ptr<T> rc = nullptr, p = nullptr, lc = v->child[_pos];
            if (_pos < v->keysize)
                rc = v->child[_pos + 1];
            if (v->key[_pos] == val)
            {
                if (lc->keysize > K_MIN)
                {
                    T k1 = lc->precessor();
                    __erase(lc, k1);
                    v->key[_pos] = k1;
                }
                else if (rc->keysize > K_MIN)
                {
                    T k1 = rc->successor();
                    __erase(rc, k1);
                    v->key[_pos] = k1;
                }
                else
                {
                    __mergechild(v, _pos);
                    __erase(lc, val);
                }
            }
            else
            {
                if (_pos > 0)
                    p = v->child[_pos - 1];
                if (lc->keysize == K_MIN)
                {
                    if (_pos > 0 && p->keysize > K_MIN)
                    {
                        transfer2rc(v, _pos - 1, p, lc);
                    }
                    else if (_pos < v->keysize && rc->keysize > K_MIN)
                    {
                        transfer2lc(v, _pos, lc, rc);
                    }
                    else if (_pos > 0)
                    {
                        __mergechild(v, _pos - 1);
                        lc = p;
                    }
                    else
                    {
                        __mergechild(v, _pos);
                    }
                }
                __erase(lc, val);
            }
        }
    }
    inline void __mergechild(bnode_ptr<T> v, int i)
    {
        bnode_ptr<T> lc = v->child[i], rc = v->child[i + 1];
        lc->keysize = K_MAX;
        lc->key[K_MIN] = v->key[i];
        copy(rc->key.begin(), rc->key.begin() + K_MAX - 1 - K_MIN, lc->key.begin() + K_MIN + 1);
        if (!lc->isleaf)
            copy(rc->child.begin(), rc->child.begin() + C_MAX - C_MIN, lc->child.begin() + C_MIN);
        v->key.erase(v->key.begin() + i);
        v->keysize--;
        v->child.erase(v->child.begin() + i + 1);

        v->key.resize(K_MAX);
        v->child.resize(C_MAX);
    }

    inline void transfer2rc(bnode_ptr<T> x, int i, bnode_ptr<T> y, bnode_ptr<T> z)
    {
        z->key.insert(z->key.begin(), x->key[i]);
        z->keysize++;
        z->key.pop_back();

        x->key[i] = y->key[y->keysize - 1];

        if (!z->isleaf)
        {
            z->child.insert(z->child.begin(), y->child[y->keysize]);
            z->child.pop_back();
        }
        y->keysize--;
    }
    inline void transfer2lc(bnode_ptr<T> x, int i, bnode_ptr<T> y, bnode_ptr<T> z)
    {
        y->keysize++;
        y->key[y->keysize - 1] = x->key[i];
        x->key[i] = z->key[0];

        z->keysize--;
        z->key.erase(z->key.begin());

        z->key.resize(K_MAX);

        if (!z->isleaf)
        {
            y->child[y->keysize] = z->child[0];
            z->child.erase(z->child.begin());

            z->child.resize(C_MAX);
        }
    }

public:
    btree<T>(int order = 3) : _order(order), _size(0), _root(nullptr)
    {
    }
    ~btree()
    {
        this->clear();
    }
    inline int const order() { return this->_order; }
    inline int const size() { return this->_size; }
    inline bnode_ptr<T> root() { return this->_root; }
    inline bool const empty() { return !size(); }
    inline void const clear()
    {
        for (auto &ptr : __memoryofbnode)
            delete ptr;
        __memoryofbnode.clear();
        _root = nullptr;
        _size = 0;
    }
    bnode_ptr<T> search(const T &val)
    {
        bnode_ptr<T> v = _root;
        _last = nullptr;
        while (v)
        {
            auto it = __lower_bound(v->key.begin(), v->key.begin() + v->keysize, val);
            if (it != v->key.begin() + v->key.size() && *it == val)
                return v;
            _last = v, v = v->child[it - v->key.begin()];
        }
        return nullptr;
    }
    bool insert(const T &val)
    {
        bnode_ptr<T> v = search(val);
        if (v)
            return 0;
        if (!_root)
            _root = __new_bnode();
        if (overflow(_root))
        {
            v = __new_bnode(false);
            v->child[0] = _root;
            __overfSolution(v, 0);
            _root = v;
        }
        __nonfull_insert(_root, val);
        this->_size++;
        return true;
    }
    bool erase(const T &val)
    {
        bnode_ptr<T> v = search(val);
        if (!v)
            return false;
        if (_root->keysize == 1)
        {
            if (_root->isleaf)
            {
                __release(_root);
                return true;
            }
            bnode_ptr<T> lc = _root->child[0], rc = _root->child[1];
            if (underflow(lc) && underflow(rc))
            {
                __mergechild(_root, 0);
                __release(_root);
                _root = lc;
            }
        }
        __erase(_root, val);
        _size--;
        return true;
    }
    void build(vector<T> &a)
    {
        for (auto &val : a)
            insert(val);
    }

    inline void printTree()
    {
        bnode_ptr<T> v = _root;
        queue<bnode_ptr<T>> q, nexq;
        q.push(v);
        int le = 0, layer = 0, blank;
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
    void inorder()
    {
        __inorder(this->_root);
        cout << "nullptr\n";
    }

    void __underfSolution(bnode_ptr<T> v)
    {
    }
};
} // namespace dsa
#endif