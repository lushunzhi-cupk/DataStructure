#include"LinkQueue.h"
//-----基本操作的函数说明-----

/*
 * 初始化
 *
 * 构造一个空的链队。
 * 初始化成功则返回OK，否则返回ERROR。
 *
 *【注】
 * 这里的队列带有头结点
 */
Status InitQueue(LinkQueue* Q) {
	/* 构造一个空队列Q */
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q->front)exit(OVERFLOW);
	Q->front->next = NULL;
	return OK;
}

/*
 * 销毁(结构)
 *
 * 释放链队所占内存。
 */
Status DestroyQueue(LinkQueue* Q) {
	/* 销毁队列Q(无论空否均可) */
	while (Q->front) {
		Q->rear = Q->front; 
		free(Q->front);
		Q->front = Q->rear;
	}
	return OK;
}

/*
 * 置空(内容)
 *
 * 这里需要释放链队中非头结点处的空间。
 */
Status ClearQueue(LinkQueue* Q) {
	/* 将Q清为空队列 */
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
 * 判空
 *
 * 判断链队中是否包含有效数据。
 *
 * 返回值：
 * TRUE : 链队为空
 * FALSE: 链队不为空
 */
Status QueueEmpty(LinkQueue Q) {
	/* 若Q为空队列,则返回TRUE,否则返回FALSE */
	return Q.front == Q.rear;
}

/*
 * 计数
 *
 * 返回链队包含的有效元素的数量。
 */
int QueueLength(LinkQueue Q) {
	/* 求队列的长度 */
	int i = 0;
	QueuePtr p = Q.front;
	while (p!=Q.rear) {
		p = p->next;
		i++;
	}
	return i;
}

/*
 * 取值
 *
 * 获取队头元素，将其存储到e中。
 * 如果可以找到，返回OK，否则，返回ERROR。
 */
Status GetHead(LinkQueue Q, QElemType* e) {
	/*获取第一个数据结点*/
	QueuePtr p;
	if (Q.front == Q.rear)
		return ERROR;
	p = Q.front->next;
	*e = p->data;
	return OK;
}

/*
 * 入队
 *
 * 将元素e添加到队列尾部。
 */
Status EnQueue(LinkQueue* Q, QElemType e) {
	/* 插入元素e为Q的新的队尾元素 */
	QueuePtr p=(QueuePtr)malloc(sizeof(QNode));
	if (!p) exit(OVERFLOW);
	p->data = e; p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	return OK;
}

/*
 * 出队
 *
 * 移除队列头部的元素，将其存储到e中。
 */
Status DeQueue(LinkQueue* Q, QElemType* e) {
	/* 若队列不空(存在数据结点),删除Q的队头元素,用e返回其值,并返回OK,否则返回ERROR */
	if (Q->front == Q->rear)return ERROR;
	QueuePtr p = Q->front->next;
	*e = p->data;
	Q->front->next = p->next;
	if (Q->rear == p)Q->rear = Q->front;//只有一个数据结点时，这个数据结点被删除，必须把尾指针指向头结点
	free(p);
	return OK;
}

/*
 * 遍历
 *
 * 用visit函数访问队列Q
 */
Status QueueTraverse(LinkQueue Q, void(*Visit)(QElemType)) {
	/* 从队头到队尾依次对队列Q中每个元素调用函数Visit()。一旦Visit失败,则操作失败 */
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
