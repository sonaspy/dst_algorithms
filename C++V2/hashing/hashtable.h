#pragma once

#ifndef hashtable_
#define hashtable_

#include "./dictionary.h"
#include "./bitmap.h"
#include "../entry.h"

template <typename K, typename V> //key、value
class Hashtable : public Dictionary<K, V>
{ //符合Dictionary接口的Hashtable模板类
  private:
    Entry<K, V> **ht;    //桶数组，存放词条指针
    int M;               //桶数组容量
    int N;               //词条数量
    Bitmap *lazyRemoval; //懒惰删除标记
#define lazilyRemoved(x) (lazyRemoval->test(x))
#define markAsRemoved(x) (lazyRemoval->set(x))
  protected:
    int probe4Hit(const K &k);  //沿关键码k对应的查找链，找到词条匹配的桶
    int probe4Free(const K &k); //沿关键码k对应的查找链，找到首个可用空桶
    void rehash();              //重散列算法：扩充桶数组，保证装填因子在警戒线以下
  public:
    Hashtable(int c = 5);          //创建一个容量不小于c的散列表（为测试暂时选用较小的默认值）
    ~Hashtable();                  //释放桶数组及其中各（非空）元素所指向的词条
    int size() const { return N; } // 当前的词条数目
    bool put(K, V);                //插入（禁止雷同词条，故可能失败）
    V *get(K k);                   //读取
    bool remove(K k);              //删除
};

static size_t hashCode(char c) { return (size_t)c; } //字符
static size_t hashCode(int k) { return (size_t)k; }  //整数以及长长整数
static size_t hashCode(long long i) { return (size_t)((i >> 32) + (int)i); }
static size_t hashCode(char s[])
{                                                 //生成字符串的循环移位散列码（cyclic shift hash code）
    unsigned int h = 0;                           //散列码
    for (size_t n = strlen(s), i = 0; i < n; i++) //自左向右，逐个处理每一字符

    {
        h = (h << 5) | (h >> 27); // swap 5|27 -- 32 bit
        h += (int)s[i];
    }                 //散列码循环左移5位，再累加当前字符
    return (size_t)h; //如此所得的散列码，实际上可理解为近似的“多项式散列码”

} //对于英语单词，"循环左移5位"是实验统计得出的最佳值

template <typename K, typename V>
Hashtable<K, V>::~Hashtable()
{                               //析构前释放桶数组及非空词条
    for (int i = 0; i < M; i++) //逐一检查各桶
        if (ht[i])
            release(ht[i]); //释放非空的桶
    release(ht);            //释放桶数组
    release(lazyRemoval);   //释放懒惰删除标记

} //release()负责释放复杂结构，与算法无直接关系，具体实现详见代码包

template <typename K, typename V>
void Hashtable<K, V>::rehash()
{
    int old_capacity = M;
    Entry<K, V> **old_ht = ht;
    M = primeNLT(2 * M, 1048576, "../../_input/prime-1048576-bitmap.txt"); //容量至少加倍
    N = 0;
    ht = new Entry<K, V> *[M];
    memset(ht, 0, sizeof(Entry<K, V> *) * M); //新桶数组
    release(lazyRemoval);
    lazyRemoval = new Bitmap(M);                   //新开懒惰删除标记比特图
    for (int i = 0; i < old_capacity; i++)         //扫描原桶数组
        if (old_ht[i])                             //将非空桶中的词条逐一
            put(old_ht[i]->key, old_ht[i]->value); //插入至新的桶数组
    release(old_ht);                               //释放原桶数组——由于其中原先存放的词条均已转移，故只需释放桶数组本身
}

template <typename K, typename V>
Hashtable<K, V>::Hashtable(int c)
{                                                                      //创建散列表，容量为
    M = primeNLT(c, 1048576, "../../_input/prime-1048576-bitmap.txt"); //不小于c的素数M
    N = 0;
    ht = new Entry<K, V> *[M];                //开辟桶数组（还需核对申请成功），初始装填因子为N/M = 0%
    memset(ht, 0, sizeof(Entry<K, V> *) * M); //初始化各桶
    lazyRemoval = new Bitmap(M);              //懒惰删除标记比特图
}

template <typename K, typename V>
bool Hashtable<K, V>::remove(K k)
{ //散列表词条删除算法
    int r = probe4Hit(k);
    if (!ht[r])
        return false; //对应词条不存在时，无法删除
    release(ht[r]);
    ht[r] = NULL;
    markAsRemoved(r);
    N--;
    return true;
    //否则释放桶中词条，设置懒惰删除标记，并更新词条总数
}
template <typename K, typename V>
bool Hashtable<K, V>::put(K k, V v)
{ //散列表词条插入
    if (ht[probe4Hit(k)])
        return false;      //雷同元素不必重复插入
    int r = probe4Free(k); //为新词条找个空桶（只要装填因子控制得当，必然成功）
    ht[r] = new Entry<K, V>(k, v);
    ++N; //插入（注意：懒惰删除标记无需复位）
    if (N * 2 > M)
        rehash(); //装填因子高于50%后重散列
    return true;
}

template <typename K, typename V>
int Hashtable<K, V>::probe4Hit(const K &k)
{
    int r = hashCode(k) % M; //从起始桶（按除余法确定）出发
    while ((ht[r] && (k != ht[r]->key)) || (!ht[r] && lazilyRemoved(r)))
        r = (r + 1) % M; //沿查找链线性试探：跳过所有冲突的桶，以及带懒惰删除标记的桶
    return r;            //调用者根据ht[r]是否为空，即可判断查找是否成功
}

template <typename K, typename V>
int Hashtable<K, V>::probe4Free(const K &k)
{
    int r = hashCode(k) % M; //从起始桶（按除余法确定）出发
    while (ht[r])
        r = (r + 1) % M; //沿查找链逐桶试探，直到首个空桶（无论是否带有懒惰删除标记）
    return r;            //为保证空桶总能找到，装填因子及散列表长需要合理设置
}

template <typename K, typename V>
V *Hashtable<K, V>::get(K k) //散列表词条查找算法

{
    int r = probe4Hit(k);
    return ht[r] ? &(ht[r]->value) : NULL;
} //禁止词条的key值雷同

#endif
