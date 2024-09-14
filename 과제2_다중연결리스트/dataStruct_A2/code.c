#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable:4996)

struct node
{
	struct node* nextName;
	struct node* nextCoupon;
	char name;
	int coupon;
} typedef NODE;

NODE* array_name[5];
NODE* array_coupon[4];

NODE* getNode(char, int);
void addShare(char, int);
void removeShare(int, char);
void traverseShareGroups(int);
void traverseShareElements(char);

// NG = 5, NE = 4�� ����ϰ� �����ڸ��� [A,B,C,D,E]�� ���� ���� [1,2,3,4]�� ����Ͻÿ�.
int main()
{

	int ng = 5; // ������
	int ne = 4; // ���� ����

	// �迭 �ʱ�ȭ
	for (int i = 0; i < ng; i++)
		array_name[i] = getNode(0, 0);
	for (int i = 0; i < ne; i++)
		array_coupon[i] = getNode(0, 0);

	char command, name;
	int coupon;

	while (1)
	{
		scanf("%c", &command);
		getchar();
		if (command == 'q')
			break;

		switch (command)
		{
		case 'a': // ��� �߰�
			scanf("%d %c", &coupon, &name);
			getchar();
			addShare(name, coupon);
			printf("OK\n");
			break;
		case 'r': // ��� ����
			scanf("%d %c", &coupon, &name);
			getchar();
			removeShare(coupon, name);
			printf("OK\n");
			break;
		case 'e': // element ��ȸ���
			scanf("%c", &name);
			getchar();
			traverseShareElements(name);
			break;
		case 'g': // group ��ȸ���
			scanf("%d", &coupon);
			getchar();
			traverseShareGroups(coupon);
			break;
		}
	}

	for (int i = 0; i < ng; i++)
	{
		NODE* current = array_name[i];
		NODE* next;
		while (current != NULL)
		{
			next = current->nextCoupon;
			free(current);
			current = next;
		}
	}

	for (int i = 0; i < ne; i++)
	{
		NODE* current = array_coupon[i];
		NODE* next;
		while (current != NULL)
		{
			next = current->nextName;
			free(current);
			current = next;
		}
	}

	return 0;
}

NODE* getNode(char name, int coupon)
{
	NODE* new = (NODE*)malloc(sizeof(NODE));
	new->name = name;
	new->coupon = coupon;
	new->nextCoupon = NULL;
	new->nextName = NULL;
	return new;
}

void addShare(char name, int coupon)
{
	NODE* newnode = getNode(name, coupon);

	// p: ������ ���
	NODE* p = array_name[name - 'A'];
	while (p->nextCoupon != NULL)
		p = p->nextCoupon;

	p->nextCoupon = newnode;

	p = array_coupon[coupon - 1];
	while (p->nextName != NULL)
		p = p->nextName;

	p->nextName = newnode;
}

void removeShare(int coupon, char name)
{
	NODE* cur = array_name[name - 'A'];
	NODE* prev = NULL;

	// cur: ������ ���
	while (cur != NULL && cur->coupon != coupon)
	{
		prev = cur;
		cur = cur->nextCoupon;
	}
	prev->nextCoupon = cur->nextCoupon;

	cur = array_coupon[coupon - 1];
	while (cur != NULL && cur->name != name)
	{
		prev = cur;
		cur = cur->nextName;
	}
	prev->nextName = cur->nextName;
	free(cur);
}

// �����
void traverseShareGroups(int coupon)
{
	NODE* p = array_coupon[coupon - 1]->nextName;
	if (p == NULL)
	{
		printf("0\n");
		return;
	}

	while (p != NULL)
	{
		printf("%c ", p->name);
		p = p->nextName;
	}
	printf("\n");
}

// ����
void traverseShareElements(char name)
{
	NODE* p = array_name[name - 'A']->nextCoupon;
	if (p == NULL)
	{
		printf("0\n");
		return;
	}

	while (p != NULL)
	{
		printf("%d ", p->coupon);
		p = p->nextCoupon;
	}
	printf("\n");
}
