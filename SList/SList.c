#include "SList.h"

//链表的打印
void SLTPrint(SLTNode* phead)
{
	SLTNode* pcur = phead;
	while (pcur)//pcur != NULL
	{
		printf("%d->", pcur->data);
		pcur = pcur->next;
	}
	printf("NULL\n");
}

//创建新的节点
SLTNode* SLTBuyNode(SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		perror("malloc fail!");
		exit(1);
	}
	newnode->data = x;
	newnode->next = NULL;

	return newnode;
}

//尾插
void SLTPushBack(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	//*pphead 就是指向第一个节点的指针
	//空链表和非空链表
	SLTNode* newnode = SLTBuyNode(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		//找尾
		SLTNode* ptail = *pphead;
		while (ptail->next)
		{
			ptail = ptail->next;
		}
		//ptail指向的就是尾结点
		ptail->next = newnode;
	}
}
//头插
void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* newnode = SLTBuyNode(x);
	//newnode *pphead
	newnode->next = *pphead;
	*pphead = newnode;
}
//尾删
void SLTPopBack(SLTNode** pphead)
{
	//链表不能为空
	assert(pphead && *pphead);
	//链表只有一个节点
	if ((*pphead)->next == NULL) //-> 优先级高于*
	{
		free(*pphead);
		*pphead = NULL;
	}
	else {
		//链表有多个节点

		SLTNode* prev = *pphead;
		SLTNode* ptail = *pphead;
		while (ptail->next)
		{
			prev = ptail;
			ptail = ptail->next;
		}
		//prev ptail
		free(ptail);
		ptail = NULL;
		prev->next = NULL;
	}
}
//头删
void SLTPopFront(SLTNode** pphead)
{
	assert(pphead && *pphead);

	SLTNode* next = (*pphead)->next;//->优先级高于*
	free(*pphead);
	*pphead = next;
}

//查找
SLTNode* SLTFind(SLTNode* phead, SLTDataType x)
{
	SLTNode* pcur = phead;//防止需要对链表进行多次遍历
	while (pcur)//等价于phead != NULL
	{
		if (pcur->data == x)
		{
			return pcur;//找到了，返回指针
		}
		pcur = pcur->next;
	}
	return NULL;//没找到的情况
}

//在任意位置之前插入
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pphead && *pphead);
	assert(pos);

	//若pos == *pphead 说明是头插
	if (pos == *pphead)
	{
		SLTPushFront(pphead, x);
	}
	else
	{
		SLTNode* newnode = SLTBuyNode(x);//新建的节点的地址

		SLTNode* prev = *pphead;//pos的前一个节点
		while (prev->next != pos)
		{
			prev = prev->next;
		}

		//prev -> newnode -> pos
		newnode->next = pos;//让新建的节点的next指针指向pos位置的节点
		prev->next = newnode;//让前一个节点的指针指向新建的节点的地址
	}
}


//在指定位置之后插入数据
void SLTInsertAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos);

	SLTNode* newnode = SLTBuyNode(x);//新建的节点的地址

	//pos -> newnode -> pos->next
	//先让newnode->next = pos->next
	newnode->next = pos->next;
	//再让pos->next = newnode
	pos->next = newnode;
}

//删除节点
void SLTErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead && *pphead);
	assert(pos);

	if (*pphead == pos)//删除头节点的情况
	{
		//SLTNode* next = pos->next;
		//free(*pphead);
		//*pphead = next;
		SLTPopFront(pphead);
	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}

		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}

//删除pos之后的节点
void SLTEraseAfter(SLTNode* pos)
{
	assert(pos && pos->next);

	SLTNode* del = pos->next;//指向要删除的地址
	pos->next = del->next;
	free(del);
	del = NULL;
}

//链表的销毁
void SListDestory(SLTNode** pphead)
{
	assert(pphead && *pphead);

	SLTNode* pcur = *pphead;
	while (pcur)
	{
		SLTNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	*pphead = NULL;
}
