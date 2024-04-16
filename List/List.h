#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//重命名数据类型
typedef int LTDataType;

typedef struct ListNode
{
	LTDataType data;
	struct ListNode* prev;//指向前一个节点
	struct ListNode* next;//指向后一个节点
}LTNode;

//初始化
//void LTInit(LTNode** pphead);
LTNode* LTInit(void);

//尾插 -- 不改变哨兵位 -- 传一级指针
void LTPushBack(LTNode* phead, LTDataType x);

//打印
void LTPrint(LTNode* phead);

//头插
void LTPushFront(LTNode* phead, LTDataType x);

//尾删
void LTPopBack(LTNode* phead);

//头删
void LTPopFront(LTNode* phead);

//在指定位置后插入数据
void LTInsert(LTNode* pos, LTDataType x);

//查找
LTNode* LTFind(LTNode* phead, LTDataType x);

//删除指定位置节点
void LTErase(LTNode* pos);

//销毁
void LTDestory(LTNode* phead);
