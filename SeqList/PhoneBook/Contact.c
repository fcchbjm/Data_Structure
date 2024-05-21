#include "Contact.h"
#include "SeqList.h"
#include <string.h>

//通讯录的初始化
void ContactInit(Contact* con)
{
	//con就是SL
	SLInit(con);
}

//通讯录的销毁
void ContactDestroy(Contact* con)
{
	//SaveContact(con);//在销毁退出前保存数据
	SLDestroy(con);
}

//通讯录添加数据
void ContactAdd(Contact* con)
{
	//获取用户输入的内容
	//姓名+性别+年龄+电话+地址
	PeoInfo info;
	printf("请输入联系人姓名：");
	scanf("%s", info.name);
	printf("请输入联系人性别：");
	scanf("%s", info.gender);
	printf("请输入联系人年龄：");
	scanf("%d", &info.age);
	printf("请输入联系人电话：");
	scanf("%s", info.tel);
	printf("请输入联系人地址：");
	scanf("%s", info.addr);

	//往通讯录中添加联系人数据
	SLPushBack(con, info);
}

int FindByName(Contact* con, char name[])
{
	for (int i = 0; i < con->size; i++)
	{
		if (0 == strcmp(con->arr[i].name, name))
		{
			//找到了
			return i;
		}
	}
	//没有找到
	return -1;
}

//通讯录删除数据
void ContactDel(Contact* con)
{
	//数据必须先存在，才能删除
	//查找
	char name[NAME_MAX] = { 0 };
	printf("请输入要删除的联系人姓名：");
	scanf("%s", name);

	int find = FindByName(con, name);
	if (find < 0)
	{
		printf("要删除的联系人不存在！\n");
		return;
	}
	else
	{
		//找到了该联系人数据，找到了下标 —— 删除指定位置的数据
		SLErase(con, find);
		printf("删除成功！\n");
	}
}

//通讯录的修改
void ContactModify(Contact* con)
{
	//要修改的联系人数据存在
	char name[NAME_MAX] = { 0 };
	printf("请输入要修改的联系人姓名：");
	scanf("%s", name);

	int find = FindByName(con, name);
	if (find < 0)
	{
		printf("联系人数据不存在！\n");
		return;
	}
	else
	{
		printf("请输入联系人新的姓名：");
		scanf("%s", con->arr[find].name);
		printf("请输入联系人新的性别：");
		scanf("%s", con->arr[find].gender);
		printf("请输入联系人新的年龄：");
		scanf("%d", &(con->arr[find].age));
		printf("请输入联系人新的电话：");
		scanf("%s", con->arr[find].tel);
		printf("请输入联系人新的地址：");
		scanf("%s", con->arr[find].addr);
		printf("修改成功！\n");
	}
}

//通讯录的查找
void ContactFind(Contact* con)
{
	char name[NAME_MAX] = { 0 };
	printf("请输入要查找的联系人姓名：");
	scanf("%s", name);

	int find = FindByName(con, name);
	if (find < 0)
	{
		printf("联系人数据不存在！\n");
		return;
	}
	else
	{
		//表头： 姓名 性别 年龄 电话 地址
		printf("%5s %5s %5s %10s %5s\n", "姓名", "性别", "年龄", "电话", "地址");
		printf("%5s %5s %5d %10s %5s\n", \
			con->arr[find].name, \
			con->arr[find].gender, \
			con->arr[find].age, \
			con->arr[find].tel, \
			con->arr[find].addr);
	}
}

//展示通讯录数据
void ContactShow(Contact* con)
{
	//表头： 姓名 性别 年龄 电话 地址
	printf("%5s %5s %5s %10s %5s\n", "姓名", "性别", "年龄", "电话", "地址");
	for (int i = 0; i < con->size; i++)
	{
		printf("%5s %5s %5d %10s %5s\n", \
			con->arr[i].name, \
			con->arr[i].gender, \
			con->arr[i].age, \
			con->arr[i].tel, \
			con->arr[i].addr);
	}
}

//保存通讯录数据
void SaveContact(Contact* con)
{
	FILE* pf = NULL;
	pf = fopen("Contact.dat", "w");
	if (pf == NULL)
	{
		perror("Failed to write to file");
		return;
	}
	//写入数据
	fprintf(pf, "%d\n", con->size);//写入有效数据个数
	for (int i = 0; i < con->size; i++)//写入通讯录数据
	{
		fprintf(pf, "%s %s %d %s %s\n", \
			con->arr[i].name, \
			con->arr[i].gender, \
			con->arr[i].age, \
			con->arr[i].tel, \
			con->arr[i].addr);
	}
	printf("数据保存成功！\n");
	fclose(pf);
	pf = NULL;
}

//读取通讯录数据
void ReadContact(Contact* con)
{
	FILE* pf = NULL;
	pf = fopen("Contact.dat", "r");
	if (pf == NULL)
	{
		perror("Failed to read to file");
		return;
	}
	fscanf(pf, "%d", &(con->size));//读取有效数据个数
	for (int i = 0; i < con->size; i++)
	{
		PeoInfo info = { 0 };
		fscanf(pf, "\n%s %s %d %s %s", \
			info.name, \
			info.gender, \
			& (info.age), \
			info.tel, \
			info.addr);
		//SLPushBack(con, info);//不能使用尾插
		SLCheckCapacity(con);//容量判断
		con->arr[i] = info;
	}
	printf("数据读取成功！\n");
	fclose(pf);
	pf = NULL;
}