#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//定义节点的结构
//数据 + 指向下一个节点的指针
typedef int SLTDataType;

typedef struct SListNode {
	SLTDataType data;//数据
	struct SListNode* next;//指向下一个链表的地址
}SLTNode;

//打印
void SLTPrint(SLTNode* phead);

//尾插
void SLTPushBack(SLTNode** pphead, SLTDataType x);

//头插
void SLTPushFront(SLTNode** pphead, SLTDataType x);

//尾删
void SLTPopBack(SLTNode** pphead);

//头删
void SLTPopFront(SLTNode** pphead);
