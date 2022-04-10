#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5
#define ElementType int

typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    int Len;
};

List MakeEmpty() {
    List ptrl;
    ptrl = (List) malloc(sizeof(struct LNode));
    ptrl->Len = 0;
    return ptrl;
}


int Find(ElementType x, List ptrl) {
    int i = 0;
    while (i < ptrl->Len   && ptrl->Data[i] != x) {
        i++;
    }
    if (i >= ptrl->Len   ) {
        return -1;
    }
    return i;
}

void Insert( ElementType x, int i, List ptrl ) {

    if (ptrl->Len >=MAXSIZE){
        printf("表满了,不能再插入了。\n") ;
        return  ;
    }
    if (i <0 || i >ptrl->Len){
        printf("位置不合法\n");
        return ;
    }
    int j =0 ;
    for (j=ptrl->Len-1; j>=i ;j--){
        ptrl->Data[j+1] = ptrl->Data[j] ;
    }
    ptrl->Data[i] = x ;
    ptrl->Len +=1;
}
void Delete(int i , List ptrl){
    if (i >=ptrl->Len || i<0) {
        printf("删除位置不合适\n");
        return;
    }

    int j=0;
    for (j=i; j<ptrl->Len-1 ;j++){
        ptrl->Data[j] = ptrl->Data[j+1];
    }
    ptrl->Len -=1;
    return ;
}


void Print(List ptrl) {
    int i;
    for (i = 0; i < ptrl->Len; i++) {
        printf("%d ", ptrl->Data[i]);
    }
    printf("\n");
}


int main() {
    List ptrl;
    int index ;

    ptrl = MakeEmpty();
    Insert(1,0,ptrl);
    Insert(2,1,ptrl);
    Insert(3,2,ptrl);
    Insert(4,3,ptrl);
    //Insert(5,4,ptrl);
    // Insert(6,5,ptrl);
    //Insert(6,7,ptrl);

    index = Find(3,ptrl);
    printf("find %d in list index=%d\n ",3, index);
    Print(ptrl);

    Delete(5,ptrl);
    Print(ptrl);
    Delete(0,ptrl);
    Print(ptrl);

    return 0;
}

