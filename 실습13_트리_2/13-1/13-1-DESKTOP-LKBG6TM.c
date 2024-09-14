#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable:4996)

struct Node {
	int id;
	int data;
	struct Node* left;
	struct Node* right;
}typedef NODE;

NODE* setNode(int id, int data) {
	NODE* new = (NODE*)malloc(sizeof(NODE));
	new->data = data;
	new->id = id;
	new->right = NULL;
	new->left = NULL;

	return new;
}

NODE* preOrderSearch(NODE* root, int targetID) {
	if (root == NULL) return;

	if (root->id == targetID) {
		return root;
	}

	preOrderSearch(root->left, targetID);
	preOrderSearch(root->right, targetID);
}

void preOrderTraverse(NODE* root) {

	if (root == NULL)
		return;

	printf(" %d", root->data); //데이터 출력

	preOrderTraverse(root->left);	//왼쪽 서브트리 순회
	preOrderTraverse(root->right);	//오른쪽 서브트리 순회
}

void inOrderTraverse(NODE* root) {
	if (root == NULL)
		return;

	inOrderTraverse(root->left);//왼쪽 서브트리 순회

	printf(" %d", root->data); //데이터 출력

	inOrderTraverse(root->right);//오른쪽 서브트리 순회
}

void postOrderTraverse(NODE* root) {
	if (root == NULL)
		return;

	postOrderTraverse(root->left);	// 왼쪽 서브트리 순회
	postOrderTraverse(root->right);	//오른쪽 서브트리 순회

	printf(" %d", root->data);		//데이터 출력
}


int main() {
	NODE* tree = setNode(1, 20);
	tree->left = setNode(2, 30);
	tree->right = setNode(3, 50);
	tree->left->left = setNode(4, 70);
	tree->left->right = setNode(5, 90);
	tree->right->right = setNode(6, 120);
	tree->right->right->left = setNode(7, 130);
	tree->right->right->right = setNode(8, 80);

	int com, id;
	scanf("%d %d", &com, &id);

	if (id < 1 || id>8) {
		printf("-1");
		return 0;
	}


	NODE* root = preOrderSearch(tree, id);

	switch (com) {
	case 1:	//선위순회
		preOrderTraverse(root);
		break;
	case 2:	//중위순회
		inOrderTraverse(root);
		break;
	case 3:	//후위순회
		postOrderTraverse(root);
		break;
	}





	return 0;
}