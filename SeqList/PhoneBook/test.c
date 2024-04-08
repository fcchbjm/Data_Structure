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
//	Contact con;//创建的通讯录对象，实际上就是顺序表对象
//	ContactInit(&con);//通讯录的初始化
//
//	ContactAdd(&con);//添加数据
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
//	ContactDestory(&con);//通讯录的销毁
//}

//int main()
//{
//	//顺序表的测试
//	//SLtest();
//	//SLtest2();
//
//	//通讯录的测试
//	ContactTest01();
//
//	return 0;
//}

void menu(void)
{
	printf("***************通讯录****************\n");
	printf("*                                   *\n");
	printf("*           1.增加联系人            *\n");
	printf("*           2.删除联系人            *\n");
	printf("*           3.修改联系人            *\n");
	printf("*           4.查找联系人            *\n");
	printf("*           5.展示联系人            *\n");
	printf("*              0.退出               *\n");
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
		printf("请选择：");
		scanf("%d", &input);
		//选择
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
			printf("退出通讯录……\n");
			break;
		default:
			printf("输入错误，请重新输入！\n");
			break;
		}
	} while (input);
	ContactDestory(&con);
	return 0;
}