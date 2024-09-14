#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

struct Node
{
	char elem;
	struct Node *prev;
	struct Node *next;
} typedef NODE;

NODE *head;
NODE *trailer;

NODE *init()
{
	head = (NODE *)malloc(sizeof(NODE));
	trailer = (NODE *)malloc(sizeof(NODE));

	head->next = trailer;
	head->prev = 0;
	trailer->prev = head;
	trailer->next = 0;

	return head;
}

void print(NODE *list)
{
	NODE *p = list->next; // 헤드 다음 노드부터 시작
	while (p != trailer)
	{
		printf("%c", p->elem);
		p = p->next;
	}
	printf("\n");
}

void get(NODE *list, int index)
{
	if (index < 1)
	{

		printf("invalid position\n");
		return;
	}

	NODE *p = list->next;
	for (int i = 1; i < index; i++)
	{
		p = p->next;
		if (p == trailer)
		{
			printf("invalid position\n");
			return;
		}
	}
	printf("%c\n", p->elem);
}

void add(NODE *list, int index, char c)
{
	if (index < 1)
	{
		printf("invalid position\n");
		return;
	}

	NODE *p = list;
	for (int i = 1; i < index; i++)
	{
		p = p->next;
		if (p == trailer)
		{
			printf("invalid position\n");
			return;
		}
	}
	// p:추가될 자리 직전 노드

	NODE *newNode = (NODE *)malloc(sizeof(NODE));
	newNode->elem = c;
	newNode->prev = p;
	newNode->next = p->next;
	p->next->prev = newNode;
	p->next = newNode;
}

void del(NODE *list, int index)
{
	if (index < 1)
	{
		printf("invalid position\n");
		return;
	}

	NODE *p = list->next; // 첫 번째 노드부터 시작
	for (int i = 1; i < index; i++)
	{
		p = p->next;
		if (p == trailer)
		{
			printf("invalid position\n");
			return;
		}
	}

	// p:삭제할 노드
	p->prev->next = p->next;
	p->next->prev = p->prev;
	free(p);
}

int main()
{
	NODE *list = init();

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		char command;
		int index;
		char elem;
		getchar();
		scanf("%c", &command);

		switch (command)
		{
		case 'A':
			scanf("%d %c", &index, &elem);
			add(list, index, elem);
			break;
		case 'D':
			scanf("%d", &index);
			del(list, index);
			break;
		case 'G':
			scanf("%d", &index);
			get(list, index);
			break;
		case 'P':
			print(list);
			break;
		}
	}

	return 0;
}