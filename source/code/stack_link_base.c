#include <stdio.h>
#include <stdlib.h>

#define ElementType int
#define ERROR    -9999
typedef  struct  SNode *Stack ;
struct  SNode {
    ElementType Data;
    struct  SNode *Next ;
};

Stack CreateStack() {
    Stack  s = (Stack)malloc(sizeof(struct SNode)) ;
    s->Next = NULL;
    return s ;
}

void  Push(Stack s, ElementType item) {
    struct SNode *tmpNode;
    tmpNode = (struct SNode *)malloc(sizeof(struct SNode)) ;
    tmpNode->Data = item ;
    tmpNode->Next = s->Next ;
    s->Next = tmpNode;
}
int IsEmpty(Stack s){
    if (s->Next == NULL){
        return 1 ;
    }
    return 0 ;
}

ElementType Pop(Stack s) {
    if (IsEmpty(s)==1){
        printf("null \n") ;
        return ERROR;
    }
    struct SNode *firstNode;
    ElementType itemValue ;
    firstNode = s->Next ;
    s->Next = firstNode->Next;
    itemValue = firstNode->Data;
    free(firstNode) ;
    return itemValue;
}

int main() {
    Stack s = CreateStack();
    ElementType item ;
    printf("is empty ? %d\n",IsEmpty(s));
    Push(s,1);
    Push(s,2);
    Push(s,3);
    Push(s,4);

    item = Pop(s) ;
    printf("%d\n",item  );
    item = Pop(s) ;
    printf("%d\n",item  );
    item = Pop(s) ;
    printf("%d\n",item  );
    item = Pop(s) ;
    printf("%d\n",item  );
    item = Pop(s) ;
    printf("%d\n",item  );

    return 0;
    /*


     */
}