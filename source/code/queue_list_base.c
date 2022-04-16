#include <stdio.h>
#include <stdlib.h>

#define ElementType int
#define ERROR    -9999
#define MAXSIZE 5
typedef struct QNode *Queue;
struct QNode {
    ElementType Data[MAXSIZE];
    int real;
    int front;
};

int IsFullQ(Queue q) {
    if ((q->real + 1) % MAXSIZE == q->front) {
        return 1;
    }
    return 0;
}

int IsEmptyQ(Queue q) {
    if (q->real == q->front) {
        return 1;
    }
    return 0;
}

Queue CreateQueue() {
    Queue q = (Queue) malloc(sizeof(struct QNode));
    q->front = 0;
    q->real = 0;
    return q;
}

void AddQ(Queue q, ElementType item) {
    if (IsFullQ(q) == 1) {
        printf("full \n");
        return;
    }
    q->real = (q->real + 1) % MAXSIZE;
    q->Data[q->real] = item;
}

ElementType DeleteQ(Queue q) {
    if (IsEmptyQ(q) == 1) {
        printf("empty \n");
        return ERROR;
    }
    q->front = (q->front + 1) % MAXSIZE;
    return q->Data[q->front];
}

int main() {
    Queue q = CreateQueue();
    ElementType item;
    printf("is empty ? %d\n", IsEmptyQ(q));
    AddQ(q, 1);
    AddQ(q, 2);
    AddQ(q, 3);
    AddQ(q, 4);
    AddQ(q, 5);
    AddQ(q, 6);
    AddQ(q, 7);
    item = DeleteQ(q);
    printf("item= %d\n", item);
    item = DeleteQ(q);
    printf("item= %d\n", item);
    item = DeleteQ(q);
    printf("item= %d\n", item);
    item = DeleteQ(q);
    printf("item= %d\n", item);

    /*
is empty ? 1
full
full
full
item= 1
item= 2
item= 3
item= 4
     * */
}