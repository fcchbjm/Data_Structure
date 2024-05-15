#include "Student.h"

int main()
{
	Student stu;
	Student* ps = &stu;
	InitStudentInfo(ps);
	int input = 0;
	do
	{
		Menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			AddStudent(ps);
			break;
		case 2:
			DeleteStudent(ps);
			break;
		case 3:
			ModifyStudent(ps);
			break;
		case 4:
			SearchStudent(ps);
			break;
		case 5:
			DisplayStudentInfo(ps);
			break;
		case 6:
			DisplayStudentByScore(ps);
			break;
		case 7:
			ReadStudentInfo(ps);
			break;
		case 8:
			SaveStudentInfo(ps);
			break;
		case 0:
			DestroyStudentInfo(ps);
			ps = NULL;
			printf("退出学生成绩管理系统……\n");
			break;
		default:
			printf("输入错误，请重新输入！\n");
			break;
		}
	} while (input);
	return 0;
}