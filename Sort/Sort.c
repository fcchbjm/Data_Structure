#include  "Sort.h"

void Swap(SortDataType* p1, SortDataType* p2)
{
	if (p1 != p2)
	{
		SortDataType tmp = *p1;
		*p1 = *p2;
		*p2 = tmp;
	}
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

//希尔排序
// 时间复杂度O(N^(1.3))
void ShellSort(SortDataType* arr, int num)
{
	int gap = num;
	while (gap > 1)//gap > 1 预排序 gap == 1 插入排序
	{
		gap = gap / 3 + 1;//保证最后一次是1
		for (int i = 0; i < num - gap; i++)
		{
			int end = i;
			SortDataType tmp = arr[end + gap];
			while (end >= 0)
			{
				if (tmp < arr[end])
				{
					arr[end + gap] = arr[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			arr[end + gap] = tmp;
		}
		
	}
}

//选择排序
// 时间复杂度：O(N^2)
void SelectSort(SortDataType* arr, int num)
{
	int begin = 0;
	int end = num - 1;
	while (begin < end)
	{
		int mini = begin;
		int maxi = begin;
		for (int i = begin + 1; i <= end; i++)
		{
			if (arr[i] > arr[maxi])
			{
				maxi = i;
			}
			if (arr[i] > arr[mini])
			{
				mini = i;
			}
		}
		Swap(&arr[begin], &arr[mini]);
		if (begin == maxi)
		{
			maxi = mini;
		}	 
		Swap(&arr[end], &arr[maxi]);
		begin++;
		end--;
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

/*
//快速排序
// 时间复杂度：最好O(NlogN)
// 缺点：有序时，可能会栈溢出
void QuickSort_hoare(SortDataType* arr, int left, int right)
{
	if (left >= right)
		return;
	int keyi = left;
	int begin = left;
	int end = right;
	while (begin < end)
	{
		//右边找小
		while (arr[end] >= arr[keyi] && begin < end)
		{
			--end;
		}
		//左边找大
		while (arr[begin] <= arr[keyi] && begin < end)
		{
			++begin;
		}
		Swap(&arr[begin], &arr[end]);
	}
	Swap(&arr[keyi], &arr[begin]);
	keyi = begin;
	//[left, keyi - 1] keyi [keyi + 1, end]
	QuickSort_hoare(arr, left, keyi - 1);
	QuickSort_hoare(arr, keyi + 1, right);
}
*/

int GetMidi(SortDataType* arr, int left, int right)
{
	int midi = (left + right) / 2;
	//left midi right
	if (arr[left] < arr[midi])
	{
		if (arr[midi] < arr[right])
			return midi;
		else if (arr[left] < arr[right])
			return right;
		else
			return left;
	}
	else //arr[left] >= arr[midi]
	{
		if (arr[midi] > arr[right])
			return midi;
		else if (arr[left] < arr[right])
			return left;
		else
			return right;
	}
}

// 快速排序 - hoare法
// 避免有序情况下，效率退化
// 1. 随机选key
// 2. 三数取中
int PartSort1(SortDataType* arr, int left, int right)
{
	//三数取中
	int midi = GetMidi(arr, left, right);
	Swap(&arr[left], &arr[midi]);

	int keyi = left;
	int begin = left;
	int end = right;
	while (begin < end)
	{
		//右边找小
		while (arr[end] >= arr[keyi] && begin < end)
		{
			--end;
		}
		//左边找大
		while (arr[begin] <= arr[keyi] && begin < end)
		{
			++begin;
		}
		Swap(&arr[begin], &arr[end]);
	}
	Swap(&arr[keyi], &arr[begin]);
	return begin;
}

//快速排序 - 前后指针法
int PartSort2(SortDataType* arr, int left, int right)
{
	//三数取中
	int midi = GetMidi(arr, left, right);
	Swap(&arr[left], &arr[midi]);
	int keyi = left;

	int prev = left;
	int cur = prev + 1;
	while (cur <= right)
	{
		if (arr[cur] < arr[keyi] && ++prev != cur)
		{
			Swap(&arr[prev], &arr[cur]);
		}
		++cur;
	}
	Swap(&arr[prev], &arr[keyi]);
	return prev;
}

//快速排序 - 递归版本
void QuickSortRec(SortDataType* arr, int left, int right)
{
	if (left >= right)
		return;

	//小区间优化 -- 不再递归分割排序，减少递归次数
	if ((right - left + 1) < 10)
	{
		InsertSort(arr + left, right - left + 1);
	}
	else
	{
		//int keyi = PartSort1(arr, left, right);
		int keyi = PartSort2(arr, left, right);
		
		//[left, keyi - 1] keyi [keyi + 1, end]
		QuickSort(arr, left, keyi - 1);
		QuickSort(arr, keyi + 1, right);
	}
}

#include "Stack.h"

//快速排序 - 非递归版本
void QuickSortNonR(SortDataType* arr, int left, int right)
{
	ST st;
	STInit(&st);
	STPush(&st, right);
	STPush(&st, left);

	while (!STEmpty(&st))
	{
		int begin = STTop(&st);
		STPop(&st);
		int end = STTop(&st);
		STPop(&st);

		//单趟排序
		int keyi = PartSort2(arr, begin, end);
		//[begin, keti - 1] keyi [keyi + 1, end]
		
		if (keyi + 1 < end)
		{
			//右区间入栈
			STPush(&st, end);
			STPush(&st, keyi + 1);
		}

		if (begin < keyi - 1)
		{
			//左区间入栈
			STPush(&st, keyi - 1);
			STPush(&st, begin);
		}
	}
	STDestroy(&st);
}

//快速排序
// 时间复杂度：最好O(NlogN)
void QuickSort(SortDataType* arr, int left, int right)
{
	//QuickSortRec(arr, left, right);
	QuickSortNonR(arr, left, right);
}

void _MergeSortRec(SortDataType* arr, SortDataType* tmp, int begin, int end)
{
	//区间只有一个值
	if (begin == end)
	{
		return;
	}

	int mid = (begin + end) / 2;
	//如果[begin, mid - 1] [mid, end]有序，就可以进行归并
	_MergeSortRec(arr, tmp, begin, mid);
	_MergeSortRec(arr, tmp, mid + 1, end);

	//归并
	int begin1 = begin;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = end;
	int i = begin;
	//比较，小的放在前面
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (arr[begin1] < arr[begin2])
		{
			tmp[i++] = arr[begin1++];
		}
		else
		{
			tmp[i++] = arr[begin2++];
		}
	}

	//剩下的内容放在末尾，两个循环只会进入一个
	while (begin1 <= end1)
	{
		tmp[i++] = arr[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = arr[begin2++];
	}

	memcpy(arr + begin, tmp + begin, (end - begin + 1) * sizeof(SortDataType));
}

//归并排序 - 递归版本
void MergeSortRec(SortDataType* arr, int num)
{
	SortDataType* tmp = (SortDataType*)malloc(sizeof(SortDataType) * num);
	if (tmp == NULL)
	{
		perror("malloc failed");
		return;
	}

	_MergeSortRec(arr, tmp, 0, num - 1);

	free(tmp);
	tmp = NULL;
}

//归并排序 - 非递归版本
void MergeSortNonR(SortDataType* arr, int num)
{
}

//归并排序
void MergeSort(SortDataType* arr, int num)
{
	MergeSortRec(arr, num);
}

