#pragma once

#define NAME_MAX 20
#define GENDER_MAX 10
#define TEL_MAX 20
#define ADDR_MAX 100

//ͨѶ¼�ṹ��
typedef struct PersonInfo
{
	char name[NAME_MAX];
	char gender[GENDER_MAX];
	int age;
	char tel[TEL_MAX];
	char addr[ADDR_MAX];
}PeoInfo;

//�Խṹ��SL����������ΪContact
//��Ϊû�а���SL��ͷ�ļ���ʹ������+typedef
typedef struct SeqList Contact;

//struct SeqList;//�����ṹ��
//typedef SL Contact;//���ṹ�����

//ͨѶ¼�ĳ�ʼ��
void ContactInit(Contact* con);
//ͨѶ¼������
void ContactDestroy(Contact* con);
//ͨѶ¼�������
void ContactAdd(Contact* con);
//ͨѶ¼ɾ������
void ContactDel(Contact* con);
//ͨѶ¼���޸�
void ContactModify(Contact* con);
//ͨѶ¼�Ĳ���
void ContactFind(Contact* con);
//չʾͨѶ¼����
void ContactShow(Contact* con);
//����ͨѶ¼����
void SaveContact(Contact* con);
//��ȡͨѶ¼����
void ReadContact(Contact* con);
//˳��������
void SLCheckCapacity(Contact* con);