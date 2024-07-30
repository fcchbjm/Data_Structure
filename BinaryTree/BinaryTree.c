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

void BinaryTreeDestory(BTNode** root)
{
	if (*root == NULL)
		return;
	BinaryTreeDestory(&((*root)->left));
	BinaryTreeDestory(&((*root)->right));

	free(*root);
	*root = NULL;
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

#include "Queue.h"

void BinaryTreeLevelOrder(BTNode* root)
{
	Queue Q;
	QueueInit(&Q);
	if (root)
		QueuePush(&Q, root);
	
	while (!QueueEmpty(&Q))
	{
		BTNode* front = QueueFront(&Q);
		QueuePop(&Q);
		printf("%d ", front->data);
		if (front->left)
			QueuePush(&Q, front->left);
		if (front->right)
			QueuePush(&Q, front->right);
	}
}

bool BinaryTreeComplete(BTNode* root)
{
	Queue Q;
	QueueInit(&Q);
	if (root)
		QueuePush(&Q, root);

	while (!QueueEmpty(&Q))
	{
		BTNode* front = QueueFront(&Q);
		QueuePop(&Q);
		//遇到第一个空，开始判断
		if (front == NULL)
		{
			break;
		}
		QueuePush(&Q, front->left);
		QueuePush(&Q, front->right);
	}

	while (!QueueEmpty(&Q))
	{
		BTNode* front = QueueFront(&Q);
		QueuePop(&Q);
		//如果有非空，就不是完全二叉树
		if (front)
		{
			QueueDestroy(&Q);
			return false;
		}
	}
	QueueDestroy(&Q);
	return true;
}
