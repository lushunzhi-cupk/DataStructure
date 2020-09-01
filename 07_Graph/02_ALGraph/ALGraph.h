#pragma once
#include <stdio.h>
#include <stdlib.h> 						//提供malloc、realloc、free、exit、rand、srand原型 
#include <stdarg.h>							//提供宏va_list、va_start、va_arg、va_end
#include "Status.h"							//**▲01 绪论**//
#define MAX_VERTEX_NUM 20



typedef char VertexType ;

// 图的类型
typedef enum {
	DG,     // 0-有向图
	DN,     // 1-有向网(带权值)
	UDG,    // 2-无向图
	UDN     // 3-无向网(带权值)
} GraphKind;


typedef struct {
	char info[];
}InfoType;

typedef struct ArcNode {
	int adjvex;
	int weight;
	struct ArcNode* nextarc;
	InfoType* info;
}ArcNode;

typedef struct VNode {
	VertexType data;
	ArcNode* firstarc;
}VNode,AdjList[MAX_VERTEX_NUM];

typedef struct {
	AdjList vertices;
	int vexnum, arcnum;
	int kind;
}ALGraph;


/*
 * 创建
 *
 */
Status CreateGraph(ALGraph* G);

/*
 * 构造有向图
 */
/*static*/ Status CreateDG(ALGraph* G);

/*
 * 构造有向网
 */
//static Status CreateDN(ALGraph* G);

/*
 * 构造无向图
 */
//static Status CreateUDG(ALGraph* G);

/*
 * 构造无向网
 */
//static Status CreateUDN(ALGraph* G);

/*
 * 录入边/弧的相关附加信息
 */
static void Input(ALGraph G, InfoType** info);

/*
 * 销毁
 *
 * 邻接表存储的图需要释放内存。
 */
Status DestroyGraph(ALGraph* G);

/*
 * 查找
 *
 * 返回顶点u在图/网中的位置
 */
int LocateVex(ALGraph G, VertexType u);

/*
 * 取值
 *
 * 返回索引v处的顶点值
 */
VertexType GetVex(ALGraph G, int v);

/*
 * 赋值
 *
 * 将顶点v赋值为value
 */
Status PutVex(ALGraph* G, VertexType v, VertexType value);

/*
 * 首个邻接点
 *
 * 返回顶点v的首个邻接点
 */
int FirstAdjVex(ALGraph G, VertexType v);

/*
 * 下一个邻接点
 *
 * 返回顶点v的(相对于w的)下一个邻接点
 */
int NextAdjVex(ALGraph G, VertexType v, VertexType w);

/*
 * 插入顶点
 *
 * 将指定的顶点v追加到顶点集中，未建立该顶点与其他顶点的关系
 */
Status InsertVex(ALGraph* G, VertexType v);

/*
 * 删除顶点
 *
 * 从顶点集中删除指定的顶点v，注意需要更新相关的顶点关系
 */
Status DeleteVex(ALGraph* G, VertexType v);

/*
 * 构造一个边/弧结点(仅限内部使用)
 */
static ArcNode* newArcNodePtr(int adjvex, ArcNode* nextarc, InfoType* info);

/*
 * 插入边/弧<v, w>
 *
 * 如果当前图/网是无向的，则插入一条弧需要增加两个顶点关系，但弧的数量只增一。
 * 对于图/网来说，可以在可变参数中列出边/弧的附加信息。
 *
 * 注：此处接收的参数与MGraph有些不一样：网的附加信息中包含了各条边/弧的权值。
 */
Status InsertArc(ALGraph* G, VertexType v, VertexType w, ...);

/*
 * 删除边/弧<v, w>
 */
Status DeleteArc(ALGraph* G, VertexType v, VertexType w);

/*
 * 深度优先遍历(此处借助递归实现)
 */
void DFSTraverse(ALGraph G, Status(Visit)(VertexType));

/*
 * 深度优先遍历核心函数
 */
static void DFS(ALGraph G, int v);

/*
 * 广度优先遍历(此处借助队列实现)
 */
void BFSTraverse(ALGraph G, Status(Visit)(VertexType));

/*
 * 以图形化形式输出当前结构
 */
void PrintGraph(ALGraph G);