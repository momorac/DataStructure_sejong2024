/*
	���ÿ� �߰��Ǵ� ���Ҵ� ��� ���� ������ �Էµȴٰ� �����ϰ� �ڵ带 �ۼ��Ͽ����ϴ�.
*/


#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#pragma warning (disable:4996)


// head�� ���� ���Ḯ��Ʈ�� ť ����
struct Node {
	int elem;
	struct Node* next;

}typedef NODE;

// ť ����ü
struct Queue {
	NODE* front;
	NODE* rear;
	int n; //ť�� ����ִ� ������ ����
}typedef Q;


//ť �ΰ��� �����ϴ� ���� ����ü
struct CombinedStack {
	Q* Q1;
	Q* Q2;
}typedef STACK;


// ť �⺻ �Լ�

int isEmpty(Q* q) {
	if (q->front == NULL && q->rear == NULL)
		return 1;
	else
		return 0;

}

int front(Q* q) {
	if (q->front == NULL) {
		return -1;
	}
	else {
		return q->front->elem;
	}
}

void enqueue(Q* q, int e) {

	// ���ο� ��� �����ؼ� �߰�
	NODE* new = (NODE*)malloc(sizeof(NODE));
	new->elem = e;


	if (q->front == NULL && q->rear == NULL) {  //ť�� �������
		new->next = NULL;
		q->front = new;
		q->rear = new;
	}
	else {
		q->rear->next = new;
		new->next = NULL;
		q->rear = new;
	}

	(q->n)++; // ť ������ ����
}

int dequeue(Q* q) {
	//ť�� ����� ��
	if (q->front == NULL && q->rear == NULL)
		return -1;


	NODE* tmp = q->front;
	int e = q->front->elem;

	q->front = tmp->next;
	free(tmp);

	q->n -= 1; //ť ������ ����

	if (q->front == NULL)
		q->rear = NULL;

	return e;
}

//���� �⺻ �Լ�

void initStack(STACK* stack) {

	stack->Q1 = (Q*)malloc(sizeof(Q));
	stack->Q2 = (Q*)malloc(sizeof(Q));

	stack->Q1->front = NULL;
	stack->Q1->rear = NULL;
	stack->Q1->n = 0;

	stack->Q2->front = NULL;
	stack->Q2->rear = NULL;
	stack->Q2->n = 0;

}

void push(STACK* stack, int e) {
	enqueue(stack->Q1, e);
}

int pop(STACK* stack) {

	// ť�� ��������� ��ȯ
	if (isEmpty(stack->Q1) && isEmpty(stack->Q2)) {
		return -1;
	}

	// Q1�� ���� �ϳ��� ���������� Q1�� ��� ���� Q2�� �Է�
	while (stack->Q1->n > 1) {
		int x = dequeue(stack->Q1);
		enqueue(stack->Q2, x);
	}
	int e = dequeue(stack->Q1);		// �ϳ� ���� ���� dequeue

	// Q2�� �� ������ Q2�� ��� ���� Q1���� �Է�
	while (stack->Q2->front != NULL) {
		int x = dequeue(stack->Q2);
		enqueue(stack->Q1, x);
	}

	return e;
}



int main() {

	// �õ� �ʱ�ȭ �� �ð� ���� �ʱ�ȭ
	srand(time(NULL));
	LARGE_INTEGER ticksPerSec;
	LARGE_INTEGER start, end, diff;

	// �յ����� ���� �� �ʱ�ȭ
	STACK stack;
	initStack(&stack);


	char com, line[101];	// �Է°� ������ ����
	int tmp;				// ���Լ� ��°� ������ ����

	while (1) {
		scanf(" %c", &com);

		// q �Է½� �ݺ��� ����
		if (com == 'q') {
			break;
		}

		switch (com) {
		case 'S':
			QueryPerformanceFrequency(&ticksPerSec);
			QueryPerformanceCounter(&start);
			tmp = isEmpty(stack.Q1); // �ð� ������ �۾�
			QueryPerformanceCounter(&end);
			diff.QuadPart = end.QuadPart - start.QuadPart;

			if (tmp)
				printf("Empty ");
			else
				printf("Nonempty ");

			printf("(%d) cputime = %.10f\n", stack.Q1->n, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));
			break;

		case 't':
			QueryPerformanceFrequency(&ticksPerSec);
			QueryPerformanceCounter(&start);

			// �ð� ������ �۾�
			if (isEmpty(stack.Q1))
				printf("Empty Stack Exception!! ");
			else {
				tmp = stack.Q1->rear->elem;
				printf("%d ", tmp);
			}

			QueryPerformanceCounter(&end);
			diff.QuadPart = end.QuadPart - start.QuadPart;


			printf("(%d) cputime = %.10f\n", stack.Q1->n, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));
			break;

		case 'p':
			gets(line, 101);
			QueryPerformanceFrequency(&ticksPerSec);
			QueryPerformanceCounter(&start);

			// �ð� ������ �۾�
			for (int i = 0; i < strlen(line); i++) {
				if (line[i] >= '0' && line[i] <= '9') {
					push(&stack, line[i] - '0');
				}
			}
			QueryPerformanceCounter(&end);
			diff.QuadPart = end.QuadPart - start.QuadPart;

			printf("OK (%d) cputime = %.10f\n", stack.Q1->n, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));
			break;

		case'P':
			QueryPerformanceFrequency(&ticksPerSec);
			QueryPerformanceCounter(&start);

			// �ð� ������ �۾�
			for (int i = 0; i < 1000000; i++) {
				// 10~99 ������ ������ ���� ����
				tmp = rand() % 90 + 10;
				push(&stack, tmp);
			}
			QueryPerformanceCounter(&end);
			diff.QuadPart = end.QuadPart - start.QuadPart;

			printf("OK (%d) cputime = %.10f\n", stack.Q1->n, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));
			break;

		case 'o':
			QueryPerformanceFrequency(&ticksPerSec);
			QueryPerformanceCounter(&start);

			// �ð� ������ �۾�
			tmp = pop(&stack);
			QueryPerformanceCounter(&end);
			diff.QuadPart = end.QuadPart - start.QuadPart;

			if (tmp < 0)
				printf("Empty Stack Exception!! ");
			else
				printf("%d ", tmp);

			printf("(%d) cputime = %.10f\n", stack.Q1->n, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));
			break;

		}

	}

	free(stack.Q1);
	free(stack.Q2);

	return 0;
}

