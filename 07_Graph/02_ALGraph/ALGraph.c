#include"ALGraph.h"
//Status CreateGraph(ALGraph *G) {
//	scanf("%d", G->kind);
//	switch (G->kind)
//	{
//	case DG:
//		return CreateDG(G);
//	case DN:
//		return CreateUDG(G);
//	case UDG:
//		return CreateUDG(G);
//	case UDN:
//		return CreateUDN(G);
//	default:
//		break;
//	}
//
//}


Status CreateDG(ALGraph *G) {
	int IncInfo;
	printf("����������Ƿ�������������Ϣ(0-û�� 1-��)\n");
	scanf("%d%*c", &(IncInfo));
	
	printf("������ͼ�Ľ������\n");
	scanf("%d%*c",&G->vexnum);
	if (G->vexnum>MAX_VERTEX_NUM) {
		printf("�����������");
		return ERROR;
	}
	printf("������ͼ�ıߵ�����\n");
	scanf("%d%*c",&G->arcnum);
	if (G->arcnum>G->vexnum*(G->vexnum-1)) {
		printf("�����������ͼ������������%d������%d����㣬���������%d����", G->vexnum * (G->vexnum - 1),G->vexnum, G->vexnum * (G->vexnum - 1));
	}
	printf("������ͼ������\n");
	scanf("%d%*c", &G->kind);


	ArcNode* r[MAX_VERTEX_NUM + 1];
	for (int i = 1; i < G->vexnum+1; i++){
		printf("����������ÿ������ֵ\n");
		scanf("%c%*c",&(G->vertices[i].data));
		G->vertices[i].firstarc = NULL;
		r[i] = NULL;

	}

	for (int k = 1; k < G->arcnum+1; k++) {
		VertexType v1, v2;
		printf("�������%d�����Ļ�β���",k);
		scanf("%c%*c", &v1);
		printf("�������%d�����Ļ�ͷ���", k);
		scanf("%c%*c", &v2);
		int i = LocateVex(*G, v1);
		int j = LocateVex(*G, v2);
		if (!i || !j||i==j)
		{
			printf("����Ľ���������������");
			k--;
			continue;
		}
		ArcNode* p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = j;
		p->weight = 1;//ͼ�Ļ���Ȩ��Ϊ1
		p->nextarc = NULL;
		if (IncInfo==1) {
			scanf("%c%*c",&p->info);
		}
		if (r[i] == NULL) {
			G->vertices[i].firstarc = p;
		}
		else {
			r[i]->nextarc = p;
		}
		r[i] = p;
	}


}

Status DestroyGraph(ALGraph* G) {
	ArcNode *p,*q;
	for (int i = 1; i < G->vexnum+1;i++) {
		p = G->vertices[i].firstarc;
		while (p) {
			q = p->nextarc;
			free(p);
			p = q;
		}
	}
	return OK;
}

int LocateVex(ALGraph G, VertexType u) {
	for (int i =0; i < G.vexnum+1;i++) {
		if (G.vertices[i].data==u) {
			return i;
		}
	}
	return INFEASIBLE;
}