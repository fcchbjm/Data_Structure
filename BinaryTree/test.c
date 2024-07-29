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

int main()
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

	printf("BinaryTreeLevelKSize(root , 1):%d\n", BinaryTreeLevelKSize(root, 1));
	printf("BinaryTreeLevelKSize(root , 2):%d\n", BinaryTreeLevelKSize(root, 2));
	printf("BinaryTreeLevelKSize(root , 3):%d\n", BinaryTreeLevelKSize(root, 3));
	printf("BinaryTreeLevelKSize(root , 4):%d\n", BinaryTreeLevelKSize(root, 4));

	return 0;
}