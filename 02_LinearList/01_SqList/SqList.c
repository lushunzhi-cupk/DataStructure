/*=============================
 * ���Ա��˳��洢�ṹ��˳���
 *
 * �����㷨: 2.3��2.4��2.5��2.6
 =============================*/

#include"SqList.h"
/*
 * �㷨2.3
 *
 * ��ʼ��
 *
 * ��ʼ���ɹ��򷵻�OK�����򷵻�ERROR��
 *
 * */
Status InitList(SqList* L) {
	//����һ���յ����Ա�L��
	L->elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L->elem)exit(OVERFLOW); //�洢����ʧ��
	L->length = 0; //�ձ���Ϊ0
	L->listsize = LIST_INIT_SIZE; //��ʼ�洢����
	return OK;
}//InitList

/*
 * ��ʼ���������Ա�L�Ѵ���
 *
 * ����������������Ա�L
 *
 * */
Status DestroyList(SqList* L) {
	//ȷ�����Ա�ṹ����
	if (L == NULL || L->elem == NULL) {
		return ERROR;
	}
	//�ͷ�˳����ַ��ָ����ڴ�
	free(L->elem);
	//���ַָ���
	L->elem = NULL;
	//��˳���ĵ�ǰ����Ϊ0�ͷ���Ĵ洢����
	L->length = 0;
	L->listsize = 0;	
}

/*
 * ��ʼ���������Ա�L�Ѵ���
 *
 * �����������L����Ϊ�ձ�
 *
 * */
Status ClearList(SqList* L){
    //ȷ�����Ա�ṹ���ڣ�����L->elem == NULL����Ҫ
    if(L==NULL){
        return ERROR;
    }
    L->length=0;
    return OK;
}

/*
 * ��ʼ���������Ա��Ѿ�����
 *
 * �����������LΪ�ձ��򷵻�TRUE,���򷵻�FALSE
 *
 * */
Status ListEmpty(SqList L){
   return L.length==0?TRUE:FALSE;
}

/*
 * ��ʼ���������Ա�L�Ѵ���
 *
 * �������������L������Ԫ�صĸ���
 *
 * */
int ListLength(SqList L){
    return L.length;
}

/*
 * ��ʼ���������Ա�L�Ѵ��ڣ�1<=i<=ListLength(L).
 *
 * �����������e����L�е�i������Ԫ��
 * */
Status GetElem(SqList L,int i,ElemType *e){
    //�ж�λ���Ƿ�Ϸ�
    if(i<1&&i>L.length){
        return ERROR;
    }
    *e=L.elem[i-1];
    return OK;
}

/*
 * ��ʼ���������Ա��Ѵ���,compare()������Ԫ���ж�������
 *
 * �������������L�е�1����Ԫ������compare()��ϵ��Ԫ�ص�λ��������������Ԫ�ز����ڣ��򷵻�ֵΪ0
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
 * ��ʼ���������Ա�L�Ѵ���
 *
 * �����������cur_e��L������Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ�����������ʧ�ܣ�pre_e�޶���
 *
 * */
Status PriorElem(SqList L, ElemType cur_e, ElemType* pre_e){
    // ȷ��˳���ṹ����
    if(L.elem==NULL){
        return ERROR;
    }
    //ȷ�����ٰ�������Ԫ��
    if(L.elem<2){
        return ERROR;
    }
    //iΪ��������0��ʼ
    int i=0;
    // �ӵ�1��Ԫ�ؿ�ʼ������cur_e��λ��
    while(i<L.length&&cur_e!=L.elem[i]){
        ++i;
    }
    // ���cur_e���׸�Ԫ��(û��ǰ��)������û�ҵ�Ԫ��cur_e������ERROR
    if(i==0||i>=L.length){
        return ERROR;
    }
    //��i��ǰ����ֵ��*pre_e
    *pre_e=L.elem[i-1];
}

/*
 * ��ʼ���������Ա�L�Ѵ��ڡ�
 *
 * ��cur_e��L������Ԫ�أ��Ҳ������һ��������next_e�������ĺ�̣����򷵻�������ʧ�ܣ�next_e�޶���
 *
 * */
Status NextElem(SqList L,ElemType cur_e,ElemType *next_e){
    // ȷ��˳���ṹ����
    if(L.elem==NULL){
        return ERROR;
    }
    //ȷ�����ٰ�������Ԫ��
    if(L.elem<2){
        return ERROR;
    }
    //iΪ��������0��ʼ
    int i=0;
    // �ӵ�1��Ԫ�ؿ�ʼ������cur_e��λ��
    while(i<L.length&&cur_e!=L.elem[i]){
        ++i;
    }
    // ���cur_e�����1��Ԫ��(û�к��)������û�ҵ�Ԫ��cur_e������ERROR
    if(i>=L.length-1){
        return ERROR;
    }
    //��i��ǰ����ֵ��*pre_e
    *next_e=L.elem[i+1];
}

/*
 * �㷨2.4
 *
 * ��ʼ���������Ա�L�Ѵ��ڡ�
 *
 * �����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e,L�ĳ��ȼ�1��
 * */
Status ListInsert(SqList *L,int i,ElemType e){
    if(i<1||i>L->length+1) return ERROR; //iֵ���Ϸ�
    
    if(L->length>=L->listsize){ //��ǰ�洢�ռ����������ӷ���
        ElemType *newbase=(ElemType*)realloc(L->elem,(L->listsize+LISTINCREMENT)*sizeof(ElemType));
        if (!newbase)exit(OVERFLOW);//�洢����ʧ��
        L->elem = newbase;//�»�ַ
        L->listsize += LISTINCREMENT;//���Ӵ洢����
    }
   
    ElemType *q=&L->elem[i-1]; //qΪ����λ��
    ElemType*p=NULL;
    for(p=&(L->elem[L->length-1]);p>=q;--p) *(p+1)=*p; //����λ�ü�֮���Ԫ������
    *q=e; //����e
    ++L->length; //����1
    return OK;
}
/*
 * �㷨2.4
 *
 * ��ʼ���������Ա�L�Ѵ����ҷǿգ�1<=i<=ListLength(L)
 *
 * */
ListDelete(SqList *L,int i,ElemType *e){
    //��˳�����Ա�L��ɾ����i��Ԫ�أ�����e������ֵ
    //i�ĺϷ�ֵΪ1<=i<=ListLength(L)
    if(i<1||i>L->length) return ERROR; //iֵ���Ϸ�
    ElemType *p=&(L->elem[i-1]); //pΪ��ɾ��Ԫ�ص�λ��
    *e=*p; //��ɾ��Ԫ�ص�ֵ��ֵ��e
    ElemType *q=L->elem+L->length-1; //��βԪ�ص�λ��
    for(++p;p<=q;++p){
        *(p-1)=*p; //��ɾ��Ԫ��֮���Ԫ������
    }
    --L->length; //���ȼ�1
    return OK;
}//ListDelete

