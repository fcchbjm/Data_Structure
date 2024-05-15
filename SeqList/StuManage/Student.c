#include "Student.h"

void InitStudentInfo(Student* stu)//��ʼ��
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

void SaveStudentInfo(Student* stu)//����ѧ����Ϣ���ļ� 
{
	FILE* pf = NULL;
	pf = fopen("Student.dat", "w");
	if (pf == NULL)
	{
		perror("Failed to write to file");
		return;
	}
	//д������
	fprintf(pf, "%d\n", stu->size);//д����Ч���ݸ���
	for (int i = 0; i < stu->size; i++)//д��ͨѶ¼����
	{
		fprintf(pf, "%s %s %d\n", \
			stu->ps[i].ID, \
			stu->ps[i].Name, \
			stu->ps[i].Score);
	}
	printf("���ݱ���ɹ���\n");
	fclose(pf);
	pf = NULL;
}

void ReadStudentInfo(Student* stu)//���ļ�����ѧ����Ϣ 
{
	FILE* pf = NULL;
	pf = fopen("Student.dat", "r");
	if (pf == NULL)
	{
		perror("Failed to read to file");
		return;
	}
	fscanf(pf, "%d", &(stu->size));//��ȡ��Ч���ݸ���
	for (int i = 0; i < stu->size; i++)
	{
		StudentInfo info = { 0 };
		fscanf(pf, "\n%s %s %d", \
			&info.ID, \
			&info.Name, \
			&info.Score);
		CheckCapacity(stu);//�����ж�
		stu->ps[i] = info;
	}
	printf("���ݶ�ȡ�ɹ���\n");
	fclose(pf);
	pf = NULL;
}

void AddStudent(Student* stu)//���һ����ѧ����¼ 
{
	CheckCapacity(stu);
	StudentInfo Info;
	printf("������ѧ��ѧ�ţ�");
	scanf("%s", &Info.ID);
	printf("������ѧ��������");
	scanf("%s", &Info.Name);
	printf("������ɼ���");
	scanf("%d", &Info.Score);

	stu->ps[stu->size++] = Info;
}

void DeleteStudent(Student* stu)//ɾ��һ��ѧ����¼ 
{
	//assert(stu);
	//assert(stu->size);
	//stu->size--;
	assert(stu);
	printf("������Ҫɾ����ѧ������:");
	int find = FindByName(stu);
	if (find == EOF)
	{
		printf("û�ҵ���ѧ��!\n");
		return;
	}
	assert(find > 0 && find < stu->size);
	for (int i = find; i < stu->size - 1; i++)
	{
		stu->ps[i] = stu->ps[i + 1];
	}
	stu->size--;
	printf("ɾ���ɹ���\n");
}

void ModifyStudent(Student* stu)//�޸�ѧ������Ϣ 
{
	assert(stu);
	printf("������Ҫ�޸ĵ�ѧ������:");
	int find = FindByName(stu);
	if (find == EOF)
	{
		printf("û�ҵ���ѧ��!\n");
		return;
	}
	printf("�������µ�ѧ��ѧ�ţ�");
	scanf("%s", &stu->ps[find].ID);
	printf("�������µ�ѧ��������");
	scanf("%s", &stu->ps[find].Name);
	printf("�������µĳɼ���");
	scanf("%d", &stu->ps[find].Score);
	printf("ѧ����Ϣ���޸ģ�\n");
}

void SearchStudent(Student* stu)//��ѯѧ��
{
	printf("������Ҫ���ҵ�ѧ������:");
	int find = FindByName(stu);
	if (find == EOF)
	{
		printf("û�ҵ���ѧ��!\n");
		return;
	}
	else
	{
		printf("�ҵ��ˣ������Ǹ�ѧ����Ϣ��\n");
		printf("|       ѧ��        |        ����       |    �ɼ�    |\n");
		printf("%-20s %-20s %-3d\n", stu->ps[find].ID, stu->ps[find].Name, stu->ps[find].Score);
	}
}

int FindByName(Student* stu)
{
	//printf("������Ҫ���ҵ�ѧ������:");
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

void DisplayStudentInfo(Student* stu)//��ʾѧ������Ϣ 
{
	printf("|       ѧ��        |        ����       |    �ɼ�    |\n");
	for (int i = 0; i < stu->size; i++)
	{
		printf("%-20s %-20s %-3d\n", stu->ps[i].ID, stu->ps[i].Name, stu->ps[i].Score);
	}
}

int SortByScore(StudentInfo* stu1, StudentInfo* stu2)
{
	return stu2->Score - stu1->Score;
}

void DisplayStudentByScore(Student* stu)//��ʾѧ���ɼ�����
{
	qsort(stu->ps, stu->size, sizeof(StudentInfo), SortByScore);

	//int count = 0;//ѧ������
	int passCount = 0;//�������� 
	int totalScore = 0;//�ܷ� 
	int maxScore = stu->ps[0].Score;//��߷� 
	int minScore = 0;//��ͷ� 

	printf("| ���� |       ѧ��        |        ����       |    �ɼ�    |  ״̬  |\n");
	for (int i = 0; i < stu->size; i++)
	{
		totalScore += stu->ps[i].Score;
		if (stu->ps[i].Score > 60)
		{
			//count++;
			printf(" %-7d %-20s %-24s %-6d %s\n", i + 1, stu->ps[i].ID, stu->ps[i].Name, stu->ps[i].Score, "����");
			//totalScore += stu->ps[i].Score;
		}
		else
		{
			//count++;
			printf(" %-7d %-20s %-24s %-6d %s\n", i + 1, stu->ps[i].ID, stu->ps[i].Name, stu->ps[i].Score, "������");
			//totalScore += stu->ps[i].Score;
			passCount++;
		}
	}
	minScore = stu->ps[stu->size - 1].Score;

	printf("ѧ�������ʣ�%.2lf%%\n", (double)passCount / (double)stu->size * 100);
	printf("ƽ���֣�%.2lf\n", (double)totalScore / (double)stu->size);
	printf("��߷֣�%d\n", maxScore);
	printf("��ͷ֣�%d\n", minScore);
}

void Menu()//�˵�
{
	printf("********** ѧ���ɼ�����ϵͳ **********\n");
	printf("*          1. ���ѧ����Ϣ           *\n");
	printf("*          2. ɾ��ѧ����Ϣ           *\n");
	printf("*          3. �޸�ѧ����Ϣ           *\n");
	printf("*          4. ��ѯѧ���ɼ�           *\n");
	printf("*          5. ��ʾѧ����Ϣ           *\n");
	printf("*          6. ��ʾѧ���ɼ�����       *\n");
	printf("*          7. ��ȡѧ����Ϣ           *\n");
	printf("*          8. д��ѧ����Ϣ           *\n");
	printf("*          0. �˳�����               *\n");
	printf("**************************************\n");
	printf("��ѡ��");
}

void DestroyStudentInfo(Student* stu)//����
{
	assert(stu);
	free(stu->ps);
	stu->size = 0;
	stu->capacity = 0;
}
