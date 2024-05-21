#include "Contact.h"
#include "SeqList.h"
#include <string.h>

//ͨѶ¼�ĳ�ʼ��
void ContactInit(Contact* con)
{
	//con����SL
	SLInit(con);
}

//ͨѶ¼������
void ContactDestroy(Contact* con)
{
	//SaveContact(con);//�������˳�ǰ��������
	SLDestroy(con);
}

//ͨѶ¼�������
void ContactAdd(Contact* con)
{
	//��ȡ�û����������
	//����+�Ա�+����+�绰+��ַ
	PeoInfo info;
	printf("��������ϵ��������");
	scanf("%s", info.name);
	printf("��������ϵ���Ա�");
	scanf("%s", info.gender);
	printf("��������ϵ�����䣺");
	scanf("%d", &info.age);
	printf("��������ϵ�˵绰��");
	scanf("%s", info.tel);
	printf("��������ϵ�˵�ַ��");
	scanf("%s", info.addr);

	//��ͨѶ¼�������ϵ������
	SLPushBack(con, info);
}

int FindByName(Contact* con, char name[])
{
	for (int i = 0; i < con->size; i++)
	{
		if (0 == strcmp(con->arr[i].name, name))
		{
			//�ҵ���
			return i;
		}
	}
	//û���ҵ�
	return -1;
}

//ͨѶ¼ɾ������
void ContactDel(Contact* con)
{
	//���ݱ����ȴ��ڣ�����ɾ��
	//����
	char name[NAME_MAX] = { 0 };
	printf("������Ҫɾ������ϵ��������");
	scanf("%s", name);

	int find = FindByName(con, name);
	if (find < 0)
	{
		printf("Ҫɾ������ϵ�˲����ڣ�\n");
		return;
	}
	else
	{
		//�ҵ��˸���ϵ�����ݣ��ҵ����±� ���� ɾ��ָ��λ�õ�����
		SLErase(con, find);
		printf("ɾ���ɹ���\n");
	}
}

//ͨѶ¼���޸�
void ContactModify(Contact* con)
{
	//Ҫ�޸ĵ���ϵ�����ݴ���
	char name[NAME_MAX] = { 0 };
	printf("������Ҫ�޸ĵ���ϵ��������");
	scanf("%s", name);

	int find = FindByName(con, name);
	if (find < 0)
	{
		printf("��ϵ�����ݲ����ڣ�\n");
		return;
	}
	else
	{
		printf("��������ϵ���µ�������");
		scanf("%s", con->arr[find].name);
		printf("��������ϵ���µ��Ա�");
		scanf("%s", con->arr[find].gender);
		printf("��������ϵ���µ����䣺");
		scanf("%d", &(con->arr[find].age));
		printf("��������ϵ���µĵ绰��");
		scanf("%s", con->arr[find].tel);
		printf("��������ϵ���µĵ�ַ��");
		scanf("%s", con->arr[find].addr);
		printf("�޸ĳɹ���\n");
	}
}

//ͨѶ¼�Ĳ���
void ContactFind(Contact* con)
{
	char name[NAME_MAX] = { 0 };
	printf("������Ҫ���ҵ���ϵ��������");
	scanf("%s", name);

	int find = FindByName(con, name);
	if (find < 0)
	{
		printf("��ϵ�����ݲ����ڣ�\n");
		return;
	}
	else
	{
		//��ͷ�� ���� �Ա� ���� �绰 ��ַ
		printf("%5s %5s %5s %10s %5s\n", "����", "�Ա�", "����", "�绰", "��ַ");
		printf("%5s %5s %5d %10s %5s\n", \
			con->arr[find].name, \
			con->arr[find].gender, \
			con->arr[find].age, \
			con->arr[find].tel, \
			con->arr[find].addr);
	}
}

//չʾͨѶ¼����
void ContactShow(Contact* con)
{
	//��ͷ�� ���� �Ա� ���� �绰 ��ַ
	printf("%5s %5s %5s %10s %5s\n", "����", "�Ա�", "����", "�绰", "��ַ");
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

//����ͨѶ¼����
void SaveContact(Contact* con)
{
	FILE* pf = NULL;
	pf = fopen("Contact.dat", "w");
	if (pf == NULL)
	{
		perror("Failed to write to file");
		return;
	}
	//д������
	fprintf(pf, "%d\n", con->size);//д����Ч���ݸ���
	for (int i = 0; i < con->size; i++)//д��ͨѶ¼����
	{
		fprintf(pf, "%s %s %d %s %s\n", \
			con->arr[i].name, \
			con->arr[i].gender, \
			con->arr[i].age, \
			con->arr[i].tel, \
			con->arr[i].addr);
	}
	printf("���ݱ���ɹ���\n");
	fclose(pf);
	pf = NULL;
}

//��ȡͨѶ¼����
void ReadContact(Contact* con)
{
	FILE* pf = NULL;
	pf = fopen("Contact.dat", "r");
	if (pf == NULL)
	{
		perror("Failed to read to file");
		return;
	}
	fscanf(pf, "%d", &(con->size));//��ȡ��Ч���ݸ���
	for (int i = 0; i < con->size; i++)
	{
		PeoInfo info = { 0 };
		fscanf(pf, "\n%s %s %d %s %s", \
			info.name, \
			info.gender, \
			& (info.age), \
			info.tel, \
			info.addr);
		//SLPushBack(con, info);//����ʹ��β��
		SLCheckCapacity(con);//�����ж�
		con->arr[i] = info;
	}
	printf("���ݶ�ȡ�ɹ���\n");
	fclose(pf);
	pf = NULL;
}