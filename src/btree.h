// author - sonaspy@outlook.com
// coding - utf_8

#ifndef __BTREE__
#define __BTREE__

namespace dsa
{

template <typename _Tp>
class btree
{
protected:
    int _size, _order; // _order [2,512]
    bnode_ptr<_Tp> _root, _last;
    unordered_set<bnode_ptr<_Tp>> __memoryofbnode;
#define K_MAX (2 * _order - 1)
#define K_MIN (_order - 1)
#define C_MAX (2 * _order)
#define C_MIN (_order)
#define overflow(p) (((p)->sizeOfkey == K_MAX))
#define underflow(p) (((p)->sizeOfkey == K_MIN))
    inline bnode_ptr<_Tp> __new_bnode(bool isleaf = true)
    {
        bnode_ptr<_Tp> v = new bnode<_Tp>(isleaf);
        v->sizeOfkey = 0;
        v->key.resize(K_MAX);
        v->child.resize(C_MAX);
        fill(v->child.begin(), v->child.end(), nullptr);
        __memoryofbnode.insert(v);
        return v;
    }
    inline void __release(bnode_ptr<_Tp> &v)
    {
        __memoryofbnode.erase(v);
        delete v;
        v = nullptr;
    }
    inline void _output_node(bnode_ptr<_Tp> v)
    {
        cout << " [ ";
        for (int i = 0; i < v->sizeOfkey; i++)
            cout << v->key[i] << " ";
        cout << "(" << v->sizeOfkey << ")";
        cout << "] ";
    }
    void __inorder(bnode_ptr<_Tp> _root)
    {
        if (!_root)
            return;
        int i;
        for (i = 0; i < _root->sizeOfkey; i++)
        {
            __inorder(_root->child[i]);
            cout << _root->key[i] << " -> ";
        }
        for (; i < _root->sizeOfkey + 1; i++)
            __inorder(_root->child[i]);
    }
    void __nonfull_insert(bnode_ptr<_Tp> v, const _Tp &val)
    {
        int idx = __upper_bound(v->key.begin(), v->key.begin() + v->sizeOfkey, val) - v->key.begin();
        if (v->isleaf)
        {
            v->key.insert(v->key.begin() + idx, val);
            v->sizeOfkey++;
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
    void __overfSolution(bnode_ptr<_Tp> p, int c_idx)
    {
        bnode_ptr<_Tp> oldnode = p->child[c_idx];
        bnode_ptr<_Tp> node = __new_bnode(oldnode->isleaf);
        node->sizeOfkey = K_MIN;
        copy(oldnode->key.begin() + C_MIN, oldnode->key.begin() + C_MIN + K_MIN, node->key.begin());
        if (!oldnode->isleaf)
            copy(oldnode->child.begin() + C_MIN, oldnode->child.begin() + C_MIN * 2, node->child.begin());
        p->key.insert(p->key.begin() + c_idx, oldnode->key[K_MIN]);
        p->sizeOfkey++;
        p->child.insert(p->child.begin() + c_idx + 1, node);
        oldnode->sizeOfkey = K_MIN;
        p->child.pop_back();
        p->key.pop_back();
    }
    void __erase(bnode_ptr<_Tp> v, const _Tp &val)
    {
        int _pos = __lower_bound(v->key.begin(), v->key.begin() + v->sizeOfkey, val) - v->key.begin();
        if (v->isleaf)
        {
            if (v->key[_pos] == val)
            {
                v->key.erase(v->key.begin() + _pos);
                v->sizeOfkey--;
                v->key.resize(K_MAX);
            }
        }
        else
        {
            bnode_ptr<_Tp> rc = nullptr, p = nullptr, lc = v->child[_pos];
            if (_pos < v->sizeOfkey)
                rc = v->child[_pos + 1];
            if (v->key[_pos] == val)
            {
                if (lc->sizeOfkey > K_MIN)
                {
                    _Tp k1 = lc->precessor();
                    __erase(lc, k1);
                    v->key[_pos] = k1;
                }
                else if (rc->sizeOfkey > K_MIN)
                {
                    _Tp k1 = rc->successor();
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
                if (lc->sizeOfkey == K_MIN)
                {
                    if (_pos > 0 && p->sizeOfkey > K_MIN)
                    {
                        __shift2rc(v, _pos - 1, p, lc);
                    }
                    else if (_pos < v->sizeOfkey && rc->sizeOfkey > K_MIN)
                    {
                        __shift2lc(v, _pos, lc, rc);
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
    inline void __mergechild(bnode_ptr<_Tp> v, int i)
    {
        bnode_ptr<_Tp> lc = v->child[i], rc = v->child[i + 1];
        lc->sizeOfkey = K_MAX;
        lc->key[K_MIN] = v->key[i];
        copy(rc->key.begin(), rc->key.begin() + K_MAX - 1 - K_MIN, lc->key.begin() + K_MIN + 1);
        if (!lc->isleaf)
            copy(rc->child.begin(), rc->child.begin() + C_MAX - C_MIN, lc->child.begin() + C_MIN);
        v->key.erase(v->key.begin() + i);
        v->sizeOfkey--;
        v->child.erase(v->child.begin() + i + 1);

        v->key.resize(K_MAX);
        v->child.resize(C_MAX);
    }

    inline void __shift2rc(bnode_ptr<_Tp> x, int i, bnode_ptr<_Tp> y, bnode_ptr<_Tp> z)
    {
        z->key.insert(z->key.begin(), x->key[i]);
        z->sizeOfkey++;
        z->key.pop_back();

        x->key[i] = y->key[y->sizeOfkey - 1];

        if (!z->isleaf)
        {
            z->child.insert(z->child.begin(), y->child[y->sizeOfkey]);
            z->child.pop_back();
        }
        y->sizeOfkey--;
    }
    inline void __shift2lc(bnode_ptr<_Tp> x, int i, bnode_ptr<_Tp> y, bnode_ptr<_Tp> z)
    {
        y->sizeOfkey++;
        y->key[y->sizeOfkey - 1] = x->key[i];
        x->key[i] = z->key[0];

        z->sizeOfkey--;
        z->key.erase(z->key.begin());

        z->key.resize(K_MAX);

        if (!z->isleaf)
        {
            y->child[y->sizeOfkey] = z->child[0];
            z->child.erase(z->child.begin());

            z->child.resize(C_MAX);
        }
    }

public:
    btree<_Tp>(int order = 3) : _order(order), _size(0), _root(nullptr)
    {
    }
    ~btree()
    {
        this->clear();
    }
    inline int const order() { return this->_order; }
    inline int const size() { return this->_size; }
    inline bnode_ptr<_Tp> root() { return this->_root; }
    inline bool const empty() { return !size(); }
    inline void const clear()
    {
        for (auto &ptr : __memoryofbnode)
            delete ptr;
        __memoryofbnode.clear();
        _root = nullptr;
        _size = 0;
    }
    bnode_ptr<_Tp> search(const _Tp &val)
    {
        bnode_ptr<_Tp> v = _root;
        _last = nullptr;
        while (v)
        {
            auto it = __lower_bound(v->key.begin(), v->key.begin() + v->sizeOfkey, val);
            if (it != v->key.begin() + v->key.size() && *it == val)
                return v;
            _last = v, v = v->child[it - v->key.begin()];
        }
        return nullptr;
    }
    bool insert(const _Tp &val)
    {
        bnode_ptr<_Tp> v = search(val);
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
    bool erase(const _Tp &val)
    {
        bnode_ptr<_Tp> v = search(val);
        if (!v)
            return false;
        if (_root->sizeOfkey == 1)
        {
            if (_root->isleaf)
            {
                __release(_root);
                return true;
            }
            bnode_ptr<_Tp> lc = _root->child[0], rc = _root->child[1];
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
    void build(vector<_Tp> &a)
    {
        for (auto &val : a)
            insert(val);
    }

    inline void printTree()
    {
        bnode_ptr<_Tp> v = _root;
        queue<bnode_ptr<_Tp>> q, nexq;
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

    void __underfSolution(bnode_ptr<_Tp> v)
    {
    }
};
} // namespace dsa
#endif