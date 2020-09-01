#include"OLGraph.h"
#include<stdio.h>
/*
 * 查找
 *
 * 返回顶点u在图/网中的位置
 */
int LocateVex(OLGraph G, VertexType u) {
    int i;

    for (i = 0; i < G.vexnum; i++) {
        if (G.xlist[i].data == u) {
            return i;
        }
    }

    return -1;
}

Status CreateDG(OLGraph* G) {
    printf("请输入结点数量");
    scanf("%d%*c", &G->vexnum);
    printf("请输入边的数量");
    scanf("%d%*c", &G->arcnum);
    printf("请输入图的类型");
    scanf("%d%*c", &G->kind);

    InfoType info = NULL;
    for (int i = 0; i < G->vexnum; i++) {
        printf("请依次输入第%d个结点",i+1);
        scanf("%c%*c", &G->xlist[i].data);
        G->xlist[i].firstin = NULL;
        G->xlist[i].firstout = NULL;
    }
    VertexType v1, v2;

    for (int k = 0; k < G->arcnum; ++k) {
        printf("请输入有向图第%d个弧的弧尾",k + 1);
        scanf("%c%*c", &v1);
        printf("请输入有向图第%d个弧的弧尾",k + 1);
        scanf("%c%*c", &v2);
        // 插入弧<v1, v2>
        InsertArc(G, v1, v2, info);
    }


}

Status InsertArc(OLGraph* G, VertexType v, VertexType w) {
    int tail, head, k, count;
    ArcBox* p;
    ArcBox* pre;
    ArcBox* r;
    bool overlay = FALSE;   // 是否为覆盖添加
    InfoType* info = NULL;     // 边/弧的附加信息
    va_list ap;

    tail = LocateVex(*G, v); // 获取顶点v在顶点集中的位置
    if (tail == -1) {
        return ERROR;  // 指定的顶点不存在
    }

    head = LocateVex(*G, w); // 获取顶点w在顶点集中的位置
    if (head == -1) {
        return ERROR;  // 指定的顶点不存在
    }

    // 拒绝环
    if (tail == head) {
        return ERROR;
    }


    /* 接下来，需要查找合适的插入位置 */

    for (count = 0; count < 2; count++) {

        // 在横向链表上查找合适的插入位置
        pre = NULL;
        // 指向以tail为尾的首条边/弧
        r = G->xlist[tail].firstout;
        while (r != NULL && r->headvex < head) {
            pre = r;
            r = r->tlink;
        }

        // 遇到了相同位置的结点
        if (r != NULL && r->headvex == head) {
            r->info = info; // 复用该结点
            overlay = TRUE; // 发生了覆盖
        }
        else {
            p = newArcBoxPtr(tail, head, NULL, r, info);

            if (pre == NULL) {
                G->xlist[tail].firstout = p;
            }
            else {
                pre->tlink = p;
            }
        }

        // 如果没有发生覆盖，说明插入了新结点，此时需要考虑其在纵向链表上的位置
        if (overlay == FALSE) {
            // 在纵向链表上查找合适的插入位置
            pre = NULL;
            // 指向以head为头的首条边/弧
            r = G->xlist[head].firstin;
            while (r != NULL && r->tailvex < tail) {
                pre = r;
                r = r->hlink;
            }

            // 遇到了相同位置的结点
            if (r != NULL && r->tailvex == tail) {
                // 不会执行到这里，因为如果发生了覆盖，前面进不来
            }
            else {
                /* 至此，结点p已经存在了 */

                if (pre == NULL) {
                    p->hlink = G->xlist[head].firstin;
                    G->xlist[head].firstin = p;
                }
                else {
                    p->hlink = pre->hlink;
                    pre->hlink = p;
                }
            }
        }

        // 如果当前图/网是无向的，需要考虑对称性
        if ((G->kind == UDG || G->kind == UDN) && tail != head) {
            // 颠倒i和j
            k = tail;
            tail = head;
            head = k;
        }
        else {
            break;  // 如果是有向的，可以结束了
        }
    }

    // 在非覆盖的情形下，才考虑更新边/弧的数量
    if (!overlay) {
        (*G).arcnum++;  // 不论有向无向，边/弧数只增一
    }

    return OK;
}

ArcBox* newArcBoxPtr(int tailvex, int headvex, ArcBox* hlink, ArcBox* tlink, InfoType* info) {
    ArcBox* p = (ArcBox*)malloc(sizeof(ArcBox));
    if (!p) {
        exit(OVERFLOW);
    }

    p->tailvex = tailvex;
    p->headvex = headvex;

    p->hlink = hlink;
    p->tlink = tlink;

    p->info = info;

    return p;
}
