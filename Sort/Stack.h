#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

typedef int STDataType;

typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;

//��ʼ��
void STInit(ST* pst);

//����
void STDestroy(ST* pst);

//�������ݣ���ջ��
void STPush(ST* pst, STDataType x);

//ɾ�����ݣ���ջ��
void STPop(ST* pst);

//��ȡջ������
STDataType STTop(ST* pst);

//�п�
_Bool STEmpty(ST* pst);

//��ȡ���ݸ���
int STSize(ST* pst);
