#include"MinimumSpanningTree.h"

void MiniSpanTree_PRIM(MGraph G,VertexType u) {
	int minedge = INT_MAX;
	int minvex = -1;
	struct {
		VertexType adjvex;
		VRType lowcost;
	}closedge[MAX_VERTEX_NUM];
	int k = LocateVex(G, u);
	for (int j = 0; j < G.vexnum;++j) {
		if (j!=k) {
			closedge[j].adjvex = u;
			closedge[j].lowcost = G.arcs[k][j].adj;
		}
	}
	closedge[k].lowcost = 0;
	for (int i = 1; i < G.vexnum;i++) {
		if (closedge[i].lowcost < minedge) {
			minedge = closedge[i].lowcost;
			k = i;
		}
	}
	printf("%d%c",closedge[k].adjvex,G.vexs[k]);
	closedge[k].lowcost = 0;
	for (int j = 0; j < G.vexnum; ++j) {
		if (G.arcs[k][j].adj < closedge[j].lowcost) {
			closedge[j].adjvex = G.vexs[k];
			closedge[j].lowcost = G.arcs[k][j].adj;
		}
	}


}