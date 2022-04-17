#include <stdio.h>
#include <stdlib.h>

#include "bitree_link_base.h"
#define StackElementType BsTree
#define ERROR    -9999
typedef  struct  SNode *Stack ;
struct  SNode {
    StackElementType Data;
    struct  SNode *Next ;
};

Stack CreateStack() {
    Stack  s = (Stack)malloc(sizeof(struct SNode)) ;
    s->Next = NULL;
    return s ;
}

void  Push(Stack s, StackElementType item) {
    struct SNode *tmpNode;
    tmpNode = (struct SNode *)malloc(sizeof(struct SNode)) ;
    tmpNode->Data = item ;
    tmpNode->Next = s->Next ;
    s->Next = tmpNode;
}
int StackIsEmpty(Stack s){
    if (s->Next == NULL){
        return 1 ;
    }
    return 0 ;
}

StackElementType Pop(Stack s) {
    if (StackIsEmpty(s)==1){
        printf("null \n") ;

        return NULL;
    }
    struct SNode *firstNode;
    StackElementType itemValue ;
    firstNode = s->Next ;
    s->Next = firstNode->Next;
    itemValue = firstNode->Data;
    free(firstNode) ;
    return itemValue;
}

