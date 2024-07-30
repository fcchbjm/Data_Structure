#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct BinaryTreeNode* QDataType;

typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType val;
}QNode;

typedef struct Queue
{
	QNode* phead; 
	QNode* ptail;
	int size;
}Queue;

////��β����
//void QueuePush(QNode** pphead, QNode** pptail, QDataType x);
//
////��ͷɾ��
//void QueuePop(QNode** pphead, QNode** pptail);

//��ʼ��
void QueueInit(Queue* pq);

//��β����
void QueuePush(Queue* pq, QDataType x);

//��ͷɾ��
void QueuePop(Queue* pq);

//ȡ��ͷ����
QDataType QueueFront(Queue* pq);

//ȡ��β����
QDataType QueueBack(Queue* pq);

//����Ԫ�ظ���
int QueueSize(Queue* pq);

//�п�
_Bool QueueEmpty(Queue* pq);

//���е�����
void QueueDestroy(Queue* pq);
