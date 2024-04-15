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
void LTInit(LTNode** pphead);

//尾插 -- 不改变哨兵位 -- 传一级指针
void LTPushBack(LTNode* phead, LTDataType x);

//打印
void LTPrint(LTNode* phead);

