// author - sonaspy@outlook.com
// coding - utf_8

#ifndef __NEW_TREE__
#define __NEW_TREE__
#include <vector>
#include <unordered_map>
#include <iostream>
#include <string>
#include <deque>
#include <queue>
#include <stack>
using namespace std;
namespace dsa
{
#define MAXCOL 1000
#define MAXROW 100000
#define from_parent2(x) (((x)->is_l() ? (x)->parent->lc : (x)->parent->rc))
#define nodeBalanced(x) ((-2 < _factor(x)) && (_factor(x) < 2))
#define _height(p) ((p != nullptr) ? (p)->height : -1)
#define _depth(p) ((p != nullptr) ? (p)->depth : -1)
#define _factor(p) ((_height(p->lc)) - (_height(p->rc)))
#define __release(p) (delete (p), (p) = nullptr)

enum RBColor
{
    RED,
    BLK
};
template <typename T>
class rbtree;
template <typename T>
class bstree;
template <typename T>
class avltree;
template <typename T>
class btree;
template <typename T>
class bintree;
template <typename T>
struct binode;
template <typename T>
struct bnode;

template <typename T>
using binode_ptr = struct binode<T> *;
template <typename T>
using bnode_ptr = struct bnode<T> *;

template <typename T>
struct __ischar
{
    operator bool()
    {
        return false;
    }
};
template <>
struct __ischar<char>
{
    operator bool()
    {
        return true;
    }
};

template <typename T>
static inline binode_ptr<T> __getmax(binode_ptr<T> opnv)
{
    while (opnv->rc)
        opnv = opnv->rc;
    return opnv;
}
template <typename T>
static inline binode_ptr<T> __getmin(binode_ptr<T> opnv)
{
    while (opnv->lc)
        opnv = opnv->lc;
    return opnv;
}

template <typename T>
struct binode
{
    T val;
    binode_ptr<T> lc, rc, parent;
    int height, depth, ltag, rtag, freq, downblk;
    RBColor color;
    binode() : lc(nullptr), rc(nullptr), parent(nullptr), height(0), freq(0), color(BLK), downblk(0) {}
    binode(const T &x, binode_ptr<T> p = nullptr, binode_ptr<T> l = nullptr, binode_ptr<T> r = nullptr, RBColor cl = BLK) : val(x), lc(l), rc(r), parent(p), height(0), freq(0), color(cl), downblk(0) {}
    bool inline is_l()
    {
        return parent && parent->lc == this;
    }
    bool inline is_r()
    {
        return parent && parent->rc == this;
    }
    bool inline isroot()
    {
        return parent == nullptr;
    }
    bool inline has_r()
    {
        return rc != nullptr;
    }
    bool inline has_l()
    {
        return lc != nullptr;
    }
    bool inline has_lr()
    {
        return lc != nullptr && rc != nullptr;
    }
    bool inline is_leaf()
    {
        return !rc && !lc;
    }
    inline bool operator==(const binode *&bn) { return val == bn->val; }
    inline bool operator<(const binode *&bn) { return val < bn->val; }
    inline bool operator>(const binode *&bn) { return val > bn->val; }
    inline binode *successor()
    {
        return this->rc ? __getmin(this->rc) : nullptr;
    }
    inline binode *precessor()
    {
        return this->lc ? __getmax(this->lc) : nullptr;
    }
    inline binode *uncle() { return this->parent->is_l() ? this->parent->parent->rc : this->parent->parent->lc; }

    inline void insert_l(const T &x)
    {
        lc = new binode(x, this);
    }
    inline void insert_r(const T &x)
    {
        rc = new binode(x, this);
    }
    int size()
    {
        int cnt = 0;
        binode *tp1;
        queue<binode *> q;
        q.push_back(this);
        while (q.size())
        {
            tp1 = q.front(), q.pop_front();
            cnt++;
            if (tp1->lc)
                q.push_back(tp1->lc);
            if (tp1->rc)
                q.push_back(tp1->rc);
        }
        return cnt;
    }
};

template <typename T>
struct bnode
{
    vector<T> key;
    vector<bnode<T> *> child; // always more 1 item than key
    bnode<T> *parent = nullptr;
    bnode()
    {
        parent = nullptr;
        child.push_back(nullptr);
    }
    bnode(const T &x, bnode *lc = nullptr, bnode *rc = nullptr)
    {
        parent = nullptr;
        key.push_back(x);
        child.resize(2);
        child[0] = lc, child[1] = rc;
        if (lc)
            lc->parent = this;
        if (rc)
            rc->parent = this;
    }
};

}; // namespace dsa
#endif
using namespace dsa;