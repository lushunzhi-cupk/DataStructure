#include"LinkQueue.h"
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
Status InitQueue(LinkQueue* Q) {
	/* ����һ���ն���Q */
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q->front)exit(OVERFLOW);
	Q->front->next = NULL;
	return OK;
}

/*
 * ����(�ṹ)
 *
 * �ͷ�������ռ�ڴ档
 */
Status DestroyQueue(LinkQueue* Q) {
	/* ���ٶ���Q(���ۿշ����) */
	while (Q->front) {
		Q->rear = Q->front; 
		free(Q->front);
		Q->front = Q->rear;
	}
	return OK;
}

/*
 * �ÿ�(����)
 *
 * ������Ҫ�ͷ������з�ͷ��㴦�Ŀռ䡣
 */
Status ClearQueue(LinkQueue* Q) {
	/* ��Q��Ϊ�ն��� */
	Q->rear = Q->front;
	QueuePtr p = Q->front->next;
	Q->front->next = NULL;
	while(p){
		QueuePtr q = p->next;
		free(p);
		p = q;
	}
	return OK;
}

/*
 * �п�
 *
 * �ж��������Ƿ������Ч���ݡ�
 *
 * ����ֵ��
 * TRUE : ����Ϊ��
 * FALSE: ���Ӳ�Ϊ��
 */
Status QueueEmpty(LinkQueue Q) {
	/* ��QΪ�ն���,�򷵻�TRUE,���򷵻�FALSE */
	return Q.front == Q.rear;
}

/*
 * ����
 *
 * �������Ӱ�������ЧԪ�ص�������
 */
int QueueLength(LinkQueue Q) {
	/* ����еĳ��� */
	int i = 0;
	QueuePtr p = Q.front;
	while (p!=Q.rear) {
		p = p->next;
		i++;
	}
	return i;
}

/*
 * ȡֵ
 *
 * ��ȡ��ͷԪ�أ�����洢��e�С�
 * ��������ҵ�������OK�����򣬷���ERROR��
 */
Status GetHead(LinkQueue Q, QElemType* e) {
	/*��ȡ��һ�����ݽ��*/
	QueuePtr p;
	if (Q.front == Q.rear)
		return ERROR;
	p = Q.front->next;
	*e = p->data;
	return OK;
}

/*
 * ���
 *
 * ��Ԫ��e��ӵ�����β����
 */
Status EnQueue(LinkQueue* Q, QElemType e) {
	/* ����Ԫ��eΪQ���µĶ�βԪ�� */
	QueuePtr p=(QueuePtr)malloc(sizeof(QNode));
	if (!p) exit(OVERFLOW);
	p->data = e; p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	return OK;
}

/*
 * ����
 *
 * �Ƴ�����ͷ����Ԫ�أ�����洢��e�С�
 */
Status DeQueue(LinkQueue* Q, QElemType* e) {
	/* �����в���(�������ݽ��),ɾ��Q�Ķ�ͷԪ��,��e������ֵ,������OK,���򷵻�ERROR */
	if (Q->front == Q->rear)return ERROR;
	QueuePtr p = Q->front->next;
	*e = p->data;
	Q->front->next = p->next;
	if (Q->rear == p)Q->rear = Q->front;//ֻ��һ�����ݽ��ʱ��������ݽ�㱻ɾ���������βָ��ָ��ͷ���
	free(p);
	return OK;
}

/*
 * ����
 *
 * ��visit�������ʶ���Q
 */
Status QueueTraverse(LinkQueue Q, void(*Visit)(QElemType)) {
	/* �Ӷ�ͷ����β���ζԶ���Q��ÿ��Ԫ�ص��ú���Visit()��һ��Visitʧ��,�����ʧ�� */
	QueuePtr p;
	p = Q.front->next;
	while (p)
	{
		Visit(p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}
