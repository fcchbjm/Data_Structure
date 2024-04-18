#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define NAME_MAX 100
#define SEX_MAX 4
#define TEL_MAX 11
#define ADDR_MAX 100

//ǰ������
typedef struct SListNode Contact;

//�û�����
typedef struct PersonInfo
{
    char name[NAME_MAX];
    char sex[SEX_MAX];
    int age;
    char tel[TEL_MAX];
    char addr[ADDR_MAX];
}PeoInfo;

//��ʼ��ͨѶ¼
//void InitContact(Contact** con);
//���ͨѶ¼����
void AddContact(Contact** con);
//ɾ��ͨѶ¼����
void DelContact(Contact** con);
//չʾͨѶ¼����
void ShowContact(Contact* con);
//����ͨѶ¼����
void FindContact(Contact* con);
//�޸�ͨѶ¼����
void ModifyContact(Contact** con);
//����ͨѶ¼����
void DestroyContact(Contact** con);
