// author - sonaspy@outlook.com
// coding - utf_8

#ifndef __BTREE__
#define __BTREE__

__DST_BEGIN_NAMESPACE

template <typename _Tp>
class btree
{
protected:
    int _size, _order; // _order [2,512]
    bnode_ptr<_Tp> _root, _last;
    unordered_set<bnode_ptr<_Tp>> __memory_pool;
    allocator<bnode<_Tp>> __btree_alloc;
    const int __SIZEOF_BNODE = ((sizeof(struct bnode<_Tp>)));
#define K_MAX (2 * _order - 1)
#define K_MIN (_order - 1)
#define C_MAX (2 * _order)
#define C_MIN (_order)
#define overflow(p) (((p)->sizeOfkey == K_MAX))
#define underflow(p) (((p)->sizeOfkey == K_MIN))

    inline bnode_ptr<_Tp> __new_bnode(bool isleaf = true)
    {
        bnode_ptr<_Tp> v = __btree_alloc.allocate(__SIZEOF_BNODE);
        __btree_alloc.construct(v, K_MAX, C_MAX, isleaf);
        __memory_pool.insert(v);
        return v;
    }
    inline void __release(bnode_ptr<_Tp> &v)
    {
        __memory_pool.erase(v);
        __btree_alloc.destroy(v);
        __btree_alloc.deallocate(v, __SIZEOF_BNODE);
        v = nullptr;
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
        bnode_ptr<_Tp> obsolete = p->child[c_idx];
        bnode_ptr<_Tp> node = __new_bnode(obsolete->isleaf);

        node->sizeOfkey = K_MIN;
        copy(obsolete->key.begin() + C_MIN, obsolete->key.begin() + C_MIN + K_MIN, node->key.begin());

        if (!obsolete->isleaf)
            copy(obsolete->child.begin() + C_MIN, obsolete->child.begin() + C_MIN * 2, node->child.begin());

        p->key.insert(p->key.begin() + c_idx, obsolete->key[K_MIN]);
        p->sizeOfkey++;
        p->child.insert(p->child.begin() + c_idx + 1, node);

        obsolete->sizeOfkey = K_MIN;

        // keep v's key and child in shape
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
                // keep v's key and child in shape
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
                    bnode_ptr<_Tp> tmp = lc->rightest();
                    _Tp k1 = tmp->key[tmp->sizeOfkey - 1];
                    __erase(lc, k1);
                    v->key[_pos] = k1;
                }
                else if (rc->sizeOfkey > K_MIN)
                {
                    bnode_ptr<_Tp> tmp = rc->leftest();
                    _Tp k1 = tmp->key[0];
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
        // keep v's key and child in shape
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

        // keep v's key and child in shape
        z->key.resize(K_MAX);

        if (!z->isleaf)
        {
            y->child[y->sizeOfkey] = z->child[0];
            z->child.erase(z->child.begin());
            // keep v's key and child in shape
            z->child.resize(C_MAX);
        }
    }

public:
    btree<_Tp>(int order = 3) : _order(order), _size(0), _root(nullptr)
    {
    }
    ~btree()
    {
        clear();
    }
    inline int const order() { return _order; }
    inline int const size() { return _size; }
    inline bnode_ptr<_Tp> root() { return _root; }
    inline bool const empty() const { return _root == nullptr; }
    inline void const clear()
    {
        for (auto &ptr : __memory_pool)
            delete ptr;
        __memory_pool.clear();
        _root = nullptr;
        _size = 0;
    }
    bool count(const _Tp &val)
    {
        return search(val) != nullptr;
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
        _size++;
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
                v->print_node();
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
        __inorder(_root);
        cout << "nullptr\n";
    }
};

__DST_END_NAMESPACE

#endif