#include <stdio.h>
#include <stdlib.h>

#define  ElementType int

#define  MaxV  9999999

typedef struct  HeapStruct *MaxHeap ;
struct  HeapStruct{
    ElementType *Data;
    int Size ;
    int Capacity;
};


MaxHeap CreateHeap(int max_size)
{
    MaxHeap  h = malloc(sizeof(struct HeapStruct)) ;
    h->Data= malloc(sizeof( ElementType) * (max_size +1));
    h->Size= 0 ;
    h->Capacity = max_size;
    h->Data[0] = MaxV ;
    return h ;
}

int IsHeapFull(MaxHeap h){
    return h->Capacity == h->Size ;
}
int IsEmpty(MaxHeap h){
    return  h->Size==0 ;
}

void InsertMaxHeap(MaxHeap h, ElementType item){
    int i ;
    if (IsHeapFull(h)){
        printf("heap is full\n");
        return ;
    }
    h->Size +=1;
    i = h->Size ;

    for (; h->Data[i/2] < item  ; i=i/2) {
        h->Data[i] = h->Data[i/2] ;
    }
    h->Data[i] = item ;
}

ElementType DeleteMax(MaxHeap h){
    if (IsEmpty(h)){
        printf("heap is empty\n");
        return MaxV ;
    }
    ElementType maxItem , temp ;
    int parent , child ;

    maxItem = h->Data[1];
    temp = h->Data[h->Size] ;
    h->Size -=1;
    for ( parent = 1; 2* parent <= h->Size ; parent = child ) {
        child = 2 * parent ;
        if (child !=h->Size  && h->Data[child] < h->Data[child+1]){
            child +=1 ;
        }
        if (temp >= h->Data[child]){
            break;
        }else{
            h->Data[parent] = h->Data[child] ;
        }
    }
    h->Data[parent] = temp;
    return maxItem ;
}

void PrintMaxHeap(MaxHeap h){
    int j ;
    for (int i = 1; i <=h->Size ; i=i*2) {
        j = i ;
        while (j<i*2 && j<=h->Size){
            printf("%d ",h->Data[j]);
            j+=1;
        }
        printf("\n");

    }
}
//void PercDown( MaxHeap H, int p){
//
//}
//
//void BuildMaxHeap(MaxHeap H){
//
//}

int main(){
    MaxHeap  h = CreateHeap(100);
    InsertMaxHeap(h,1);
    InsertMaxHeap(h,2);
    InsertMaxHeap(h,3);
    InsertMaxHeap(h,4);
    InsertMaxHeap(h,5);
    InsertMaxHeap(h,6);
    InsertMaxHeap(h,7);
    InsertMaxHeap(h,8);
    PrintMaxHeap(h) ;
    printf("******\n");
    DeleteMax(h);
    PrintMaxHeap(h) ;
    printf("\n");
}