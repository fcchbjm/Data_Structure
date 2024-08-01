#include  "Sort.h"

void Swap(SortDataType* p1, SortDataType* p2)
{
	SortDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//��������
// ʱ�临�Ӷȣ�O(N^2)
// ���������� O(N^2)  ��������˳�� O(N)
void InsertSort(SortDataType* arr, int num)
{
	for (int i = 0; i < num - 1; i++)
	{
		int end = i;
		SortDataType tmp = arr[end + 1];
		while (end >= 0)//����[0, end]�Ѿ�����
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
		arr[end + 1] = tmp;//�����������[0]
	}
}

//ϣ������
// ʱ�临�Ӷ�O(N^(1.3))
void ShellSort(SortDataType* arr, int num)
{
	int gap = num;
	while (gap > 1)//gap > 1 Ԥ���� gap == 1 ��������
	{
		gap = gap / 3 + 1;//��֤���һ����1
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

//ѡ������
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

void AdjustDown(SortDataType* arr, int n, int parent)//�Ѷ�Ԫ�����µ���
{
	//��������С
	int child = parent * 2 + 1;
	while (child < n)//���child >= n��˵�����Ӳ����ڣ�������Ҷ����
	{
		//�ҳ�С���Ǹ�����
		if (child + 1 < n && arr[child + 1] > arr[child])//��ֹԽ��
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
	//����
	for (int i = (num - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(arr, num, i);
	}

	//����
	int end = num - 1;
	while (end > 0)
	{
		Swap(&arr[0], &arr[end]);
		AdjustDown(arr, end, 0);
		--end;
	}
}

//ð������
// ʱ�临�Ӷȣ�O(N^2)
// ���������� O(N^2)  ��������˳�� O(N)
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
