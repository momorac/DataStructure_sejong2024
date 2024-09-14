#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

struct Node {
    char data[101];
    struct Node* left;
    struct Node* right;
} typedef NODE;

NODE* getNode() {
    NODE* new = (NODE*)malloc(sizeof(NODE));
    new->left = NULL;
    new->right = NULL;
    return new;
}

NODE* makeExternalNode() {

    char str[101];  // �Է� ������ ���ڴ� �ִ� 100��(�ѱ� 50��)
    NODE* new = getNode();

    printf("50�� ������ ���� ������ �Է��ϼ���: ");
    gets(str);

    strcpy(new->data, str); // ����� �����Ϳ� �Է��� �ؽ�Ʈ ����

    new->left = NULL;
    new->right = NULL;
    return new;
}

NODE* makeInternalNode(int* count) {
    char str[101], tmp;
    NODE* new = getNode();


    // �ִ� ���� Ƚ�� �ʰ� ��
    if (*count > 32) {
        printf("�ִ� ���� Ƚ���� �ʰ��Ͽ����ϴ�. ���� ���� �Է� �� ����Ʈ�� ������ �����մϴ�.\n");

        printf("������ ������ �� ");
        new->left = makeExternalNode();
        printf("������ ������ �� ");
        new->right = makeExternalNode();
        return new;
    }

    // ���� �Է¹ޱ�
    printf("50�� ������ ������ �Է��ϼ���: ");
    gets(str);
    strcpy(new->data, str);
    (*count)++;

    printf("%s ������ ���� ���� �����϶�, ������ �Ͻðڽ��ϱ�? ��:Y / �ƴϿ�:N\n", new->data);
    scanf(" %c", &tmp);
    getchar();

    if (tmp == 'Y')
        new->left = makeInternalNode(count);
    else if (tmp == 'N')
        new->left = makeExternalNode();

    printf("%s ������ ���� ���� �����϶�, ������ �Ͻðڽ��ϱ�? ��:Y / �ƴϿ�:N\n", new->data);
    scanf(" %c", &tmp);
    getchar();

    if (tmp == 'Y')
        new->right = makeInternalNode(count);
    else if (tmp == 'N')
        new->right = makeExternalNode();

    return new;
}


NODE* buildDecisionTree() {
    printf("����Ʈ�� ������ �����մϴ�\n");
    int count = 0;
    NODE* root = makeInternalNode(&count);
    return root;
}


void processNode(NODE* node) {
    char tmp;
    printf("%s ", node->data);
    if (node->right == NULL && node->left == NULL)
        return;
    scanf(" %c", &tmp);
    if (tmp == 'Y') {
        processNode(node->left);
    }
    else if (tmp == 'N') {
        processNode(node->right);
    }
}

// ���� ���� �Լ�
void runDecisionTree(NODE* root) {
    printf("***������ ���� ������ �Է����ּ���***\n");
    processNode(root);
}

// �����Ҵ� �����ϴ� �Լ�
void freeTree(NODE* node) {
    if (node == NULL) return;
    freeTree(node->left);
    freeTree(node->right);
    free(node);
}

int main() {

    // ����Ʈ�� ����
    NODE* root = buildDecisionTree();
    printf("����Ʈ�� ������ �Ϸ�Ǿ����ϴ�. �׽�Ʈ�� �����մϴ�.\n");
    printf("������ ���� ������ �����̸� 'Y', �����̸� 'N'���� �Է��� �ּ���.\n");

    // �׽�Ʈ 3ȸ ����
    for (int i = 0; i < 3; i++) {
        runDecisionTree(root);
        printf("\n");
    }

    freeTree(root);

    return 0;
}
