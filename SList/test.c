#include"SList.h"

void SListTest01()
{
	//��������һ��һ���Ľڵ����
	//���������ڵ�
	SLTNode* node1 = (SLTNode*)malloc(sizeof(SLTNode));
	node1->data = 1;

	SLTNode* node2 = (SLTNode*)malloc(sizeof(SLTNode));
	node2->data = 2;

	SLTNode* node3 = (SLTNode*)malloc(sizeof(SLTNode));
	node3->data = 3;

	SLTNode* node4 = (SLTNode*)malloc(sizeof(SLTNode));
	node4->data = 4;

	//���ĸ��ڵ���������
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = NULL;

	//��������Ĵ�ӡ
	SLTNode* plist = node1;
	SLTPrint(plist);
}

void SListTest02()
{
	SLTNode* plist = NULL;
	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTPrint(plist);
	//SLTPushBack(NULL, 5);
	//
	//����ͷ��
	//SLTPushFront(&plist, 6);
	//SLTPrint(plist);
	//SLTPushFront(&plist, 7);
	//SLTPrint(plist);
	//SLTPushFront(&plist, 8);
	//SLTPrint(plist);

	////����βɾ
	//SLTPopBack(&plist);
	//SLTPrint(plist);
	//SLTPopBack(&plist);
	//SLTPrint(plist);
	//SLTPopBack(&plist);
	//SLTPrint(plist);
	//SLTPopBack(&plist);
	//SLTPrint(plist);

	////����ͷɾ
	//SLTPopFront(&plist);
	//SLTPrint(plist);
	//SLTPopFront(&plist);
	//SLTPrint(plist);
	//SLTPopFront(&plist);
	//SLTPrint(plist);
	//SLTPopFront(&plist);
	//SLTPrint(plist);

	////���Բ���
	//SLTNode* find = NULL;
	//find = SLTFind(plist, 1);
	//if (find)
	//{
	//	printf("�ҵ���!\n");
	//}
	//else
	//{
	//	printf("û���ҵ���\n");
	//}
	//find = SLTFind(plist, 5);
	//if (find)
	//{
	//	printf("�ҵ���!\n");
	//}
	//else
	//{
	//	printf("û���ҵ���\n");
	//}

	////����ǰ����
	//SLTNode* find = NULL;
	//find = SLTFind(plist, 1);
	//SLTInsert(&plist, find, 7);
	//SLTPrint(plist);
	//find = SLTFind(plist, 4);
	//SLTInsert(&plist, find, 8);
	//SLTPrint(plist);

	////���Ժ����
	//SLTNode* find = NULL;
	//find = SLTFind(plist, 1);
	//SLTInsertAfter(find, 7);
	//SLTPrint(plist);
	//find = SLTFind(plist, 4);
	//SLTInsertAfter(find, 8);
	//SLTPrint(plist);

	////����ɾ��
	//SLTNode* find = NULL;
	//find = SLTFind(plist, 1);
	//SLTErase(&plist, find);
	//SLTPrint(plist);
	//find = SLTFind(plist, 4);
	//SLTErase(&plist, find);
	//SLTPrint(plist);

	//���Ժ�ɾ��
	SLTNode* find = NULL;
	find = SLTFind(plist, 1);
	SLTEraseAfter(find);
	SLTPrint(plist);
	find = SLTFind(plist, 3);
	SLTEraseAfter(find);
	SLTPrint(plist);
}

int main()
{
	//SListTest01();
	SListTest02();
	return 0;
}