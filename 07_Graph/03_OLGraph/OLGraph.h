#pragma once
#include<stdio.h>
#include<stdlib.h> //引入malloc
#include<Status.h>
#include<stdbool.h>
#define MAX_VERTEX_NUM 20
typedef char VertexType;
typedef char InfoType;

typedef enum { DG, DN, UDG, UDN } GraphKind;//{有向图，有向网，无向图，无向网}
typedef struct ArcBox {
	int tailvex, headvex; //该弧的尾和头结点的位置
	struct ArcBox* hlink, * tlink; //分别为弧头相同和弧尾相同的弧的链域
	InfoType* info; //该弧相关信息的指针
}ArcBox;

typedef struct VexNode {
	VertexType data;
	ArcBox* firstin, * firstout;
}VexNode;

typedef struct OLGraph {
	VexNode xlist[MAX_VERTEX_NUM];
	int vexnum, arcnum;
	int kind;
}OLGraph;

Status CreateDG(OLGraph* G);
int LocateVex(OLGraph G, VertexType u);
Status InsertArc(OLGraph* G, VertexType v, VertexType w);
ArcBox* newArcBoxPtr(int tailvex, int headvex, ArcBox* hlink, ArcBox* tlink, InfoType* info);
