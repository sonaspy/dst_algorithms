// author - sonaspy@outlook.com
// coding - utf_8

#ifndef __BINARYTREE__
#define __BINARYTREE__

#include "trees.h"
namespace dsa
{

template <typename T>
class bintree
{
protected:
    binode<T> *_root, *tp1;
    deque<binode<T> *> q, nexq;
    int _size;
    bool isunique; // pre post build
    vector<vector<string>> disp_buf;
    static inline void __updatedepth(binode<T> *&opnv) { opnv->depth = _depth(opnv->parent) + 1; }
    static inline void __updateheight(binode<T> *&opnv) { opnv->height = max(_height(opnv->lc), _height(opnv->rc)) + 1; }
    static inline void __updateheightabove(binode<T> *opnv)
    {
        while (opnv)
        {
            __updateheight(opnv);
            opnv = opnv->parent;
        }
    }
    static void __update_member(binode<T> *opnv, binode<T> *p)
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
    inline void __update_root(binode<T> *&opnv)
    {
        _root = opnv;
    }
    binode<T> *__build_pi(int opnv, int lo, int hi, binode<T> *p)
    {
        if (hi < lo)
            return nullptr;
        int i = lo;
        binode<T> *node = new binode<T>(preorder[opnv]);
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
    void __print_horizon(binode<T> *opnv, int root_x, int root_y, int interval)
    {
        if (!opnv)
            return;
        int left_child = root_y - interval, right_child = root_y + interval;
        string tp = to_string(opnv->val);
        if (tp.size() == 1)
            tp.push_back(' ');
        disp_buf[root_x][root_y] = tp;
        if (opnv->lc)
            disp_buf[root_x + 1][root_y - (interval + 1) / 2] = "/ ";
        if (opnv->rc)
            disp_buf[root_x + 1][root_y + (interval + 1) / 2] = " \\";
        __print_horizon(opnv->lc, root_x + 2, left_child, (interval >> 1));
        __print_horizon(opnv->rc, root_x + 2, right_child, (interval >> 1));
    }
    void __print_vertical(binode<T> *opnv, int root_x, int root_y, int interval)
    { // root_y = 0;
        if (!opnv)
            return;
        int left_child = root_x + interval, right_child = root_x - interval;
        string tp = to_string(opnv->val);
        while (tp.size() < 4)
            tp.push_back(' ');
        disp_buf[root_x][root_y] = tp;
        if (opnv->lc)
            disp_buf[root_x + (interval + 1) / 2][root_y + 1] = " \\  ";
        if (opnv->rc)
            disp_buf[root_x - (interval + 1) / 2][root_y + 1] = " /  ";
        __print_vertical(opnv->lc, left_child, root_y + 2, (interval >> 1));
        __print_vertical(opnv->rc, right_child, root_y + 2, (interval >> 1));
    }
    binode<T> *__build_ip(int opnv, int lo, int hi, binode<T> *p)
    {
        if (hi < lo)
            return nullptr;
        int i = lo;
        binode<T> *node = new binode<T>(postorder[opnv]);
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
    binode<T> *__build_pp(int leftOfpre, int rightOfpre, int leftOfpost, int rightOfpost)
    {
        if (leftOfpre > rightOfpre || leftOfpost > rightOfpost)
            return nullptr;
        binode<T> *opnv = new binode<T>(preorder[leftOfpre]);
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
            isunique = 0;
        }
        return opnv;
    }
    binode<T> *__invert(binode<T> *opnv)
    {
        if (!opnv)
            return nullptr;
        binode<T> *tmp = __invert(opnv->rc);
        opnv->rc = __invert(opnv->lc);
        opnv->lc = tmp;
        return opnv;
    }
    void __earse_leaf(binode<T> *&opnv, binode<T> *p)
    {
        if (!opnv)
            return;
        if (!opnv->lc && !opnv->rc)
        {
            if (p)
                __release(opnv);
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

    void __del_targetSub(binode<T> *opnv, int target)
    {
        binode<T> *x;
        if (opnv->val == target)
        {
            __del_allSub(opnv);
            return;
        }
        this->q.push_back(opnv);
        while (this->q.size())
        {
            x = this->q.front(), this->q.pop_front();
            if (x->val == target)
            {
                __del_allSub(x->lc);
                __del_allSub(x->rc);
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
    void __del_allSub(binode<T> *opnv)
    {
        if (!opnv)
            return;
        __del_allSub(opnv->lc);
        __del_allSub(opnv->rc);
        __release(opnv);
    }
    bool __treeIdentical(binode<T> *T1, binode<T> *T2)
    {
        if (!T1 && !T2)
            return 1;
        if (!T1 || !T2 || T1->val != T2->val)
            return 0;
        bool lf = __treeIdentical(T1->lc, T2->lc);
        bool rf = __treeIdentical(T1->rc, T2->rc);
        return lf && rf;
    }
    bool __TreeSimilar(binode<T> *T1, binode<T> *T2)
    {
        if (!T1 && !T2)
            return 1;
        if (!T1 || !T2) // if wanna test the two trees is identical , plus "|| T1->val != T2->val"
            return 0;
        return __TreeSimilar(T1->lc, T2->lc) && __TreeSimilar(T1->rc, T2->rc);
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
    void __recur_pre(binode<T> *opnv, _Function f)
    {
        if (!opnv)
            return;
        f(opnv);
        __recur_pre(opnv->lc, f);
        __recur_pre(opnv->rc, f);
    }
    template <class _Function>
    void __recur_in(binode<T> *opnv, _Function f)
    {
        if (!opnv)
            return;
        __recur_in(opnv->lc, f);
        f(opnv);
        __recur_in(opnv->rc, f);
    }
    template <class _Function>
    void __recur_post(binode<T> *opnv, _Function f)
    {
        if (!opnv)
            return;
        __recur_post(opnv->lc, f);
        __recur_post(opnv->rc, f);
        f(opnv);
    }

    void __InThread(binode<T> *opnv, binode<T> *pre)
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

public:
    unordered_map<T, binode<T> *> hashtable;
    vector<T> preorder, inorder, postorder;
    bintree()
    {
        this->_root = nullptr;
        this->isunique = true;
        this->q.clear(), this->nexq.clear();
        this->_size = 0;
    }
    ~bintree()
    {
        this->clear();
    }

    inline bool const empty() const { return this->_root == nullptr; }
    inline binode<T> *root() { return this->_root; }
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
        isunique = 1;
        disp_buf.clear();
    }

    void printTreeHorizon()
    {
        if (!this->_root)
            return;
        printf("🌲\n");
        if (this->_size > (1 << 8) - 1)
        {
            cout << " Too Many Node !\n";
            return;
        }
        this->disp_buf = vector<vector<string>>(40, vector<string>(MAXCOL, string(2, ' ')));
        __print_horizon(this->_root, 0, pow(2, this->_root->height) - 1, pow(2, this->_root->height - 1));
        int n = this->_root->height * 2 + 1, i, j, breadth = pow(2, this->_root->height + 1) + 1;
        for (i = 0; i < n; ++i)
        {
            for (j = 0; j < breadth; ++j)
                cout << disp_buf[i][j];
            cout << endl;
        }
        printf("🌲\n");
    }
    void printTreeVertical()
    {
        if (!this->_root)
            return;
        if (this->_size > (1 << 15) - 1)
        {
            cout << " Too Many Node !\n";
            return;
        }
        printf("🌲\n");
        this->disp_buf = vector<vector<string>>(MAXROW, vector<string>(40, string(4, ' ')));
        __print_vertical(this->_root, pow(2, this->_root->height) - 1, 0, pow(2, this->_root->height - 1));
        int i, j, breadth = pow(2, this->_root->height + 1) + 1, n = this->_root->height * 2 + 1;
        for (i = 0; i < breadth; ++i)
        {
            for (j = 0; j < n; ++j)
                cout << disp_buf[i][j];
            cout << endl;
        }
        printf("🌲\n");
    }
    binode<T> *__buildcmp(int id, vector<int> &a)
    {
        if (a.size() - 1 < id)
            return nullptr;
        binode<T> *opnv = new binode<T>(a[id]);
        opnv->lc = __buildcmp(id * 2 + 1, a);
        opnv->rc = __buildcmp(id * 2 + 2, a);
        return opnv;
    }
    inline void build_cmp(vector<int> &a)
    {
        __update_root(__buildcmp(0, a));
        bintree<T>::__update_status();
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
        bintree<T>::__update_status();
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
    inline bool similar(bintree<T> T2)
    {
        return __TreeSimilar(this->_root, T2.root());
    }
    inline bool identical(bintree<T> T2)
    {
        return __treeIdentical(this->_root, T2.root());
    }
    inline bool symmetric()
    {
        if (!this->_root)
            return true;
        return __TreeSimilar(this->_root->lc, this->_root->rc);
    }
    binode<T> *convert2list()
    {
        if (!this->_root)
            return;
        vector<binode<T> *> ls;
        intrav([&](binode<T> *opnv) { ls.push_back(opnv); });
        auto p1 = ls.begin(), p2 = ls.begin() + 1;
        binode<T> *head = *p1;
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
    void eraseSubOf(const T &x)
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
        binode<T> *opnv = this->_root;
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
    void intrav(_Function f)
    {
        __recur_in(this->_root, f);
    }
    template <class _Function>
    void pretrav(_Function f)
    {
        __recur_pre(this->_root, f);
    }
    template <class _Function>
    void posttrav(_Function f)
    {
        __recur_post(this->_root, f);
    }
    void inTrav()
    {
        vector<T> resSeq;
        stack<binode<T> *> s;
        binode<T> *opnv = this->_root;
        if (!opnv)
            return;
        binode<T> *p = opnv;
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
    void preTrav()
    {
        vector<T> resSeq;
        binode<T> *opnv = this->_root;
        if (!opnv)
            return;
        stack<binode<T> *> s;
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
    void postTrav()
    {
        vector<T> resSeq;
        binode<T> *opnv = this->_root;
        if (!opnv)
            return;
        stack<pair<binode<T> *, bool>> s;
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
    binode<T> *get_LCA(binode<T> *p, binode<T> *q)
    {
        while (p->depth > q->depth)
            p = p->parent;
        while (q->depth > p->depth)
            q = q->parent;
        while (p != q)
            p = p->parent, q = q->parent;
        return p;
    }

    // T1 <-> T2  convertable, left <-> right;
    int Isomprphic(binode<T> *root1, binode<T> *root2)
    {
        if (!root1 && !root2)
            return 1;
        if ((!root1 && root2) || (!root2 && root1))
            return 0;
        if (root1->val != root2->val)
            return 0;
        if (!root1->lc && !root2->lc)
            return Isomprphic(root1->rc, root2->rc);
        if (root1->lc && root2->lc && root1->lc->val == root2->lc->val)
            return Isomprphic(root1->lc, root2->lc) && Isomprphic(root1->rc, root2->rc);
        else
            return Isomprphic(root1->lc, root2->rc) && Isomprphic(root1->rc, root2->lc);
    }
};
} // namespace dsa
#endif