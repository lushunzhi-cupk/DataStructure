/*=================================
 * 图的数组(邻接矩阵)存储表示
 *
 * 包含算法: 7.1、7.2、7.4、7.5、7.6
 ==================================*/

#pragma once

#include <stdio.h>
#include <limits.h>     // 提供宏INT_MAX
#include <string.h>     // 提供memset、strcmp 原型
#include <stdarg.h>     // 提供宏va_list、va_start、va_arg、va_end
#include "Status.h"     //**▲01 绪论**//
#include "LinkQueue.h"  //**▲03 栈和队列**//


#define INFINITE INT_MAX//最大值∞
#define MAX_VERTEX_NUM 20//最大顶点个数

typedef enum {DG,DN,UDG,UDN} GraphKind;//{有向图，有向网，无向图，无向网}


// 顶点类型
typedef char VertexType;

/*
 * 顶点关系类型
 *
 * 在无权图中，该值通常为0或1，表示两顶点是否直接连通；
 * 在有权图中，该值通常为权值。
 */
typedef int VRType;

// 边的相关附加信息
typedef struct {
	char info[];
}InfoType;

// 边的类型
typedef struct ArcCell {
	VRType adj;// 顶点关系，在有权图跟无权图中的含义不同
	InfoType* info; //每条边上可能有附加信息info
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

// 图的数组(邻接矩阵)存储表示类型定义 
typedef struct {
	VertexType vexs[MAX_VERTEX_NUM];// 顶点向量
	AdjMatrix arcs;	// 邻接矩阵
	int vexnum, arcnum;//图的当前顶点数和弧数
	GraphKind kind;//图的种类标志
}MGraph;


// 访问标志数组，记录访问过的顶点
static Boolean visited[MAX_VERTEX_NUM];

// 函数变量
static Status(*VisitFunc)(VertexType e);


// 边/弧上是否存在附加信息
extern Boolean IncInfo;

/*
 * 算法7.1
 */
Status CreateGraph(MGraph* G, char* path[]);

/*
 * 构造有向图
 */
Status CreateDG(MGraph* G);

/*
 * 构造有向网
 */
Status CreateDN(MGraph* G);

/*
 * 构造无向图
 */
Status CreateUDG(MGraph* G);

/*
 * 算法7.2
 *
 * 构造无向网
 */
Status CreateUDN(MGraph* G);

/*
 * 录入边的相关附加信息
 */
static void Input(InfoType** info);

/*
 * 销毁
 *
 * 邻接矩阵存储的图无需释放内存，只需重置相关遍历即可。
 */
Status DestroyGraph(MGraph* G);

/*
 * 查找
 *
 * 返回顶点u在图/网中的位置
 */
int LocateVex(MGraph G, VertexType e);

/*
 * 取值
 *
 * 返回索引v处的顶点值
 */
VertexType GetVex(MGraph G, int v);

/*
 * 赋值
 *
 * 将顶点v赋值为value
 */
Status PutVex(MGraph* G, VertexType v, VertexType value);

/*
 * 首个邻接点
 *
 * 返回顶点v的首个邻接点
 */
int FirstAdjVex(MGraph G, VertexType v);

/*
 * 下一个邻接点
 *
 * 返回顶点v的(相对于w的)下一个邻接点
 */
int NextAdjVex(MGraph G, VertexType v, VertexType w);

/*
 * 插入顶点
 *
 * 将指定的顶点v追加到顶点集中，未建立该顶点与其他顶点的关系
 */
Status InsertVex(MGraph* G, VertexType v);

/*
 * 删除顶点
 *
 * 从顶点集中删除指定的顶点v，注意需要更新相关的顶点关系
 */
Status DeleteVex(MGraph* G, VertexType v);

/*
 * 插入边/弧<v, w>
 *
 * 如果当前图/网是无向的，则插入一条弧需要增加两个顶点关系，但弧的数量只增一。
 *
 * 对于图来说，可以在可变参数中列出边/弧的附加信息；
 * 对于网来说，可以在可变参数中依次列出边/弧的权值以及附加信息。
 */
Status InsertArc(MGraph* G, VertexType v, VertexType w, ...);

/*
 * 删除边/弧<v, w>
 *
 * 此删除只是更新边/弧的连通关系
 */
Status DeleteArc(MGraph* G, VertexType v, VertexType w);

/*
 * 算法7.4
 *
 * 深度优先遍历(此处借助递归实现)
 */
void DFSTraverse(MGraph G, Status(Visit)(VertexType));

/*
 * 算法7.5
 *
 * 深度优先遍历核心函数
 */
void DFS(MGraph G, int v);

/*
 * 算法7.6
 *
 * 广度优先遍历(此处借助队列实现)
 */
void BFSTraverse(MGraph G, Status(Visit)(VertexType));

/*
 * 以图形化形式输出当前结构
 *
 * 注：在图/网中，使用"-"来表示两顶点不直接连通
 */
void PrintGraph(MGraph G);



void Visit(VertexType v);