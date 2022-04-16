#include <stdio.h>
#include <stdlib.h>

#define ElementType int
#define ERROR    -9999
struct  Node {
    ElementType Data;
    struct Node *Next ;
};

typedef  struct  QNode *Queue ;
struct QNode {
    struct Node *real;
    struct Node *front;
};


int IsFullQ(Queue q) {
    return 0 ;
}

int IsEmptyQ(Queue q) {
    if ( q->front  == NULL){
        return 1 ;
    }
    return 0 ;
}

Queue CreateQueue() {
   Queue  q = (Queue)malloc(sizeof(struct QNode)) ;
   q->front = NULL ;
   q->real = NULL ;
   return q ;
}

void AddQ(Queue q, ElementType item) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node)) ;
    node->Next = NULL;
    node->Data = item ;
    if (q->real ==NULL){
        q->real = node ;
    }else{
        q->real->Next = node;
        q->real = q->real->Next ;
    }
    if (q->front == NULL){
        q->front = node ;
    }

}

ElementType DeleteQ(Queue q) {
    if (IsEmptyQ(q) == 1) {
        printf("empty \n");
        return ERROR;
    }
    ElementType firstValue ;
    struct  Node *frontNode ;

    frontNode=  q->front ;
    if (q->front == q->real ){
        q->front = NULL;
        q->real = NULL;

    }else{
        q->front = q->front->Next ;
    }
    firstValue = frontNode->Data;
    free(frontNode);
    return firstValue ;

}



int main() {
    Queue q = CreateQueue();
    ElementType item;
    printf("is empty ? %d\n", IsEmptyQ(q));
    AddQ(q, 1);
    AddQ(q, 2);
    AddQ(q, 3);
    AddQ(q, 4);

    item = DeleteQ(q);
    printf("item= %d\n", item);
    item = DeleteQ(q);
    printf("item= %d\n", item);
    item = DeleteQ(q);
    printf("item= %d\n", item);
    item = DeleteQ(q);
    printf("item= %d\n", item);
    item = DeleteQ(q);
    printf("item= %d\n", item);
    item = DeleteQ(q);
    printf("item= %d\n", item);


    return 0;
    /*


     */
}