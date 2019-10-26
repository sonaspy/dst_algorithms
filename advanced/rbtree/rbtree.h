#ifndef RB_TREE_H
#define RB_TREE_H

#include "rbnode.h"

template <class T>
class RB_Tree {
  public:
    RB_Tree(T Root_Data);
    ~RB_Tree();
    void Left_Rotate(RB_Tree_Node<T> *current_Node);
    void Right_Rotate(RB_Tree_Node<T> *current_Node);
    void Insert_Node(T insert_data);
    int Delete_Node(T delete_data);
    void Fix_Tree(RB_Tree_Node<T> *current_Node);
    void erase_Node(RB_Tree_Node<T> *Node_del);
    void Fix_Tree_Delete(RB_Tree_Node<T> *current_Node);
    RB_Tree_Node<T> *Find_Successor_Node(RB_Tree_Node<T> *current_Node);
    RB_Tree_Node<T> *Root_Node;
};

template <class T>
RB_Tree<T>::RB_Tree(T Root_Data) : Root_Node(NULL) {
    if (Root_Node == NULL) {
        Root_Node = new RB_Tree_Node<T>(Root_Data);
        Root_Node->color_tag = 0;
    }
}

template <class T>
RB_Tree<T>::~RB_Tree() {}

template <class T>
void RB_Tree<T>::Insert_Node(T insert_data) {

    RB_Tree_Node<T> *temp_Node = Root_Node;
    while (temp_Node != NULL) {
        if (insert_data > temp_Node->data) {
            if (temp_Node->Right_child == NULL) {
                temp_Node->Right_child = new RB_Tree_Node<T>(insert_data);
                temp_Node->Right_child->color_tag = 1;
                temp_Node->Right_child->Father_Node = temp_Node;
                if (temp_Node->color_tag == 1) {
                    Fix_Tree(temp_Node->Right_child);
                }
                break;
            } else {
                temp_Node = temp_Node->Right_child;
            }
        } else {
            if (temp_Node->Left_child == NULL) {
                temp_Node->Left_child = new RB_Tree_Node<T>(insert_data);
                temp_Node->Left_child->color_tag = 1;
                temp_Node->Left_child->Father_Node = temp_Node;
                if (temp_Node->color_tag == 1) {
                    Fix_Tree(temp_Node->Left_child);
                }
                break;
            } else {
                temp_Node = temp_Node->Left_child;
            }
        }
    }
}

template <class T>
int RB_Tree<T>::Delete_Node(T delete_data) {
    RB_Tree_Node<T> *temp_Node = Root_Node;
    while (temp_Node->data != delete_data && temp_Node != NULL) {
        if (delete_data > temp_Node->data) {
            temp_Node = temp_Node->Right_child;
        } else {
            temp_Node = temp_Node->Left_child;
        }
    }
    if (temp_Node)

    {
        int color_tag = temp_Node->color_tag;

        if (temp_Node->Left_child == NULL && temp_Node->Right_child == NULL)

        {

            delete temp_Node;
        } else if (temp_Node->Left_child == NULL &&
                   temp_Node->Right_child != NULL)

        {
            if (temp_Node != Root_Node)

            {
                if (temp_Node->Father_Node->Left_child == temp_Node) {
                    temp_Node->Father_Node->Left_child = temp_Node->Right_child;
                    temp_Node->Right_child->Father_Node =
                        temp_Node->Father_Node;

                } else {
                    temp_Node->Father_Node->Right_child =
                        temp_Node->Right_child;
                    temp_Node->Right_child->Father_Node =
                        temp_Node->Father_Node;
                }
            } else

            {
                Root_Node = temp_Node->Right_child;
                temp_Node->Right_child->Father_Node = Root_Node;
            }
        } else if (temp_Node->Left_child != NULL &&
                   temp_Node->Right_child == NULL)

        {
            if (temp_Node != Root_Node)

            {
                if (temp_Node->Father_Node->Left_child == temp_Node) {
                    temp_Node->Father_Node->Left_child = temp_Node->Left_child;
                    temp_Node->Left_child->Father_Node = temp_Node->Father_Node;

                } else {
                    temp_Node->Father_Node->Right_child = temp_Node->Left_child;
                    temp_Node->Left_child->Father_Node = temp_Node->Father_Node;
                }
            } else

            {
                Root_Node = temp_Node->Left_child;
                temp_Node->Left_child->Father_Node = Root_Node;
            }
        } else if (temp_Node->Left_child != NULL &&
                   temp_Node->Right_child != NULL)

        {
            RB_Tree_Node<T> *Successor_Node = Find_Successor_Node(temp_Node);
            if (temp_Node == temp_Node->Father_Node->Left_child) {
                temp_Node->Father_Node->Left_child = Successor_Node;
                Successor_Node->Right_child = temp_Node->Right_child;
                Successor_Node->Left_child = temp_Node->Left_child;
                Successor_Node->Father_Node = temp_Node->Father_Node;
                Successor_Node->color_tag = temp_Node->color_tag;
                if (Successor_Node->Right_child) {
                    Successor_Node->Father_Node->Left_child =
                        Successor_Node->Right_child;
                    Successor_Node->Right_child->Father_Node =
                        Successor_Node->Father_Node;
                }

            } else {
                temp_Node->Father_Node->Right_child = Successor_Node;
                Successor_Node->Right_child = temp_Node->Right_child;
                Successor_Node->Left_child = temp_Node->Left_child;
                Successor_Node->Father_Node = temp_Node->Father_Node;
                Successor_Node->color_tag = temp_Node->color_tag;
                if (Successor_Node->Right_child) {
                    Successor_Node->Father_Node->Left_child =
                        Successor_Node->Right_child;
                    Successor_Node->Right_child->Father_Node =
                        Successor_Node->Father_Node;
                }
            }
        }

        if (color_tag == 0)

        {
            Fix_Tree_Delete(RB_Tree_Node<T> * temp_Node)
        }
    }

    else {
        return -1;
    }
    return 1;
}

template <class T>
void RB_Tree<T>::Fix_Tree(RB_Tree_Node<T> *current_Node) {
    RB_Tree_Node<T> *temp_current_Node = current_Node;
    RB_Tree_Node<T> *uncle_Node;

    while (true) {
        if (temp_current_Node->Father_Node == NULL) {
            break;
        }
        if (temp_current_Node->Father_Node->color_tag != 1) {
            break;
        }
        RB_Tree_Node<T> *father_Node = temp_current_Node->Father_Node;
        RB_Tree_Node<T> *grandfa_Node = father_Node->Father_Node;
        if (grandfa_Node) {
            if (father_Node == grandfa_Node->Left_child) {
                uncle_Node = grandfa_Node->Right_child;

                if (uncle_Node) {

                    if (uncle_Node->color_tag == 1) {
                        uncle_Node->color_tag = 0;
                        father_Node->color_tag = 0;
                        grandfa_Node->color_tag = 1;
                        temp_current_Node = grandfa_Node;
                    }

                    else if (temp_current_Node == father_Node->Right_child) {
                        temp_current_Node = temp_current_Node->Father_Node;
                        Left_Rotate(temp_current_Node);
                    }

                    else {
                        father_Node->color_tag = 0;
                        grandfa_Node->color_tag = 1;
                        Right_Rotate(grandfa_Node);
                    }
                }

                else {
                    if (temp_current_Node == father_Node->Right_child) {
                        temp_current_Node = temp_current_Node->Father_Node;
                        Left_Rotate(temp_current_Node);
                    } else {
                        father_Node->color_tag = 0;
                        grandfa_Node->color_tag = 1;
                        Right_Rotate(grandfa_Node);
                    }
                }
            } else {
                uncle_Node = grandfa_Node->Left_child;
                if (uncle_Node) {

                    if (uncle_Node->color_tag == 1) {
                        uncle_Node->color_tag = 0;
                        father_Node->color_tag = 0;
                        grandfa_Node->color_tag = 1;
                        temp_current_Node = grandfa_Node;
                    }

                    else if (temp_current_Node == father_Node->Left_child) {
                        temp_current_Node = temp_current_Node->Father_Node;
                        Right_Rotate(temp_current_Node);
                    }

                    else {
                        father_Node->color_tag = 0;
                        grandfa_Node->color_tag = 1;
                        Left_Rotate(grandfa_Node);
                    }
                } else {
                    if (temp_current_Node == father_Node->Left_child) {
                        temp_current_Node = temp_current_Node->Father_Node;
                        Right_Rotate(temp_current_Node);
                    } else {
                        father_Node->color_tag = 0;
                        grandfa_Node->color_tag = 1;
                        Left_Rotate(grandfa_Node);
                    }
                }
            }
        }
    }
    Root_Node->color_tag = 0;
}

template <class T>
void RB_Tree<T>::Left_Rotate(RB_Tree_Node<T> *current_Node) {
    RB_Tree_Node<T> *Right_child = current_Node->Right_child;
    RB_Tree_Node<T> *father_Node = current_Node->Father_Node;
    current_Node->Right_child = Right_child->Left_child;
    Right_child->Father_Node = father_Node;
    if (father_Node == NULL) {
        Root_Node = Right_child;
    } else if (current_Node == father_Node->Left_child) {
        father_Node->Left_child = Right_child;
    } else {
        father_Node->Right_child = Right_child;
    }

    Right_child->Left_child = current_Node;
    current_Node->Father_Node = Right_child;
}

template <class T>
void RB_Tree<T>::Right_Rotate(RB_Tree_Node<T> *current_Node) {
    RB_Tree_Node<T> *left_Node = current_Node->Left_child;
    RB_Tree_Node<T> *father_Node = current_Node->Father_Node;
    current_Node->Left_child = left_Node->Right_child;
    left_Node->Right_child = current_Node;
    if (father_Node == NULL) {
        Root_Node = left_Node;
    } else if (current_Node = father_Node->Left_child) {
        father_Node->Left_child = left_Node;
    } else {
        father_Node->Right_child = left_Node;
    }
    current_Node->Father_Node = left_Node;
    left_Node->Father_Node = father_Node;
}

template <class T>
RB_Tree_Node<T> *
RB_Tree<T>::Find_Successor_Node(RB_Tree_Node<T> *current_Node) {
    RB_Tree_Node<T> *temp_Node = current_Node->Right_child;
    while (temp_Node->Left_child != NULL) {
        temp_Node = temp_Node->Left_child;
    }
    return temp_Node;
}

template <class T>
void RB_Tree<T>::erase_Node(RB_Tree_Node<T> *Node_del) {
    if (Node_del->Father_Node) {
        Node_del->Father_Node = NULL;
    }
    Node_del->color_tag = NULL;
    Node_del->Father_Node = NULL;
    Node_del->Left_child = NULL;
    Node_del->Right_child = NULL;
    Node_del->data = NULL;
    delete Node_del;
}

#endif