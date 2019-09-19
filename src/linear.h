// author - sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>
using namespace std;
namespace dsa
{
struct ListNode
{
    int val, freq;
    ListNode *next, *pre;
    ListNode() : val(INT_MIN), freq(0), next(nullptr), pre(nullptr) {}
    ListNode(int v) : val(v), freq(0), next(nullptr), pre(nullptr) {}
};
void towersOfHanoi(int n, char x, char y, char z)
{ // Move the top n disks from tower x to tower y.
    // Use tower z for intermediate storage.
    if (n > 0)
    {
        towersOfHanoi(n - 1, x, z, y);
        std::cout << "Move top disk from tower " << x
                  << " to top of tower " << y << std::endl;
        towersOfHanoi(n - 1, z, y, x);
    }
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

double myPow(double x, int n)
{
    long long N = n;
    if (N < 0)
    {
        x = 1 / x;
        N = -N;
    }
    double ans = 1;
    double cur = x;
    for (long long i = N; i; i /= 2)
    {
        if ((i % 2) == 1)
            ans *= cur;
        cur *= cur;
    }
    return ans;
}

double polynomial(int n, double a[], double x)
{
    int i;
    double p = a[n];
    for (i = n; i; --i)
        p = a[i - 1] + x * p;
    return p;
}

// find median in 2 array
template <class T>
T M_search(T *lo1, T *hi1, T *lo2, T *hi2)
{
    T *m1, *m2;
    while (lo1 < hi1 || lo2 < hi2)
    {
        m1 = lo1 + (hi1 - lo1) / 2;
        m2 = lo2 + (hi2 - lo2) / 2;
        if (*m1 == *m2)
            return *m1;
        if (*m1 < *m2)
        {
            lo1 = (hi1 - lo1) % 2 ? m1 + 1 : m1;
            hi2 = m2;
        }
        else
        {
            lo2 = (hi2 - lo2) % 2 ? m2 + 1 : m2;
            hi1 = m1;
        }
    }
    return min(*lo1, *lo2);
}

template <class RandomIterator>
bool isparlindrome(RandomIterator lo, RandomIterator hi)
{
    if (lo < hi)
        for (; lo < --hi; ++lo)
            if (*lo != *hi)
                return false;
    return true;
}

template <class RandomIterator>
void reverse_(RandomIterator lo, RandomIterator hi)
{
    if (lo < hi)
        for (; lo < --hi; ++lo)
            iter_swap(lo, hi);
}

template <class T>
bool list_move(T *lo, T *hi, int offset, bool left)
{
    if (lo < hi)
    {
        reverse(lo, hi);
        if (left)
        {
            reverse(lo, hi - offset);
            reverse(hi - offset, hi);
        }
        else
        {
            reverse(lo, lo + offset);
            reverse(lo + offset, hi);
        }
        return true;
    }
    return false;
}

template <class T>
T *bin_search(T *lo, T *hi, const T &val)
{
    T *mid;
    while (lo <= hi)
    {
        mid = lo + (hi - lo) / 2;
        if (*mid < val)
            lo = mid + 1;
        else if (val < *mid)
            hi = mid - 1;
        else
            return mid;
    }
    return hi;
}

inline int GCD(int a, int b)
{
    while (b)
    {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}
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

class Linked_List
{
public:
    void _merge_list(ListNode *l1, ListNode *l2, ListNode *&l)
    { // 2 increasing order list merge to a new increasing order list. in-place (rear insert)
        ListNode *p = l1->next, *q = l2->next, *r;
        l = l1;
        l->next = nullptr;
        delete l2;
        r = l;
        while (p && q)
        {
            p->val <= q->val ? r->next = p, p = p->next : r->next = q, q = q->next;
            r = r->next;
        }
        r->next = p ? p : q;
    }

#define HEAD_INSERT(L, first) \
    first->next = L->next;    \
    L->next = first
    void _merge_list2(ListNode *l1, ListNode *l2, ListNode *&l)
    { // 2 increasing order list merge to a new decreasing order list. in-place (head insert)
        ListNode *p = l1->next, *q = l2->next, *h;
        l = l1;
        l->next = nullptr;
        delete l2;
        while (p && q)
        {
            p->val <= q->val ? h = p, p = p->next : h = q, q = q->next;
            HEAD_INSERT(l, h);
        }
        while (p)
        {
            h = p, p = p->next;
            HEAD_INSERT(l, h);
        }
        while (q)
        {
            h = q, q = q->next;
            HEAD_INSERT(l, h);
        }
    }

    void reverse_List(ListNode *L)
    {
        ListNode *walk, *post;
        walk = L->next;
        L->next = NULL;
        while (walk)
        {
            post = walk->next;
            HEAD_INSERT(L, walk);
            walk = post;
        }
    }

    template <class T>
    void unique_sorted_list(T *lo, T *hi)
    {
        T *i = lo, *j = lo + 1;
        for (; j < hi; ++j)
            if (*i != *j)
                *(++i) = *j;
    }
    void unique_sorted_Linkedlist(ListNode *l)
    {
        ListNode *p = l->next, *d;
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

    void del_x_inlist1(ListNode *&l, int x)
    {
        if (!l)
            return;
        if (l->val == x)
        {
            ListNode *p = l;
            l = l->next;
            delete l;
            del_x_inlist1(l, x);
        }
        else
            del_x_inlist1(l->next, x);
    }
    void del_x_inlist2(ListNode *&l, int x)
    {
        ListNode *p = l->next, *r = l, *q;
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

    void sort_linkedlist(ListNode *&l)
    { // insertion
        ListNode *walk = l->next, *pre, *the_nex = walk->next;
        walk->next = nullptr;
        walk = the_nex;
        while (walk)
        {
            the_nex = walk->next;
            for (pre = l; pre->next && pre->next->val <= walk->val; pre = pre->next)
                ;
            walk->next = pre->next;
            pre->next = walk;
            walk = the_nex;
        }
    }
    void sort_linkedlist1(ListNode *&l)
    { // bubble
        ListNode *pre, *post;
        int flag;
        do
        {
            flag = 0, pre = l, post = pre->next;
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

    void Min_delete(ListNode *&l)
    {
        ListNode *p, *pre, *u;
        while (l->next)
        {
            pre = l;
            p = pre->next;
            while (p->next)
            {
                if (p->next->val < pre->next->val)
                    pre = p;
                p = p->next;
            }
            //cout << pre->next->val;
            u = pre->next;
            pre->next = u->next;
            delete u;
        }
        delete (l);
    }

    ListNode *Locate(ListNode *&l, int x)
    {
        ListNode *p = l->next, *left;
        while (p && p->val != x)
            p = p->next;
        if (!p)
            return nullptr;
        p->freq++;
        p->next->pre = p->pre;
        p->pre->next = p->next;
        left = p->pre;
        while (left != l && left->freq <= p->freq)
            left = left->pre;
        p->next = left->next;
        p->pre = left;
        left->next = p;
        p->next->pre = p;
        return p;
    }
    bool if_list_sorted(ListNode *L)
    {
        ListNode *p = L->next;
        vector<int> a;
        for (; p; p = p->next)
            a.push_back(p->val);
        return is_sorted(a.begin(), a.end());
    }

    ListNode *kth_ultimate(ListNode *&L, int k)
    {
        ListNode *r, *l;
        r = l = L;
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

    void output(ListNode *h)
    {
        ListNode *p = h->next;
        while (p)
        {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }

    ListNode *createList(vector<int> &a)
    {
        ListNode *dummy = new ListNode, *p = dummy;
        for (auto &i : a)
        {
            p->next = new ListNode(i);
            p = p->next;
        }
        return dummy;
    }

    ListNode *find_common_p(ListNode *l1, ListNode *l2)
    {
        ListNode *thelong, *theshort, *p = l1, *q = l2;
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

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> mapping;
    unordered_set<int> st;
    vector<int> result;
    for (int i = 0; i < nums.size(); i++)
    {
        mapping[nums[i]] = 0;
        st.insert(nums[i]);
    }
    for (int i = 0; i < nums.size(); i++)
    {
        const int gap = target - nums[i];
        if (st.count(gap) && !mapping[gap] && !mapping[nums[i]])
        {
            result.push_back(nums[i]);
            result.push_back(gap);
            mapping[gap] = 1;
            mapping[nums[i]] = 1;
        }
    }
    return result;
}

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