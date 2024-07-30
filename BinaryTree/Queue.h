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

////队尾插入
//void QueuePush(QNode** pphead, QNode** pptail, QDataType x);
//
////队头删除
//void QueuePop(QNode** pphead, QNode** pptail);

//初始化
void QueueInit(Queue* pq);

//队尾插入
void QueuePush(Queue* pq, QDataType x);

//队头删除
void QueuePop(Queue* pq);

//取队头数据
QDataType QueueFront(Queue* pq);

//取队尾数据
QDataType QueueBack(Queue* pq);

//队列元素个数
int QueueSize(Queue* pq);

//判空
_Bool QueueEmpty(Queue* pq);

//队列的销毁
void QueueDestroy(Queue* pq);
