#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLDataType;

//��̬˳���
typedef struct SeqList
{
	SLDataType* arr;
	int size;
	int capacity;
}SL;

//˳���ĳ�ʼ��
void SLInit(SL* ps);
//˳��������
void SLDestory(SL* ps);
//ͷ����������
void SLPushFront(SL* ps, SLDataType x);
//β����������
void SLPushBack(SL* ps, SLDataType x);
//��ӡ˳���
void SLPrint(SL s);
//ͷ��ɾ������
void SLPopFront(SL* ps);
//β��ɾ������
void SLPopBack(SL* ps);