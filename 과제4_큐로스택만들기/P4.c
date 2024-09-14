/*
	스택에 추가되는 원소는 모두 양의 정수가 입력된다고 가정하고 코드를 작성하였습니다.
*/


#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#pragma warning (disable:4996)


// head가 없는 연결리스트로 큐 구현
struct Node {
	int elem;
	struct Node* next;

}typedef NODE;

// 큐 구조체
struct Queue {
	NODE* front;
	NODE* rear;
	int n; //큐에 들어있는 원소의 개수
}typedef Q;


//큐 두개를 포함하는 스택 구조체
struct CombinedStack {
	Q* Q1;
	Q* Q2;
}typedef STACK;


// 큐 기본 함수

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

	// 새로운 노드 생성해서 추가
	NODE* new = (NODE*)malloc(sizeof(NODE));
	new->elem = e;


	if (q->front == NULL && q->rear == NULL) {  //큐가 비었을때
		new->next = NULL;
		q->front = new;
		q->rear = new;
	}
	else {
		q->rear->next = new;
		new->next = NULL;
		q->rear = new;
	}

	(q->n)++; // 큐 사이즈 증가
}

int dequeue(Q* q) {
	//큐가 비었을 때
	if (q->front == NULL && q->rear == NULL)
		return -1;


	NODE* tmp = q->front;
	int e = q->front->elem;

	q->front = tmp->next;
	free(tmp);

	q->n -= 1; //큐 사이즈 감소

	if (q->front == NULL)
		q->rear = NULL;

	return e;
}

//스택 기본 함수

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

	// 큐가 비어있으면 반환
	if (isEmpty(stack->Q1) && isEmpty(stack->Q2)) {
		return -1;
	}

	// Q1에 원소 하나만 남을때까지 Q1의 모든 원소 Q2로 입력
	while (stack->Q1->n > 1) {
		int x = dequeue(stack->Q1);
		enqueue(stack->Q2, x);
	}
	int e = dequeue(stack->Q1);		// 하나 남은 원소 dequeue

	// Q2가 빌 때까지 Q2의 모든 원소 Q1으로 입력
	while (stack->Q2->front != NULL) {
		int x = dequeue(stack->Q2);
		enqueue(stack->Q1, x);
	}

	return e;
}



int main() {

	// 시드 초기화 및 시간 변수 초기화
	srand(time(NULL));
	LARGE_INTEGER ticksPerSec;
	LARGE_INTEGER start, end, diff;

	// 합동스택 선언 및 초기화
	STACK stack;
	initStack(&stack);


	char com, line[101];	// 입력값 저장할 버퍼
	int tmp;				// 부함수 출력값 저장할 버퍼

	while (1) {
		scanf(" %c", &com);

		// q 입력시 반복문 종료
		if (com == 'q') {
			break;
		}

		switch (com) {
		case 'S':
			QueryPerformanceFrequency(&ticksPerSec);
			QueryPerformanceCounter(&start);
			tmp = isEmpty(stack.Q1); // 시간 측정할 작업
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

			// 시간 측정할 작업
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

			// 시간 측정할 작업
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

			// 시간 측정할 작업
			for (int i = 0; i < 1000000; i++) {
				// 10~99 사이의 랜덤한 정수 생성
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

			// 시간 측정할 작업
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

