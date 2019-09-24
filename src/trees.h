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

namespace dsa
{
#define MAXCOL 100000
#define MAXROW 100000
#define from_parent2(x) (((x)->is_l() ? (x)->parent->lc : (x)->parent->rc))
#define nodeBalanced(x) ((-2 < _factor(x)) && (_factor(x) < 2))
#define _height(p) ((p != nullptr) ? (p)->height : -1)
#define _depth(p) ((p != nullptr) ? (p)->depth : -1)
#define _factor(p) ((_height(p->lc)) - (_height(p->rc)))

enum RBColor
{
    RED,
    BLK
};
template <typename _Tp>
class rbtree;
template <typename _Tp>
class bstree;
template <typename _Tp>
class avltree;
template <typename _Tp>
class btree;
template <typename _Tp>
class bintree;
template <typename _Tp>
struct binode;
template <typename _Tp>
struct bnode;

template <typename _Tp>
using binode_ptr = struct binode<_Tp> *;
template <typename _Tp>
using bnode_ptr = struct bnode<_Tp> *;

template <typename _Tp>
struct IS_CHAR
{
    operator bool()
    {
        return false;
    }
};
template <>
struct IS_CHAR<char>
{
    operator bool()
    {
        return true;
    }
};

template <typename _Tp>
static inline binode_ptr<_Tp> __getmax(binode_ptr<_Tp> opnv)
{
    while (opnv->rc)
        opnv = opnv->rc;
    return opnv;
}
template <typename _Tp>
static inline binode_ptr<_Tp> __getmin(binode_ptr<_Tp> opnv)
{
    while (opnv->lc)
        opnv = opnv->lc;
    return opnv;
}

template <typename _Tp>
struct binode
{
    _Tp val;
    binode_ptr<_Tp> lc, rc, parent;
    int height, depth, ltag, rtag, freq, downblk;
    RBColor color;
    binode() : lc(nullptr), rc(nullptr), parent(nullptr), height(0), freq(0), color(BLK), downblk(0) {}
    binode(const _Tp &x, binode_ptr<_Tp> p = nullptr, binode_ptr<_Tp> l = nullptr, binode_ptr<_Tp> r = nullptr, RBColor cl = BLK) : val(x), lc(l), rc(r), parent(p), height(0), freq(0), color(cl), downblk(0) {}
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

    inline binode_ptr<_Tp> successor()
    {
        return this->rc ? __getmin(this->rc) : nullptr;
    }
    inline binode_ptr<_Tp> precessor()
    {
        return this->lc ? __getmax(this->lc) : nullptr;
    }
    inline binode_ptr<_Tp> uncle() { return this->parent->is_l() ? this->parent->parent->rc : this->parent->parent->lc; }

    inline void insert_l(const _Tp &x)
    {
        lc = new binode(x, this);
    }
    inline void insert_r(const _Tp &x)
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
    inline bool operator==(const binode *&bn) { return val == bn->val; }
    inline bool operator<(const binode *&bn) { return val < bn->val; }
    inline bool operator>(const binode *&bn) { return val > bn->val; }
};

template <typename _Tp>
struct bnode
{
    int keysize;
    vector<_Tp> key;
    vector<bnode_ptr<_Tp>> child;
    bool isleaf;
    bnode(bool leaf = true)
    {
        isleaf = leaf;
    }
    _Tp precessor()
    {
        bnode_ptr<_Tp> x = this;
        int i = keysize;
        while (!x->isleaf)
        {
            x = x->child[i];
            i = x->keysize;
        }
        return x->key[keysize - 1];
    }
    _Tp successor()
    {
        bnode_ptr<_Tp> x = this;
        while (!x->isleaf)
            x = x->child[0];
        return x->key[0];
    }
};

}; // namespace dsa

#include "bintree.h"
#include "huffman.h"
#include "bstree.h"
#include "avltree.h"
#include "spltree.h"
#include "rbtree.h"
#include "btree.h"

#endif