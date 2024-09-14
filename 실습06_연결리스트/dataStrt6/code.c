#include <stdio.h>
#include <stdlib.h> 
#pragma warning (disable:4996)

struct Node
{
	char elem;
	struct Node* prev;
	struct Node* next;
}typedef NODE;

NODE* head;
NODE* trailer;

NODE* init() {

	head = (NODE*)malloc(sizeof(NODE));
	trailer = (NODE*)malloc(sizeof(NODE));

	head->next = trailer;
	head->prev = trailer;
	trailer->prev = head;
	trailer->next = head;

	return head;
}

void print(NODE* list) {
	NODE* p = head->next; // ��� ���� ������ ����
	while (p != trailer) {
		printf("%c", p->elem);
		p = p->next;
	}
}

void get(NODE* list, int index) {
	if (index < 1) {
		printf("invalid position\n");
		return;
	}

	NODE* p = list;
	for (int i = 1; i <= index; i++) {
		p = p->next;
		if (p == trailer) {
			printf("invalid position\n");
			return;
		}
	}
	printf("%c", p->elem);
}
void add(NODE* list, int index, char c) {
	if (index < 1) {
		printf("invalid position\n");
		return;
	}

	NODE* p = list;
	for (int i = 1; i < index; i++) {
		p = p->next;
		if (p == trailer) {
			printf("invalid position\n");
			return;
		}
	}

	NODE* new = (NODE*)malloc(sizeof(NODE));
	new->elem = c;
	new->prev = p;
	new->next = p->next;
	p->next->prev = new;
	p->next = new;
}

void del(NODE* list, int index) {
	if (index < 1) {
		printf("invalid position\n");
		return;
	}

	NODE* p = list->next;  //ù ��° ������ ����
	for (int i = 1; i < index; i++) {
		p = p->next;
		if (p == trailer) {
			printf("invalid position\n");
			return;
		}
	}

	// p:������ ���
	p->prev->next = p->next;
	p->next->prev = p->prev;
	free(p);
	free(p);

}


main()
{
	NODE* list = init();

	/*
	add(list, 1, 'a');
	add(list, 2, 'b');
	add(list, 3, 'd');
	add(list, 3, 'c');
	print(list);
	*/

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		char command;
		int index;
		char elem;
		scanf("%c %d %c", &command, &index, &elem);

		switch (command) {
		case 'A':
			add(list, index, elem);
			break;
		case 'D':
			del(list, index);
			break;
		case 'G':
			get(list, index);
			break;
		case 'P':
			print(list);
			break;
		}
	}

	return 0;
}