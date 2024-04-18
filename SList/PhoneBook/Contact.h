#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define NAME_MAX 100
#define SEX_MAX 4
#define TEL_MAX 11
#define ADDR_MAX 100

//前置声明
typedef struct SListNode Contact;

//用户数据
typedef struct PersonInfo
{
    char name[NAME_MAX];
    char sex[SEX_MAX];
    int age;
    char tel[TEL_MAX];
    char addr[ADDR_MAX];
}PeoInfo;

//初始化通讯录
//void InitContact(Contact** con);
//添加通讯录数据
void AddContact(Contact** con);
//删除通讯录数据
void DelContact(Contact** con);
//展示通讯录数据
void ShowContact(Contact* con);
//查找通讯录数据
void FindContact(Contact* con);
//修改通讯录数据
void ModifyContact(Contact** con);
//销毁通讯录数据
void DestroyContact(Contact** con);
