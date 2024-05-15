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
    int size;//有效数据个数
    int capacity;//空间大小
}Student;

void InitStudentInfo(Student* stu);//初始化

void SaveStudentInfo(Student* stu);//保存学生信息到文件 

void ReadStudentInfo(Student* stu);//从文件加载学生信息 

void AddStudent(Student* stu);//添加一个新学生记录

void DeleteStudent(Student* stu);//删除一个学生记录 

void ModifyStudent(Student* stu);//修改学生的信息 

void SearchStudent(Student* stu);//查询学生的成绩 

void DisplayStudentInfo(Student* stu);//显示学生的信息 

void DisplayStudentByScore(Student* stu);//显示学生成绩排名

void Menu();//菜单

void DestroyStudentInfo(Student* stu);//销毁
