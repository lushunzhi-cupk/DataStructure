/*=========================
 * ���е���ʽ�洢�ṹ�����ӣ�
 ==========================*/
#pragma once
#include<stdio.h>
#include"Status.h"
typedef char QElemType;
//-----�������С������е���ʽ�洢�ṹ-----
typedef struct QNode {
	QElemType data;
	struct QNode* next;
}QNode,*QueuePtr;

typedef struct {
	QueuePtr front;//��ͷָ��
	QueuePtr rear;//��βָ��
}LinkQueue;

//-----���������ĺ���˵��-----

/*
 * ��ʼ��
 *
 * ����һ���յ����ӡ�
 * ��ʼ���ɹ��򷵻�OK�����򷵻�ERROR��
 *
 *��ע��
 * ����Ķ��д���ͷ���
 */
Status InitQueue(LinkQueue* Q);

/*
 * ����(�ṹ)
 *
 * �ͷ�������ռ�ڴ档
 */
Status DestroyQueue(LinkQueue* Q);

/*
 * �ÿ�(����)
 *
 * ������Ҫ�ͷ������з�ͷ��㴦�Ŀռ䡣
 */
Status ClearQueue(LinkQueue* Q);

/*
 * �п�
 *
 * �ж��������Ƿ������Ч���ݡ�
 *
 * ����ֵ��
 * TRUE : ����Ϊ��
 * FALSE: ���Ӳ�Ϊ��
 */
Status QueueEmpty(LinkQueue Q);

/*
 * ����
 *
 * �������Ӱ�������ЧԪ�ص�������
 */
int QueueLength(LinkQueue Q);

/*
 * ȡֵ
 *
 * ��ȡ��ͷԪ�أ�����洢��e�С�
 * ��������ҵ�������OK�����򣬷���ERROR��
 */
Status GetHead(LinkQueue Q, QElemType* e);

/*
 * ���
 *
 * ��Ԫ��e��ӵ�����β����
 */
Status EnQueue(LinkQueue* Q, QElemType e);

/*
 * ����
 *
 * �Ƴ�����ͷ����Ԫ�أ�����洢��e�С�
 */
Status DeQueue(LinkQueue* Q, QElemType* e);

/*
 * ����
 *
 * ��visit�������ʶ���Q
 */
Status QueueTraverse(LinkQueue Q, void(Visit)(QElemType));
