#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int SortDataType;

//≤Â»Î≈≈–Ú
void InsertSort(SortDataType* arr, int num);

//œ£∂˚≈≈–Ú
void ShellSort(SortDataType* arr, int num);

//—°‘Ò≈≈–Ú
void SelectSort(SortDataType* arr, int num);

//∂—≈≈–Ú
void HeapSort(SortDataType* arr, int num);

//√∞≈›≈≈–Ú
void BubbleSort(SortDataType* arr, int num);

//øÏÀŸ≈≈–Ú
void QuickSort(SortDataType* arr, int left, int right);


