// author - sonaspy@outlook.com
// coding - utf_8

#ifndef __HUFFMAN__
#define __HUFFMAN__
#include "bintree.h"
namespace dsa
{

struct hfmkvnode
{
    binode<char> *node;
    string pattern;
    hfmkvnode(binode<char> *&v, string &p) : node(v), pattern(p) {}
    bool operator<(const hfmkvnode &b) const { return node->freq > b.node->freq; }
};

typedef unordered_map<char, int> FREQ_table;
typedef unordered_map<char, string> PFCtable;
typedef vector<hfmkvnode> PFCvec;

class huffman : public bintree<char>
{
protected:
    struct _cmp
    {
        bool operator()(const binode<char> *a, const binode<char> *b) const { return a->freq > b->freq; }
    };
    int _wpl, _mode;
    string _pattern;
    priority_queue<binode<char> *, vector<binode<char> *>, _cmp> _pq;
#define leftChar ((_mode == 1 ? '1' : '0'))
#define rightChar ((_mode == 1 ? '0' : '1'))
    void __trav(binode<char> *v, PFCvec &pv)
    {
        if (!v)
            return;
        if (v->is_l())
            _pattern.push_back(leftChar);
        if (v->is_r())
            _pattern.push_back(rightChar);
        if (v->is_leaf())
            pv.push_back(hfmkvnode(v, _pattern));
        __trav(v->lc, pv);
        __trav(v->rc, pv);
        _pattern.pop_back();
    }

public:
    huffman(FREQ_table &mp)
    {
        _wpl = 0;
        _mode = 0;
        this->_ishuffman = 1;
        binode<char> *v, *w, *root;
        for (auto &kv : mp)
        {
            v = new binode<char>(kv.first);
            v->freq = kv.second;
            _pq.push(v);
        }
        while (_pq.size() > 1)
        {
            v = _pq.top(), _pq.pop();
            w = _pq.top(), _pq.pop();
            root = new binode<char>(0xff, nullptr, v, w);
            v->parent = w->parent = root;
            root->freq = v->freq + w->freq;
            _wpl += root->freq;
            _pq.push(root);
        }
        this->__update_root(root);
        this->__update_status();
    }
    void generate(PFCvec &pv, int mode)
    {
        this->_mode = mode;
        __trav(this->_root, pv);
    }
    inline void clear()
    {
        bintree<char>::clear();
        _wpl = 0;
    }
    int wpl()
    {
        return _wpl;
    }
    ~huffman() { this->clear(); }
};
} // namespace dsa
#endif