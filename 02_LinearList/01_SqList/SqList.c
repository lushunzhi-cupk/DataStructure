/*=============================
 * 线性表的顺序存储结构（顺序表）
 *
 * 包含算法: 2.3、2.4、2.5、2.6
 =============================*/

#include"SqList.h"
/*
 * 算法2.3
 *
 * 初始化
 *
 * 初始化成功则返回OK，否则返回ERROR。
 *
 * */
Status InitList(SqList* L) {
	//构造一个空的线性表L。
	L->elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L->elem)exit(OVERFLOW); //存储分配失败
	L->length = 0; //空表长度为0
	L->listsize = LIST_INIT_SIZE; //初始存储容量
	return OK;
}//InitList

/*
 * 初始条件：线性表L已存在
 *
 * 操作结果：销毁线性表L
 *
 * */
Status DestroyList(SqList* L) {
	//确保线性表结构存在
	if (L == NULL || L->elem == NULL) {
		return ERROR;
	}
	//释放顺序表基址所指向的内存
	free(L->elem);
	//令基址指向空
	L->elem = NULL;
	//令顺序表的当前长度为0和分配的存储容量
	L->length = 0;
	L->listsize = 0;	
}

/*
 * 初始条件：线性表L已存在
 *
 * 操作结果：将L重置为空表
 *
 * */
Status ClearList(SqList* L){
    //确保线性表结构存在，但是L->elem == NULL不需要
    if(L==NULL){
        return ERROR;
    }
    L->length=0;
    return OK;
}

/*
 * 初始条件：线性表已经存在
 *
 * 操作结果：若L为空表，则返回TRUE,否则返回FALSE
 *
 * */
Status ListEmpty(SqList L){
   return L.length==0?TRUE:FALSE;
}

/*
 * 初始条件：线性表L已存在
 *
 * 操作结果：返回L中数据元素的个数
 *
 * */
int ListLength(SqList L){
    return L.length;
}

/*
 * 初始条件：线性表L已存在，1<=i<=ListLength(L).
 *
 * 操作结果：用e返回L中第i个数据元素
 * */
Status GetElem(SqList L,int i,ElemType *e){
    //判断位置是否合法
    if(i<1&&i>L.length){
        return ERROR;
    }
    *e=L.elem[i-1];
    return OK;
}

/*
 * 初始条件：线性表已存在,compare()是数据元素判定函数。
 *
 * 操作结果：返回L中第1个与元素满足compare()关系的元素的位序。若这样的数据元素不存在，则返回值为0
 *
 * */
int  LocateElem(SqList L,ElemType e,Status (compare)(ElemType e1,ElemType e2)){
    int i=0;
    ElemType *p=L.elem;
    if(L.elem==NULL) return ERROR;
    while(i<L.length&&!compare(*p++,e)){
        ++i;
    }
    if(i < L.length) {
        return i+1;
    } else {
        return 0;
    }
}

/*
 * 初始条件：线性表L已存在
 *
 * 操作结果：若cur_e是L的数据元素，且不是第一个，则用pre_e返回他的前驱，否则操作失败，pre_e无定义
 *
 * */
Status PriorElem(SqList L, ElemType cur_e, ElemType* pre_e){
    // 确保顺序表结构存在
    if(L.elem==NULL){
        return ERROR;
    }
    //确保最少包含两个元素
    if(L.elem<2){
        return ERROR;
    }
    //i为索引，从0开始
    int i=0;
    // 从第1个元素开始，查找cur_e的位置
    while(i<L.length&&cur_e!=L.elem[i]){
        ++i;
    }
    // 如果cur_e是首个元素(没有前驱)，或者没找到元素cur_e，返回ERROR
    if(i==0||i>=L.length){
        return ERROR;
    }
    //把i的前驱的值给*pre_e
    *pre_e=L.elem[i-1];
}

/*
 * 初始条件：线性表L已存在。
 *
 * 若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继，否则返回他操作失败，next_e无定义
 *
 * */
Status NextElem(SqList L,ElemType cur_e,ElemType *next_e){
    // 确保顺序表结构存在
    if(L.elem==NULL){
        return ERROR;
    }
    //确保最少包含两个元素
    if(L.elem<2){
        return ERROR;
    }
    //i为索引，从0开始
    int i=0;
    // 从第1个元素开始，查找cur_e的位置
    while(i<L.length&&cur_e!=L.elem[i]){
        ++i;
    }
    // 如果cur_e是最后1个元素(没有后继)，或者没找到元素cur_e，返回ERROR
    if(i>=L.length-1){
        return ERROR;
    }
    //把i的前驱的值给*pre_e
    *next_e=L.elem[i+1];
}

/*
 * 算法2.4
 *
 * 初始条件：线性表L已存在。
 *
 * 操作结果：在L中第i个位置之前插入新的数据元素e,L的长度加1。
 * */
Status ListInsert(SqList *L,int i,ElemType e){
    if(i<1||i>L->length+1) return ERROR; //i值不合法
    
    if(L->length>=L->listsize){ //当前存储空间已满，增加分配
        ElemType *newbase=(ElemType*)realloc(L->elem,(L->listsize+LISTINCREMENT)*sizeof(ElemType));
        if (!newbase)exit(OVERFLOW);//存储分配失败
        L->elem = newbase;//新基址
        L->listsize += LISTINCREMENT;//增加存储容量
    }
   
    ElemType *q=&L->elem[i-1]; //q为插入位置
    ElemType*p=NULL;
    for(p=&(L->elem[L->length-1]);p>=q;--p) *(p+1)=*p; //插入位置及之后的元素右移
    *q=e; //插入e
    ++L->length; //表长增1
    return OK;
}
/*
 * 算法2.4
 *
 * 初始条件：线性表L已存在且非空，1<=i<=ListLength(L)
 *
 * */
ListDelete(SqList *L,int i,ElemType *e){
    //在顺序线性表L中删除第i个元素，并用e返回其值
    //i的合法值为1<=i<=ListLength(L)
    if(i<1||i>L->length) return ERROR; //i值不合法
    ElemType *p=&(L->elem[i-1]); //p为被删除元素的位置
    *e=*p; //被删除元素的值赋值给e
    ElemType *q=L->elem+L->length-1; //表尾元素的位置
    for(++p;p<=q;++p){
        *(p-1)=*p; //被删除元素之后的元素左移
    }
    --L->length; //长度减1
    return OK;
}//ListDelete

