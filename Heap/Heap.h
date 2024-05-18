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

//��������
void HPPush(HP* php, HPDataType x);

//ɾ���Ѷ�Ԫ�أ���λ�ã�
void HPPop(HP* php);

//���ضѶ�Ԫ��
HPDataType HPTop(HP* php);

//�п�
_Bool HPEmpty(HP* php);

//���ϵ���
void AdjustUp(HPDataType* a, int child);

//�Ѷ�Ԫ�����µ���
void AdjustDown(HPDataType* a, int n, int parent);

//����
void Swap(HPDataType* p1, HPDataType* p2);
