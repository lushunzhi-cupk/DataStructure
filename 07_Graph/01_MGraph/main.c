#include"MGraph.h"

int main() {
	MGraph  G;

	/*LinkQueue Q;
	InitQueue(&Q);*/

	CreateUDN(&G);
//	CreateDN(&G);
	//int fa=FirstAdjVex(G,'a');
	int fa = NextAdjVex(G, 'a', 'b');
	printf("%d\n",fa);
	PrintGraph(G);

	InsertArc(&G,'a','b');
	PrintGraph(G);


//	DFSTraverse(G,Visit);
//	BFSTraverse(G,Visit);
//	CreateDG(&G);
}