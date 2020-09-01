/*=============================
 * 线性表的顺序存储结构（顺序表）
 *
 * 包含算法: 2.3、2.4、2.5、2.6
 =============================*/

#pragma once
#include<stdio.h>
#include<stdlib.h> // 提供malloc、realloc、free、exit原型
#include<Status.h> //**▲01 绪论**//

/* 顺序表元素类型定义 */
typedef int ElemType ;

/*线性的动态分配顺序存储结构*/
#define LIST_INIT_SIZE 100 //线性存储空间的初始分配量
#define LISTINCREMENT 10 //线性表存储空间的分配增量
typedef struct {
	ElemType* elem; //存储空间基址
	int length; //当前长度
	int listsize; //当前分配的存储空间容量(以sizeof(ElemType)为单位)
}SqList;


/*
 * 算法2.3
 *
 * 初始化
 *
 * 初始化成功则返回OK，否则返回ERROR。
 */
Status InitList(SqList* L);

/*
 * 销毁(结构)
 *
 * 释放顺序表所占内存。
 */
Status DestroyList(SqList* L);

/*
 * 置空(内容)
 *
 * 只是清理顺序表中存储的数据，不释放顺序表所占内存。
 */
Status ClearList(SqList* L);

/*
 * 初始条件：线性表已经存在
 *
 * 操作结果：若L为空表，则返回TRUE,否则返回FALSE
 *
 * */
Status ListEmpty(SqList L);

/*
 * 计数
 *
 * 返回顺序表包含的有效元素的数量。
 */
int ListLength(SqList L);

/*
 * 取值
 *
 * 获取顺序表中第i个元素，将其存储到e中。
 * 如果可以找到，返回OK，否则，返回ERROR。
 *
 *【备注】
 * 教材中i的含义是元素位置，从1开始计数，但这不符合编码的通用约定。
 * 通常，i的含义应该指索引，即从0开始计数。
 */
Status GetElem(SqList L, int i, ElemType* e);

/*
 * ████████ 算法2.6 ████████
 *
 * 查找
 *
 * 返回顺序表中首个与e满足Compare关系的元素位序。
 * 如果不存在这样的元素，则返回0。
 *
 *【备注】
 * 元素e是Compare函数第二个形参
 */
int LocateElem(SqList L, ElemType e, Status(Compare)(ElemType, ElemType));

/*
 * 前驱
 *
 * 获取元素cur_e的前驱，
 * 如果存在，将其存储到pre_e中，返回OK，
 * 如果不存在，则返回ERROR。
 */
Status PriorElem(SqList L, ElemType cur_e, ElemType* pre_e);

/*
 * 后继
 *
 * 获取元素cur_e的后继，
 * 如果存在，将其存储到next_e中，返回OK，
 * 如果不存在，则返回ERROR。
 */
Status NextElem(SqList L, ElemType cur_e, ElemType* next_e);

/*
 * ████████ 算法2.4 ████████
 *
 * 插入
 *
 * 向顺序表第i个位置上插入e，插入成功则返回OK，否则返回ERROR。
 *
 *【备注】
 * 教材中i的含义是元素位置，从1开始计数
 */
Status ListInsert(SqList* L, int i, ElemType e);

/*
 * ████████ 算法2.5 ████████
 *
 * 删除
 *
 * 删除顺序表第i个位置上的元素，并将被删除元素存储到e中。
 * 删除成功则返回OK，否则返回ERROR。
 *
 *【备注】
 * 教材中i的含义是元素位置，从1开始计数
 */
Status ListDelete(SqList* L, int i, ElemType* e);

/*
 * 遍历
 *
 * 用visit函数访问顺序表L
 */
void ListTraverse(SqList L, void (Visit)(ElemType));
