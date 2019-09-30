// author - sonaspy@outlook.com
// coding - utf_8

#ifndef __BINARYTREE__
#define __BINARYTREE__

namespace dsa
{

template <typename _Tp>
class bintree
{
protected:
    binode_ptr<_Tp> _root, tp1;
    deque<binode_ptr<_Tp>> q, nexq;
    int _size, _unitsize;
    bool _isunique, _isRBtree, _ishuffman;
    string _direct2l, _direct2r;
    vector<vector<string>> __display_buffer;
    unordered_set<binode_ptr<_Tp>> __memofbinode;
    inline binode_ptr<_Tp> __newbinode(const _Tp &x, binode_ptr<_Tp> p = nullptr, binode_ptr<_Tp> l = nullptr, binode_ptr<_Tp> r = nullptr, RBColor cl = BLK)
    {
        binode_ptr<_Tp> v = new binode<_Tp>(x, p, l, r, cl);
        __memofbinode.insert(v);
        this->_size++;
        return v;
    }
    inline binode_ptr<_Tp> __newbinode()
    {
        binode_ptr<_Tp> v = new binode<_Tp>();
        __memofbinode.insert(v);
        this->_size++;
        return v;
    }
    inline void __release(binode_ptr<_Tp> &v)
    {
        __memofbinode.erase(v);
        delete v;
        v = nullptr;
        this->_size--;
    }
    static inline void __updatedepth(binode_ptr<_Tp> &opnv) { opnv->depth = _depth(opnv->parent) + 1; }
    static inline void __updateheight(binode_ptr<_Tp> &opnv) { opnv->height = max(_height(opnv->lc), _height(opnv->rc)) + 1; }
    static inline void __updateheightabove(binode_ptr<_Tp> opnv)
    {
        while (opnv)
        {
            __updateheight(opnv);
            opnv = opnv->parent;
        }
    }
    static void __update_member(binode_ptr<_Tp> opnv, binode_ptr<_Tp> p)
    {
        if (!opnv)
            return;
        opnv->parent = p;
        __updatedepth(opnv);
        __update_member(opnv->lc, opnv);
        __update_member(opnv->rc, opnv);
        __updateheight(opnv);
    }
    inline void __update_status()
    {
        __update_member(_root, nullptr);
    }
    inline void __update_root(binode_ptr<_Tp> opnv)
    {
        _root = opnv;
    }
    binode_ptr<_Tp> __build_pi(int opnv, int lo, int hi, binode_ptr<_Tp> p)
    {
        if (hi < lo)
            return nullptr;
        int i = lo;
        binode_ptr<_Tp> node = this->__newbinode(preorder[opnv]);
        hashtable[preorder[opnv]] = node;
        node->parent = p;
        __updatedepth(node);
        while (i < hi && inorder[i] != preorder[opnv])
            i++;
        node->lc = __build_pi(opnv + 1, lo, i - 1, node);
        node->rc = __build_pi(opnv + 1 + i - lo, i + 1, hi, node);
        __updateheight(node);
        return node;
    }
    void __print_horizon(binode_ptr<_Tp> opnv, int root_x, int root_y, int interval)
    {
        if (!opnv)
            return;
        string tp;
        if (IS_CHAR<_Tp>())
            tp.push_back(opnv->val);
        else
            tp = to_string(opnv->val);
        if (_isRBtree)
            tp += opnv->color == RED ? "🔴" : "⚫️";
        while (tp.size() < _unitsize)
            tp.push_back(' ');
        this->__display_buffer[root_x][root_y] = tp;
        if (opnv->lc)
            this->__display_buffer[root_x + 1][root_y - (interval + 1) / 2] = _direct2l;
        if (opnv->rc)
            this->__display_buffer[root_x + 1][root_y + (interval + 1) / 2] = _direct2r;
        __print_horizon(opnv->lc, root_x + 2, root_y - interval, (interval >> 1));
        __print_horizon(opnv->rc, root_x + 2, root_y + interval, (interval >> 1));
    }
    binode_ptr<_Tp> __build_ip(int opnv, int lo, int hi, binode_ptr<_Tp> p)
    {
        if (hi < lo)
            return nullptr;
        int i = lo;
        binode_ptr<_Tp> node = this->__newbinode(postorder[opnv]);
        hashtable[postorder[opnv]] = node;
        node->parent = p;
        __updatedepth(node);
        while (i < hi && inorder[i] != postorder[opnv])
            i++;
        node->lc = __build_ip(opnv - 1 + i - hi, lo, i - 1, node);
        node->rc = __build_ip(opnv - 1, i + 1, hi, node);
        __updateheight(node);
        return node;
    }
    binode_ptr<_Tp> __build_pp(int leftOfpre, int rightOfpre, int leftOfpost, int rightOfpost)
    {
        if (leftOfpre > rightOfpre || leftOfpost > rightOfpost)
            return nullptr;
        binode_ptr<_Tp> opnv = this->__newbinode(preorder[leftOfpre]);
        if (leftOfpre == rightOfpre)
            return opnv;
        int leftSubVal = preorder[leftOfpre + 1], i, sub_cnt;
        for (i = leftOfpost; i < rightOfpost && postorder[i] != leftSubVal; i++)
            ;
        sub_cnt = i - leftOfpost;
        if (i + 1 < rightOfpost) // 2 child
        {
            opnv->lc = __build_pp(leftOfpre + 1, leftOfpre + sub_cnt + 1, leftOfpost, i);
            opnv->rc = __build_pp(leftOfpre + sub_cnt + 2, rightOfpre, i + 1, rightOfpost - 1);
        }
        else
        {
            opnv->lc = __build_pp(leftOfpre + 1, rightOfpre, leftOfpost, rightOfpost - 1);
            // only one child, default choose left
            _isunique = 0;
        }
        return opnv;
    }
    binode_ptr<_Tp> __invert(binode_ptr<_Tp> opnv)
    {
        if (!opnv)
            return nullptr;
        binode_ptr<_Tp> tmp = __invert(opnv->rc);
        opnv->rc = __invert(opnv->lc);
        opnv->lc = tmp;
        return opnv;
    }
    void __earse_leaf(binode_ptr<_Tp> &opnv, binode_ptr<_Tp> p)
    {
        if (!opnv)
            return;
        if (!opnv->lc && !opnv->rc)
        {
            if (p)
                this->__release(opnv);
            return;
        }
        __earse_leaf(opnv->lc, opnv);
        __earse_leaf(opnv->rc, opnv);
    }
    int __leafcount()
    {
        if (!this->_root)
            return -1;
        int cnt = 0;
        this->q.push_back(this->_root);
        while (this->q.size())
        {
            tp1 = this->q.front(), this->q.pop_front();
            if (!tp1->lc && !tp1->rc)
                cnt++;
            if (tp1->lc)
                this->q.push_back(tp1->lc);
            if (tp1->rc)
                this->q.push_back(tp1->rc);
        }
        this->q.clear();
        return cnt;
    }

    void __del_targetSub(binode_ptr<_Tp> opnv, int target)
    {
        binode_ptr<_Tp> x;
        if (opnv->val == target)
        {
            __eraseallSub(opnv);
            return;
        }
        this->q.push_back(opnv);
        while (this->q.size())
        {
            x = this->q.front(), this->q.pop_front();
            if (x->val == target)
            {
                __eraseallSub(x->lc);
                __eraseallSub(x->rc);
                x->lc = x->rc = nullptr;
                continue;
            }
            if (x->lc)
                this->q.push_back(x->lc);
            if (x->rc)
                this->q.push_back(x->rc);
        }
        this->q.clear();
    }
    void __eraseallSub(binode_ptr<_Tp> opnv)
    {
        if (!opnv)
            return;
        __eraseallSub(opnv->lc);
        __eraseallSub(opnv->rc);
        this->__release(opnv);
    }
    // v1 <-> v2  convertable, left <-> right;
    bool __isomprphic(binode_ptr<_Tp> v1, binode_ptr<_Tp> v2)
    {
        if (!v1 && !v2)
            return 1;
        if ((!v1 && v2) || (!v2 && v1))
            return 0;
        if (v1->val != v2->val)
            return 0;
        if (!v1->lc && !v2->lc)
            return __isomprphic(v1->rc, v2->rc);
        if (v1->lc && v2->lc && v1->lc->val == v2->lc->val)
            return __isomprphic(v1->lc, v2->lc) && __isomprphic(v1->rc, v2->rc);
        else
            return __isomprphic(v1->lc, v2->rc) && __isomprphic(v1->rc, v2->lc);
    }
    bool __treeIdentical(binode_ptr<_Tp> v1, binode_ptr<_Tp> v2)
    {
        if (!v1 && !v2)
            return 1;
        if (!v1 || !v2 || v1->val != v2->val)
            return 0;
        bool lf = __treeIdentical(v1->lc, v2->lc);
        bool rf = __treeIdentical(v1->rc, v2->rc);
        return lf && rf;
    }
    bool __TreeSimilar(binode_ptr<_Tp> v1, binode_ptr<_Tp> v2)
    {
        if (!v1 && !v2)
            return 1;
        if (!v1 || !v2) // if wanna test the two trees is identical , plus "|| v1->val != v2->val"
            return 0;
        return __TreeSimilar(v1->lc, v2->lc) && __TreeSimilar(v1->rc, v2->rc);
    }
    void __tree2Infix(binode<string> *opnv, int depth, string &s)
    {
        if (!opnv)
            return;
        if (!opnv->lc && !opnv->rc)
            s += opnv->val;
        else
        {
            if (depth)
                s.push_back('(');
            __tree2Infix(opnv->lc, depth + 1, s);
            s += opnv->val;
            __tree2Infix(opnv->rc, depth + 1, s);
            if (depth)
                s.push_back(')');
        }
    }
    template <class _Function>
    void __recur_pre(binode_ptr<_Tp> opnv, _Function _func)
    {
        if (!opnv)
            return;
        _func(opnv);
        __recur_pre(opnv->lc, _func);
        __recur_pre(opnv->rc, _func);
    }
    template <class _Function>
    void __recur_in(binode_ptr<_Tp> opnv, _Function _func)
    {
        if (!opnv)
            return;
        __recur_in(opnv->lc, _func);
        _func(opnv);
        __recur_in(opnv->rc, _func);
    }
    template <class _Function>
    void __recur_post(binode_ptr<_Tp> opnv, _Function _func)
    {
        if (!opnv)
            return;
        __recur_post(opnv->lc, _func);
        __recur_post(opnv->rc, _func);
        _func(opnv);
    }

    void __InThread(binode_ptr<_Tp> opnv, binode_ptr<_Tp> pre)
    {
        if (opnv)
        {
            __InThread(opnv->lc, pre);
            if (!opnv->lc)
            {
                opnv->ltag = 1;
                opnv->lc = pre;
            }
            if (pre && !pre->rc)
            {
                pre->rtag = 1;
                pre->rc = opnv;
            }
            __InThread(opnv->rc, opnv);
        }
    }
    double __op(double a, double b, char oper)
    {
        double res;
        switch (oper)
        {
        case '+':
            res = a + b;
            break;
        case '-':
            res = a - b;
            break;
        case '*':
            res = a * b;
            break;
        case '/':
            res = a / b;
            break;
        }
        return res;
    }
    double __infix_val(binode<string> *opnv)
    {
        if (!opnv)
            return 0;
        if (opnv->lc && opnv->rc)
        {
            double a = stof(__infix_val(opnv->lc)), b = stof(__infix_val(opnv->rc));
            return __op(a, b, opnv->val[0]);
        }
        return stof(opnv->val);
    }
    int __diameter()
    {
        q.push_back(this->_root);
        int level = 0, last = 0;
        while (q.size())
        {
            if (q.size() > 1)
                last = level;
            while (q.size())
            {
                tp1 = q.front(), q.pop_front();
                if (tp1->lc)
                    nexq.push_back(tp1->lc);
                if (tp1->rc)
                    nexq.push_back(tp1->rc);
            }
            level++;
            swap(q, nexq);
        }
        this->q.clear(), this->nexq.clear();
        return last + level - 1;
    }

    binode_ptr<_Tp> __buildcmp(int id, vector<int> &a)
    {
        if (a.size() - 1 < id)
            return nullptr;
        binode_ptr<_Tp> opnv = this->__newbinode(a[id]);
        opnv->lc = __buildcmp(id * 2 + 1, a);
        opnv->rc = __buildcmp(id * 2 + 2, a);
        return opnv;
    }

public:
    unordered_map<_Tp, binode_ptr<_Tp>> hashtable;
    vector<_Tp> preorder, inorder, postorder;
    bintree()
    {
        this->_root = nullptr;
        this->_isunique = true;
        this->q.clear(), this->nexq.clear();
        this->_size = 0;
        _isRBtree = 0;
        _ishuffman = 0;
    }
    ~bintree()
    {
        this->clear();
    }

    inline bool const empty() const { return _root == nullptr; }
    inline binode_ptr<_Tp> root() { return this->_root; }
    inline int size() const { return _size; }
    inline int diam() { return __diameter(); }
    inline int height() const
    {
        if (!_root)
            return 0;
        return _root->height;
    }
    inline void clear()
    {
        _root = tp1 = nullptr;
        q.clear(), nexq.clear();
        _size = 0;
        _isunique = 1;
        __display_buffer.clear();
        for (auto &ptr : __memofbinode)
            delete ptr;
        __memofbinode.clear();
    }

    void printhorizon()
    {
        if (!this->_root)
            return;
        __update_status();
        if (_ishuffman)
            cout << "🕵🏻‍   🌲  HUFFMAN TREE  🌲   🕵🏻‍" << endl;
        if (_isRBtree)
            cout << "🎩   🌲  RBTREE  🌲   🎒" << endl;
        printf("🌲\n");
        if (this->_size > (1 << 8) - 1)
        {
            cout << " Too Many Node to print !\n";
            return;
        }
        _unitsize = IS_CHAR<_Tp>() ? 1 : to_string(_root->rightest()->val).size();
        if (_isRBtree)
            _unitsize++;
        _direct2l = _direct2r = string(_unitsize, ' ');
        _direct2l[_unitsize / 2] = '/';
        _direct2r[_unitsize / 2] = '\\';
        this->__display_buffer = vector<vector<string>>(40, vector<string>(MAXCOL, string(_unitsize, ' ')));
        __print_horizon(this->_root, 0, pow(2, this->_root->height) - 1, pow(2, this->_root->height - 1));
        int n = this->_root->height * 2 + 1, i, j, breadth = pow(2, this->_root->height + 1) + 1;
        for (i = 0; i < n; ++i)
        {
            for (j = 0; j < breadth; ++j)
                cout << this->__display_buffer[i][j];
            cout << endl;
        }
        printf("🌲\n");
        if (_ishuffman)
            cout << "🕵🏻‍   🌲  HUFFMAN TREE  🌲   🕵🏻‍" << endl;
        if (_isRBtree)
            cout << "🎩   🌲  RBTREE  🌲   🎒" << endl;
        __display_buffer.clear();
    }
    inline void build(vector<int> &a)
    {
        __update_root(__buildcmp(0, a));
        __update_status();
    }
    inline void build_pi(vector<int> &pr, vector<int> &in)
    {
        this->preorder = pr, this->inorder = in;
        __update_root(__build_pi(0, 0, pr.size() - 1, nullptr));
        this->_size = in.size();
    }
    inline void build_ip(vector<int> &in, vector<int> &po)
    {
        this->postorder = po, this->inorder = in;
        __update_root(__build_ip(in.size() - 1, 0, in.size() - 1, nullptr));
        this->_size = in.size();
    }
    inline void invert()
    {
        if (!this->_root)
            return;
        __invert(this->_root);
        __update_status();
    }
    inline void earse_leaf()
    {
        if (!_root)
            return;
        __earse_leaf(_root, nullptr);
        _size = _root ? _root->size() : 0;
        __update_status();
    }
    inline int leafsize()
    {
        if (!this->_root)
            return 0;
        return __leafcount();
    }
    inline bool similar(bintree<_Tp> T2)
    {
        return __TreeSimilar(this->_root, T2.root());
    }
    inline bool identical(bintree<_Tp> T2)
    {
        return __treeIdentical(this->_root, T2.root());
    }
    inline bool isompriphic(bintree<_Tp> T2)
    {
        return __isomprphic(_root, T2.root());
    }
    inline bool symmetric()
    {
        if (!_root)
            return true;
        return __TreeSimilar(_root->lc, _root->rc);
    }
    binode_ptr<_Tp> convert2list()
    {
        if (!this->_root)
            return;
        vector<binode_ptr<_Tp>> ls;
        intrav([&](binode_ptr<_Tp> opnv) { ls.push_back(opnv); });
        auto p1 = ls.begin(), p2 = ls.begin() + 1;
        binode_ptr<_Tp> head = *p1;
        for (; p2 != ls.end(); p1++, p2++)
        {
            (*p1)->lc = nullptr;
            (*p1)->rc = (*p2);
        }
        (*p1)->rc = (*p1)->lc = nullptr;
        return head;
    }
    string tree2infix()
    {
        string s;
        __tree2Infix(this->_root, 0, s);
        return s;
    }
    void eraseSubOf(const _Tp &x)
    {
        if (!this->_root)
            return;
        __del_targetSub(this->_root, x);
    }
    double infixval()
    {
        return __infix_val(this->_root);
    }
    bool iscmp()
    {
        if (!this->_root)
            return true;
        binode_ptr<_Tp> opnv = this->_root;
        this->q.push_back(opnv);
        while (this->q.size())
        {
            tp1 = this->q.front(), this->q.pop_front();
            if (tp1)
                this->q.push_back(tp1->lc), this->q.push_back(tp1->rc);
            else
                while (this->q.size())
                {
                    tp1 = this->q.front(), this->q.pop_front();
                    if (tp1)
                        return false;
                }
        }
        this->q.clear();
        return true;
    }
    template <class _Function>
    void intrav(_Function _func)
    {
        __recur_in(this->_root, _func);
    }
    template <class _Function>
    void pretrav(_Function _func)
    {
        __recur_pre(this->_root, _func);
    }
    template <class _Function>
    void posttrav(_Function _func)
    {
        __recur_post(this->_root, _func);
    }
    void generate_inorder()
    {
        vector<_Tp> resSeq;
        stack<binode_ptr<_Tp>> s;
        binode_ptr<_Tp> opnv = this->_root;
        if (!opnv)
            return;
        binode_ptr<_Tp> p = opnv;
        while (s.size() || p)
        {
            while (p)
            {
                s.push(p);
                p = p->lc;
            }
            if (s.size())
            {
                p = s.top();
                s.pop();
                resSeq.push_back(p->val);
                p = p->rc;
            }
        }
        this->inorder = resSeq;
    }
    void generate_preorder()
    {
        vector<_Tp> resSeq;
        binode_ptr<_Tp> opnv = this->_root;
        if (!opnv)
            return;
        stack<binode_ptr<_Tp>> s;
        s.push(opnv);
        while (s.size())
        {
            opnv = s.top(), s.pop();
            resSeq.push_back(opnv->val);
            if (opnv->rc)
                s.push(opnv->rc);
            if (opnv->lc)
                s.push(opnv->lc);
        }
        this->preorder = resSeq;
    }
    void generate_postorder()
    {
        vector<_Tp> resSeq;
        binode_ptr<_Tp> opnv = this->_root;
        if (!opnv)
            return;
        stack<pair<binode_ptr<_Tp>, bool>> s;
        s.push(make_pair(opnv, false));
        bool isMyTurn;
        while (s.size())
        {
            opnv = s.top().first, isMyTurn = s.top().second, s.pop();
            if (isMyTurn)
                resSeq.push_back(opnv->val);
            else
            {
                s.push(make_pair(opnv, true));
                if (opnv->rc)
                    s.push(make_pair(opnv->rc, false));
                if (opnv->lc)
                    s.push(make_pair(opnv->lc, false));
            }
        }
        this->postorder = resSeq;
    }
    binode_ptr<_Tp> get_lca(binode_ptr<_Tp> p, binode_ptr<_Tp> q)
    {
        while (p->height < q->height)
            p = p->parent;
        while (q->height < p->height)
            q = q->parent;
        while (p != q)
            p = p->parent, q = q->parent;
        return p;
    }
    bool insert(const _Tp &val)
    {
        if (_root)
            _root->leftest()->lc = __newbinode(val);
        else
            _root = __newbinode(val);
        return true;
    }
    bool erase(const _Tp &val)
    {
        return false;
    }
    bool count(const _Tp &val)
    {
        int c = 0;
        intrav([&](binode_ptr<_Tp> v, int c) {if(v->val == val)c++; });
        return c;
    }
};

} // namespace dsa
#endif