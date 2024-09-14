#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int elem;
    struct Node *next;
} typedef NODE;

NODE *head1;
NODE *head2;

NODE *getNode(int e)
{
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->elem = e;
    newNode->next = NULL;

    return newNode;
}

NODE *addNode(NODE *head, int e)
{
    NODE *p = head;
    // p: 추가될 위치 이전 노드
    while (p->next != NULL)
    {
        if (p->elem == e)
        {
            return NULL;
        }
        p = p->next;
    }

    NODE *newNode = getNode(e);
    p->next = newNode;
    return newNode;
}

int subset(NODE *head1, NODE *head2)
{
    bool isSubset = true;
    int minElem = 9999;

    NODE *p = head1->next;
    while (p != NULL)
    {

        NODE *q = head2->next;

        while (q != NULL && isSubset == true)
        {
            if (p->elem == q->elem)
                break;
            q = q->next;
        }

        if (q == NULL)
        {
            isSubset = false;
            if (p->elem < minElem)
                minElem = p->elem;
        }
        p = p->next;
    }

    if (isSubset)
        return 0;
    else
        return minElem;
}

int main()
{

    // 리스트 초기화 : 헤더 값 -1로 설정
    head1 = getNode(-1);
    head2 = getNode(-1);
    NODE *set1_last = head1;
    NODE *set2_last = head2;

    int n, tmpElem;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tmpElem);
        set1_last = addNode(head1, tmpElem);
    }

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tmpElem);
        set2_last = addNode(head2, tmpElem);
    }

    printf("%d", subset(head1, head2));



    // 메모리 해제
    NODE *temp;
    NODE *current;

    current = head1;
    while (current != NULL)
    {
        temp = current;
        current = current->next;
        free(temp);
    }

    current = head2;
    while (current != NULL)
    {
        temp = current;
        current = current->next;
        free(temp);
    }


    return 0;
}