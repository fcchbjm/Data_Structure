 #pragma once

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Contact.h"

//typedef int SLDataType;

//将通讯录结构体类型重命名为SLDataType
typedef PeoInfo SLDataType;

//动态顺序表
//将结构体SeqList重命名为SL
typedef struct SeqList
{
	SLDataType* arr;
	int size;
	int capacity;
}SL;

//顺序表的初始化
void SLInit(SL* ps);
//顺序表的销毁
void SLDestroy(SL* ps);
//头部插入数据
void SLPushFront(SL* ps, SLDataType x);
//尾部插入数据
void SLPushBack(SL* ps, SLDataType x);
//打印顺序表
void SLPrint(SL s);
//头部删除数据
void SLPopFront(SL* ps);
//尾部删除数据
void SLPopBack(SL* ps);
//任意位置前插入数据
void SLInsert(SL* ps, int pos, SLDataType x);
//任意位置删除数据
void SLErase(SL* ps, int pos);
//顺序表的查找
//int SLFind(SL* ps, SLDataType x);