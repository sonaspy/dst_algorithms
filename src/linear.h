// author - sonaspy@outlook.com
// coding - utf_8
#ifndef __LINEAR__
#define __LINEAR__
#include "functions.h"
using namespace std;
namespace dsa
{

template <typename T>
struct ListNode;
template <typename T>
using lnodeptr = struct ListNode<T> *;

template <typename T>
struct ListNode
{
    T val;
    int freq;
    lnodeptr<T> next, pre;
    ListNode() : val(INT_MIN), freq(0), next(nullptr), pre(nullptr) {}
    ListNode(T v) : val(v), freq(0), next(nullptr), pre(nullptr) {}
};

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

bool isMatch(vector<int> &push_seq, vector<int> &pop_seq, int capacity)
{
    int walk = 0;
    stack<int> s;
    for (int j = 0; j < push_seq.size(); j++)
    {
        s.push(push_seq[j]);
        if (s.size() > capacity)
            break;
        while (s.size() && s.top() == pop_seq[walk])
            s.pop(), walk++;
    }
    return walk == capacity;
}

template <typename T>
class link_list
{
protected:
    lnodeptr<T> _dummy;
    unordered_set<lnodeptr<T>> __memoflnode;
    inline lnodeptr<T> __newlnode(const T &val)
    {
        lnodeptr<T> v = new ListNode<T>(val);
        __memoflnode.insert(v);
        return v;
    }
    inline lnodeptr<T> __newlnode()
    {
        lnodeptr<T> v = new ListNode<T>();
        __memoflnode.insert(v);
        return v;
    }
    inline void __release(lnodeptr<T> &v)
    {
        delete v;
        v = nullptr;
        __memoflnode.erase(v);
    }

public:
    link_list()
    {
        _dummy = nullptr;
    }
    ~link_list()
    {
        clear();
    }
    void clear()
    {
        _dummy = nullptr;
        for (auto &ptr : __memoflnode)
            delete ptr;
        __memoflnode.clear();
    }
    void __merge_list(lnodeptr<T> l2)
    { // 2 increasing order list merge to a new increasing order list. in-place (rear insert)
        lnodeptr<T> p = _dummy->next, q = l2->next, r;
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

#define HEAD_INSERT(dum, __1st) \
    __1st->next = dum->next;    \
    dum->next = __1st
    void __merge_list2(lnodeptr<T> l2)
    { // 2 increasing order list merge to a new decreasing order list. in-place (head insert)
        lnodeptr<T> p = _dummy->next, q = l2->next, h;
        _dummy->next = nullptr;
        delete l2;
        while (p && q)
        {
            p->val <= q->val ? h = p, p = p->next : h = q, q = q->next;
            HEAD_INSERT(_dummy, h);
        }
        while (p)
        {
            h = p, p = p->next;
            HEAD_INSERT(_dummy, h);
        }
        while (q)
        {
            h = q, q = q->next;
            HEAD_INSERT(_dummy, h);
        }
    }
    void __reverse_list()
    {
        lnodeptr<T> walk, post;
        walk = _dummy->next;
        _dummy->next = NULL;
        while (walk)
        {
            post = walk->next;
            HEAD_INSERT(_dummy, walk);
            walk = post;
        }
    }
    void unique_sorted_Linkedlist()
    {
        lnodeptr<T> p = _dummy->next, d;
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
    }
    void __erase0(lnodeptr<T> &v, const T &x)
    {
        if (!v)
            return;
        if (v->val == x)
        {
            lnodeptr<T> p = v;
            v = v->next;
            delete v;
            __erase0(v, x);
        }
        else
            __erase0(v->next, x);
    }
    void __erase1(const T &x)
    {
        lnodeptr<T> p = _dummy->next, r = _dummy, q;
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
                q = p;
                p = p->next;
                delete q;
            }
        }
        r->next = nullptr;
    }
    void sort_linkedlist()
    { // insert
        lnodeptr<T> walk = _dummy->next, pre, the_nex = walk->next;
        walk->next = nullptr;
        walk = the_nex;
        while (walk)
        {
            the_nex = walk->next;
            for (pre = _dummy; pre->next && pre->next->val <= walk->val; pre = pre->next)
                ;
            walk->next = pre->next;
            pre->next = walk;
            walk = the_nex;
        }
    }
    void sort_linkedlist1()
    { // bubble
        lnodeptr<T> pre, post;
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
    }
    void __locate(const T &x)
    {
        lnodeptr<T> p = _dummy->next, left;
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
        lnodeptr<T> p = _dummy->next, walk = p->next;
        while (walk)
        {
            if (walk->val > p->val)
                return false;
            p = walk;
            walk = walk->next;
        }
        return true;
    }

    lnodeptr<T> kth_ultimate(int k)
    {
        lnodeptr<T> r, l;
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

    void output()
    {
        lnodeptr<T> p = _dummy->next;
        while (p)
        {
            cout << p->val << " -> ";
            p = p->next;
        }
        cout << "nullptr" << endl;
    }

    void build(vector<int> &a)
    {
        _dummy = __newlnode();
        lnodeptr<T> p = _dummy;
        for (auto &val : a)
        {
            p->next = __newlnode(val);
            p->next->pre = p;
            p = p->next;
        }
    }

    lnodeptr<T> find_common_p(lnodeptr<T> &l1, lnodeptr<T> &l2)
    {
        lnodeptr<T> thelong, theshort, p = l1, q = l2;
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

bool bracketMatch(char *f)
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

// 后缀表达式O(N)
// 中缀 -> 后缀
/*
1.运算数 output
2.左括号， push
3.右括号， pop output, until reach '(', pop too.
4.运算符 I.if pri(this) > pri(top),push. II.if <= ,pop output, then compare again, until push.
5.'(' push之前pri最高， push后pri最低
6.表达式处理完毕后 output rest in stack
(before start, put a guard in stack ,pri = -1(lowest) );
*/
}; // namespace dsa

#endif