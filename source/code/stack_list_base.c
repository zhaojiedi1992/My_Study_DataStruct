#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5
#define ElementType int
#define ERROR    -9999

typedef struct SNode *Stack;
struct SNode {
    ElementType Data[MAXSIZE];
    int Top;    // 顶部元素的下标。
};


Stack CreateStack() {
    Stack  s = (Stack) malloc(sizeof(struct SNode)) ;
    s->Top =-1;
    return s ;
}

int IsFull(Stack s) {
    if (s->Top == MAXSIZE - 1) {
        return 1;
    }
    return 0;
}

void Push(Stack s, ElementType item) {
    if (IsFull(s) == 1) {
        printf("is full\n");
        return;
    }
    (s->Top)++;
    s->Data[s->Top] = item;
}


int IsEmpty(Stack s) {
    if (s->Top == -1) {
        return 1;
    }
    return 0;
}

ElementType Pop(Stack s) {
    if (IsEmpty(s) == 1) {
        printf("is null\n");
        return ERROR;
    }

    ElementType item = s->Data[s->Top];
    (s->Top)--;
    return item;
}


int main() {
    Stack s = CreateStack();
    ElementType item ;
    printf("%d\n",IsEmpty(s));
    Push(s,1);
    printf("%d\n",IsFull(s));
    Push(s,2);
    Push(s,3);
    Push(s,4);
    Push(s,5);
    printf("%d\n",IsFull(s));
    Push(s,6);
    printf("%d\n",IsFull(s));
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
    item = Pop(s) ;
    printf("%d\n",item  );
    return 0;
    /*
    1
    0
    1
    is full
    1
    5
    4
    3
    2
    1
    is null
    -9999

     */
}

