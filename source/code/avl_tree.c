#include <stdio.h>
#include <stdlib.h>

#define  ElementType int
typedef struct AVLNode *AVLTree;
struct AVLNode {
    ElementType Data;
    AVLTree Left;
    AVLTree Right;
    int Height;
};

AVLTree CreateAvlTree(){
    AVLTree t = (AVLTree)malloc(sizeof(struct AVLNode));
    return t ;
}

int Max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

int GetHeight(AVLTree t) ;
void UpdateHeight(AVLTree t) {
    t->Height = Max(GetHeight(t->Left), GetHeight(t->Right)) + 1;
    return ;
}


int GetHeight(AVLTree t) {
    int rightHeight;
    int leftHeight;
    if (!t) {
        return 0;
    }
    UpdateHeight(t);
    return t->Height;
}

AVLTree RR(AVLTree a) {
    AVLTree b = a->Right;
    a->Right = b->Left;
    b->Left = a;

    UpdateHeight(a);
    UpdateHeight(b);
    return b;
}

AVLTree LL(AVLTree a) {
    AVLTree b = a->Left;
    a->Left = b->Right;
    b->Right = a;

    UpdateHeight(a);
    UpdateHeight(b);
    return b;
}

AVLTree LR(AVLTree a) {
    a->Left = RR(a->Left);
    return LL(a);
}
AVLTree RL(AVLTree a) {
    a->Right = LL(a->Right);
    return RR(a);
}

AVLTree Insert(AVLTree t, ElementType item) {
    if (!t) {
        //  给叶子节点添加一个子节点的时候，走到这个部分。
        AVLTree node = (AVLTree)malloc(sizeof(struct AVLNode));
        node->Data = item;
        node->Left = NULL;
        node->Right = NULL;
        node->Height = 1;
        return node;
    }
    if (item > t->Data) {
        t->Right = Insert(t->Right, item);
        if (GetHeight(t->Right) - GetHeight(t->Left) == 2) {
            if (item > t->Right->Data) {
                t = RR(t);
            } else {
                t = RL(t);
            }
        }
    } else {
        t->Left = Insert(t->Left, item);
        if (GetHeight(t->Left) - GetHeight(t->Right) == 2) {
            if (item < t->Left->Data) {
                t = LL(t);
            } else {
                t = LR(t);
            }
        }
    }
    t->Height = Max(GetHeight(t->Left), GetHeight(t->Right)) + 1;
    return t;
}
void PreOrderTraversalByRecursive(AVLTree bt){
    if (bt){
        printf("%d ", bt->Data);
        PreOrderTraversalByRecursive(bt->Left);
        PreOrderTraversalByRecursive(bt->Right);
    }
}

int main(){
    AVLTree  avlTree= NULL ;
    //avlTree = CreateAvlTree();
    avlTree= Insert(avlTree,1);
    avlTree = Insert(avlTree,2) ;
    avlTree= Insert(avlTree,3) ;
    PreOrderTraversalByRecursive(avlTree);
    printf("\n");
    avlTree= Insert(avlTree,7) ;
    PreOrderTraversalByRecursive(avlTree);
    printf("\n");
    avlTree= Insert(avlTree,6) ;
    avlTree= Insert(avlTree,5) ;
    avlTree= Insert(avlTree,0) ;
    PreOrderTraversalByRecursive(avlTree);
}
/*
 * =========================================================
    one          two        three     three_adjust(RR)
    1            1             1            2
                    2             2       1     3
                                    3
 * =========================================================
    four        five            five_adjust(RL)
     2           2                  2
   1    3      1    3           1      6
           7           7              3  7
                     6
=========================================================
 six                six_adjust(RL)
      2                  3
   1     6            2    6
       3   7        1     5  7
        5
=========================================================
 seven              seven_adjust(LL)
        3                   3
      2   6              1     6
    1    5  7           0 2   5 7
  0
 */