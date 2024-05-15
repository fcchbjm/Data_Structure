#pragma once

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define ID_MAX 20
#define NAME_MAX 20

typedef struct StudentInfo
{
    char ID[ID_MAX];
    char Name[NAME_MAX];
    int Score;
}StudentInfo;

typedef struct Student
{
    StudentInfo* ps;
    int size;//��Ч���ݸ���
    int capacity;//�ռ��С
}Student;

void InitStudentInfo(Student* stu);//��ʼ��

void SaveStudentInfo(Student* stu);//����ѧ����Ϣ���ļ� 

void ReadStudentInfo(Student* stu);//���ļ�����ѧ����Ϣ 

void AddStudent(Student* stu);//���һ����ѧ����¼

void DeleteStudent(Student* stu);//ɾ��һ��ѧ����¼ 

void ModifyStudent(Student* stu);//�޸�ѧ������Ϣ 

void SearchStudent(Student* stu);//��ѯѧ���ĳɼ� 

void DisplayStudentInfo(Student* stu);//��ʾѧ������Ϣ 

void DisplayStudentByScore(Student* stu);//��ʾѧ���ɼ�����

void Menu();//�˵�

void DestroyStudentInfo(Student* stu);//����
