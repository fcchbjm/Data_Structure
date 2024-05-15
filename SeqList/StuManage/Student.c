#include "Student.h"

void InitStudentInfo(Student* stu)//初始化
{
	assert(stu);
	stu->ps = NULL;
	stu->size = 0;
	stu->capacity = 0;
}

void CheckCapacity(Student* stu)
{
	assert(stu);
	if (stu->size >= stu->capacity)
	{
		int newcapacity = stu->capacity == 0 ? 4 : 2 * stu->capacity;
		StudentInfo* newps = realloc(stu->ps, newcapacity * sizeof(StudentInfo));
		if (newcapacity == NULL)
		{
			perror("realloc failed!\n");
			exit(1);
		}
		stu->capacity = newcapacity;
		stu->ps = newps;
	}
}

void SaveStudentInfo(Student* stu)//保存学生信息到文件 
{
	FILE* pf = NULL;
	pf = fopen("Student.dat", "w");
	if (pf == NULL)
	{
		perror("Failed to write to file");
		return;
	}
	//写入数据
	fprintf(pf, "%d\n", stu->size);//写入有效数据个数
	for (int i = 0; i < stu->size; i++)//写入通讯录数据
	{
		fprintf(pf, "%s %s %d\n", \
			stu->ps[i].ID, \
			stu->ps[i].Name, \
			stu->ps[i].Score);
	}
	printf("数据保存成功！\n");
	fclose(pf);
	pf = NULL;
}

void ReadStudentInfo(Student* stu)//从文件加载学生信息 
{
	FILE* pf = NULL;
	pf = fopen("Student.dat", "r");
	if (pf == NULL)
	{
		perror("Failed to read to file");
		return;
	}
	fscanf(pf, "%d", &(stu->size));//读取有效数据个数
	for (int i = 0; i < stu->size; i++)
	{
		StudentInfo info = { 0 };
		fscanf(pf, "\n%s %s %d", \
			&info.ID, \
			&info.Name, \
			&info.Score);
		CheckCapacity(stu);//容量判断
		stu->ps[i] = info;
	}
	printf("数据读取成功！\n");
	fclose(pf);
	pf = NULL;
}

void AddStudent(Student* stu)//添加一个新学生记录 
{
	CheckCapacity(stu);
	StudentInfo Info;
	printf("请输入学生学号：");
	scanf("%s", &Info.ID);
	printf("请输入学生姓名：");
	scanf("%s", &Info.Name);
	printf("请输入成绩：");
	scanf("%d", &Info.Score);

	stu->ps[stu->size++] = Info;
}

void DeleteStudent(Student* stu)//删除一个学生记录 
{
	//assert(stu);
	//assert(stu->size);
	//stu->size--;
	assert(stu);
	printf("请输入要删除的学生姓名:");
	int find = FindByName(stu);
	if (find == EOF)
	{
		printf("没找到该学生!\n");
		return;
	}
	assert(find > 0 && find < stu->size);
	for (int i = find; i < stu->size - 1; i++)
	{
		stu->ps[i] = stu->ps[i + 1];
	}
	stu->size--;
	printf("删除成功！\n");
}

void ModifyStudent(Student* stu)//修改学生的信息 
{
	assert(stu);
	printf("请输入要修改的学生姓名:");
	int find = FindByName(stu);
	if (find == EOF)
	{
		printf("没找到该学生!\n");
		return;
	}
	printf("请输入新的学生学号：");
	scanf("%s", &stu->ps[find].ID);
	printf("请输入新的学生姓名：");
	scanf("%s", &stu->ps[find].Name);
	printf("请输入新的成绩：");
	scanf("%d", &stu->ps[find].Score);
	printf("学生信息已修改！\n");
}

void SearchStudent(Student* stu)//查询学生
{
	printf("请输入要查找的学生姓名:");
	int find = FindByName(stu);
	if (find == EOF)
	{
		printf("没找到该学生!\n");
		return;
	}
	else
	{
		printf("找到了，下面是该学生信息：\n");
		printf("|       学号        |        姓名       |    成绩    |\n");
		printf("%-20s %-20s %-3d\n", stu->ps[find].ID, stu->ps[find].Name, stu->ps[find].Score);
	}
}

int FindByName(Student* stu)
{
	//printf("请输入要查找的学生姓名:");
	char name[NAME_MAX] = { 0 };
	scanf("%s", &name);
	for (int i = 0; i < stu->size; i++)
	{
		if (strcmp(stu->ps[i].Name, name) == 0)
		{
			return i;
		}
	}
	return EOF;
}

void DisplayStudentInfo(Student* stu)//显示学生的信息 
{
	printf("|       学号        |        姓名       |    成绩    |\n");
	for (int i = 0; i < stu->size; i++)
	{
		printf("%-20s %-20s %-3d\n", stu->ps[i].ID, stu->ps[i].Name, stu->ps[i].Score);
	}
}

int SortByScore(StudentInfo* stu1, StudentInfo* stu2)
{
	return stu2->Score - stu1->Score;
}

void DisplayStudentByScore(Student* stu)//显示学生成绩排名
{
	qsort(stu->ps, stu->size, sizeof(StudentInfo), SortByScore);

	//int count = 0;//学生人数
	int passCount = 0;//及格人数 
	int totalScore = 0;//总分 
	int maxScore = stu->ps[0].Score;//最高分 
	int minScore = 0;//最低分 

	printf("| 排名 |       学号        |        姓名       |    成绩    |  状态  |\n");
	for (int i = 0; i < stu->size; i++)
	{
		totalScore += stu->ps[i].Score;
		if (stu->ps[i].Score > 60)
		{
			//count++;
			printf(" %-7d %-20s %-24s %-6d %s\n", i + 1, stu->ps[i].ID, stu->ps[i].Name, stu->ps[i].Score, "及格");
			//totalScore += stu->ps[i].Score;
		}
		else
		{
			//count++;
			printf(" %-7d %-20s %-24s %-6d %s\n", i + 1, stu->ps[i].ID, stu->ps[i].Name, stu->ps[i].Score, "不及格");
			//totalScore += stu->ps[i].Score;
			passCount++;
		}
	}
	minScore = stu->ps[stu->size - 1].Score;

	printf("学生及格率：%.2lf%%\n", (double)passCount / (double)stu->size * 100);
	printf("平均分：%.2lf\n", (double)totalScore / (double)stu->size);
	printf("最高分：%d\n", maxScore);
	printf("最低分：%d\n", minScore);
}

void Menu()//菜单
{
	printf("********** 学生成绩管理系统 **********\n");
	printf("*          1. 添加学生信息           *\n");
	printf("*          2. 删除学生信息           *\n");
	printf("*          3. 修改学生信息           *\n");
	printf("*          4. 查询学生成绩           *\n");
	printf("*          5. 显示学生信息           *\n");
	printf("*          6. 显示学生成绩排名       *\n");
	printf("*          7. 读取学生信息           *\n");
	printf("*          8. 写入学生信息           *\n");
	printf("*          0. 退出程序               *\n");
	printf("**************************************\n");
	printf("请选择：");
}

void DestroyStudentInfo(Student* stu)//销毁
{
	assert(stu);
	free(stu->ps);
	stu->size = 0;
	stu->capacity = 0;
}
