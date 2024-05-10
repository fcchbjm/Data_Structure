#include "Queue.h"

void QueueInit(Queue* pq)
{
	assert(pq);
	pq->phead = NULL;
	pq->ptail = NULL;
	pq->size = 0;
}

void QueuePush(Queue* pq, QDataType x)
{
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("malloc failed");
		exit(1);
	}

	newnode->next = NULL;
	newnode->val = x;

	if (pq->ptail == NULL)
	{
		pq->phead = newnode;
		pq->ptail = newnode;
	}
	else
	{
		pq->ptail->next = newnode;
		pq->ptail = newnode;
	}
	pq->size++;
}

void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->size);

	QNode* next = pq->phead->next;
	free(pq->phead);
	pq->phead = next;

	if (pq->phead == NULL)//只有一个节点的情况
	{
		pq->ptail = NULL;
	}

	pq->size--;
}

QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->phead);
	return pq->phead->val;
}

QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->ptail);
	return pq->ptail->val;
}

int QueueSize(Queue* pq)
{
	assert(pq);
	return pq->size;
}

_Bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->size == 0;
}

void QueueDestroy(Queue* pq)
{
	assert(pq);
	QNode* pcur = pq->phead;
	while (pcur)
	{
		QNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	pq->phead = NULL;
	pq->ptail = NULL;
	pq->size = 0;
}
