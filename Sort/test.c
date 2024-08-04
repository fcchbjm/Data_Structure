#include "Sort.h"

void PrintArray(int* arr, int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void SortTest01()
{
	int arr[] = { 2,3,4,1,5,6,0,9,8,7 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	InsertSort(arr, sz);
	PrintArray(arr, sz);
}

void SortTest02()
{
	int arr[] = { 2,3,4,1,5,6,0,9,8,7 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	HeapSort(arr, sz);
	PrintArray(arr, sz);
}

void SortTest03()
{
	int arr[] = { 2,3,4,1,5,6,0,9,8,7 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	BubbleSort(arr, sz);
	PrintArray(arr, sz);
}

void SortTest04()
{
	int arr[] = { 2,3,4,1,5,6,0,9,8,7 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	ShellSort(arr, sz);
	PrintArray(arr, sz);
}

void SortTest05()
{
	int arr[] = { 2,3,4,1,5,6,0,9,8,7 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	SelectSort(arr, sz);
	PrintArray(arr, sz);
}

void SortTest06()
{
	int arr[] = { 6,1,5,7,9,3,4,5,10,8 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	PrintArray(arr, sz);
	QuickSort(arr, 0, sz);
	PrintArray(arr, sz);
}

void TestOP()
{
	srand(time(NULL));
	const int N = 100000;

	int* arr1 = (int*)malloc(N * sizeof(int));
	if (arr1 == NULL)
	{
		perror("malloc failed");
		return;
	}
	int* arr2 = (int*)malloc(N * sizeof(int));
	if (arr2 == NULL)
	{
		perror("malloc failed");
		return;
	}
	int* arr3 = (int*)malloc(N * sizeof(int));
	if (arr3 == NULL)
	{
		perror("malloc failed");
		return;
	}
	int* arr4 = (int*)malloc(N * sizeof(int));
	if (arr4 == NULL)
	{
		perror("malloc failed");
		return;
	}
	int* arr5 = (int*)malloc(N * sizeof(int));
	if (arr5 == NULL)
	{
		perror("malloc failed");
		return;
	}
	int* arr6 = (int*)malloc(N * sizeof(int));
	if (arr6 == NULL)
	{
		perror("malloc failed");
		return;
	}
	int* arr7 = (int*)malloc(N * sizeof(int));
	if (arr7 == NULL)
	{
		perror("malloc failed");
		return;
	}

	for (int i = 0; i < N; i++)
	{
		//�ظ��ܶ�
		//arr1[i] = rand();
		//�ظ�����
		arr1[i] = rand() + i;
		arr2[i] = arr1[i];
		arr3[i] = arr1[i];
		arr4[i] = arr1[i];
		arr5[i] = arr1[i];
		arr6[i] = arr1[i];
		arr7[i] = arr1[i];
	}

	int begin1 = clock();
	InsertSort(arr1, N);
	int end1 = clock();

	int begin2 = clock();
	ShellSort(arr2, N);
	int end2 = clock();

	int begin3 = clock();
	SelectSort(arr3, N);
	int end3 = clock();

	int begin4 = clock();
	HeapSort(arr4, N);
	int end4 = clock();

	int begin5 = clock();
	QuickSort(arr5, 0, N);
	int end5 = clock();

	int begin6 = clock();

	int end6 = clock();

	int begin7 = clock();
	BubbleSort(arr7, N);
	int end7 = clock();

	printf("InsertSort:%d\n", end1 - begin1);
	printf("ShellSort:%d\n", end2 - begin2);
	printf("SelectSort:%d\n", end3 - begin3);
	printf("HeapSort:%d\n", end4 - begin4);
	printf("QuickSort:%d\n", end5 - begin5);
	printf("MergeSort:%d\n", end6 - begin6);
	printf("BubbleSort:%d\n", end7 - begin7);

	free(arr1);
	free(arr2);
	free(arr3);
	free(arr4);
	free(arr5);
	free(arr6);
	free(arr7);
}

int main()
{
	//SortTest01();
	//SortTest02();
	//SortTest03();
	//SortTest04();
	//SortTest05();
	//SortTest06();

	TestOP();

	return 0;
}