#include  "Sort.h"

void Swap(SortDataType* p1, SortDataType* p2)
{
	SortDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//插入排序
// 时间复杂度：O(N^2)
// 最坏情况：逆序 O(N^2)  最好情况：顺序 O(N)
void InsertSort(SortDataType* arr, int num)
{
	for (int i = 0; i < num - 1; i++)
	{
		int end = i;
		SortDataType tmp = arr[end + 1];
		while (end >= 0)//假设[0, end]已经有序
		{
			if (tmp < arr[end])
			{
				arr[end + 1] = arr[end];
				--end;
			}
			else
			{
				break;
			}
		}
		arr[end + 1] = tmp;//如果插入数组[0]
	}
}

void AdjustDown(SortDataType* arr, int n, int parent)//堆顶元素向下调整
{
	//假设左孩子小
	int child = parent * 2 + 1;
	while (child < n)//如果child >= n，说明孩子不存在，调整到叶子了
	{
		//找出小的那个孩子
		if (child + 1 < n && arr[child + 1] > arr[child])//防止越界
		{
			++child;
		}

		if (arr[child] > arr[parent])
		{
			Swap(&arr[child], &arr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(SortDataType* arr, int num)
{
	//建堆
	for (int i = (num - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(arr, num, i);
	}

	//排序
	int end = num - 1;
	while (end > 0)
	{
		Swap(&arr[0], &arr[end]);
		AdjustDown(arr, end, 0);
		--end;
	}
}

//冒泡排序
// 时间复杂度：O(N^2)
// 最坏情况：逆序 O(N^2)  最好情况：顺序 O(N)
void BubbleSort(SortDataType* arr, int num)
{
	for (int i = 0; i < num - 1; i++)
	{
		int flag = 1;
		for (int j = 0; j < num - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				Swap(&arr[j], &arr[j + 1]);
				flag = 0;
			}
		}
		if (flag)
		{
			break;
		}
	}
}
