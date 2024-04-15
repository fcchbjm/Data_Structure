#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//��������������
typedef int LTDataType;

typedef struct ListNode
{
	LTDataType data;
	struct ListNode* prev;//ָ��ǰһ���ڵ�
	struct ListNode* next;//ָ���һ���ڵ�
}LTNode;

//��ʼ��
void LTInit(LTNode** pphead);

//β�� -- ���ı��ڱ�λ -- ��һ��ָ��
void LTPushBack(LTNode* phead, LTDataType x);

//��ӡ
void LTPrint(LTNode* phead);

