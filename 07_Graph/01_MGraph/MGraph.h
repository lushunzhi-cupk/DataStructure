/*=================================
 * ͼ������(�ڽӾ���)�洢��ʾ
 *
 * �����㷨: 7.1��7.2��7.4��7.5��7.6
 ==================================*/

#pragma once

#include <stdio.h>
#include <limits.h>     // �ṩ��INT_MAX
#include <string.h>     // �ṩmemset��strcmp ԭ��
#include <stdarg.h>     // �ṩ��va_list��va_start��va_arg��va_end
#include "Status.h"     //**��01 ����**//
#include "LinkQueue.h"  //**��03 ջ�Ͷ���**//


#define INFINITE INT_MAX//���ֵ��
#define MAX_VERTEX_NUM 20//��󶥵����

typedef enum {DG,DN,UDG,UDN} GraphKind;//{����ͼ��������������ͼ��������}


// ��������
typedef char VertexType;

/*
 * �����ϵ����
 *
 * ����Ȩͼ�У���ֵͨ��Ϊ0��1����ʾ�������Ƿ�ֱ����ͨ��
 * ����Ȩͼ�У���ֵͨ��ΪȨֵ��
 */
typedef int VRType;

// �ߵ���ظ�����Ϣ
typedef struct {
	char info[];
}InfoType;

// �ߵ�����
typedef struct ArcCell {
	VRType adj;// �����ϵ������Ȩͼ����Ȩͼ�еĺ��岻ͬ
	InfoType* info; //ÿ�����Ͽ����и�����Ϣinfo
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

// ͼ������(�ڽӾ���)�洢��ʾ���Ͷ��� 
typedef struct {
	VertexType vexs[MAX_VERTEX_NUM];// ��������
	AdjMatrix arcs;	// �ڽӾ���
	int vexnum, arcnum;//ͼ�ĵ�ǰ�������ͻ���
	GraphKind kind;//ͼ�������־
}MGraph;


// ���ʱ�־���飬��¼���ʹ��Ķ���
static Boolean visited[MAX_VERTEX_NUM];

// ��������
static Status(*VisitFunc)(VertexType e);


// ��/�����Ƿ���ڸ�����Ϣ
extern Boolean IncInfo;

/*
 * �㷨7.1
 */
Status CreateGraph(MGraph* G, char* path[]);

/*
 * ��������ͼ
 */
Status CreateDG(MGraph* G);

/*
 * ����������
 */
Status CreateDN(MGraph* G);

/*
 * ��������ͼ
 */
Status CreateUDG(MGraph* G);

/*
 * �㷨7.2
 *
 * ����������
 */
Status CreateUDN(MGraph* G);

/*
 * ¼��ߵ���ظ�����Ϣ
 */
static void Input(InfoType** info);

/*
 * ����
 *
 * �ڽӾ���洢��ͼ�����ͷ��ڴ棬ֻ��������ر������ɡ�
 */
Status DestroyGraph(MGraph* G);

/*
 * ����
 *
 * ���ض���u��ͼ/���е�λ��
 */
int LocateVex(MGraph G, VertexType e);

/*
 * ȡֵ
 *
 * ��������v���Ķ���ֵ
 */
VertexType GetVex(MGraph G, int v);

/*
 * ��ֵ
 *
 * ������v��ֵΪvalue
 */
Status PutVex(MGraph* G, VertexType v, VertexType value);

/*
 * �׸��ڽӵ�
 *
 * ���ض���v���׸��ڽӵ�
 */
int FirstAdjVex(MGraph G, VertexType v);

/*
 * ��һ���ڽӵ�
 *
 * ���ض���v��(�����w��)��һ���ڽӵ�
 */
int NextAdjVex(MGraph G, VertexType v, VertexType w);

/*
 * ���붥��
 *
 * ��ָ���Ķ���v׷�ӵ����㼯�У�δ�����ö�������������Ĺ�ϵ
 */
Status InsertVex(MGraph* G, VertexType v);

/*
 * ɾ������
 *
 * �Ӷ��㼯��ɾ��ָ���Ķ���v��ע����Ҫ������صĶ����ϵ
 */
Status DeleteVex(MGraph* G, VertexType v);

/*
 * �����/��<v, w>
 *
 * �����ǰͼ/��������ģ������һ������Ҫ�������������ϵ������������ֻ��һ��
 *
 * ����ͼ��˵�������ڿɱ�������г���/���ĸ�����Ϣ��
 * ��������˵�������ڿɱ�����������г���/����Ȩֵ�Լ�������Ϣ��
 */
Status InsertArc(MGraph* G, VertexType v, VertexType w, ...);

/*
 * ɾ����/��<v, w>
 *
 * ��ɾ��ֻ�Ǹ��±�/������ͨ��ϵ
 */
Status DeleteArc(MGraph* G, VertexType v, VertexType w);

/*
 * �㷨7.4
 *
 * ������ȱ���(�˴������ݹ�ʵ��)
 */
void DFSTraverse(MGraph G, Status(Visit)(VertexType));

/*
 * �㷨7.5
 *
 * ������ȱ������ĺ���
 */
void DFS(MGraph G, int v);

/*
 * �㷨7.6
 *
 * ������ȱ���(�˴���������ʵ��)
 */
void BFSTraverse(MGraph G, Status(Visit)(VertexType));

/*
 * ��ͼ�λ���ʽ�����ǰ�ṹ
 *
 * ע����ͼ/���У�ʹ��"-"����ʾ�����㲻ֱ����ͨ
 */
void PrintGraph(MGraph G);



void Visit(VertexType v);