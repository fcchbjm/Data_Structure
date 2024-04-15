#include "List.h"

void ListTest01()
{
	LTNode* plist = NULL;
	LTInit(&plist);

	LTPushBack(plist, 1);
	LTPushBack(plist, 2);
	LTPushBack(plist, 3);
	LTPushBack(plist, 4);
	LTPushBack(plist, 5);
	LTPrint(plist);
}

int main()
{
	ListTest01();
	return 0;
}