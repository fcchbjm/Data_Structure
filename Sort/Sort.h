#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int SortDataType;

//��������
void InsertSort(SortDataType* arr, int num);

//������
void HeapSort(SortDataType* arr, int num);

//ð������
void BubbleSort(SortDataType* arr, int num);