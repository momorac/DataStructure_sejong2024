#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int id;
	int data;
	struct Node *left;
	struct Node *right;
} typedef NODE;

NODE *setNode(int id, int data)
{
	NODE *new = (NODE *)malloc(sizeof(NODE));
	new->data = data;
	new->id = id;
	new->right = NULL;
	new->left = NULL;

	return new;
}

void searchNodeById(NODE *root, int target_id, NODE **buffer)
{
	if (root == NULL)
		return;

	if (root->id == target_id)
	{
		*buffer = root;
		return;
	}

	searchNodeById(root->left, target_id, buffer);
	searchNodeById(root->right, target_id, buffer);
}

void preOrderTraverse(NODE *root)
{
	if (root == NULL)
		return;

	printf(" %d", root->data);
	preOrderTraverse(root->left);
	preOrderTraverse(root->right);
}

void inOrderTraverse(NODE *root)
{
	if (root == NULL)
		return;

	inOrderTraverse(root->left);
	printf(" %d", root->data);
	inOrderTraverse(root->right);
}

void postOrderTraverse(NODE *root)
{
	if (root == NULL)
		return;

	postOrderTraverse(root->left);
	postOrderTraverse(root->right);
	printf(" %d", root->data);
}

int main()
{
	NODE *tree = setNode(1, 20);
	tree->left = setNode(2, 30);
	tree->right = setNode(3, 50);
	tree->left->left = setNode(4, 70);
	tree->left->right = setNode(5, 90);
	tree->right->right = setNode(6, 120);
	tree->right->right->left = setNode(7, 130);
	tree->right->right->right = setNode(8, 80);

	int com, id;
	scanf("%d %d", &com, &id);

	if (id < 1 || id > 8)
	{
		printf("-1");
		return 0;
	}

	NODE *root;
	searchNodeById(tree, id, &root);

	switch (com)
	{
	case 1:
		preOrderTraverse(root);
		break;
	case 2:
		inOrderTraverse(root);
		break;
	case 3:
		postOrderTraverse(root);
		break;
	}

	free(tree->right->right->right);
	free(tree->right->right->left);
	free(tree->right->right);
	free(tree->left->right);
	free(tree->left->left);
	free(tree->right);
	free(tree->left);
	free(tree);

	return 0;
}