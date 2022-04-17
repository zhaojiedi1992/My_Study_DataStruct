// bstree_link_base.c
#include <stdio.h>
#include <stdlib.h>
#include "bitree_link_base.h"


// 判断树是否为空
int TreeIsEmpty(BsTree bt) {
    if (bt == NULL) {
        return 1;
    }
    return 0;
}

// 创建树
BsTree CreateBsTree() {
    BsTree bt = (BsTree) malloc(sizeof(struct TreeNode));
    return bt;
}

Position FindByRecursive(ElementType item, BsTree bst) {
    if (!bst) {
        return NULL;
    }
    if (item == bst->Data) {
        return bst;
    }
    if (item > bst->Data) {
        return FindByRecursive(item, bst->Right);
    }
    if (item < bst->Data) {
        return FindByRecursive(item, bst->Left);
    }
}

Position FindByIterate(ElementType item, BsTree bst) {

    BsTree pst = bst;
    while (pst) {
        if (pst->Data == item) {
            return pst;
        }
        if (item > pst->Data) {
            pst = pst->Right;
        } else {
            pst = pst->Left;
        }
    }
    return NULL;
}

Position FindMax(BsTree bst) {
    BsTree pst = bst;
    while (pst && pst->Right) {
        pst = pst->Right;
    }
    return pst;

}

Position FindMin(BsTree bst) {
    BsTree pst = bst;
    while (pst && pst->Left) {
        pst = pst->Left;
    }
    return pst;

}

// 前序递归
void PreOrderTraversalByRecursive(BsTree bt) {
    if (bt) {
        printf("%d ", bt->Data);
        PreOrderTraversalByRecursive(bt->Left);
        PreOrderTraversalByRecursive(bt->Right);
    }
}

BsTree InsertByIterate(ElementType item, BsTree bst) {
    // BsTree  pst = bst ;
    BsTree parent = bst;
    BsTree current = bst;
    while (current) {
        parent = current ;
        if (item > current->Data) {
            current = current->Right;

        } else {
            current = current->Left;
        }
    }

    BsTree node = malloc(sizeof(struct TreeNode));
    node->Data = item;
    node->Left = NULL;
    node->Right = NULL;
    if (item > parent->Data) {
        parent->Right = node;
    } else {
        parent->Left = node;
    }

    return bst;

}

BsTree InsertByRecursive(ElementType item, BsTree bst) {
    if ( ! bst ){
        BsTree node = malloc(sizeof(struct TreeNode));
        node->Data = item;
        node->Left = node->Right = NULL;
        return node;
    }
    if (item > bst->Data ){
        bst->Right = InsertByRecursive(item,bst->Right);
    }else{
        bst->Left = InsertByRecursive(item,bst->Left);
    }
    return bst ;
    // == 这个咱不考虑
}

BsTree DeleteByRecursive(ElementType item, BsTree bst) {
    if ( !bst ){
       printf("找不到删除元素");
       return NULL;
    }
    if (item > bst->Data ){
        bst->Right = DeleteByRecursive(item,bst->Right);
    }else if(item < bst->Data ){
        bst->Left = DeleteByRecursive(item,bst->Left);
    }else{
        // 左节点为空的删除
        if (bst->Left == NULL ){
            bst = bst->Right;
        }else if (bst->Right ==NULL){   // 右节点为空。
            bst = bst->Left ;
        }else{
            // 左右都有的。
            Position  tmp = FindMin(bst->Right);
            bst->Data = tmp->Data;
            bst->Right = DeleteByRecursive(bst->Data,bst->Right);
        }
    }
   return bst ;
}

BsTree CreateDemoTree() {
    /*
            40
         20      60
       10  30   50


    * */
    BsTree bt1 = CreateBsTree();
    bt1->Data = 40;
    BsTree bt2 = CreateBsTree();
    bt2->Data = 20;
    BsTree bt3 = CreateBsTree();
    bt3->Data = 60;
    BsTree bt4 = CreateBsTree();
    bt4->Data = 10;
    BsTree bt5 = CreateBsTree();
    bt5->Data = 30;
    BsTree bt6 = CreateBsTree();
    bt6->Data = 50;

    bt1->Left = bt2;
    bt1->Right = bt3;

    bt2->Left = bt4;
    bt2->Right = bt5;

    bt3->Left = bt6;
    return bt1;
}

int mainByIterate() {
    Position pos;
    BsTree bst = CreateDemoTree();
    printf("PreOrderTraversal\n");
    PreOrderTraversalByRecursive(bst);
    printf("\n");

    pos = FindByIterate(20, bst);
    PreOrderTraversalByRecursive(pos);
    printf("\n");

    pos = FindMax(bst);
    PreOrderTraversalByRecursive(pos);
    printf("\n");

    pos = FindMin(bst);
    PreOrderTraversalByRecursive(pos);
    printf("\n");


//    bst = InsertByIterate(33, bst);
//    PreOrderTraversalByRecursive(bst);
//    printf("\n");

//    bst = DeleteByRecursive(70, bst);
//    PreOrderTraversalByRecursive(bst);
//    printf("\n");
//    bst = DeleteByRecursive(80, bst);
//    PreOrderTraversalByRecursive(bst);
//    printf("\n");

    bst = DeleteByRecursive(20, bst);
    PreOrderTraversalByRecursive(bst);
    printf("\n");
}
int mainByRecursive() {
    Position pos;
    BsTree bst = CreateDemoTree();
    printf("PreOrderTraversal\n");
    PreOrderTraversalByRecursive(bst);
    printf("\n");

    pos = FindByRecursive(20, bst);
    PreOrderTraversalByRecursive(pos);
    printf("\n");



    pos = FindMax(bst);
    PreOrderTraversalByRecursive(pos);
    printf("\n");

    pos = FindMin(bst);
    PreOrderTraversalByRecursive(pos);
    printf("\n");

    bst = InsertByRecursive(70, bst);
    PreOrderTraversalByRecursive(bst);
    printf("\n");



    bst = DeleteByRecursive(40, bst);
    PreOrderTraversalByRecursive(bst);
    printf("\n");



}

int main(){
    mainByRecursive();
   // mainByIterate()
}