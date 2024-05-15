# Data Structure 数据结构

Implement data structures in C

**本仓库我们在C语言的基础上简单的实现部分数据结构**


# SeqList 顺序表

*在物理上连续，在逻辑上也连续*

优点：
1.随机访问,即可在O(1)时间内找到第i个元素
2.存储密度高,每个节点只存储数据元素本身

缺点：
1.拓展容量不方便
2.插入、删除操作不方便,需要移动大量元素

```C
typedef struct SeqList
{
	SLDataType* arr;//数据
	int size;//有效元素个数
	int capacity;//空间大小
}SL;
```

**顺序表基本结构**

[SeqList.c](https://github.com/fcchbjm/Data_Structure/blob/master/SeqList/SeqList.c)
：包含顺序表的结构体部分和函数的声明

[SeqList.h](https://github.com/fcchbjm/Data_Structure/blob/master/SeqList/SeqList.h)
：对顺序表进行相关操作的函数体部分

[test.c](https://github.com/fcchbjm/Data_Structure/blob/master/SeqList/test.c)
：主函数和测试代码

**项目：通讯录**

```C
typedef struct PersonInfo//通讯录结构体
{
	char name[NAME_MAX];
	char gender[GENDER_MAX];
	int age;
	char tel[TEL_MAX];
	char addr[ADDR_MAX];
}PeoInfo;

//因为没有不会SL的头文件，使用声明+typedef
typedef struct SeqList Contact;//对结构体SL进行重命名为Contact
```

```C
typedef PeoInfo SLDataType;//将通讯录结构体类型重命名为SLDataType

//动态顺序表
typedef struct SeqList//将结构体SeqList重命名为SL
{
	SLDataType* arr;
	int size;
	int capacity;
}SL;
```

[Contact.c](https://github.com/fcchbjm/Data_Structure/blob/master/SeqList/PhoneBook/Contact.c)
：基于顺序表实现的通讯录相关功能的函数体部分

[Contact.h](https://github.com/fcchbjm/Data_Structure/blob/master/SeqList/PhoneBook/Contact.h)
：通讯录结构体部分和函数的声明

[SeqList.c](https://github.com/fcchbjm/Data_Structure/blob/master/SeqList/PhoneBook/SeqList.c)
：顺序表的功能以及为了实现通讯录做出的少量修改

[SeqList.h](https://github.com/fcchbjm/Data_Structure/blob/master/SeqList/PhoneBook/SeqList.h)
：顺序表的结构体和函数的声明

[test.c](https://github.com/fcchbjm/Data_Structure/blob/master/SeqList/PhoneBook/test.c)
：通讯录主函数和菜单部分，以及部分测试功能的测试代码

**项目：学生成绩管理系统**

```C
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
```

[Student.h](https://github.com/fcchbjm/Data_Structure/blob/master/SeqList/StuManage/Student.h)
：基于顺序表实现的学生成绩管理系统的结构体和函数的声明

[Student.c](https://github.com/fcchbjm/Data_Structure/blob/master/SeqList/StuManage/Student.c)
：基于顺序表实现的学生成绩管理系统相关功能的函数体部分

[test.c](https://github.com/fcchbjm/Data_Structure/blob/master/SeqList/StuManage/test.c)
：学生成绩管理系统主函数部分


# SList 单链表


*不带头单项不循环链表*

*在物理不连续，在逻辑上连续*

优点：
1.可在任意位置插入删除，时间复杂度为O(1)
2.没有增容问题，一次仅开辟一个节点的空间

缺点：不能随机访问

```C
typedef struct SListNode 
{
	SLTDataType data;//数据
	struct SListNode* next;//指向下一个链表地址的指针
}SLTNode;
```

**单链表基本结构**

[SList.c](https://github.com/fcchbjm/Data_Structure/blob/master/SList/SList.c)
：包含单链表的结构体部分和函数的声明

[SList.h](https://github.com/fcchbjm/Data_Structure/blob/master/SList/SList.h)
：对单链表进行相关操作的函数体部分

[test.c](https://github.com/fcchbjm/Data_Structure/blob/master/SList/test.c)
：主函数和测试代码

**项目：通讯录**

```C
typedef struct SListNode Contact;//前置声明

typedef struct PersonInfo//用户数据
{
    char name[NAME_MAX];
    char sex[SEX_MAX];
    int age;
    char tel[TEL_MAX];
    char addr[ADDR_MAX];
}PeoInfo;
```
```C
//数据 + 指向下一个节点的指针
typedef PeoInfo SLTDataType;//定义节点的结构

typedef struct SListNode 
{
	SLTDataType data;//数据
	struct SListNode* next;//指向下一个链表的地址
}SLTNode;
```

[Contact.c](https://github.com/fcchbjm/Data_Structure/blob/master/SList/PhoneBook/Contact.c)
：基于单链表实现的通讯录相关功能的函数体部分

[Contact.h](https://github.com/fcchbjm/Data_Structure/blob/master/SList/PhoneBook/Contact.h)
：通讯录结构体部分和函数的声明

[SList.c](https://github.com/fcchbjm/Data_Structure/blob/master/SList/PhoneBook/SList.c)
：单链表的功能以及为了实现通讯录做出的少量修改

[SList.h](https://github.com/fcchbjm/Data_Structure/blob/master/SList/PhoneBook/SList.h)
：单链表的结构体和函数的声明

[test.c](https://github.com/fcchbjm/Data_Structure/blob/master/SList/PhoneBook/test.c)
：通讯录主函数和菜单部分，以及部分测试功能的测试代码


# List 双向链表


*带头双向不循环链表*

*在物理不连续，在逻辑上连续*

优点：
1.插入、删除和查找操作效率高，适用于需要频繁进行查找操作的数据结构，如数据库索引、哈希表等
2.可以找到前后节点，可进可退

缺点：
1.实现复杂，占用空间多
2.增加删除节点复杂，需要多分配一个指针存储空间

```C
typedef struct ListNode
{
	LTDataType data;
	struct ListNode* prev;//指向前一个节点
	struct ListNode* next;//指向后一个节点
}LTNode;
```

**双向链表基本结构**

[List.c](https://github.com/fcchbjm/Data_Structure/blob/master/List/List.c)
：包含双向链表的结构体部分和函数的声明

[List.h](https://github.com/fcchbjm/Data_Structure/blob/master/List/List.h)
：对双向链表进行相关操作的函数体部分

[test.c](https://github.com/fcchbjm/Data_Structure/blob/master/List/test.c)
：主函数和测试代码


# Stack 栈


特点：后进先出 FILO（First In Last Out）

**栈的基本结构**

[Stack.h](https://github.com/fcchbjm/Data_Structure/blob/master/Stack/Stack.h)
：基于顺序表实现的栈的结构体和函数的声明

[Stack.c](https://github.com/fcchbjm/Data_Structure/blob/master/Stack/Stack.c)
：基于顺序表实现的栈相关功能的函数体部分

[test.c](https://github.com/fcchbjm/Data_Structure/blob/master/Stack/test.c)
：主函数以及部分测试功能的测试代码


# Queue 队列


特点：先进先出 FIFO（First in First Out）

**队列的基本结构**

[Queue.h](https://github.com/fcchbjm/Data_Structure/blob/master/Queue/Queue.h)

[Queue.c](https://github.com/fcchbjm/Data_Structure/blob/master/Queue/Queue.c)

[test.c](https://github.com/fcchbjm/Data_Structure/blob/master/Queue/test.c)



