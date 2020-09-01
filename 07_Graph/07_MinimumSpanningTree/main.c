#include"MinimumSpanningTree.h"
int main(){
	MGraph G;
	CreateUDN(&G);
	VertexType v='a';
	MiniSpanTree_PRIM(G,v);
}