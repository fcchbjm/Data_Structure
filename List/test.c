#include "List.h"

void ListTest01()
{
	LTNode* plist = NULL;
	plist = LTInit();

	//LTPushBack(plist, 1);
	//LTPushBack(plist, 2);
	//LTPushBack(plist, 3);
	//LTPushBack(plist, 4);
	//LTPushBack(plist, 5);
	//LTPrint(plist);

	LTPushFront(plist, 1);
	LTPushFront(plist, 2);
	LTPushFront(plist, 3);
	LTPushFront(plist, 4);
	LTPushFront(plist, 5);
	LTPrint(plist);

	//LTPopBack(plist);
	//LTPrint(plist);
	//LTPopBack(plist);
	//LTPrint(plist);
	//LTPopBack(plist);
	//LTPrint(plist);

	//LTPopFront(plist);
	//LTPrint(plist);
	//LTPopFront(plist);
	//LTPrint(plist);
	//LTPopFront(plist);
	//LTPrint(plist);

	//LTNode* find = NULL;
	//find = LTFind(plist, 2);
	//if (find)
	//{
	//	printf("找到了！\n");
	//}
	//else
	//{
	//	printf("找不到！\n");
	//}
	//find = LTFind(plist, 7);
	//if (find)
	//{
	//	printf("找到了！\n");
	//}
	//else
	//{
	//	printf("找不到！\n");
	//}

	//LTNode* find = NULL;
	//find = LTFind(plist, 2);
	//if (find)
	//{
	//	printf("找到了！\n");
	//}
	//else
	//{
	//	printf("找不到！\n");
	//}
	//LTInsert(find, 6);
	//LTPrint(plist);
	//LTErase(find);
	//find = NULL;
	//LTPrint(plist);

	LTDestroy(plist);
	plist = NULL;
}

int main()
{
	ListTest01();
	return 0;
}