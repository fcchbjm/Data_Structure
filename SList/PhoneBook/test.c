#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"

//void SListTest01()
//{
//	//��������һ��һ���Ľڵ����
//	//���������ڵ�
//	SLTNode* node1 = (SLTNode*)malloc(sizeof(SLTNode));
//	node1->data = 1;
//
//	SLTNode* node2 = (SLTNode*)malloc(sizeof(SLTNode));
//	node2->data = 2;
//
//	SLTNode* node3 = (SLTNode*)malloc(sizeof(SLTNode));
//	node3->data = 3;
//
//	SLTNode* node4 = (SLTNode*)malloc(sizeof(SLTNode));
//	node4->data = 4;
//
//	//���ĸ��ڵ���������
//	node1->next = node2;
//	node2->next = node3;
//	node3->next = node4;
//	node4->next = NULL;
//
//	//��������Ĵ�ӡ
//	SLTNode* plist = node1;
//	SLTPrint(plist);
//}

//void SListTest02()
//{
//	//��������
//	SLTNode* plist = NULL;
//	SLTPushBack(&plist, 1);
//	SLTPushBack(&plist, 2);
//	SLTPushBack(&plist, 3);
//	SLTPushBack(&plist, 4);
//	SLTPrint(plist);
//
//	//����β��
//	//SLTPushBack(NULL, 5);
//	
//	//����ͷ��
//	//SLTPushFront(&plist, 6);
//	//SLTPrint(plist);
//	//SLTPushFront(&plist, 7);
//	//SLTPrint(plist);
//	//SLTPushFront(&plist, 8);
//	//SLTPrint(plist);
//
//	////����βɾ
//	//SLTPopBack(&plist);
//	//SLTPrint(plist);
//	//SLTPopBack(&plist);
//	//SLTPrint(plist);
//	//SLTPopBack(&plist);
//	//SLTPrint(plist);
//	//SLTPopBack(&plist);
//	//SLTPrint(plist);
//
//	////����ͷɾ
//	//SLTPopFront(&plist);
//	//SLTPrint(plist);
//	//SLTPopFront(&plist);
//	//SLTPrint(plist);
//	//SLTPopFront(&plist);
//	//SLTPrint(plist);
//	//SLTPopFront(&plist);
//	//SLTPrint(plist);
//
//	////���Բ���
//	//SLTNode* find = NULL;
//	//find = SLTFind(plist, 1);
//	//if (find)
//	//{
//	//	printf("�ҵ���!\n");
//	//}
//	//else
//	//{
//	//	printf("û���ҵ���\n");
//	//}
//	//find = SLTFind(plist, 5);
//	//if (find)
//	//{
//	//	printf("�ҵ���!\n");
//	//}
//	//else
//	//{
//	//	printf("û���ҵ���\n");
//	//}
//
//	////����ǰ����
//	//SLTNode* find = NULL;
//	//find = SLTFind(plist, 1);
//	//SLTInsert(&plist, find, 7);
//	//SLTPrint(plist);
//	//find = SLTFind(plist, 4);
//	//SLTInsert(&plist, find, 8);
//	//SLTPrint(plist);
//
//	////���Ժ����
//	//SLTNode* find = NULL;
//	//find = SLTFind(plist, 1);
//	//SLTInsertAfter(find, 7);
//	//SLTPrint(plist);
//	//find = SLTFind(plist, 4);
//	//SLTInsertAfter(find, 8);
//	//SLTPrint(plist);
//
//	////����ɾ��
//	//SLTNode* find = NULL;
//	//find = SLTFind(plist, 1);
//	//SLTErase(&plist, find);
//	//SLTPrint(plist);
//	//find = SLTFind(plist, 4);
//	//SLTErase(&plist, find);
//	//SLTPrint(plist);
//
//	////���Ժ�ɾ��
//	//SLTNode* find = NULL;
//	//find = SLTFind(plist, 1);
//	//SLTEraseAfter(find);
//	//SLTPrint(plist);
//	//find = SLTFind(plist, 3);
//	//SLTEraseAfter(find);
//	//SLTPrint(plist);
//
//	//��������
//	SListDestroy(&plist);
//	SLTPrint(plist);
//}

//void Contacttest01()
//{
//	Contact* con = NULL;
//	//InitContact(&con);
//
//	AddContact(&con);
//}
//
//int main()
//{
//	//SListTest01();
//	//SListTest02();
//
//	Contacttest01();
//
//	return 0;
//}

void menu(void)
{
	printf("***************ͨѶ¼****************\n");
	printf("*                                   *\n");
	printf("*           1.������ϵ��            *\n");
	printf("*           2.ɾ����ϵ��            *\n");
	printf("*           3.�޸���ϵ��            *\n");
	printf("*           4.������ϵ��            *\n");
	printf("*           5.չʾ��ϵ��            *\n");
	//printf("*           6.��ȡ��ϵ��            *\n");
	//printf("*           7.������ϵ��            *\n");
	printf("*              0.�˳�               *\n");
	printf("*                                   *\n");
	printf("*************************************\n");
}

int main()
{
	int input = 0;
	Contact* con = NULL;
	//ContactInit(&con);
	do
	{
		menu();
		printf("��ѡ��");
		scanf("%d", &input);
		//ѡ��
		switch (input)
		{
		case 1:
			AddContact(&con);
			break;
		case 2:
			DelContact(&con);
			break;
		case 3:
			ModifyContact(&con);
			break;
		case 4:
			FindContact(&con);
			break;
		case 5:
			ShowContact(&con);
			break;
		//case 6:
		//	ReadContact(&con);
		//	break;
		//case 7:
		//	SaveContact(&con);
		//	break;
		case 0:
			printf("�˳�ͨѶ¼����\n");
			break;
		default:
			printf("����������������룡\n");
			break;
		}
	} while (input);
	DestroyContact(&con);
	return 0;
}