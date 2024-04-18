#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

////初始化通讯录
//void InitContact(Contact** con)
//{
//	*con = (Contact*)malloc(sizeof(Contact));
//	if (*con == NULL)
//	{
//		perror("malloc failed!");
//		exit(1);
//	}
//
//	(*con)->next = NULL;
//}

//通讯录添加数据
void AddContact(Contact** con)
{
	//获取用户输入的内容
	//姓名+性别+年龄+电话+地址
	PeoInfo info;
	printf("请输入联系人姓名：");
	scanf("%s", info.name);
	printf("请输入联系人性别：");
	scanf("%s", info.sex);
	printf("请输入联系人年龄：");
	scanf("%d", &info.age);
	printf("请输入联系人电话：");
	scanf("%s", info.tel);
	printf("请输入联系人地址：");
	scanf("%s", info.addr);

	//往通讯录中添加联系人数据
	SLTPushBack(con, info);
}


Contact* FindByName(Contact** con, char name[])
{
	Contact* pcur = *con;
	while (pcur)
	{
		if (strcmp(pcur->data.name, name) == 0)
		{
			return pcur;
		}
		pcur = pcur->next;
	}
	return NULL;
}

//通讯录删除数据
void DelContact(Contact** con)
{
	//数据必须先存在，才能删除
	//查找
	char name[NAME_MAX] = { 0 };
	printf("请输入要删除的联系人姓名：");
	scanf("%s", name);

	Contact* find = FindByName(con, name);
	if (find == NULL)
	{
		printf("要删除的联系人不存在！\n");
		return;
	}
	else
	{
		//找到了该联系人数据，找到了下标 —— 删除指定位置的数据
		SLTErase(con, find);
		printf("删除成功！\n");
	}
}

//通讯录的修改
void ModifyContact(Contact** con)
{
	//要修改的联系人数据存在
	char name[NAME_MAX] = { 0 };
	printf("请输入要修改的联系人姓名：");
	scanf("%s", name);

	Contact* find = FindByName(con, name);
	if (find == NULL)
	{
		printf("联系人数据不存在！\n");
		return;
	}
	else
	{
		printf("请输入联系人新的姓名：");
		scanf("%s", find->data.name);
		printf("请输入联系人新的性别：");
		scanf("%s", find->data.sex);
		printf("请输入联系人新的年龄：");
		scanf("%d", &(find->data.age));
		printf("请输入联系人新的电话：");
		scanf("%s", find->data.tel);
		printf("请输入联系人新的地址：");
		scanf("%s", find->data.addr);
		printf("修改成功！\n");
	}
}

//通讯录的查找
void FindContact(Contact** con)
{
	char name[NAME_MAX] = { 0 };
	printf("请输入要查找的联系人姓名：");
	scanf("%s", name);

	Contact* find = FindByName(con, name);
	if (find == NULL)
	{
		printf("联系人数据不存在！\n");
		return;
	}
	else
	{
		//表头： 姓名 性别 年龄 电话 地址
		printf("%5s %5s %5s %10s %5s\n", "姓名", "性别", "年龄", "电话", "地址");
		printf("%5s %5s %5d %10s %5s\n", \
			find->data.name, \
			find->data.sex, \
			find->data.age, \
			find->data.tel, \
			find->data.addr);
	}
}

//展示通讯录数据
void ShowContact(Contact** con)
{
	//表头： 姓名 性别 年龄 电话 地址
	printf("%5s %5s %5s %10s %5s\n", "姓名", "性别", "年龄", "电话", "地址");
	Contact* pcur = *con;
	do
	{
		printf("%5s %5s %5d %10s %5s\n", \
			pcur->data.name, \
			pcur->data.sex, \
			pcur->data.age, \
			pcur->data.tel, \
			pcur->data.addr);
		pcur = pcur->next;
	} while (pcur);
}

//通讯录的销毁
void DestroyContact(Contact* con)
{
	//SaveContact(con);//在销毁退出前保存数据
	SListDestroy(con);
}

