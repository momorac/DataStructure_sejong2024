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

    char str[101];  // 입력 가능한 문자는 최대 100자(한글 50자)
    NODE* new = getNode();

    printf("50자 이하의 최종 결정을 입력하세요: ");
    gets(str);

    strcpy(new->data, str); // 노드의 데이터에 입력한 텍스트 저장

    new->left = NULL;
    new->right = NULL;
    return new;
}

NODE* makeInternalNode(int* count) {
    char str[101], tmp;
    NODE* new = getNode();


    // 최대 질문 횟수 초과 시
    if (*count > 32) {
        printf("최대 문답 횟수를 초과하였습니다. 최종 결정 입력 후 결정트리 구축을 종료합니다.\n");

        printf("응답이 긍정일 때 ");
        new->left = makeExternalNode();
        printf("응답이 부정일 때 ");
        new->right = makeExternalNode();
        return new;
    }

    // 질문 입력받기
    printf("50자 이하의 질문을 입력하세요: ");
    gets(str);
    strcpy(new->data, str);
    (*count)++;

    printf("%s 질문에 대한 답이 긍정일때, 질문을 하시겠습니까? 예:Y / 아니오:N\n", new->data);
    scanf(" %c", &tmp);
    getchar();

    if (tmp == 'Y')
        new->left = makeInternalNode(count);
    else if (tmp == 'N')
        new->left = makeExternalNode();

    printf("%s 질문에 대한 답이 부정일때, 질문을 하시겠습니까? 예:Y / 아니오:N\n", new->data);
    scanf(" %c", &tmp);
    getchar();

    if (tmp == 'Y')
        new->right = makeInternalNode(count);
    else if (tmp == 'N')
        new->right = makeExternalNode();

    return new;
}


NODE* buildDecisionTree() {
    printf("결정트리 구축을 시작합니다\n");
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

// 문답 실행 함수
void runDecisionTree(NODE* root) {
    printf("***질문에 대해 응답을 입력해주세요***\n");
    processNode(root);
}

// 동적할당 해제하는 함수
void freeTree(NODE* node) {
    if (node == NULL) return;
    freeTree(node->left);
    freeTree(node->right);
    free(node);
}

int main() {

    // 결정트리 구축
    NODE* root = buildDecisionTree();
    printf("결정트리 구축이 완료되었습니다. 테스트를 실행합니다.\n");
    printf("질문에 대한 응답은 긍정이면 'Y', 부정이면 'N'으로 입력해 주세요.\n");

    // 테스트 3회 실행
    for (int i = 0; i < 3; i++) {
        runDecisionTree(root);
        printf("\n");
    }

    freeTree(root);

    return 0;
}
