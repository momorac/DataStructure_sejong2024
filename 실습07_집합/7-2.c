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

NODE *getNode(int);
void addNode(NODE *, int);
int subset(NODE *, NODE *);
NODE *Union(NODE *, NODE *);
NODE *Intersect(NODE *, NODE *);
void freeNodes(NODE *);

int main()
{

    // 리스트 초기화 : 헤더 값 -1로 설정
    head1 = getNode(-1);
    head2 = getNode(-1);
    NODE *set1 = head1;
    NODE *set2 = head2;

    int n, tmpElem;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tmpElem);
        addNode(head1, tmpElem);
    }

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tmpElem);
        addNode(head2, tmpElem);
    }

    NODE *unionSet = Union(head1, head2);
    NODE *p = unionSet->next;

    if (p == NULL)
        printf("0");
    else
    {
        while (p != NULL)
        {
            printf("%d ", p->elem);
            p = p->next;
        }
    }
    printf("\n");

    NODE *intersectSet = Intersect(head1, head2);
    p = intersectSet->next;
    if (p == NULL)
        printf("0\n");
    else
    {
        while (p != NULL)
        {
            printf("%d ", p->elem);
            p = p->next;
        }
    }

    freeNodes(head1);
    freeNodes(head2);
    freeNodes(unionSet);
    freeNodes(intersectSet);

    return 0;
}

NODE *getNode(int e)
{
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->elem = e;
    newNode->next = NULL;

    return newNode;
}

void addNode(NODE *head, int e)
{
    NODE *p = head;
    // p: 추가될 위치 이전 노드
    while (p->next != NULL)
    {
        if (p->elem == e)
            return;

        if (p->elem < e && e < (p->next)->elem)
            break;

        p = p->next;
    }

    if (p->elem == e)
        return;

    NODE *newNode = getNode(e);
    newNode->next = p->next;
    p->next = newNode;
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

NODE *Union(NODE *head1, NODE *head2)
{
    NODE *unionSet = getNode(-1);

    NODE *p = head1->next;
    while (p != NULL)
    {
        addNode(unionSet, p->elem);
        p = p->next;
    }

    p = head2->next;
    while (p != NULL)
    {
        addNode(unionSet, p->elem);
        p = p->next;
    }

    return unionSet;
}

NODE *Intersect(NODE *head1, NODE *head2)
{
    NODE *intersectSet = getNode(-1);
    NODE *p = head1->next;
    NODE *q = head2->next;

    while (p != NULL && q != NULL)
    {
        if (p->elem < q->elem)
        {
            p = p->next;
        }
        else if (p->elem > q->elem)
        {
            q = q->next;
        }
        else // p->elem == q->elem
        {
            addNode(intersectSet, p->elem);
            p = p->next;
            q = q->next;
        }
    }
    return intersectSet;
}

void freeNodes(NODE *head)
{
    NODE *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}
