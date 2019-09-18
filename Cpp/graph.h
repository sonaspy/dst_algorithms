// author -sonaspy@outlook.com
// coding - utf_8

#ifndef __NEW_GRAPH__
#define __NEW_GRAPH__
#include <bits/stdc++.h>
#include "set_union.h"
#include "functions.h"
using namespace std;

namespace dsa
{
#define MAXVSIZE 1111
#define INF_VAL 1 << 30
struct edge
{
    int w1, w2, w3, v1, v2, mark = 0;
    edge(int w1) : w1(w1), w2(INF_VAL), w3(INF_VAL), v1(-1), v2(-1) {}
    edge(int v1, int v2) : w1(INF_VAL), w2(INF_VAL), w3(INF_VAL), v1(v1), v2(v2) {}
    edge(int w1, int v1, int v2) : w1(w1), w2(INF_VAL), w3(INF_VAL), v1(v1), v2(v2) {}
};
struct __cmp1
{
    bool operator()(const edge *e1, const edge *e2) const { return e1->w1 > e2->w1; }
};
class spanningTree
{
private:
    unordered_set<int> vset;
    unordered_set<edge *> eset;
    int _sum;
    _set_union st;

public:
    spanningTree()
    {
        _sum = 0;
    }
    inline void addsum(int v) { _sum += v; }
    inline void pushv(int v) { vset.insert(v); }
    inline void pushe(edge *e) { eset.insert(e); }
    inline void unite(int v1, int v2) { st.unite(v1, v2); }
    inline int vsize() { return vset.size(); }
    inline int esize() { return eset.size(); }
    inline int sum() { return _sum; }
    bool overlap(int v1, int v2) { return st.same(v1, v2); }
    bool exist(int v) { return vset.count(v); }
    inline bool empty() { return vset.empty(); }
    bool connected()
    {
        st.resize(vset.size());
        return st.connected();
    }
    inline void clear() { _sum = 0, st.clear(), vset.clear(), eset.clear(); }
};

class udGraph
{
protected:
    int nv, connected_cnt, stp_unique;
    unordered_set<edge *> __memoryOEdge;
    unordered_map<int, set<int>> posv, pre, prev, post;
    vector<vector<edge *>> matrix;
    vector<int> indeg, outdeg, vis, cost1, cost2, tmppath;
    vector<vector<int>> _key_path, _res_path;

    unordered_map<int, vector<edge *>> mpOfedge;
    spanningTree stp;
    void __restore_buf()
    {
        fill(vis.begin(), vis.end(), 0);
        fill(cost1.begin(), cost1.end(), 0);
        fill(cost2.begin(), cost1.end(), 0);
        tmppath.clear();
    }
    void __prim()
    {
        if (connected_cnt > 1)
            return;
        stp.clear();
        int i, j, v, length[nv], min_, v1;
        vector<int> parent(nv, 0);
        for (i = 0; i < nv; i++)
        {
            parent[i] = 0;
            length[i] = (matrix[0][i]) ? matrix[0][i]->w1 : INF_VAL;
        }
        parent[0] = -1, length[0] = 0;
        stp.pushv(0);
        while (1)
        {
            v = -1, min_ = INF_VAL;
            for (i = 0; i < nv; i++)
            {
                if (!stp.exist(i) && length[i] < min_)
                    v = i, min_ = length[i];
            }
            v1 = parent[v];
            stp.pushe(matrix[v1][v]);
            stp.pushv(v);
            stp.addsum(min_);
            if (stp.vsize() == nv)
                break;
            for (j = 0; j < nv; j++)
                if (!stp.exist(j) && matrix[v][j] && matrix[v][j]->w1 < length[j])
                {
                    length[j] = matrix[v][j]->w1;
                    parent[j] = v;
                }
        }
    }

    void __kruskal()
    {
        if (connected_cnt > 1)
            return;
        stp.clear();
        edge *e;
        int v1, v2;
        priority_queue<edge *, vector<edge *>, __cmp1> e_pq;
        for (auto &peq : __memoryOEdge)
            e_pq.push(peq);
        while (e_pq.size() && stp.esize() < nv - 1)
        {
            e = e_pq.top(), e_pq.pop();
            v1 = e->v1, v2 = e->v2;
            if (stp.overlap(v1, v2))
                continue;
            stp.unite(v1, v2), stp.pushv(v1), stp.pushv(v2);
            stp.addsum(e->w1);
            stp.pushe(e);
        }
    }

    void __dfs(int v_id)
    {
        for (auto w : posv[v_id])
            if (!vis[w])
            {
                vis[w] = 1;
                __dfs(w);
            }
    }
    void __bfs(int src)
    {
        __restore_buf();
        int layer = 0, v;
        queue<int> q, nexq;
        q.push(src);
        vis[src] = 1;
        while (q.size())
        {
            while (q.size())
            {
                v = q.front(), q.pop();
                for (auto w : posv[v])
                    if (!vis[w])
                    {
                        vis[w] = 1;
                        nexq.push(w);
                    }
            }
            layer++;
            swap(q, nexq);
        }
        __restore_buf();
    }
    void __getPathByPre(int walk, int &src)
    {
        tmppath.push_back(walk);
        if (walk == src)
        {
            _res_path.push_back(tmppath);
            return;
        }
        for (auto j : pre[walk])
            __getPathByPre(j, src);
        tmppath.pop_back();
    }

public:
    udGraph()
    {
        matrix = vector<vector<edge *>>(MAXVSIZE, vector<edge *>(MAXVSIZE, nullptr));
        vis = indeg = outdeg = vector<int>(MAXVSIZE, 0);
        nv = connected_cnt = 0;
        stp_unique = -1;
    }
    inline int connected_component()
    {
        if (connected_cnt)
            return connected_cnt;
        int cnt = 0;
        fill(vis.begin(), vis.end(), 0);
        for (int i = 0; i < nv; i++)
        {
            if (!vis[i])
            {
                vis[i] = 1;
                __dfs(i);
                cnt++;
            }
        }
        connected_cnt = cnt;
        return cnt;
    }
    inline bool hasPath(int v1, int v2)
    {
        fill(vis.begin(), vis.end(), 0);
        vis[v1] = 1;
        __dfs(v1);
        return vis[v2];
    }
    inline bool connected()
    {
        if (connected_cnt)
            return connected_cnt == 1;
        connected_component();
        return connected_cnt == 1;
    }
    void init(vector<vector<int>> &g)
    {
        int n = g.size();
        this->nv = n;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
                if (g[i][j] != INF_VAL)
                {
                    matrix[j][i] = matrix[i][j] = new edge(g[i][j], i, j);
                    posv[i].insert(j), posv[j].insert(i);
                    __memoryOEdge.insert(matrix[i][j]);
                    mpOfedge[matrix[i][j]->w1].push_back(matrix[i][j]);
                }
        }
        for (auto &i : mpOfedge)
        {
            if (i.second.size() > 1)
                for (auto &j : i.second)
                    j->mark = 1;
        }
        connected();
    }
    inline void clear()
    {
        this->cost1.clear(), this->cost2.clear();
        this->connected_cnt = 0;
        this->indeg.clear();
        this->matrix.clear();
        this->mpOfedge.clear();
        this->nv = 0;
        this->outdeg.clear();
        this->posv.clear();
        this->prev.clear();
        this->pre.clear();
        this->_key_path.clear();
        this->stp.clear();
        this->tmppath.clear();
        this->vis.clear();
        for (auto node : __memoryOEdge)
            delete node;
        this->__memoryOEdge.clear();
    }
    inline int stpsum()
    {
        return stp.sum();
    }
    void dijkstra(int src, int dst, vector<int> &cost)
    {
        vector<int> cost2, cost3, pathsum;
        pathsum[src] = 1;
        int v, min_, w;
        unordered_set<int> vset;
        fill(cost.begin(), cost.end(), INF_VAL);
        cost[src] = 0;
        vset.insert(src);
        while (1)
        {
            min_ = INF_VAL, v = -1;
            for (int i = 0; i < nv; i++)
            {
                if (!vset.count(i) && cost[i] < min_)
                    min_ = cost[i], v = i;
            }
            if (v == -1)
                break;
            vset.insert(v);
            for (w = 0; w < nv; w++)
            {
                if (!vset.count(w) && matrix[v][w]) // one type weight
                {
                    if (matrix[v][w]->w1 + cost[v] < cost[w]) // 1.
                    {
                        cost[w] = matrix[v][w]->w1 + cost[v];
                        //cost2[w] = matrix[v][w]->w2 + cost2[v];
                        pre[w].clear(), pre[w].insert(v);
                        pathsum[w] = pathsum[v];
                    }
                    else if (matrix[v][w]->w1 + cost[v] == cost[w]) //2.
                    {
                        pre[w].insert(v);
                        pathsum[w] += pathsum[v];
                    }
                    //or 1.same
                    //2. else if (matrix[v][w]->w1 + cost[v] == cost[w] && matrix[v][w]->w2 + cost2[v] < cost2[w])
                    // {
                    //  cost2[w] = matrix[v][w]->w2 + cost2[v];
                    //  pre[w] = v; pahtsum[w] = pathsum[v];
                    // }
                    // 3. else if (matrix[v][w]->w1 + cost[v] == cost[w] && matrix[v][w]->w2 + cost2[v] == cost2[w])
                    // {
                    //    pre[w].push_back(v);
                    //    pathsum[w] += pathsum[v];
                    // }........ analog
                }
            }
        }
        tmppath.clear(), _key_path.clear();
        __getPathByPre(dst, src);
        reverse(_key_path.begin(), _key_path.end());
    }
    bool stpUnique()
    {
        return stp_unique;
    }
    bool Floyd(vector<vector<int>> &mp, vector<vector<int>> &path)
    {
        int i, j, k;
        fill(path.begin(), path.end(), vector<int>(path.size(), -1));
        for (i = 0; i < nv; i++)
        {
            for (j = 0; j < nv; j++)
            {
                mp[i][j] = matrix[i][j] ? matrix[i][j]->w1 : INF_VAL;
                mp[i][j] = i == j ? 0 : mp[i][j];
            }
        }
        for (k = 0; k < nv; k++)
        {
            for (i = 0; i < nv; i++)
            {
                for (j = 0; j < nv; j++)
                {
                    if (mp[i][k] != INF_VAL && mp[k][j] != INF_VAL && mp[i][j] > mp[i][k] + mp[k][j])
                        mp[i][j] = mp[i][k] + mp[k][j], path[i][j] = k;
                    if (i == j && mp[i][j] < 0)
                        return false;
                }
            }
        }
        return true;
    }

    inline void makestp(int f)
    {
        f ? __kruskal() : __prim();
    }
    void rand_acyclic_init(int n_)
    {
        srand(time(NULL));
        vector<vector<int>> g(n_, vector<int>(n_, INF_VAL));
        for (int i = 0; i < n_; i++)
        {
            for (int j = i + 1; j < n_; j++)
                g[i][j] = g[j][i] = rand() % 4 ? INF_VAL : rand() % 100 + 1;
        }
        init(g);
    }
    inline int vsize() { return this->nv; }
    inline int esize() { return __memoryOEdge.size(); }
    ~udGraph()
    {
        this->clear();
    }
};

class dGraph : public udGraph
{
protected:
    vector<int> __top_order, __intop_order, v_early, v_late, rescost;
    unordered_map<edge *, pair<int, int>> aoe; // aoe pair(early, late), flexible time = second - first. keyaction is which has zero flexible time;
    int _total_cost;
    unordered_set<int> _src, _dst;
    bool _acyclic;
    void __dfs(int v_id, vector<int> &o)
    {
        for (auto w : posv[v_id])
        {
            if (vis[w])
                continue;
            vis[w] = 1;
            __dfs(w, o);
        }
        o.push_back(v_id);
    }
    void __dfs_nonrecur(int src)
    {
        stack<int> sk;
        sk.push(src);
        int v;
        vis[v] = 1;
        //function(v);
        while (sk.size())
        {
            v = sk.top(), sk.pop();
            //function(v);
            for (auto w : posv[v])
            {
                if (vis[w])
                    continue;
                vis[w] = 1;
                sk.push(w);
            }
        }
        __restore_buf();
    }
    void __getPathByPost(int walk, int &dst)
    {
        if (walk == dst)
        {
            rescost.push_back(_total_cost);
            _key_path.push_back(tmppath);
            return;
        }
        for (auto w : post[walk])
        {
            tmppath.push_back(w);
            _total_cost += matrix[walk][w]->w1;
            __getPathByPost(w, dst);
            _total_cost -= matrix[walk][w]->w1;
            tmppath.pop_back();
        }
    }
    void __top_sort()
    {
        int v;
        queue<int> q;
        vector<int> indegtmp(indeg.begin(), indeg.begin() + nv);
        for (int i = 0; i < nv; i++)
            if (!indegtmp[i])
            {
                q.push(i);
                __top_order.push_back(i);
            }
        while (q.size())
        {
            v = q.front(), q.pop();
            for (auto w : posv[v])
                if (--indegtmp[w] == 0)
                {
                    q.push(w);
                    __top_order.push_back(w);
                }
        }
        _acyclic = __top_order.size() == nv;
        __intop_order.insert(__intop_order.end(), __top_order.rbegin(), __top_order.rend());
        __restore_buf();
    }
    void __key_action()
    {
        if (aoe.size())
            return;
        if (!_acyclic)
        {
            cout << "the Graph is Cyclic !\n";
            return;
        }
        v_early = v_late = vector<int>(nv, 0);
        for (int walk : __top_order)
        {
            int maxt = 0;
            for (int pre : this->prev[walk])
                maxt = max(this->matrix[pre][walk]->w1 + v_early[pre], maxt);
            v_early[walk] = maxt;
        }
        for (int walk : __intop_order)
        {
            int mint = v_early[__top_order.back()];
            for (int post : this->posv[walk])
                mint = min(v_late[post] - this->matrix[walk][post]->w1, mint);
            v_late[walk] = mint;
        }
        set<int> ksrc, kdst;
        for (auto &e : __memoryOEdge)
        {
            aoe[e].first = v_early[e->v1];
            aoe[e].second = v_late[e->v2] - e->w1;

            if (aoe[e].first == aoe[e].second)
            {
                this->post[e->v1].insert(e->v2);
                if (_src.count(e->v1))
                    ksrc.insert(e->v1);
                if (_dst.count(e->v2))
                    kdst.insert(e->v2);
            }
        }
        cout << "src: \n";
        for (auto i : ksrc)
            cout << i << " ";
        cout << endl;
        cout << "dst: \n";
        for (auto i : kdst)
            cout << i << " ";
        cout << endl;
        for (auto s : ksrc)
        {
            for (auto d : kdst)
            {
                tmppath.push_back(s);
                __getPathByPost(s, d);
                tmppath.pop_back();
            }
        }
    }

public:
    dGraph()
    {
        matrix = vector<vector<edge *>>(MAXVSIZE, vector<edge *>(MAXVSIZE, nullptr));
        vis = indeg = outdeg = vector<int>(MAXVSIZE, 0);
    }
    inline void clear()
    {
        udGraph::clear();
        __top_order.clear(), __intop_order.clear(), v_early.clear(), v_late.clear(), rescost.clear();
        aoe.clear();
        _total_cost = 0;
        _src.clear(), _dst.clear();
    }

    inline bool acyclic() { return _acyclic; }
    void in_toporder(vector<int> &ord)
    {
        for (int i = 0; i < nv; i++)
        {
            if (!indeg[i] && !vis[i])
            {
                vis[i] = 1;
                __dfs(i, ord);
            }
        }
        __restore_buf();
    }
    void toporder(vector<int> &ord)
    {
        if (!_acyclic)
            return;
        ord = __top_order;
        __restore_buf();
    }
    bool istoporder(vector<int> &ord)
    {
        if (ord.size() != nv)
            return 0;
        vector<int> In = indeg;
        for (auto V : ord)
        {
            if (In[V])
                return false;
            for (auto w : posv[V])
                In[w]--;
        }
        __restore_buf();
        return true;
    }
    void __dfs_cycle(int v1, int v2)
    {
        vis[v1] = 1;
        tmppath.push_back(v1);
        if (v1 == v2 && tmppath.size() > 1)
        {
            output_vec(tmppath);
            vis[v1] = 0;
            tmppath.pop_back();
            return;
        }
        for (auto w : posv[v1])
        {
            if (!vis[w] || w == v2)
                __dfs_cycle(w, v2);
        }
        vis[v1] = 0;
        tmppath.pop_back();
    }
    void getCycle(int v0)
    {
        printf("Cycles Go Through Vertex No.%d:\n", v0);
        __dfs_cycle(v0, v0);
        cout << endl;
        __restore_buf();
    }
    void topsort()
    {
        __top_sort();
        __restore_buf();
    }
    inline void get_keyaction()
    {
        __key_action();
        if (!rescost.size())
        {
            printf("No Key Path Exists\n");
            return;
        }
        for (int i = 0; i < rescost.size(); i++)
        {
            output_vec(_key_path[i]);
            printf("The No.%d Key Actions' Path Length Is -> %d\n", i + 1, rescost[i]);
        }
    }
    void rand_acyclic_init(int n_, int sparse_level, int weight_range)
    {
        vector<vector<int>> g(n_, vector<int>(n_, INF_VAL));
        for (int i = 0; i < n_; i++)
        {
            for (int j = i + 1; j < n_; j++)
                g[i][j] = rand() % sparse_level ? INF_VAL : rand() % weight_range + 1;
        }
        init(g);
        __restore_buf();
    }
    void rand_init(int n_, int sparse_level, int weight_range)
    {
        vector<vector<int>> g(n_, vector<int>(n_, INF_VAL));
        for (int i = 0; i < n_; i++)
        {
            for (int j = i + 1; j < n_; j++)
            {
                if (rand() % sparse_level)
                {
                    g[i][j] = INF_VAL;
                    g[j][i] = rand() % sparse_level ? INF_VAL : rand() % weight_range + 1;
                }
                else
                    g[i][j] = rand() % weight_range + 1;
            }
        }
        init(g);
        __restore_buf();
    }
    void init(vector<vector<int>> &g)
    {
        int n = g.size();
        this->nv = n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                if (g[i][j] != INF_VAL)
                {
                    matrix[i][j] = new edge(g[i][j], i, j);
                    prev[j].insert(i), posv[i].insert(j);
                    indeg[j]++, outdeg[i]++;
                    __memoryOEdge.insert(matrix[i][j]);
                }
        }
        for (int i = 0; i < nv; i++)
        {
            if (indeg[i] == 0)
                _src.insert(i);
            if (outdeg[i] == 0)
                _dst.insert(i);
        }
        connected();
        __top_sort();
        __restore_buf();
    }
    ~dGraph()
    {
        this->clear();
    }
};

}; // namespace dsa

#endif