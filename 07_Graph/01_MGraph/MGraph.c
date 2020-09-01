/*=================================
 * ͼ������(�ڽӾ���)�洢��ʾ
 *
 * �����㷨: 7.1��7.2��7.4��7.5��7.6
 ==================================*/

#include"MGraph.h"  

Boolean IncInfo = TRUE;
/*
 * �㷨7.1
 */
CreateGraph(MGraph *G) {
	scanf_s("%d",G->kind);
	switch (G->kind)
	{
	case DG:
		return CreateDG(G);
	case DN:
		return CreateDN(G);
	case UDG:
		return CreateUDG(G);
	case UDN:
		return CreateUDN(G);
	default:
		return ERROR;
		break;
	}
}



/*
 * ��������ͼ
 */
Status CreateDG(MGraph *G) {
	G->kind = DG;
	ArcCell arcs = { 0,NULL };

	printf("����������ͼ�Ķ������");
	scanf("%d%*c", &G->vexnum);
	printf("����������ͼ�Ļ��ĸ���");
	scanf("%d%*c", &G->arcnum);
	if (G->arcnum < 0 || G->arcnum > G->vexnum * G->vexnum - 1) {
		printf("�ߵĸ������Ϸ��������˳�");
		return INFEASIBLE;
	}
	printf("�������Ƿ��������ıߵ���Ϣ(0-�������� 1-����)");
	scanf("%d%*c", &IncInfo);
	printf("�������������н��");
	for (int i = 0; i < G->vexnum; ++i) scanf("%c%*c", &G->vexs[i]);

	for (int i = 0; i < G->vexnum;i++) {
		for (int j = 0; j < G->vexnum;j++) {
			G->arcs[i][j] = arcs;
		}
	}

	for (int k = 0; k < G->arcnum;k++) {
		VertexType v1, v2;
	
		printf("�������%d��������Ӧ����������\n", k + 1);
		printf("�����뻡β����\n");
		scanf("%c%*c", &v1);
		printf("�����뻡ͷ����\n");
		scanf("%c%*c", &v2);
		int i = LocateVex(*G, v1);
		int j = LocateVex(*G, v2);
		if (i==-1||j==-1) {
			printf("��㲻����,�����½��������ߵ�����\n");
			k -= 1;
			continue;
		}
		if (G->arcs[i][j].adj == 1) {
			printf("���Ѿ����ڣ������½��������ߵ�����\n");
			k -= 1;
			continue;
		}
		if (IncInfo) Input(&(G->arcs[i][j].info));
		G->arcs[i][j].adj = 1;
	}
};//CreateDG




/*
 * ����������
 */
Status CreateDN(MGraph *G) {
	G->kind = DN;
	ArcCell arcs = { 0,NULL };
	printf("�������������Ķ������");
	scanf("%d%*c", &G->vexnum);
	printf("���������������ĸ���");
	scanf("%d%*c", &G->arcnum);
	if (G->arcnum < 0 || G->arcnum >G->vexnum * G->vexnum - 1) {
		printf("�ߵĸ������Ϸ�,�����˳�");
		exit(INFEASIBLE);
	}
	printf("����������ͼ�Ļ��Ƿ����������Ϣ (0-�������� 1-����)");
	scanf("%d%*c", &IncInfo);
	printf("�������������н��");
	for (int i = 0; i < G->vexnum; ++i) scanf("%c%*c", &G->vexs[i]);

	for (int i = 0; i < G->vexnum; ++i) {
		for (int j = 0; j < G->vexnum; ++j) {
			G->arcs[i][j] = arcs;
		}
	}
	for (int k = 0; k < G->arcnum; k++) {
		VertexType v1, v2;
		VRType w;

		printf("�������%d��������Ӧ�����������Լ�����֮�仡��ֵ\n", k + 1);
		printf("�����뻡β����\n");
		scanf("%c%*c", &v1);
		printf("�����뻡ͷ����\n");
		scanf("%c%*c", &v2);
		printf("��������������֮�仡��Ȩֵ\n");
		scanf("%d%*c", &w);
		int i = LocateVex(*G, v1);
		int j = LocateVex(*G, v2);
		if (i == -1 || j == -1) {
			printf("��㲻����,�����½��������ߵ�����\n");
			k -= 1;
			continue;
		}
		if (G->arcs[i][j].adj == 1) {
			printf("���Ѿ����ڣ������½��������ߵ�����\n");
			k -= 1;
			continue;
		}
		G->arcs[i][j].adj = w;
		if (IncInfo) Input(&(G->arcs[i][j].info));
	}
	return OK;
}//CreateDN


/*
 * ��������ͼ
 */
Status CreateUDG(MGraph* G) {
	G->kind = UDG;
	ArcCell arcs = { 0,NULL };


	printf("����������ͼ�Ķ������");
	scanf("%d%*c", &G->vexnum);
	printf("����������ͼ�Ļ��ĸ���");
	scanf("%d%*c", &G->arcnum);
	if (G->arcnum < 0 || G->arcnum >(G->vexnum * G->vexnum - 1)/2) {
		printf("�ߵĸ������Ϸ��������˳�");
		exit(INFEASIBLE);
	}
	printf("�������Ƿ��������ıߵ���Ϣ(0-�������� 1-����)");
	scanf("%d%*c", &IncInfo);
	printf("�������������н��");
	for (int i = 0; i < G->vexnum; ++i) scanf("%c%*c", &G->vexs[i]);

	for (int i = 0; i < G->vexnum; i++) {
		for (int j = 0; j < G->vexnum; j++) {
			G->arcs[i][j] = arcs;
		}
	}

	for (int k = 0; k < G->arcnum; k++) {
		VertexType v1, v2;

		printf("�������%d��������Ӧ����������\n", k + 1);
		printf("�������һ������\n");
		scanf("%c%*c", &v1);
		printf("�������һ������\n");
		scanf("%c%*c", &v2);
		int i = LocateVex(*G, v1);
		int j = LocateVex(*G, v2);
		if (i == -1 || j == -1) {
			printf("��㲻����,�����½��������ߵ�����\n");
			k -= 1;
			continue;
		}
		if (G->arcs[i][j].adj == 1) {
			printf("���Ѿ����ڣ������½��������ߵ�����\n");
			k -= 1;
			continue;
		}
		if (IncInfo) Input(&(G->arcs[i][j].info));
		G->arcs[i][j].adj = 1;
	}
};//CreateUDG


/*
 * ����������
 */
Status CreateUDN(MGraph *G) {
	G->kind = UDN;
	printf("�������������Ķ������\n");
	scanf("%d%*c",&G->vexnum);
//	printf(G->vexnum);
	printf("�������������ıߵĸ���\n");
	scanf("%d%*c",&G->arcnum);
//	printf(G->arcnum);
	if (G->arcnum < 0 || G->arcnum > (G->vexnum * G->vexnum - 1)/2) {
		printf("���������ߵĸ������Ϸ�,�����˳�");
		exit(INFEASIBLE);
	}
	printf("�������������Ļ��Ƿ����������Ϣ (0-�������� 1-����)\n");
	scanf("%d%*c", &IncInfo);
	printf("�������������н��\n");
	for (int i = 0; i < G->vexnum; ++i) scanf("%c%*c",&G->vexs[i]);

	for (int i = 0; i < G->vexnum; ++i){
		for (int j = 0; j < G->vexnum; ++j) {
			G->arcs[i][j].adj = INFINITE;
			G->arcs[i][j].info = NULL;
		}
	}
	for (int k = 0; k < G->arcnum;k++) {
		VertexType v1, v2;
		VRType w;

		printf("�������%d��������Ӧ�����������Լ�����֮��ߵ�Ȩֵ\n", k + 1);
		printf("�������һ������\n");
		scanf("%c%*c", &v1);
		printf("������ڶ�������\n");
		scanf("%c%*c", &v2);
		printf("��������������֮��ߵ�Ȩֵ\n");
		scanf("%d%*c", &w);
		int i = LocateVex(*G,v1);
		int j = LocateVex(*G,v2);
		if (i == -1 || j == -1) {
			printf("��㲻����,�����½��������ߵ�����\n");
			k -= 1;
			continue;
		}
		if (G->arcs[i][j].adj == 1) {
			printf("���Ѿ�����,�Ƿ����(0-��1-��)�������½��������ߵ�����\n");
			int select;
			scanf("%d",&select);
			if (select == 0) {
				printf("δ���±ߣ��˴β������ϣ������");

			}
			else {
				G->arcs[i][j].adj = w;
				printf("�Ѹ��±ߣ������");
			}
			k -= 1;
			continue;
		}
		G->arcs[i][j].adj= w;
		if (IncInfo) Input(&(G->arcs[i][j].info));
		G->arcs[j][i].adj = w;
	}
	return OK;
}//CreateUDN


/*
 * ¼��ߵ���ظ�����Ϣ
 */
void Input(InfoType **info) {
	scanf_s("%s", info);
}


/*
 * ����
 *
 * �ڽӾ���洢��ͼ�����ͷ��ڴ棬ֻ��������ر������ɡ�
 */
Status DestroyGraph(MGraph* G) {
	G->vexnum = 0;
	G->arcnum = 0;
	return SUCCESS;
}



/*
 * ����
 *
 * ���ض���u��ͼ/���е�λ��
 */
int LocateVex(MGraph G,VertexType v) {
	for (int i = 0; i < G.vexnum;i++) {
		if (G.vexs[i] == v) {
			return i;
		}
	}
	return INFEASIBLE;
}


/*
 * ȡֵ
 *
 * ��������v���Ķ���ֵ
 */
VertexType GetVex(MGraph G, int v) {
	if (v < 0 || v >= G.vexnum) {
		printf("��������");
		exit(ERROR);
	}
	return  G.vexs[v];
}

/*
 * ��ֵ
 *
 * ������v��ֵΪvalue
 */
Status PutVex(MGraph* G, VertexType v, VertexType value) {
	if (v < 0 || v >= G->vexnum) {
		printf("��������");
		exit(ERROR);
	}
	G->vexs[v] = value;
	return SUCCESS;
}


/*
 * �׸��ڽӵ�
 *
 * ���ض���v���׸��ڽӵ�
 */
int FirstAdjVex(MGraph G, VertexType v) {
	int vl = LocateVex(G, v);
	VRType adj=NULL;
	if (vl==INFEASIBLE) {
		return INFEASIBLE;
	}
	
	switch (G.kind)
	{
	case DG:
		adj = 0;
	case UDG:
		adj = 0;
	case DN:
		adj = INFINITE;
	case UDN:
		adj = INFINITE;
	default:
		break;
	}

	/*if (adj != 0 || adj != INFINITE) {
		exit(ERROR);
	};*/

	for (int j = 0; j < G.vexnum;j++) {
		if (G.arcs[vl][j].adj != adj) {
			return j;
		}
		
	}
	return INFEASIBLE;
}

/*
 * ��һ���ڽӵ�
 *
 * ���ض���v��(�����w��)��һ���ڽӵ�
 */
int NextAdjVex(MGraph G, VertexType v, VertexType w) {
	int vl = LocateVex(G, v);
	int wl = LocateVex(G, w);
	VRType adj=-1;
	if (INFEASIBLE == vl || INFEASIBLE == wl) {
		return INFEASIBLE;
	}

	switch (G.kind)
	{
	case DG:
		adj = 0;
	case UDG:
		adj = 0;
	case DN:
		adj = INFINITE;
	case UDN:
		adj = INFINITE;
	default:
		break;
	}

	if (adj != 0 && adj != INFINITE) {
		exit(ERROR);
	};

	for (int i = wl+1; i < G.vexnum;i++) {
		if (G.arcs[vl][i].adj != adj) {
			return i;
		}
	}
	return INFEASIBLE;
}

/*
 * ���붥��
 *
 * ��ָ���Ķ���v׷�ӵ����㼯�У�δ�����ö�������������Ĺ�ϵ
 */
Status InsertVex(MGraph* G, VertexType v) { 
	if (G->vexnum >= MAX_VERTEX_NUM) {
		return ERROR;
	}

	VRType adj=-1;

	switch (G->kind)
	{
	case DG:
		adj = 0;
	case DN:
		adj = INFINITE;
	case UDG:
		adj = 0;
	case UDN:
		adj = INFINITE;
	default:
		break;
	}

	G->vexs[G->vexnum] = v;
	G->vexnum++;
	for (int i = 0; i < G->vexnum;i++) {
		G->arcs[i][G->vexnum - 1].adj = adj;
		G->arcs[G->vexnum - 1][i].adj = adj;
	}
	return OK;
}

/*
 * ɾ������
 *
 * �Ӷ��㼯��ɾ��ָ���Ķ���v��ע����Ҫ������صĶ����ϵ
 */
Status DeleteVex(MGraph* G, VertexType v) {
	VRType adj = INFEASIBLE;
	int vl = LocateVex(*G,v);

	switch (G->kind)
	{
	case DG:
		adj = 0;
	case DN:
		adj = INFINITE;
	case UDG:
		adj = 0;
	case UDN:
		adj = INFINITE;
	default:
		break;
	}


	if(G->kind==DG||G->kind==DN){
		for (int i = 0; i < G->vexnum;i++) {
			if (G->arcs[i][vl].adj != adj)
				G->arcnum--;
			if (G->arcs[vl][i].adj != adj)
				G->arcnum--;
		}
	}else if (G->kind == UDG || G->kind == UDN) {
		for (int i = 0; i < G->vexnum; i++) {
			if (G->arcs[i][vl].adj != adj)
				G->arcnum--;
		}
	}
	else {
		return ERROR;
	}

	for (int i = vl+1; i < G->vexnum;i++) {
		for (int j = 0; j < G->vexnum;j++) {
			G->arcs[j][vl-1] = G->arcs[j][vl];
		}
	}

	for (int i = vl + 1; i <= G->vexnum;i++) {//����һ��
		for (int j = 0; j < G->vexnum;j++) {//����һ�������ÿһ��
			G->arcs[i - 1][j] = G->arcs[i][j];
		}
	}

	for (int i = vl + 1; i < G->vexnum;i++) {
		G->vexs[vl - 1] = G->vexs[vl];
	}
	G->vexnum--;
	return OK;
}


/*
 * �����/��<v, w>
 *
 * �����ǰͼ/��������ģ������һ������Ҫ�������������ϵ������������ֻ��һ��
 *
 * ����ͼ��˵�������ڿɱ�������г���/���ĸ�����Ϣ��
 * ��������˵�������ڿɱ�����������г���/����Ȩֵ�Լ�������Ϣ��
 */
Status InsertArc(MGraph* G, VertexType v, VertexType w, ...) {
	VRType adj = INFEASIBLE;
	switch (G->kind)
	{
	case DG:
		adj = 0;
	case DN:
		adj = INFINITE;
	case UDG:
		adj = 0;
	case UDN:
		adj = INFINITE;
	default:
		break;
	}
	Boolean overlay =FALSE;//Ĭ�ϲ�֧�ָ������
	printf("�������Ƿ�֧�ָ��ǲ���(0-��֧�� 1-֧��)");
	scanf("%d",&overlay);

	int kv = LocateVex(*G, v);
	int kw = LocateVex(*G, w);
	// ָ���Ķ��㲻����
	if (kv == INFEASIBLE || kw == INFEASIBLE) {
		return ERROR;
	}
	//��ֹ���뻷
	if (kv == kw)return ERROR;
	//ȷ���Ƿ��Ǹ��ǲ���
	overlay = G->arcs[kv][kw].adj != adj;

	G->arcs[kv][kw].adj = 1;

	if (!overlay) {
		G->arcnum++;
	}


	// �����/���ϴ��ڸ�����Ϣ
	if (IncInfo) {
		va_list ap;
		va_start(ap, w);                // ��w���ѯ�׸��ɱ����
		InfoType* info = va_arg(ap, InfoType*);   // ��ȡ������Ϣ
		va_end(ap);
	}

	
}

/*
 * �㷨7.4
 *
 * ������ȱ���(�˴������ݹ�ʵ��)
 */
void DFSTraverse(MGraph G, Status(*Visit)(VertexType)) {
	VisitFunc = Visit;
	for (int v = 0; v < G.vexnum;++v) {
		visited[v] = FALSE;
	}

	for (int v = 0; v < G.vexnum;++v) {
		if (!visited[v]) { 
			DFS(G, v);
		}
	}
}


/*
 * �㷨7.5
 *
 * ������ȱ������ĺ���
 */
void DFS(MGraph G, int v) {
	visited[v] = TRUE;
	Visit(G.vexs[v]);
	for (int w = FirstAdjVex(G, G.vexs[v]); w >= 0; w = NextAdjVex(G, v, w)) {
		if (!visited[w]) { 
			DFS(G, w);
		}
	}
	
}


/*
 * �㷨7.6
 *
 * ������ȱ���(�˴���������ʵ��)
 */
void BFSTraverse(MGraph G, Status(*Visit)(VertexType)) {
	LinkQueue Q;
	InitQueue(&Q);
	for (int v = 0; v < G.vexnum; v++) visited[v] = FALSE;
	for (int v = 0; v < G.vexnum;v++) {
		if (!visited[v]) {
			visited[v] = TRUE;
			Visit(G.vexs[v]);
			EnQueue(&Q,v);
			int u;
			while (!QueueEmpty(Q)) {
				DeQueue(&Q, &u);
				for (int w = FirstAdjVex(G, G.vexs[u]); w >= 0; w = NextAdjVex(G, G.vexs[u], G.vexs[w])) {
					if (!visited[w]) {
						visited[w] = TRUE;
						Visit(G.vexs[w]);
						EnQueue(&Q,w);
					}
				}
			}
		}
}

}//BFSTraverse



/*
 * ��ͼ�λ���ʽ�����ǰ�ṹ
 *
 * ע����ͼ/���У�ʹ��"-"����ʾ�����㲻ֱ����ͨ
 */
void PrintGraph(MGraph G) {
	int i, j;

	if (G.vexnum == 0) {
		printf("��ͼ�������ӡ��\n");
		return;
	}

	printf("��ǰͼ/������ %2d �����㣬 %2d ����/��...\n", G.vexnum, G.arcnum);

	printf("  ");
	for (i = 0; i < G.vexnum; i++) {
		printf("  %c", G.vexs[i]);
	}
	printf("\n");

	for (i = 0; i < G.vexnum; i++) {
		printf("%c ", G.vexs[i]);

		for (j = 0; j < G.vexnum; j++) {
			if (((G.kind == DG || G.kind == UDG) && G.arcs[i][j].adj == 0) || ((G.kind == DN || G.kind == UDN) && G.arcs[i][j].adj == INFINITE)) {
				printf("  -");
			}
			else {
				printf("%3d", G.arcs[i][j].adj);
			}
		}

		printf("\n");
	}
}

void Visit(VertexType v) {
	printf("%c",v);
}