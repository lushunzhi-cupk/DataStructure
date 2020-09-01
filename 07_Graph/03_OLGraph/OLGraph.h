#pragma once
#include<stdio.h>
#include<stdlib.h> //����malloc
#include<Status.h>
#include<stdbool.h>
#define MAX_VERTEX_NUM 20
typedef char VertexType;
typedef char InfoType;

typedef enum { DG, DN, UDG, UDN } GraphKind;//{����ͼ��������������ͼ��������}
typedef struct ArcBox {
	int tailvex, headvex; //�û���β��ͷ����λ��
	struct ArcBox* hlink, * tlink; //�ֱ�Ϊ��ͷ��ͬ�ͻ�β��ͬ�Ļ�������
	InfoType* info; //�û������Ϣ��ָ��
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
