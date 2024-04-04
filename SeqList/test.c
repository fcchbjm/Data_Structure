#include "SeqList.h"

void SLtest(void)
{
	SL sl;
	SLInit(&sl);
	
	for (int i = 0; i < 10; i++)
	{
		SLPushBack(&sl, i);
	}

	for (int i = 0; i < 10; i++)
	{
		SLPushFront(&sl, i);
	}

	SLPopFront(&sl);

	SLPopBack(&sl);

	SLDestory(&sl);
}

int main()
{
	SLtest();
	return 0;
}