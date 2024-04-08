#include "SeqList.h"

//void SLtest(void)
//{
//	SL sl;
//	SLInit(&sl);
//	
//	for (int i = 0; i < 10; i++)
//	{
//		SLPushBack(&sl, i);
//		SLPrint(sl);
//	}
//
//	for (int i = 0; i < 10; i++)
//	{
//		SLPushFront(&sl, i);
//		SLPrint(sl);
//	}
//
//	SLPopFront(&sl);
//	SLPrint(sl);
//
//	SLPopBack(&sl);
//	SLPrint(sl);
//
//	SLDestory(&sl);
//}

//void SLtest2()
//{
//	SL sl;
//	SLInit(&sl);
//
//	for (int i = 0; i < 10; i++)
//	{
//		SLPushBack(&sl, i);
//	}
//	SLPrint(sl);
//
//	SLErase(&sl, 0);
//	SLPrint(sl);
//
//	SLInsert(&sl, 1, 10);
//	SLPrint(sl);
//
//	int ret = 0;
//	ret = SLFind(&sl, 5);
//	printf("ret=%d\n", ret);
//
//	ret = SLFind(&sl, 11);
//	printf("ret=%d\n", ret);
//
//	SLDestory(&sl);
//}

//void ContactTest01()
//{
//	Contact con;//������ͨѶ¼����ʵ���Ͼ���˳������
//	ContactInit(&con);//ͨѶ¼�ĳ�ʼ��
//
//	ContactAdd(&con);//�������
//	ContactAdd(&con);
//	ContactShow(&con);
//
//	//ContactDel(&con);
//	//ContactShow(&con);
//
//	//ContactModify(&con);
//	//ContactShow(&con);
//
//	ContactFind(&con);
//
//	ContactDestory(&con);//ͨѶ¼������
//}

//int main()
//{
//	//˳���Ĳ���
//	//SLtest();
//	//SLtest2();
//
//	//ͨѶ¼�Ĳ���
//	ContactTest01();
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
	printf("*              0.�˳�               *\n");
	printf("*                                   *\n");
	printf("*************************************\n");
}

int main()
{
	int input = 0;
	Contact con;
	ContactInit(&con);
	do
	{
		menu();
		printf("��ѡ��");
		scanf("%d", &input);
		//ѡ��
		switch (input)
		{
		case 1:
			ContactAdd(&con);
			break;
		case 2:
			ContactDel(&con);
			break;
		case 3:
			ContactModify(&con);
			break;
		case 4:
			ContactFind(&con);
			break;
		case 5:
			ContactShow(&con);
			break;
		case 0:
			printf("�˳�ͨѶ¼����\n");
			break;
		default:
			printf("����������������룡\n");
			break;
		}
	} while (input);
	ContactDestory(&con);
	return 0;
}