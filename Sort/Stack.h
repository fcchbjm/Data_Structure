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

//初始化
void STInit(ST* pst);

//销毁
void STDestroy(ST* pst);

//插入数据（入栈）
void STPush(ST* pst, STDataType x);

//删除数据（出栈）
void STPop(ST* pst);

//获取栈顶数据
STDataType STTop(ST* pst);

//判空
_Bool STEmpty(ST* pst);

//获取数据个数
int STSize(ST* pst);
