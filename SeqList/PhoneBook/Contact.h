#pragma once

#define NAME_MAX 20
#define GENDER_MAX 10
#define TEL_MAX 20
#define ADDR_MAX 100

//通讯录结构体
typedef struct PersonInfo
{
	char name[NAME_MAX];
	char gender[GENDER_MAX];
	int age;
	char tel[TEL_MAX];
	char addr[ADDR_MAX];
}PeoInfo;

//对结构体SL进行重命名为Contact
typedef struct SeqList Contact;

//struct SeqList;//声明结构体
//typedef SL Contact;//给结构体改名

//通讯录的初始化
void ContactInit(Contact* con);
//通讯录的销毁
void ContactDestory(Contact* con);
//通讯录添加数据
void ContactAdd(Contact* con);
//通讯录删除数据
void ContactDel(Contact* con);
//通讯录的修改
void ContactModify(Contact* con);
//通讯录的查找
void ContactFind(Contact* con);
//展示通讯录数据
void ContactShow(Contact* con);
