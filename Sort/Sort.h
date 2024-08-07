#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef int SortDataType;

//��������
void InsertSort(SortDataType* arr, int num);

//ϣ������
void ShellSort(SortDataType* arr, int num);

//ѡ������
void SelectSort(SortDataType* arr, int num);

//������
void HeapSort(SortDataType* arr, int num);

//ð������
void BubbleSort(SortDataType* arr, int num);

//��������
void QuickSort(SortDataType* arr, int left, int right);

//�鲢����
void MergeSort(SortDataType* arr, int num);

//��������
void CountSort(int* arr, int num);
