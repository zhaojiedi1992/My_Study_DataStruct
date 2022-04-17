// bitree_link_base.c
#include <stdio.h>
#include <stdlib.h>
#include "stack_link_base_for_tree.c"
#include "queue_link_base_for_tree.c"
#include "bitree_link_base.h"

// 判断树是否为空
int TreeIsEmpty(BsTree bt){
    if( bt == NULL){
        return 1 ;
    }
    return 0;
}

// 创建树
BsTree CreateBsTree(){
    BsTree  bt = (BsTree)malloc(sizeof(struct TreeNode));
    return bt ;
}

// 前序递归
void PreOrderTraversalByRecursive(BsTree bt){
    if (bt){
        printf("%d ", bt->Data);
        PreOrderTraversalByRecursive(bt->Left);
        PreOrderTraversalByRecursive(bt->Right);
    }
}

// 中续递归
void InOrderTraversalByRecursive(BsTree bt){
    if (bt){
        InOrderTraversalByRecursive(bt->Left);
        printf("%d ", bt->Data);
        InOrderTraversalByRecursive(bt->Right);
    }
}

// 后续递归
void PosOrderTraversalByRecursive(BsTree bt){
    if (bt){
        PosOrderTraversalByRecursive(bt->Left);
        PosOrderTraversalByRecursive(bt->Right);
        printf("%d ", bt->Data);
    }
}

// 前序迭代
void PreOrderTraversalByIterate(BsTree bt){
    Stack s = CreateStack();
    BsTree  t = bt;
    while( t || !StackIsEmpty(s)){
        while(t){
            printf("%d ",t->Data);
            Push(s,  t);
            t= t->Left;
        }
        if (!StackIsEmpty(s)){
            t= (BsTree) Pop(s);
            t=t->Right;
        }
    }
}

// 中序迭代
void InOrderTraversalByIterate(BsTree bt){
    Stack s = CreateStack();
    BsTree  t = bt;
    while( t || !StackIsEmpty(s)){
        while(t){
            Push(s,  t);
            t= t->Left;
        }
        if (!StackIsEmpty(s)){
            t= (BsTree) Pop(s);
            printf("%d ",t->Data);
            t=t->Right;
        }
    }
}

// 后序迭代
void PostOrderTraversalByIterate(BsTree bt){
    Stack s = CreateStack();
    BsTree  t = bt;
    BsTree  prev= NULL ;
    while( t || !StackIsEmpty(s)){
        while(t){
            Push(s,  t);
            t= t->Left;
        }
        t = (BsTree)Pop(s);
        if (t->Right == NULL || t->Right == prev){
            printf("%d ",t->Data);
            prev = t ;
            t = NULL;

        }else{
            Push(s,t);
            t= t->Right;
        }

    }
}


// 层次遍历
void LevelOrderTraversal(BsTree bt){

    Queue  q = CreateQueue();
    BsTree  t = bt ;
    if (bt == NULL){
        return ;
    }
    AddQ(q,t);
    while(!IsEmptyQ(q)){

        t= DeleteQ(q);
        printf("%d ",t->Data);
        if (t->Left){
            AddQ(q,t->Left);
        }
        if (t->Right){
            AddQ(q,t->Right);
        }

    }

}
BsTree CreateDemoTree(){
    /*
            1
         2      3
       5   4   6


    * */
    BsTree  bt1 = CreateBsTree();
    bt1->Data = 1 ;
    BsTree  bt2 = CreateBsTree();
    bt2->Data = 2 ;
    BsTree  bt3 = CreateBsTree();
    bt3->Data = 3 ;
    BsTree  bt4 = CreateBsTree();
    bt4->Data = 4 ;
    BsTree  bt5 = CreateBsTree();
    bt5->Data = 5 ;
    BsTree  bt6 = CreateBsTree();
    bt6->Data = 6 ;

    bt1->Left = bt2 ;
    bt1->Right =bt3 ;

    bt2->Left = bt5 ;
    bt2->Right=bt4 ;

    bt3->Left = bt6 ;
    return  bt1 ;
}

int main(){

    BsTree  bt =CreateDemoTree();
    printf("PreOrderTraversal\n");
    PreOrderTraversalByRecursive(bt);
    printf("\n");

    printf("InOrderTraversalByRecursive\n");
    InOrderTraversalByRecursive(bt);
    printf("\n");

    printf("PosOrderTraversalByRecursive\n");
    PosOrderTraversalByRecursive(bt);
    printf("\n");


    printf("PreOrderTraversalByIterate\n");
    PreOrderTraversalByIterate(bt);
    printf("\n");

    printf("InOrderTraversalByIterate\n");
    InOrderTraversalByIterate(bt);
    printf("\n");

    printf("PostOrderTraversalByIterate\n");
    PostOrderTraversalByIterate(bt);
    printf("\n");

    printf("LevelOrderTraversal\n");
    LevelOrderTraversal(bt);
    printf("\n");
}
