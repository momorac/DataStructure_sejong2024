#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

struct Node {
	int data;
	struct Node* right;
	struct Node* left;
}typedef NODE;


NODE* getNode(int data, NODE* right, NODE* left) {
	NODE* new = (NODE*)malloc(sizeof(NODE));
	new->data = data;
	new->right = right;
	new->left = left;

	return new;
}

int main() {
	NODE* F[8];

	F[7] = getNode(80, NULL, NULL);
	F[6] = getNode(130, NULL, NULL);
	F[5] = getNode(120, F[6], F[7]);
	F[4] = getNode(90, NULL, NULL);
	F[3] = getNode(70, NULL, NULL);
	F[2] = getNode(50, NULL, F[5]);
	F[1] = getNode(30, F[3], F[4]);
	F[0] = getNode(20, F[1], F[2]);

	int n;
	scanf("%d", &n);
	if (n < 1 || n>8)
		printf("-1");
	else {
		printf("%d", F[n - 1]->data);
		if (F[n - 1]->right != NULL)
			printf(" %d", F[n - 1]->right->data);
		if (F[n - 1]->left != NULL)
			printf(" %d", F[n - 1]->left->data);
	}



	return 0;
}