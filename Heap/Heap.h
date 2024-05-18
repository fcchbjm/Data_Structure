#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef int HPDataType;

typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}HP;

void HPInit(HP* php);

void HPDestroy(HP* php);

//插入数据
void HPPush(HP* php, HPDataType x);

//删除堆顶元素（根位置）
void HPPop(HP* php);

//返回堆顶元素
HPDataType HPTop(HP* php);

//判空
_Bool HPEmpty(HP* php);

//向上调整
void AdjustUp(HPDataType* a, int child);

//堆顶元素向下调整
void AdjustDown(HPDataType* a, int n, int parent);

//交换
void Swap(HPDataType* p1, HPDataType* p2);
