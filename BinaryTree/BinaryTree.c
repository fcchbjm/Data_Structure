#include "BinaryTree.h"

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
	if (root != NULL && k == 1)
		return 1;
	if (root != NULL && k > 1)
		return BinaryTreeLevelKSize(root->left, --k) + BinaryTreeLevelKSize(root->right, --k);
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
