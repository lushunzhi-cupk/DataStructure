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
	printf("请输入边上是否有其他额外信息(0-没有 1-有)\n");
	scanf("%d%*c", &(IncInfo));
	
	printf("请输入图的结点数量\n");
	scanf("%d%*c",&G->vexnum);
	if (G->vexnum>MAX_VERTEX_NUM) {
		printf("结点数量过多");
		return ERROR;
	}
	printf("请输入图的边的数量\n");
	scanf("%d%*c",&G->arcnum);
	if (G->arcnum>G->vexnum*(G->vexnum-1)) {
		printf("您输入的有向图弧的数量大于%d条，有%d个结点，所以最多有%d个弧", G->vexnum * (G->vexnum - 1),G->vexnum, G->vexnum * (G->vexnum - 1));
	}
	printf("请输入图的类型\n");
	scanf("%d%*c", &G->kind);


	ArcNode* r[MAX_VERTEX_NUM + 1];
	for (int i = 1; i < G->vexnum+1; i++){
		printf("请依次输入每条结点的值\n");
		scanf("%c%*c",&(G->vertices[i].data));
		G->vertices[i].firstarc = NULL;
		r[i] = NULL;

	}

	for (int k = 1; k < G->arcnum+1; k++) {
		VertexType v1, v2;
		printf("请输入第%d条弧的弧尾结点",k);
		scanf("%c%*c", &v1);
		printf("请输入第%d条弧的弧头结点", k);
		scanf("%c%*c", &v2);
		int i = LocateVex(*G, v1);
		int j = LocateVex(*G, v2);
		if (!i || !j||i==j)
		{
			printf("输入的结点错误，请重新输入");
			k--;
			continue;
		}
		ArcNode* p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = j;
		p->weight = 1;//图的弧的权重为1
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