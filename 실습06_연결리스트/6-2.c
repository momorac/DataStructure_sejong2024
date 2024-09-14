#include <stdio.h>
#include <stdlib.h>

// 문제 : 다항식을 단일 연결리스트로 저장해 구현

struct TermNode
{
    int coef; // coefficient : 항의 계수
    int exp;  // exponent : 항의 차수
    struct TermNode *next;
} typedef NODE;

NODE *init(NODE **);
NODE *appendTerm(NODE *, int, int);
NODE *addPoly(NODE *, NODE *);
void printPoly(NODE *);
void freePoly(NODE *);

NODE *head1;
NODE *head2;
NODE *head_result;

int main()
{
    NODE *poly1;
    NODE *poly2;
    poly1 = init(&head1);
    poly2 = init(&head2);

    int count, c, e;
    // 첫번째 다항식 입력받기
    scanf("%d", &count);
    for (int j = 0; j < count; j++)
    {
        scanf("%d %d", &c, &e);
        poly1 = appendTerm(poly1, c, e);
    }

    // 두번째 다항식 입력받기
    scanf("%d", &count);
    for (int j = 0; j < count; j++)
    {
        scanf("%d %d", &c, &e);
        poly2 = appendTerm(poly2, c, e);
    }
    // printPoly(head1);
    // printPoly(head2);

    addPoly(head1, head2);
    printPoly(head_result);

    freePoly(head1);
    freePoly(head2);
    freePoly(head_result);

    return 0;
}

NODE *init(NODE **head)
{
    *head = (NODE *)malloc(sizeof(NODE));
    (*head)->coef = 0;
    (*head)->exp = 0;
    (*head)->next = NULL;
    return *head;
}

NODE *appendTerm(NODE *lastT, int c, int e)
{
    NODE *newT = (NODE *)malloc(sizeof(NODE));
    newT->coef = c;
    newT->exp = e;
    newT->next = NULL;
    lastT->next = newT;
    return newT;
}

NODE *addPoly(NODE *poly1, NODE *poly2)
{
    NODE *poly_result;
    poly_result = init(&head_result);

    // 헤더는 스킵
    NODE *p1 = poly1->next;
    NODE *p2 = poly2->next;
    NODE *q = poly_result;

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->exp > p2->exp)
        {
            q = appendTerm(q, p1->coef, p1->exp);
            p1 = p1->next;
        }
        else if (p1->exp < p2->exp)
        {
            q = appendTerm(q, p2->coef, p2->exp);
            p2 = p2->next;
        }
        else
        {
            int sum = p1->coef + p2->coef;
            if (sum != 0)
                q = appendTerm(q, sum, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    while (p1 != NULL)
    {
        appendTerm(q, p1->coef, p1->exp);
        p1 = p1->next;
    }
    while (p2 != NULL)
    {
        appendTerm(q, p2->coef, p2->exp);
        p2 = p2->next;
    }

    return poly_result;
}

// 다항식 출력하는 함수
void printPoly(NODE *poly)
{
    NODE *p = poly;
    while (p != NULL)
    {
        if (p->coef == 0)
        {
            p = p->next;
            continue;
        }
        printf(" %d %d", p->coef, p->exp);
        p = p->next;
    }
}

// 동적할당 해제 함수
void freePoly(NODE *poly)
{
    NODE *current = poly;
    NODE *next;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
}
