// author - sonaspy@outlook.com
// coding - utf_8
#ifndef __LINEAR__
#define __LINEAR__
#include "algorithms.h"
using namespace std;
namespace dsa
{

template <typename _Tp>
struct listNode;
template <typename _Tp>
using lnode_ptr = struct listNode<_Tp> *;

template <typename _Tp>
struct listNode
{
    _Tp val;
    int freq;
    lnode_ptr<_Tp> next, pre;
    listNode() : val(INT_MIN), freq(0), next(nullptr), pre(nullptr) {}
    listNode(_Tp v, lnode_ptr<_Tp> p = nullptr, lnode_ptr<_Tp> nex = nullptr) : val(v), freq(0), next(nex), pre(p) {}
};

template <typename _Tp>
class link_list
{
protected:
    int _size;

#define __insert_head(dum, __1st) \
    __1st->next = dum->next;      \
    dum->next = __1st

    lnode_ptr<_Tp> _dummy, _rear;
    unordered_set<lnode_ptr<_Tp>> __memoflnode;
    inline lnode_ptr<_Tp> __newlnode(const _Tp &val, lnode_ptr<_Tp> p = nullptr, lnode_ptr<_Tp> nex = nullptr)
    {
        lnode_ptr<_Tp> v = new listNode<_Tp>(val, p, nex);
        __memoflnode.insert(v);
        _size++;
        return v;
    }
    inline lnode_ptr<_Tp> __newlnode()
    {
        lnode_ptr<_Tp> v = new listNode<_Tp>();
        __memoflnode.insert(v);
        _size++;
        return v;
    }
    inline void __release(lnode_ptr<_Tp> &v)
    {
        __memoflnode.erase(v);
        _size--;
        delete v;
        v = nullptr;
    }
    void __erase0(lnode_ptr<_Tp> &v, const _Tp &x)
    {
        if (!v)
            return;
        if (v->val == x)
        {
            lnode_ptr<_Tp> p = v;
            v = v->next;
            delete v;
            __erase0(v, x);
        }
        else
            __erase0(v->next, x);
    }
    void __erase1(const _Tp &x)
    {
        lnode_ptr<_Tp> p = _dummy->next, r = _dummy, tmp;
        while (p)
        {
            if (p->val != x)
            {
                r->next = p;
                r = p;
                p = p->next;
            }
            else
            {
                tmp = p;
                p = p->next;
                __release(tmp);
            }
        }
        r->next = nullptr;
        __add_pre();
    }
    void __merge_list(lnode_ptr<_Tp> l2)
    { // 2 increasing order list merge to a new increasing order list. in-place (rear insert)
        lnode_ptr<_Tp> p = _dummy->next, q = l2->next, r;
        _dummy->next = nullptr;
        delete l2;
        r = _dummy;
        while (p && q)
        {
            p->val <= q->val ? r->next = p, p = p->next : r->next = q, q = q->next;
            r = r->next;
        }
        r->next = p ? p : q;
    }
    void __merge_list2(lnode_ptr<_Tp> l2)
    { // 2 increasing order list merge to a new decreasing order list. in-place (head insert)
        lnode_ptr<_Tp> p = _dummy->next, q = l2->next, h;
        _dummy->next = nullptr;
        delete l2;
        while (p && q)
        {
            p->val <= q->val ? h = p, p = p->next : h = q, q = q->next;
            __insert_head(_dummy, h);
        }
        while (p)
        {
            h = p, p = p->next;
            __insert_head(_dummy, h);
        }
        while (q)
        {
            h = q, q = q->next;
            __insert_head(_dummy, h);
        }
    }
    void __add_pre()
    {
        lnode_ptr<_Tp> _walk = _dummy->next, p = _dummy;
        for (; _walk; _walk = _walk->next)
            _walk->pre = p, p = _walk;
    }

public:
    link_list()
    {
        _dummy = _rear = __newlnode();
        _size = 0;
    }
    ~link_list()
    {
        clear();
    }
    inline int size() const { return _size; }
    inline int empty() const { return _size == 0; }
    void clear()
    {
        _dummy = nullptr;
        for (auto &ptr : __memoflnode)
            delete ptr;
        __memoflnode.clear();
        _size = 0;
    }
    void reverse()
    {
        lnode_ptr<_Tp> _walk, post;
        _walk = _dummy->next;
        _dummy->next = NULL;
        while (_walk)
        {
            post = _walk->next;
            __insert_head(_dummy, _walk);
            _walk = post;
        }
        __add_pre();
    }
    void erase_val(const _Tp &val)
    {
        __erase1(val);
    }
    void erase(int _pos)
    {
        if (_pos < _size)
        {
            lnode_ptr<_Tp> _walk = _dummy->next, p, post;
            for (; _pos--; _walk = _walk->next)
                ;
            post = _walk->next;
            p = _walk->pre;
            p->next = post;
            if (post)
                post->pre = p;
            else
                _rear = p;
            __release(_walk);
        }
    }
    void insert(int _pos, const _Tp &val)
    {
        if (_pos <= _size)
        {
            lnode_ptr<_Tp> _walk = _dummy->next, p = _dummy, v;
            for (; _pos--; _walk = _walk->next)
                p = _walk;
            v = __newlnode(val, p, _walk);
            p->next = v;
            if (_walk)
                _walk->pre = v;
            else
                _rear = v;
        }
    }
    void unique()
    {
        lnode_ptr<_Tp> p = _dummy->next, d;
        if (!p)
            return;
        while (p->next)
        {
            d = p->next;
            if (d->val == p->val)
            {
                p->next = d->next;
                delete d;
            }
            else
                p = p->next;
        }
        __add_pre();
    }
    void insertsort()
    {
        lnode_ptr<_Tp> _walk = _dummy->next, pre, the_nex = _walk->next;
        _walk->next = nullptr;
        _walk = the_nex;
        while (_walk)
        {
            the_nex = _walk->next;
            for (pre = _dummy; pre->next && pre->next->val <= _walk->val; pre = pre->next)
                ;
            _walk->next = pre->next;
            pre->next = _walk;
            _walk = the_nex;
        }
        __add_pre();
    }
    void bubblesort()
    {
        lnode_ptr<_Tp> pre, post;
        int flag;
        do
        {
            flag = 0, pre = _dummy, post = pre->next;
            while (post && post->next)
            {
                if (post->val > post->next->val)
                {
                    flag = 1;
                    pre->next = post->next;
                    post->next = post->next->next;
                    pre->next->next = post;
                }
                pre = post;
                post = post->next;
            }
        } while (flag);
        __add_pre();
    }
    void locate(const _Tp &x)
    {
        lnode_ptr<_Tp> p = _dummy->next, left;
        while (p && p->val != x)
            p = p->next;
        if (!p)
            return;
        p->freq++;

        p->next->pre = p->pre;
        p->pre->next = p->next;
        left = p->pre;

        while (left != _dummy && left->freq <= p->freq)
            left = left->pre;

        p->next = left->next;
        p->pre = left;
        left->next = p;
        p->next->pre = p;
    }
    bool is_sorted()
    {
        if (!_dummy->next || !_dummy->next->next)
            return true;
        lnode_ptr<_Tp> p = _dummy->next, _walk = p->next;
        while (_walk)
        {
            if (_walk->val > p->val)
                return false;
            p = _walk;
            _walk = _walk->next;
        }
        return true;
    }

    lnode_ptr<_Tp> kth_ultimate(int k)
    {
        lnode_ptr<_Tp> r, l;
        r = l = _dummy;
        while (--k && r)
            r = r->next;
        if (0 <= k && !r->next)
            return nullptr;
        while (r->next && l->next)
        {
            r = r->next;
            l = l->next;
        }
        return l;
    }
    void print()
    {
        lnode_ptr<_Tp> p = _dummy->next;
        while (p)
        {
            cout << p->val << " -> ";
            p = p->next;
        }
        cout << "nullptr" << endl;
    }
    void build(vector<int> &a)
    {
        _rear = _dummy;
        lnode_ptr<_Tp> p = _dummy;
        for (auto &val : a)
        {
            p->next = __newlnode(val, p);
            p = p->next;
            _rear = p;
        }
    }
    lnode_ptr<_Tp> find_common_p(lnode_ptr<_Tp> &l1, lnode_ptr<_Tp> &l2)
    {
        lnode_ptr<_Tp> thelong, theshort, p = l1, q = l2;
        int len1 = 0, len2 = 0, step = 0;
        while (p)
            p = p->next, len1++;
        while (q)
            q = q->next, len2++;
        thelong = len1 > len2 ? l1 : l2;
        theshort = thelong == l2 ? l1 : l2;
        step = abs(len1 - len2);
        while (step--)
            thelong = thelong->next;
        while (thelong != theshort)
            thelong = thelong->next, theshort = theshort->next;
        return thelong;
    }
    void push_back(const _Tp &val)
    {
        _rear->next = __newlnode(val, _rear);
        _rear = _rear->next;
    }
    void push_front(const _Tp &val)
    {
        lnode_ptr<_Tp> v = __newlnode(val, _dummy);
        v->next = _dummy->next;
        _dummy->next = v;
    }
    void pop_front()
    {
        if (_size)
        {
            lnode_ptr<_Tp> tmp = _dummy->next;
            _dummy->next = tmp->next;
            if (_dummy->next)
                _dummy->next->pre = _dummy;
            __release(tmp);
        }
    }
    void pop_back()
    {
        if (_size)
        {
            lnode_ptr<_Tp> tmp = _rear;
            _rear = _rear->pre;
            _rear->next = nullptr;
            __release(tmp);
        }
    }
    _Tp back()
    {
        return _rear->val;
    }
    _Tp front()
    {
        return _dummy->next->val;
    }
};

class sk_queue
{
private:
    stack<int> s1, s2; // s1 - input . s2 - output
    int maxsize;

public:
    inline bool enQueue(int x)
    {
        if (s1.size() == maxsize)
        {
            if (s2.size())
                return 0;
            while (s1.size())
                s2.push(s1.top()), s1.pop();
        }
        s1.push(x);
        return 1;
    }
    inline bool deQueue(int &x)
    {
        if (s1.empty() && s2.empty())
            return 0;
        if (s2.empty())
            while (s1.size())
                s2.push(s1.top()), s1.pop();
        x = s2.top();
        s2.pop();
        return 1;
    }
};

class tag_queue
{
private:
    int tag, front, rear, maxsize;
    vector<int> data;

public:
    tag_queue()
    {
        tag = front = rear = 0;
        data.resize(100);
        maxsize = 100;
    }
    inline bool isempty()
    {
        return front == rear && !tag;
    }
    inline bool isfull()
    {
        return front == rear && tag;
    }
    bool enqueue(int x)
    {
        if (isfull())
            return 0;
        data[rear] = x;
        rear = (rear + 1) % maxsize;
        tag = 1;
        return 1;
    }
    bool dequeue(int &x)
    {
        if (isempty())
            return 0;
        x = data[front];
        front = (front + 1) % maxsize;
        tag = 0;
        return 1;
    }
};

class share_stack
{
private:
    int maxsize, top1, top2;
    vector<int> data;

public:
    share_stack(int m)
    {
        maxsize = m, top1 = -1, top2 = maxsize;
        data.resize(maxsize);
    }
    inline bool isfull() { return top1 + 1 == top2; }
    inline bool isempty(int id) { return id == 1 ? top1 == -1 : top2 == maxsize; }
    bool push(int id, int x)
    {
        if (isfull())
            return 0;
        data[id == 1 ? ++top1 : --top2] = x;
        return true;
    }
    bool pop(int id, int &x)
    {
        if (isempty(id))
            return 0;
        x = data[id == 1 ? top1-- : top2++];
        return 1;
    }
};

template <typename _Tp>
class _stack
{
protected:
    vector<_Tp> data;

public:
    _stack()
    {
    }
    inline void empty()
    {
        return data.empty();
    }
    inline void push(const _Tp &val)
    {
        data.push_back(val);
    }
    inline _Tp top()
    {
        return data.back();
    }
    inline void pop()
    {
        data.pop_back();
    }
    inline int size()
    {
        return data.size();
    }
};


template <typename _Tp>
class _deque
{
protected:
    vector<int> data;
    int _rear, _front, _maxsize;
public:
    _deque(int n = 100)
    {
        _maxsize = n + 1;
        data.resize(_maxsize);
        _rear = _front = 0;
    }
    int size()
    {
        return (_rear - _front + _maxsize) % _maxsize;
    }
    void resize(int n)
    {
        data.resize(n + 1);
        _maxsize = n + 1;
    }
    void clear()
    {
        _rear = _front = 0;
    }
    bool empty()
    {
        return _rear == _front;
    }
    bool full()
    {
        return (_rear + 1) % _maxsize == _front;
    }
    void pop_back()
    {
        if (empty())
            return;
        _rear = (_rear - 1 + _maxsize) % _maxsize;
    }
    void pop_front()
    {
        if (empty())
            return;
        _front = (_front + 1) % _maxsize;
    }
    void push_back(const _Tp &val)
    {
        if (full())
            return;
        _rear = (_rear + 1) % _maxsize;
        data[_rear] = val;
    }
    void push_front(const _Tp &val)
    {
        if (full())
            return;
        data[_front] = val;
        _front = (_front - 1 + _maxsize) % _maxsize;
    }
    _Tp front()
    {
        return data[(_front + 1) % _maxsize];
    }
    _Tp back()
    {
        return data[_rear];
    }
};

bool
bracketMatch(char *f)
{
    stack<char> s;
    char *p = f;
    while (*p)
    {
        if (*p == '\'')
            while (*(++p) != '\'')
                ;
        else if (*p == '\"')
            while (*(++p) != '\"')
                ;
        switch (*p)
        {
        case '{':
        case '[':
        case '(':
            s.push(*p);
            break;
        case ')':
            if (s.top() == '(')
                s.pop();
            else
                return 0;
            break;
        case '}':
            if (s.top() == '{')
                s.pop();
            else
                return 0;
            break;
        case ']':
            if (s.top() == '[')
                s.pop();
            else
                return 0;
            break;
        }
        ++p;
    }
    return s.empty();
}

class NQueen
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        this->columns = vector<bool>(n, false);           // if there is a queen in this column.
        this->main_diag = vector<bool>(2 * n - 1, false); // if there is a queen in this diag
        this->vice_diag = vector<bool>(2 * n - 1, false); // if there is a queen in this diag
        this->C = vector<int>(n, -1);                     // each row's queen put in which column
        vector<vector<string>> res;
        this->n = n;
        dfs(res, 0);
        return res;
    }

private:
    vector<bool> columns, main_diag, vice_diag;
    vector<int> C;
    int n;
    void dfs(vector<vector<string>> &res, int row)
    {
        if (row == n)
        {
            res.push_back(vector<string>());
            for (int i = 0; i < n; i++)
            {
                string s(n, '.');
                for (int j = 0; j < n; j++)
                    if (j == C[i])
                        s[j] = 'Q';
                res.back().push_back(s);
            }
            return;
        }
        for (int j = 0; j < n; j++)
        {
            if (!columns[j] && !main_diag[row - j + n - 1] && !vice_diag[row + j])
            {
                C[row] = j;
                columns[j] = main_diag[row - j + n - 1] = vice_diag[row + j] = true;
                dfs(res, row + 1);
                C[row] = -1;
                columns[j] = main_diag[row - j + n - 1] = vice_diag[row + j] = false;
            }
        }
    }
};

// 后缀表达式O(N)
// 中缀 -> 后缀
/*
1.运算数 output
2.左括号， push
3.右括号， pop output, until reach '(', pop too.
4.运算符 I.if pri(this) > pri(top),push. else, pop output, then compare again, until push.
5.'(' push之前pri最高， push后pri最低
6.表达式处理完毕后 output rest in stack
(before start, put a guard in stack ,pri = -1(lowest) );
*/
}; // namespace dsa

#endif