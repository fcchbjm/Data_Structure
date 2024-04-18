#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

////��ʼ��ͨѶ¼
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

//ͨѶ¼�������
void AddContact(Contact** con)
{
	//��ȡ�û����������
	//����+�Ա�+����+�绰+��ַ
	PeoInfo info;
	printf("��������ϵ��������");
	scanf("%s", info.name);
	printf("��������ϵ���Ա�");
	scanf("%s", info.sex);
	printf("��������ϵ�����䣺");
	scanf("%d", &info.age);
	printf("��������ϵ�˵绰��");
	scanf("%s", info.tel);
	printf("��������ϵ�˵�ַ��");
	scanf("%s", info.addr);

	//��ͨѶ¼�������ϵ������
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

//ͨѶ¼ɾ������
void DelContact(Contact** con)
{
	//���ݱ����ȴ��ڣ�����ɾ��
	//����
	char name[NAME_MAX] = { 0 };
	printf("������Ҫɾ������ϵ��������");
	scanf("%s", name);

	Contact* find = FindByName(con, name);
	if (find == NULL)
	{
		printf("Ҫɾ������ϵ�˲����ڣ�\n");
		return;
	}
	else
	{
		//�ҵ��˸���ϵ�����ݣ��ҵ����±� ���� ɾ��ָ��λ�õ�����
		SLTErase(con, find);
		printf("ɾ���ɹ���\n");
	}
}

//ͨѶ¼���޸�
void ModifyContact(Contact** con)
{
	//Ҫ�޸ĵ���ϵ�����ݴ���
	char name[NAME_MAX] = { 0 };
	printf("������Ҫ�޸ĵ���ϵ��������");
	scanf("%s", name);

	Contact* find = FindByName(con, name);
	if (find == NULL)
	{
		printf("��ϵ�����ݲ����ڣ�\n");
		return;
	}
	else
	{
		printf("��������ϵ���µ�������");
		scanf("%s", find->data.name);
		printf("��������ϵ���µ��Ա�");
		scanf("%s", find->data.sex);
		printf("��������ϵ���µ����䣺");
		scanf("%d", &(find->data.age));
		printf("��������ϵ���µĵ绰��");
		scanf("%s", find->data.tel);
		printf("��������ϵ���µĵ�ַ��");
		scanf("%s", find->data.addr);
		printf("�޸ĳɹ���\n");
	}
}

//ͨѶ¼�Ĳ���
void FindContact(Contact** con)
{
	char name[NAME_MAX] = { 0 };
	printf("������Ҫ���ҵ���ϵ��������");
	scanf("%s", name);

	Contact* find = FindByName(con, name);
	if (find == NULL)
	{
		printf("��ϵ�����ݲ����ڣ�\n");
		return;
	}
	else
	{
		//��ͷ�� ���� �Ա� ���� �绰 ��ַ
		printf("%5s %5s %5s %10s %5s\n", "����", "�Ա�", "����", "�绰", "��ַ");
		printf("%5s %5s %5d %10s %5s\n", \
			find->data.name, \
			find->data.sex, \
			find->data.age, \
			find->data.tel, \
			find->data.addr);
	}
}

//չʾͨѶ¼����
void ShowContact(Contact** con)
{
	//��ͷ�� ���� �Ա� ���� �绰 ��ַ
	printf("%5s %5s %5s %10s %5s\n", "����", "�Ա�", "����", "�绰", "��ַ");
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

//ͨѶ¼������
void DestroyContact(Contact* con)
{
	//SaveContact(con);//�������˳�ǰ��������
	SListDestroy(con);
}

