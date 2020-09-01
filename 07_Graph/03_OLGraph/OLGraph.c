#include"OLGraph.h"
#include<stdio.h>
/*
 * ����
 *
 * ���ض���u��ͼ/���е�λ��
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
    printf("������������");
    scanf("%d%*c", &G->vexnum);
    printf("������ߵ�����");
    scanf("%d%*c", &G->arcnum);
    printf("������ͼ������");
    scanf("%d%*c", &G->kind);

    InfoType info = NULL;
    for (int i = 0; i < G->vexnum; i++) {
        printf("�����������%d�����",i+1);
        scanf("%c%*c", &G->xlist[i].data);
        G->xlist[i].firstin = NULL;
        G->xlist[i].firstout = NULL;
    }
    VertexType v1, v2;

    for (int k = 0; k < G->arcnum; ++k) {
        printf("����������ͼ��%d�����Ļ�β",k + 1);
        scanf("%c%*c", &v1);
        printf("����������ͼ��%d�����Ļ�β",k + 1);
        scanf("%c%*c", &v2);
        // ���뻡<v1, v2>
        InsertArc(G, v1, v2, info);
    }


}

Status InsertArc(OLGraph* G, VertexType v, VertexType w) {
    int tail, head, k, count;
    ArcBox* p;
    ArcBox* pre;
    ArcBox* r;
    bool overlay = FALSE;   // �Ƿ�Ϊ�������
    InfoType* info = NULL;     // ��/���ĸ�����Ϣ
    va_list ap;

    tail = LocateVex(*G, v); // ��ȡ����v�ڶ��㼯�е�λ��
    if (tail == -1) {
        return ERROR;  // ָ���Ķ��㲻����
    }

    head = LocateVex(*G, w); // ��ȡ����w�ڶ��㼯�е�λ��
    if (head == -1) {
        return ERROR;  // ָ���Ķ��㲻����
    }

    // �ܾ���
    if (tail == head) {
        return ERROR;
    }


    /* ����������Ҫ���Һ��ʵĲ���λ�� */

    for (count = 0; count < 2; count++) {

        // �ں��������ϲ��Һ��ʵĲ���λ��
        pre = NULL;
        // ָ����tailΪβ��������/��
        r = G->xlist[tail].firstout;
        while (r != NULL && r->headvex < head) {
            pre = r;
            r = r->tlink;
        }

        // ��������ͬλ�õĽ��
        if (r != NULL && r->headvex == head) {
            r->info = info; // ���øý��
            overlay = TRUE; // �����˸���
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

        // ���û�з������ǣ�˵���������½�㣬��ʱ��Ҫ�����������������ϵ�λ��
        if (overlay == FALSE) {
            // �����������ϲ��Һ��ʵĲ���λ��
            pre = NULL;
            // ָ����headΪͷ��������/��
            r = G->xlist[head].firstin;
            while (r != NULL && r->tailvex < tail) {
                pre = r;
                r = r->hlink;
            }

            // ��������ͬλ�õĽ��
            if (r != NULL && r->tailvex == tail) {
                // ����ִ�е������Ϊ��������˸��ǣ�ǰ�������
            }
            else {
                /* ���ˣ����p�Ѿ������� */

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

        // �����ǰͼ/��������ģ���Ҫ���ǶԳ���
        if ((G->kind == UDG || G->kind == UDN) && tail != head) {
            // �ߵ�i��j
            k = tail;
            tail = head;
            head = k;
        }
        else {
            break;  // ���������ģ����Խ�����
        }
    }

    // �ڷǸ��ǵ������£��ſ��Ǹ��±�/��������
    if (!overlay) {
        (*G).arcnum++;  // �����������򣬱�/����ֻ��һ
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
