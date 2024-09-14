#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable:4996)

struct Node
{
	int elem;
	struct Node* left;
	struct Node* right;
} typedef NODE;

NODE* getNode(int elem)
{
	NODE* new = (NODE*)malloc(sizeof(NODE));
	new->elem = elem;
	new->left = NULL;
	new->right = NULL;

	return new;
}

int setLeaf(NODE* node, int x, int left, int right)
{
	int result = 0;

	if (node->elem == x) {
		if (left)
		{
			NODE* leftChild = getNode(left);
			node->left = leftChild;
		}
		if (right)
		{
			NODE* rightChild = getNode(right);
			node->right = rightChild;
		}
		return 1;
	}

	if (result == 0 && node->left)
		result = setLeaf(node->left, x, left, right);
	if (result == 0 && node->right)
		result = setLeaf(node->right, x, left, right);

	return 0;
}

void traverse(NODE* root, char* command) {

	if (root == NULL) return;

	printf(" %d", root->elem);

	if (*command == 'L') {
		traverse(root->left, command + 1);
	}
	else if (*command == 'R') {
		traverse(root->right, command + 1);
	}
}



void freeTree(NODE* root) {
	if (root == NULL)
		return;

	freeTree(root->left);
	freeTree(root->right);
	free(root);
}

int main()
{

	int n, x, y, z;
	scanf("%d", &n);

	scanf("%d %d %d", &x, &y, &z);

	NODE* root = getNode(x);
	setLeaf(root, x, y, z);


	for (int i = 0; i < n - 1; i++)
	{
		scanf("%d %d %d", &x, &y, &z);
		setLeaf(root, x, y, z);
	}

	int sCount;
	char command[101];
	scanf("%d", &sCount);


	for (int i = 0; i < sCount; i++) {
		getchar();
		scanf("%s", command);
		traverse(root, command);
		printf("\n");
	}

	freeTree(root);

	return 0;
}