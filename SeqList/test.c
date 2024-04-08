#include "SeqList.h"

void SLtest(void)
{
	SL sl;
	SLInit(&sl);//��ʼ��
	
	for (int i = 0; i < 10; i++)
	{
		SLPushBack(&sl, i);//β��1~9
		SLPrint(sl);
	}

	for (int i = 0; i < 10; i++)
	{
		SLPushFront(&sl, i);//ͷ��1~9
		SLPrint(sl);
	}

	SLPopFront(&sl);//ͷɾ
	SLPrint(sl);

	SLPopBack(&sl);//βɾ
	SLPrint(sl);

	SLDestory(&sl);//����
}

void SLtest2()
{
	SL sl;
	SLInit(&sl);//��ʼ��

	for (int i = 0; i < 10; i++)
	{
		SLPushBack(&sl, i);//β��1~9
	}
	SLPrint(sl);

	SLErase(&sl, 0);//ɾ����һ��Ԫ��
	SLPrint(sl);

	SLInsert(&sl, 1, 10);//�ڵڶ���Ԫ��ǰ����10
	SLPrint(sl);

	int ret = 0;
	ret = SLFind(&sl, 5);//����5���Ԫ��
	printf("ret=%d\n", ret);

	ret = SLFind(&sl, 11);//����11���Ԫ��
	printf("ret=%d\n", ret);

	SLDestory(&sl);//����
}

int main()
{
	SLtest();
	SLtest2();
	return 0;
}