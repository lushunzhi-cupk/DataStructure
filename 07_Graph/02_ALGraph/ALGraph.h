#pragma once
#include <stdio.h>
#include <stdlib.h> 						//�ṩmalloc��realloc��free��exit��rand��srandԭ�� 
#include <stdarg.h>							//�ṩ��va_list��va_start��va_arg��va_end
#include "Status.h"							//**��01 ����**//
#define MAX_VERTEX_NUM 20



typedef char VertexType ;

// ͼ������
typedef enum {
	DG,     // 0-����ͼ
	DN,     // 1-������(��Ȩֵ)
	UDG,    // 2-����ͼ
	UDN     // 3-������(��Ȩֵ)
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
 * ����
 *
 */
Status CreateGraph(ALGraph* G);

/*
 * ��������ͼ
 */
/*static*/ Status CreateDG(ALGraph* G);

/*
 * ����������
 */
//static Status CreateDN(ALGraph* G);

/*
 * ��������ͼ
 */
//static Status CreateUDG(ALGraph* G);

/*
 * ����������
 */
//static Status CreateUDN(ALGraph* G);

/*
 * ¼���/������ظ�����Ϣ
 */
static void Input(ALGraph G, InfoType** info);

/*
 * ����
 *
 * �ڽӱ�洢��ͼ��Ҫ�ͷ��ڴ档
 */
Status DestroyGraph(ALGraph* G);

/*
 * ����
 *
 * ���ض���u��ͼ/���е�λ��
 */
int LocateVex(ALGraph G, VertexType u);

/*
 * ȡֵ
 *
 * ��������v���Ķ���ֵ
 */
VertexType GetVex(ALGraph G, int v);

/*
 * ��ֵ
 *
 * ������v��ֵΪvalue
 */
Status PutVex(ALGraph* G, VertexType v, VertexType value);

/*
 * �׸��ڽӵ�
 *
 * ���ض���v���׸��ڽӵ�
 */
int FirstAdjVex(ALGraph G, VertexType v);

/*
 * ��һ���ڽӵ�
 *
 * ���ض���v��(�����w��)��һ���ڽӵ�
 */
int NextAdjVex(ALGraph G, VertexType v, VertexType w);

/*
 * ���붥��
 *
 * ��ָ���Ķ���v׷�ӵ����㼯�У�δ�����ö�������������Ĺ�ϵ
 */
Status InsertVex(ALGraph* G, VertexType v);

/*
 * ɾ������
 *
 * �Ӷ��㼯��ɾ��ָ���Ķ���v��ע����Ҫ������صĶ����ϵ
 */
Status DeleteVex(ALGraph* G, VertexType v);

/*
 * ����һ����/�����(�����ڲ�ʹ��)
 */
static ArcNode* newArcNodePtr(int adjvex, ArcNode* nextarc, InfoType* info);

/*
 * �����/��<v, w>
 *
 * �����ǰͼ/��������ģ������һ������Ҫ�������������ϵ������������ֻ��һ��
 * ����ͼ/����˵�������ڿɱ�������г���/���ĸ�����Ϣ��
 *
 * ע���˴����յĲ�����MGraph��Щ��һ�������ĸ�����Ϣ�а����˸�����/����Ȩֵ��
 */
Status InsertArc(ALGraph* G, VertexType v, VertexType w, ...);

/*
 * ɾ����/��<v, w>
 */
Status DeleteArc(ALGraph* G, VertexType v, VertexType w);

/*
 * ������ȱ���(�˴������ݹ�ʵ��)
 */
void DFSTraverse(ALGraph G, Status(Visit)(VertexType));

/*
 * ������ȱ������ĺ���
 */
static void DFS(ALGraph G, int v);

/*
 * ������ȱ���(�˴���������ʵ��)
 */
void BFSTraverse(ALGraph G, Status(Visit)(VertexType));

/*
 * ��ͼ�λ���ʽ�����ǰ�ṹ
 */
void PrintGraph(ALGraph G);