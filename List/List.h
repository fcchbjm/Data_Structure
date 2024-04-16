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
//void LTInit(LTNode** pphead);
LTNode* LTInit(void);

//β�� -- ���ı��ڱ�λ -- ��һ��ָ��
void LTPushBack(LTNode* phead, LTDataType x);

//��ӡ
void LTPrint(LTNode* phead);

//ͷ��
void LTPushFront(LTNode* phead, LTDataType x);

//βɾ
void LTPopBack(LTNode* phead);

//ͷɾ
void LTPopFront(LTNode* phead);

//��ָ��λ�ú��������
void LTInsert(LTNode* pos, LTDataType x);

//����
LTNode* LTFind(LTNode* phead, LTDataType x);

//ɾ��ָ��λ�ýڵ�
void LTErase(LTNode* pos);

//����
void LTDestory(LTNode* phead);
