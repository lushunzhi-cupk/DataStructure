/*=================================
 * 图的数组(邻接矩阵)存储表示
 *
 * 包含算法: 7.1、7.2、7.4、7.5、7.6
 ==================================*/

#include"MGraph.h"  

Boolean IncInfo = TRUE;
/*
 * 算法7.1
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
 * 构造有向图
 */
Status CreateDG(MGraph *G) {
	G->kind = DG;
	ArcCell arcs = { 0,NULL };

	printf("请输入有向图的顶点个数");
	scanf("%d%*c", &G->vexnum);
	printf("请输入有向图的弧的个数");
	scanf("%d%*c", &G->arcnum);
	if (G->arcnum < 0 || G->arcnum > G->vexnum * G->vexnum - 1) {
		printf("边的个数不合法，程序退出");
		return INFEASIBLE;
	}
	printf("请输入是否包含额外的边的信息(0-不包含│ 1-包含)");
	scanf("%d%*c", &IncInfo);
	printf("请依次输入所有结点");
	for (int i = 0; i < G->vexnum; ++i) scanf("%c%*c", &G->vexs[i]);

	for (int i = 0; i < G->vexnum;i++) {
		for (int j = 0; j < G->vexnum;j++) {
			G->arcs[i][j] = arcs;
		}
	}

	for (int k = 0; k < G->arcnum;k++) {
		VertexType v1, v2;
	
		printf("请输入第%d条弧所对应的两个顶点\n", k + 1);
		printf("请输入弧尾顶点\n");
		scanf("%c%*c", &v1);
		printf("请输入弧头顶点\n");
		scanf("%c%*c", &v2);
		int i = LocateVex(*G, v1);
		int j = LocateVex(*G, v2);
		if (i==-1||j==-1) {
			printf("结点不存在,请重新进行这条边的输入\n");
			k -= 1;
			continue;
		}
		if (G->arcs[i][j].adj == 1) {
			printf("边已经存在，请重新进行这条边的输入\n");
			k -= 1;
			continue;
		}
		if (IncInfo) Input(&(G->arcs[i][j].info));
		G->arcs[i][j].adj = 1;
	}
};//CreateDG




/*
 * 构造有向网
 */
Status CreateDN(MGraph *G) {
	G->kind = DN;
	ArcCell arcs = { 0,NULL };
	printf("请输入有向网的顶点个数");
	scanf("%d%*c", &G->vexnum);
	printf("请输入有向网弧的个数");
	scanf("%d%*c", &G->arcnum);
	if (G->arcnum < 0 || G->arcnum >G->vexnum * G->vexnum - 1) {
		printf("边的个数不合法,程序退出");
		exit(INFEASIBLE);
	}
	printf("请输入有向图的弧是否包含额外信息 (0-不包含│ 1-包含)");
	scanf("%d%*c", &IncInfo);
	printf("请依次输入所有结点");
	for (int i = 0; i < G->vexnum; ++i) scanf("%c%*c", &G->vexs[i]);

	for (int i = 0; i < G->vexnum; ++i) {
		for (int j = 0; j < G->vexnum; ++j) {
			G->arcs[i][j] = arcs;
		}
	}
	for (int k = 0; k < G->arcnum; k++) {
		VertexType v1, v2;
		VRType w;

		printf("请输入第%d条弧所对应的两个顶点以及它们之间弧的值\n", k + 1);
		printf("请输入弧尾顶点\n");
		scanf("%c%*c", &v1);
		printf("请输入弧头顶点\n");
		scanf("%c%*c", &v2);
		printf("请输入两个顶点之间弧的权值\n");
		scanf("%d%*c", &w);
		int i = LocateVex(*G, v1);
		int j = LocateVex(*G, v2);
		if (i == -1 || j == -1) {
			printf("结点不存在,请重新进行这条边的输入\n");
			k -= 1;
			continue;
		}
		if (G->arcs[i][j].adj == 1) {
			printf("边已经存在，请重新进行这条边的输入\n");
			k -= 1;
			continue;
		}
		G->arcs[i][j].adj = w;
		if (IncInfo) Input(&(G->arcs[i][j].info));
	}
	return OK;
}//CreateDN


/*
 * 构造无向图
 */
Status CreateUDG(MGraph* G) {
	G->kind = UDG;
	ArcCell arcs = { 0,NULL };


	printf("请输入无向图的顶点个数");
	scanf("%d%*c", &G->vexnum);
	printf("请输入无向图的弧的个数");
	scanf("%d%*c", &G->arcnum);
	if (G->arcnum < 0 || G->arcnum >(G->vexnum * G->vexnum - 1)/2) {
		printf("边的个数不合法，程序退出");
		exit(INFEASIBLE);
	}
	printf("请输入是否包含额外的边的信息(0-不包含│ 1-包含)");
	scanf("%d%*c", &IncInfo);
	printf("请依次输入所有结点");
	for (int i = 0; i < G->vexnum; ++i) scanf("%c%*c", &G->vexs[i]);

	for (int i = 0; i < G->vexnum; i++) {
		for (int j = 0; j < G->vexnum; j++) {
			G->arcs[i][j] = arcs;
		}
	}

	for (int k = 0; k < G->arcnum; k++) {
		VertexType v1, v2;

		printf("请输入第%d条弧所对应的两个顶点\n", k + 1);
		printf("请输入第一个顶点\n");
		scanf("%c%*c", &v1);
		printf("请输入第一个顶点\n");
		scanf("%c%*c", &v2);
		int i = LocateVex(*G, v1);
		int j = LocateVex(*G, v2);
		if (i == -1 || j == -1) {
			printf("结点不存在,请重新进行这条边的输入\n");
			k -= 1;
			continue;
		}
		if (G->arcs[i][j].adj == 1) {
			printf("边已经存在，请重新进行这条边的输入\n");
			k -= 1;
			continue;
		}
		if (IncInfo) Input(&(G->arcs[i][j].info));
		G->arcs[i][j].adj = 1;
	}
};//CreateUDG


/*
 * 构造无向网
 */
Status CreateUDN(MGraph *G) {
	G->kind = UDN;
	printf("请输入无向网的顶点个数\n");
	scanf("%d%*c",&G->vexnum);
//	printf(G->vexnum);
	printf("请输入无向网的边的个数\n");
	scanf("%d%*c",&G->arcnum);
//	printf(G->arcnum);
	if (G->arcnum < 0 || G->arcnum > (G->vexnum * G->vexnum - 1)/2) {
		printf("顶点个数或边的个数不合法,程序退出");
		exit(INFEASIBLE);
	}
	printf("请输入无向网的弧是否包含额外信息 (0-不包含│ 1-包含)\n");
	scanf("%d%*c", &IncInfo);
	printf("请依次输入所有结点\n");
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

		printf("请输入第%d条边所对应的两个顶点以及它们之间边的权值\n", k + 1);
		printf("请输入第一个顶点\n");
		scanf("%c%*c", &v1);
		printf("请输入第二个顶点\n");
		scanf("%c%*c", &v2);
		printf("请输入两个顶点之间边的权值\n");
		scanf("%d%*c", &w);
		int i = LocateVex(*G,v1);
		int j = LocateVex(*G,v2);
		if (i == -1 || j == -1) {
			printf("结点不存在,请重新进行这条边的输入\n");
			k -= 1;
			continue;
		}
		if (G->arcs[i][j].adj == 1) {
			printf("边已经存在,是否更新(0-否，1-是)，请重新进行这条边的输入\n");
			int select;
			scanf("%d",&select);
			if (select == 0) {
				printf("未更新边，此次操作作废，请继续");

			}
			else {
				G->arcs[i][j].adj = w;
				printf("已更新边，请继续");
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
 * 录入边的相关附加信息
 */
void Input(InfoType **info) {
	scanf_s("%s", info);
}


/*
 * 销毁
 *
 * 邻接矩阵存储的图无需释放内存，只需重置相关遍历即可。
 */
Status DestroyGraph(MGraph* G) {
	G->vexnum = 0;
	G->arcnum = 0;
	return SUCCESS;
}



/*
 * 查找
 *
 * 返回顶点u在图/网中的位置
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
 * 取值
 *
 * 返回索引v处的顶点值
 */
VertexType GetVex(MGraph G, int v) {
	if (v < 0 || v >= G.vexnum) {
		printf("索引错误");
		exit(ERROR);
	}
	return  G.vexs[v];
}

/*
 * 赋值
 *
 * 将顶点v赋值为value
 */
Status PutVex(MGraph* G, VertexType v, VertexType value) {
	if (v < 0 || v >= G->vexnum) {
		printf("索引错误");
		exit(ERROR);
	}
	G->vexs[v] = value;
	return SUCCESS;
}


/*
 * 首个邻接点
 *
 * 返回顶点v的首个邻接点
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
 * 下一个邻接点
 *
 * 返回顶点v的(相对于w的)下一个邻接点
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
 * 插入顶点
 *
 * 将指定的顶点v追加到顶点集中，未建立该顶点与其他顶点的关系
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
 * 删除顶点
 *
 * 从顶点集中删除指定的顶点v，注意需要更新相关的顶点关系
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

	for (int i = vl + 1; i <= G->vexnum;i++) {//控制一排
		for (int j = 0; j < G->vexnum;j++) {//控制一排里面的每一个
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
 * 插入边/弧<v, w>
 *
 * 如果当前图/网是无向的，则插入一条弧需要增加两个顶点关系，但弧的数量只增一。
 *
 * 对于图来说，可以在可变参数中列出边/弧的附加信息；
 * 对于网来说，可以在可变参数中依次列出边/弧的权值以及附加信息。
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
	Boolean overlay =FALSE;//默认不支持覆盖添加
	printf("请输入是否支持覆盖插入(0-不支持 1-支持)");
	scanf("%d",&overlay);

	int kv = LocateVex(*G, v);
	int kw = LocateVex(*G, w);
	// 指定的顶点不存在
	if (kv == INFEASIBLE || kw == INFEASIBLE) {
		return ERROR;
	}
	//防止插入环
	if (kv == kw)return ERROR;
	//确定是否是覆盖插入
	overlay = G->arcs[kv][kw].adj != adj;

	G->arcs[kv][kw].adj = 1;

	if (!overlay) {
		G->arcnum++;
	}


	// 如果边/弧上存在附加信息
	if (IncInfo) {
		va_list ap;
		va_start(ap, w);                // 在w后查询首个可变参数
		InfoType* info = va_arg(ap, InfoType*);   // 获取附加信息
		va_end(ap);
	}

	
}

/*
 * 算法7.4
 *
 * 深度优先遍历(此处借助递归实现)
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
 * 算法7.5
 *
 * 深度优先遍历核心函数
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
 * 算法7.6
 *
 * 广度优先遍历(此处借助队列实现)
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
 * 以图形化形式输出当前结构
 *
 * 注：在图/网中，使用"-"来表示两顶点不直接连通
 */
void PrintGraph(MGraph G) {
	int i, j;

	if (G.vexnum == 0) {
		printf("空图，无需打印！\n");
		return;
	}

	printf("当前图/网包含 %2d 个顶点， %2d 条边/弧...\n", G.vexnum, G.arcnum);

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