#include "SqList.h"
int main(){
    SqList L;
    InitList(&L);
    ListInsert(&L,1,0);
//    ListInsert(&L,2,1);
//    ListInsert(&L,3,2);

    ElemType e;
    ElemType e2;
    ElemType *pre_e;
    PriorElem(L,3,&e);
    printf("%d",e);
//    NextElem(L,1,&e2);
//    printf("%d",e2);

}