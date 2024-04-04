#include "SeqList.h"

void SLInit(SL* ps)
{
	ps->arr = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

void SLDestory(SL* ps)
{
	if (ps->arr)
	{
		free(ps->arr);
	}
	ps->arr = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

void SLCheckCapacity(SL* ps)
{
	//�ڲ�������ǰ���жϿռ乻����
	if (ps->size == ps->capacity)
	{
		//����ռ� -- ���� --> realloc
		//����һ���������������������ӣ�������߹�С��Ƶ�������ݣ���ʹ���������Ч�ʽ���
		//ע�⣺�ж�capacity�Ƿ�Ϊ0
		int newcapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		SLDataType* tmp = (SLDataType*)realloc(ps->arr, newcapacity * sizeof(SLDataType));
		if (tmp == NULL)
		{
			perror("realloc failed");
			exit(1);
		}
		ps->arr = tmp;
		ps->capacity = newcapacity;
	}
}

void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps);

	////�ڲ�������ǰ���жϿռ乻����
	//if (ps->size == ps->capacity)
	//{
	//	//����ռ� -- ���� --> realloc
	//	//����һ���������������������ӣ�������߹�С��Ƶ�������ݣ���ʹ���������Ч�ʽ���
	//	//ע�⣺�ж�capacity�Ƿ�Ϊ0
	//	int newcapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
	//	SLDataType* tmp = (SLDataType*)realloc(ps->arr, newcapacity * sizeof(SLDataType));
	//	if (tmp == NULL)
	//	{
	//		perror("realloc failed");
	//		exit(1);
	//	}
	//	ps->arr = tmp;
	//	ps->capacity = newcapacity;
	//}

	SLCheckCapacity(ps);

	//β��
	ps->arr[ps->size++] = x;
	//ps->arr[ps->size] = x;
	//++(ps->size);
}

void SLPushFront(SL* ps, SLDataType x)
{
	assert(ps);

	SLCheckCapacity(ps);

	//�������������������ƶ�һλ
	for (int i = ps->size; i > 0; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}

	ps->arr[0] = x;
	ps->size++;
}

void SLPrint(SL s)
{
	for (int i = 0; i < s.size; i++)
	{
		printf("%d ", s.arr[i]);
	}
	printf("\n");
}

void SLPopBack(SL* ps)
{
	assert(ps);
	assert(ps->size > 0);
	//ps->arr[ps->size - 1] = -1;
	--(ps->size);
}

void SLPopFront(SL* ps)
{
	assert(ps);
	assert(ps->size > 0);
	for (int i = 0; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	--(ps->size);
}

void SLInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);

	SLCheckCapacity(ps);

	for (int i = ps->size; i > pos; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[pos] = x;
	ps->size++;
}

void SLErase(SL* ps, int pos)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);
	for (int i = pos; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}

int SLFind(SL* ps, SLDataType x)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->arr[i] == x)
		{
			return i;
		}
	}
	return -1;
}