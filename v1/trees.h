// author - sonaspy@outlook.com
// coding - utf_8

#ifndef __NEW_TREE__
#define __NEW_TREE__

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <string>
#include <deque>
#include <queue>
#include <stack>
using namespace std;

__DST_BEGIN_NAMESPACE

#define MAXCOL 100000
#define MAXROW 100000
#define fromParent2(x) (((x)->is_l() ? (x)->parent->lc : (x)->parent->rc))
#define avlnodebalanced(x) ((-2 < _factor(x)) && (_factor(x) < 2))
#define _height(p) ((p != nullptr) ? (p)->height : -1)
#define _depth(p) ((p != nullptr) ? (p)->depth : -1)
#define _factor(p) ((_height(p->lc)) - (_height(p->rc)))

enum RBColor { RED, BLK };
template <typename _Tp>
class rbtree;
template <typename _Tp>
class bstree;
template <typename _Tp>
class avltree;
template <typename _Tp>
class bintree;
template <typename _Tp>
struct binode;
template <typename _Tp>
struct bnode;

template <typename _Tp>
using binode_ptr = struct binode<_Tp> *;

template <typename _Tp>
struct IS_CHAR {
    operator bool() { return false; }
};
template <>
struct IS_CHAR<char> {
    operator bool() { return true; }
};

template <typename _Tp>
struct binode {
    _Tp val;
    binode_ptr<_Tp> lc, rc, parent;
    int height, depth, ltag, rtag, freq, downblk;
    RBColor color;
    binode()
        : lc(nullptr), rc(nullptr), parent(nullptr), height(0), freq(0),
          color(BLK), downblk(0) {}
    binode(const _Tp &x, binode_ptr<_Tp> p = nullptr,
           binode_ptr<_Tp> l = nullptr, binode_ptr<_Tp> r = nullptr,
           RBColor cl = BLK)
        : val(x), lc(l), rc(r), parent(p), height(0), freq(0), color(cl),
          downblk(0) {}
    bool inline is_l() { return parent && parent->lc == this; }
    bool inline is_r() { return parent && parent->rc == this; }
    bool inline isroot() { return parent == nullptr; }
    bool inline has_r() { return rc != nullptr; }
    bool inline has_l() { return lc != nullptr; }
    bool inline has_lr() { return lc != nullptr && rc != nullptr; }
    bool inline is_leaf() { return !rc && !lc; }
    inline binode_ptr<_Tp> leftest() {
        binode_ptr<_Tp> opnv = this;
        while (opnv->lc)
            opnv = opnv->lc;
        return opnv;
    }
    inline binode_ptr<_Tp> rightest() {
        binode_ptr<_Tp> opnv = this;
        while (opnv->rc)
            opnv = opnv->rc;
        return opnv;
    }
    inline binode_ptr<_Tp> successor() {
        return this->rc ? this->rc->leftest() : nullptr;
    }
    inline binode_ptr<_Tp> precessor() {
        return this->lc ? this->lc->rightest() : nullptr;
    }
    inline binode_ptr<_Tp> uncle() {
        return this->parent->is_l() ? this->parent->parent->rc
                                    : this->parent->parent->lc;
    }

    inline void insert_l(const _Tp &x) { lc = new binode(x, this); }
    inline void insert_r(const _Tp &x) { rc = new binode(x, this); }
    int size() {
        int cnt = 0;
        binode *tp1;
        queue<binode *> q;
        q.push_back(this);
        while (q.size()) {
            tp1 = q.front(), q.pop_front();
            cnt++;
            if (tp1->lc)
                q.push_back(tp1->lc);
            if (tp1->rc)
                q.push_back(tp1->rc);
        }
        return cnt;
    }
    inline bool operator==(const binode *&bn) { return val == bn->val; }
    inline bool operator<(const binode *&bn) { return val < bn->val; }
    inline bool operator>(const binode *&bn) { return val > bn->val; }
    ~binode() {}
};

template <typename _Tp>
class trees {
  public:
    virtual ~trees() {}
    virtual bool insert(const _Tp &val) = 0;
    virtual bool erase(const _Tp &val) = 0;
    virtual bool count(const _Tp &val) = 0;
    virtual void build(vector<_Tp> &a) = 0;
    virtual int size() = 0;
    virtual int empty() = 0;
    virtual void clear() = 0;
};

__DST_END_NAMESPACE

#include "bintree.h"
#include "huffman.h"
#include "bstree.h"
#include "avltree.h"
#include "spltree.h"
#include "rbtree.h"

#endif