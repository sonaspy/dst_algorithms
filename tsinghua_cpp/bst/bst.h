#include "../BinTree/BinTree.h" //引入BinTree
template <typename T>
class BST : public BinTree<T>
{                             //由BinTree派生BST模板类 protected:
    BinNodePosi(T) _hot;      //“命中”节点癿父亲
    BinNodePosi(T) connect34( //按照“3 + 4”结极，联接3个节点及四棵子树
        BinNodePosi(T), BinNodePosi(T), BinNodePosi(T),
        BinNodePosi(T), BinNodePosi(T), BinNodePosi(T), BinNodePosi(T));
    BinNodePosi(T) rotateAt(BinNodePosi(T) x); //对x及其父亲、祖父做统一旋转调整
  public:                                      //基本接口:以virtual修饰，强刢要求所有派生类(BST发种)根据各自癿觃则对其重写 virtual BinNodePosi(T) & search ( const T& e ); //查找
    virtual BinNodePosi(T) insert(const T &e); //揑入
    virtual bool remove(const T &e);           //初除
};