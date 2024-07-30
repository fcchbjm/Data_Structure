#define _CRT_SECURE_NO_WARNINGS 1
#include "vld.h"
#include "BinaryTree.h"

BTNode* BuyNode(BTDataType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (node == NULL)
	{
		perror("malloc failed");
		return NULL;
	}
	node->data = x;
	node->left = NULL;
	node->right = NULL;
	return node;
}

BTNode* CreatBinaryTree()
{
	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	BTNode* node4 = BuyNode(4);
	BTNode* node5 = BuyNode(5);
	BTNode* node6 = BuyNode(6);

	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;

	return node1;
}

//int TreeHeight(BTNode* root)
//{
//	if (root == NULL)
//		return 0;
//
//	return TreeHeight(root->left) > TreeHeight(root->right) ? \
//		TreeHeight(root->left) + 1 : TreeHeight(root->right) + 1;
//}

int TreeHeight(BTNode* root)
{
	if (root == NULL)
		return 0;

	int leftHeight = TreeHeight(root->left);
	int rightHeight = TreeHeight(root->right);

	return leftHeight > rightHeight ? \
		leftHeight + 1 : rightHeight + 1;
	//return fmax(TreeHeight(root->left), TreeHeight(root->right));
}

void BTTest01()
{
	BTNode* root = CreatBinaryTree();

	BinaryTreePrevOrder(root);
	printf("\n");

	BinaryTreeInOrder(root);
	printf("\n");

	BinaryTreePostOrder(root);
	printf("\n");

	printf("BinaryTreeSize:%d\n", BinaryTreeSize(root));
	printf("BinaryTreeSize:%d\n", BinaryTreeSize(root));

	printf("BinaryTreeLeafSize:%d\n", BinaryTreeLeafSize(root));

	printf("TreeHeight:%d\n", TreeHeight(root));

	printf("BinaryTreeLevelKSize(1):%d\n", BinaryTreeLevelKSize(root, 1));
	printf("BinaryTreeLevelKSize(2):%d\n", BinaryTreeLevelKSize(root, 2));
	printf("BinaryTreeLevelKSize(3):%d\n", BinaryTreeLevelKSize(root, 3));
	printf("BinaryTreeLevelKSize(4):%d\n", BinaryTreeLevelKSize(root, 4));

	printf("BinaryTreeFind(1):%d\n", BinaryTreeFind(root, 1)->data);
	printf("BinaryTreeFind(2):%d\n", BinaryTreeFind(root, 2)->data);
	printf("BinaryTreeFind(3):%d\n", BinaryTreeFind(root, 3)->data);
	printf("BinaryTreeFind(4):%d\n", BinaryTreeFind(root, 4)->data);
	printf("BinaryTreeFind(5):%d\n", BinaryTreeFind(root, 5)->data);
	printf("BinaryTreeFind(6):%d\n", BinaryTreeFind(root, 6)->data);
	printf("BinaryTreeFind(7):%p\n", BinaryTreeFind(root, 7));
}

void BTTest02()
{
	char arr[100] = { 0 };
	scanf("%s", arr);
	size_t sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	BTNode* root = BinaryTreeCreate(arr, sz, &i);
	BinaryTreeInOrder(root);
	printf("\n");

	BinaryTreeDestory(&root);
	printf("%p\n", root);
}

BTNode* CreatBinaryTree02()//ÍêÈ«¶þ²æÊ÷
{
	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	BTNode* node4 = BuyNode(4);
	BTNode* node5 = BuyNode(5);
	BTNode* node6 = BuyNode(6);

	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node2->right = node5;
	node4->left = node6;

	return node1;
}

void BTTest03()
{
	BTNode* root = CreatBinaryTree02();

	BinaryTreeLevelOrder(root);
	printf("\n");

	printf("BinaryTreeComplete:%d\n", BinaryTreeComplete(root));

	BinaryTreeDestory(&root);
}

int main()
{
	BTTest03();
	return 0;
}