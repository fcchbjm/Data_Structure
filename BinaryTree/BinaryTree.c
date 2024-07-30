#include "BinaryTree.h"

BTNode* BinaryTreeCreate(BTDataType* arr, int num, int* pi)
{
	if (*pi >= num)
	{
		return NULL;
	}
	if (arr[*pi] == '#')
	{
		(*pi)++;
		return NULL;
	}

	BTNode* root = malloc(sizeof(BTNode));
	if (root == NULL)
	{
		perror("malloc failed");
		return NULL;
	}
	root->data = arr[(*pi)++];
	root->left = BinaryTreeCreate(arr, num, pi);
	root->right = BinaryTreeCreate(arr, num, pi);

	return root;
}

int BinaryTreeSize(BTNode* root)//节点个数
{
	return root == NULL ? 0 : \
		1 + BinaryTreeSize(root->left) + BinaryTreeSize(root->right);
}

int BinaryTreeLeafSize(BTNode* root)//叶子节点个数
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}

int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	//if (k == 1 && root != NULL)
	if (k == 1)
		return 1;
	//if (k > 1 && root != NULL)
	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}

BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if(root == NULL)
		return NULL;

	if (root->data == x)
		return root;

	BTNode* left = BinaryTreeFind(root->left, x);
	if (left)
		return left;

	BTNode* right = BinaryTreeFind(root->right, x);
	if (right)
		return right;

	return NULL;
}

void BinaryTreePrevOrder(BTNode* root)//前序遍历
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	printf("%d ", root->data);
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
}

void BinaryTreeInOrder(BTNode* root)//中序遍历
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	BinaryTreeInOrder(root->left);
	printf("%d ", root->data);
	BinaryTreeInOrder(root->right);
}

void BinaryTreePostOrder(BTNode* root)//后序遍历
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	BinaryTreePostOrder(root->left);
	BinaryTreePostOrder(root->right);
	printf("%d ", root->data);
}
