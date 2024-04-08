#include "SeqList.h"

void SLtest(void)
{
	SL sl;
	SLInit(&sl);//初始化
	
	for (int i = 0; i < 10; i++)
	{
		SLPushBack(&sl, i);//尾插1~9
		SLPrint(sl);
	}

	for (int i = 0; i < 10; i++)
	{
		SLPushFront(&sl, i);//头插1~9
		SLPrint(sl);
	}

	SLPopFront(&sl);//头删
	SLPrint(sl);

	SLPopBack(&sl);//尾删
	SLPrint(sl);

	SLDestory(&sl);//销毁
}

void SLtest2()
{
	SL sl;
	SLInit(&sl);//初始化

	for (int i = 0; i < 10; i++)
	{
		SLPushBack(&sl, i);//尾插1~9
	}
	SLPrint(sl);

	SLErase(&sl, 0);//删掉第一个元素
	SLPrint(sl);

	SLInsert(&sl, 1, 10);//在第二个元素前插入10
	SLPrint(sl);

	int ret = 0;
	ret = SLFind(&sl, 5);//查找5这个元素
	printf("ret=%d\n", ret);

	ret = SLFind(&sl, 11);//查找11这个元素
	printf("ret=%d\n", ret);

	SLDestory(&sl);//销毁
}

int main()
{
	SLtest();
	SLtest2();
	return 0;
}