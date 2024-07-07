#include "Heap.h"
#include "vld.h"

void TestHeap01()
{
	int a[10] = { 2,3,4,1,6,5,9,8,7,0 };
	HP hp;
	HPInit(&hp);
	size_t sz = sizeof(a) / sizeof(int);
	for (size_t i = 0; i < sz; i++)
	{
		HPPush(&hp, a[i]);
	}

	int i = 0;
	while (!HPEmpty(&hp))
	{
		//printf("%d ", HPTop(&hp));
		a[i++] = HPTop(&hp);
		HPPop(&hp);
	}

	HPDestroy(&hp);
}

void HeapSort(HPDataType* a, int n)
{
	//Ω®∂—
	//Ωµ–Ú -- Ω®–°∂—
	//…˝–Ú -- Ω®¥Û∂—

	//for (int i = 1; i < n; i++)
	//{
	//	AdjustUp(a, i);
	//}

	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}

	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}

//≈≈–Ú
//void HeapSort(HPDataType* a, int n);

void TestHeap02()
{
	int a[10] = { 2,3,4,1,6,5,9,8,7,0 };
	size_t sz = sizeof(a) / sizeof(int);
	HeapSort(a, sz);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", a[i]);
	}

}

int main()
{
	//TestHeap01();
	TestHeap02();
	return 0;
}
