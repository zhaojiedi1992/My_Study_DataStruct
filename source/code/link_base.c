#include <stdio.h>
#include <stdlib.h>

#define ElementType int

typedef struct LNode *List;
struct LNode
{
    ElementType Data;
    List Next;
};

List MakeEmpty() {
    List ptrl = NULL;
    return ptrl;
}

int Length(List ptrl){
    List p = ptrl ;
    int cnt =0 ;
    while  (p){
        p=p->Next;
        cnt +=1;
    }
    return cnt ;
}
List FindKth(int i , List ptrl){
    if (i<0){
        printf("位置不合适、n");
        return NULL ;
    }
    List p = ptrl   ;
    int j = 0;
    while (j<i && p!=NULL  ){
        j+=1;
        p=p->Next   ;
    }
    if ( j ==i ) {
        return p ;
    }
    return NULL;
}

List Find(ElementType x, List ptrl) {
    List p = ptrl ;
    while (p!=NULL && p->Data !=x){
        p= p->Next;
    }
    return p  ;
}

List Insert( ElementType x, int i, List ptrl ) {
    if (i == 0 ){
        List h = (List) malloc(sizeof(struct LNode));
        h->Data = x ;
        h->Next = ptrl ;
        return h ;
    }

    List p = FindKth(i-1,ptrl) ;
    if (p == NULL){
        printf("参数i错误\n");
        return NULL;
    }

    List s = (List) malloc(sizeof(struct LNode));
    s->Data =x ;
    s->Next = p->Next;
    p->Next = s ;
    return ptrl;

}
List  Delete(int i , List ptrl){
    if (i == 0 ){
        List s = ptrl ;
        if (!ptrl) {
            free(s);
            return NULL;
        }
        ptrl = ptrl->Next    ;
        free(s);
        return ptrl ;
    }

    List p = FindKth(i-1,ptrl) ;
    if (p == NULL){
        printf("参数i错误\n");
        return NULL;
    }

    List s = p->Next ;
    p->Next = s->Next ;
    free(s);
    return ptrl;
}


void Print(List ptrl) {
   List  p= ptrl ;
   if (p == NULL){
       printf("p == NULL\n");
       return ;
   }
   while (p){
        printf("%d ", p ->Data);
        p=p->Next ;
    }
    printf("\n");
}


int main() {
    List ptrl;
    List index ;

    ptrl = MakeEmpty();
    ptrl = Insert(1,0,ptrl);
    ptrl = Insert(2,1,ptrl);
    ptrl = Insert(3,2,ptrl);
    ptrl = Insert(4,3,ptrl);
    //Insert(5,4,ptrl);
    // Insert(6,5,ptrl);
    //Insert(6,7,ptrl);
    Print(ptrl);
    index = Find(3,ptrl);
    printf("find %d in list index=%d\n ",3, index->Data);
    Print(ptrl);

    ptrl = Delete(0,ptrl);
    Print(ptrl);
    ptrl = Delete(2,ptrl);
    Print(ptrl);
    ptrl = Delete(0,ptrl);
    Print(ptrl);
    ptrl = Delete(0,ptrl);
    Print(ptrl);
    ptrl = Delete(0,ptrl);
    Print(ptrl);
    return 0;
}

