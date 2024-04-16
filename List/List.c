#include "List.h"

LTNode* LTBuyNode(LTDataType x)
{
	LTNode* node = (LTNode*)malloc(sizeof(LTNode));
	if (node == NULL)
	{
		perror("malloc failed");
		exit(1);
	}
	node->data = x;
	node->prev = node->next = node;

	return node;
}

//void LTInit(LTNode** pphead)
//{
//	//给双向链表创建一个哨兵位
//	*pphead = LTBuyNode(-1);
//}
LTNode* LTInit(void)
{
	LTNode* node = LTBuyNode(EOF);
	return node;
}

void LTPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* newnode = LTBuyNode(x);

	//phead ..... phead->prev newnode
	newnode->prev = phead->prev;
	newnode->next = phead;

	phead->prev->next = newnode;
	phead->prev = newnode;
}

void LTPrint(LTNode* phead)
{
	LTNode* pcur = phead->next;
	while (pcur != phead)
	{
		printf("%d->", pcur->data);
		pcur = pcur->next;
	}
	printf("\n");
}

void LTPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* newnode = LTBuyNode(x);

	//phead newnode phead->next ......
	newnode->next = phead->next;
	newnode->prev = phead;

	phead->next->prev = newnode;
	phead->next = newnode;
}

void LTPopBack(LTNode* phead)
{
	assert(phead && phead->next != phead);//链表有效且不为空（只有一个哨兵位）

	//phead  ......  del->prev(phead->prev->prev)  del(phead->prev)
	LTNode* del = phead->prev;
	del->prev->next = phead;
	phead->prev = del->prev;

	//删除del节点
	free(del);
	del = NULL;
}

void LTPopFront(LTNode* phead)
{
	assert(phead && phead->next != phead);

	LTNode* del = phead->next;

	//phead  del(phead->next)  del->next(phead->next->next) ......
	phead->next = del->next;
	del->next->prev = phead;

	//删除del节点
	free(del);
	del = NULL;
}

LTNode* LTFind(LTNode* phead, LTDataType x)
{
	LTNode* pcur = phead->next;
	while (pcur != phead)
	{
		if (pcur->data == x)
		{
			return pcur;
		}
		pcur = pcur->next;
	}
	return NULL;
}

void LTErase(LTNode* pos)
{
	//pos理论上不能为phead，但是参数有限，无法校验
	assert(pos);

	//... pos->prev pos pos->next ...
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;

	free(pos);
	pos = NULL;
}

void LTDestory(LTNode* phead)
{
	assert(phead);

	LTNode* pcur = phead->next;
	while(pcur != phead)
	{
		LTNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}

	//销毁phead
	free(phead);
	phead = NULL;
	pcur = NULL;
}

void LTInsert(LTNode* pos, LTDataType x)
{
	assert(pos);

	LTNode* newnode = LTBuyNode(x);

	//... pos newnode pos->next ...
	newnode->next = pos->next;
	newnode->prev = pos;

	pos->next->prev = newnode;
	pos->next = newnode;
}
