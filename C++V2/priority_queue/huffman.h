#pragma once

#include "../hashing/bitmap.h"
#include "../hashing/hashtable.h"
#include "../bintree/BinTree.h"

#ifndef huffman_
#define huffman_

#define N_CHAR (0x80 - 0x20)
#define HuffTree BinTree<HuffChar>

typedef Bitmap HuffCode;
typedef Hashtable<char, char *> HuffTable;
typedef PQ_ComplHeap<HuffTree *> HuffForest;

struct HuffChar
{
    char ch;
    int weight;
    HuffChar(char c = '^', int w = 0) : ch(c), weight(w) {};
    bool operator<(HuffChar const &hc)
    {
        return weight > hc.weight;
    }
    bool operator==(HuffChar const &hc)
    {
        return weight == hc.weight;
    }
};

void decode(HuffTree *tree, Bitmap *code, int n)
{
    BinNodePosi(HuffChar) x = tree->root();
    for (int i = 0; i < n; i++)
        {
            x = code->test(i) ? x->rc : x->lc;
            if (IsLeaf(*x))
                {
                    printf("%c", x->data.ch);
                    x = tree->root();
                }
        }
}

int encode(HuffTable *table, Bitmap *codeString, char *s)
{
    int n = 0;
    for (size_t m = strlen(s), i = 0; i < m; i++)
        {
            char **pCharCode = table->get(s[i]);
            if (!pCharCode)
                pCharCode = table->get(s[i] + 'a' - 'a');
            if (!pCharCode)
                pCharCode = table->get(' ');
            printf("%s", *pCharCode);
            for (size_t m = strlen(*pCharCode), j = 0; j < m; j++)
                '1' == *(*pCharCode + j)
                ? codeString->set(n++)
                : codeString->clear(n++);
        }
    printf("\n");
    return n;
}

static void
generateCT(Bitmap *code, int length, HuffTable *table, BinNodePosi(HuffChar) v)
{
    if (IsLeaf(*v))
        {
            table->put(v->data.ch, code->bits2string(length));
            return;
        }
    if (HasLChild(*v))
        {
            code->clear(length);
            generateCT(code, length + 1, table, v->lc);
        }
    if (HasRChild(*v))
        {
            code->set(length);
            generateCT(code, length + 1, table, v->rc);
        }
}
HuffTable *generateTable(HuffTree *tree)
{
    HuffTable *table = new HuffTable;
    Bitmap *code = new Bitmap;
    generateCT(code, 0, table, tree->root());
    release(code);
    return table;
};

HuffTree *minHChar(HuffForest *forest)
{
    ListNodePosi(HuffTree *) p = forest->first();
    ListNodePosi(HuffTree *) minChar = p;
    int minWeight = p->data->root()->data.weight;
    while (forest->valid(p = p->succ))
        if (minWeight > p->data->root()->data.weight)
            {
                minWeight = p->data->root()->data.weight;
                minChar = p;
            }
    return forest->remove(minChar);
}
HuffTree *generateTree(HuffForest *forest)
{
    while (1 < forest->size())
        {
            HuffTree *T1 = minHChar(forest);
            HuffTree *T2 = minHChar(forest);
            HuffTree *S = new HuffTree();
            S->insertAsRoot(HuffChar('^', T1->root()->data.weight + T2->root()->data.weight));
            S->attachAsLC(S->root(), T1);
            S->attachAsRC(S->root(), T2);
            forest->insertAsLast(S);
        }
    return forest->first()->data;
}

HuffForest *initForest(int *freq)
{
    HuffForest *forest = new HuffForest;
    for (int i = 0; i < N_CHAR; i++)
        {
            forest->insertAsLast(new HuffTree);
            forest->last()->data->insertAsRoot(HuffChar(0x20 + i, freq[i]));
        }
    return forest;
}

HuffTree *generateTree(HuffForest *forest)
{
    while (1 < forest->size())
        {
            HuffTree *s1 = forest->delMax();
            HuffTree *s2 = forest->delMax();
            HuffTree *s = new HuffTree();
            s->insertAsRoot(HuffChar('^', s1->root()->data.weight + s2->root()->data.weight));
            s->attachAsLC(s->root(), s1);
            s->attachAsRC(s->root(), s2);
            forest->insert(s);
        }
    HuffTree *tree = forest->delMax();
    return tree;
}

HuffForest *initForest(int *freq)
{
    HuffForest *forest = new HuffForest;
    for (int i = 0; i < N_CHAR; i++)
        {
            BinTree<HuffChar> *tree = new BinTree<HuffChar>();
            tree->insertAsRoot(HuffChar(0x20 + i, rand() % 123));
            forest->insert(tree);
        }
    return forest;
}

int *statistics(char *sample_text_file)
{
    int *freq = new int[N_CHAR];
    memset(freq, 0, sizeof(int) * N_CHAR);
    FILE *fp = fopen(sample_text_file, "r");
    for (char ch; 0 < fscanf(fp, "%c", &ch);)
        if (ch >= 0x20)
            freq[ch - 0x20]++;
    fclose(fp);
    return freq;
}

#endif