#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#pragma warning (disable:4996)


// head가 있는 단일 연결리스트로 스택 구현
struct Node {
	int elem;
	struct Node* next;
}typedef NODE;


// top 노드의 주소를 저장한 포인터를 포함하는 스택 구조체 선언
struct Stack {
	NODE* top;
}typedef STACK;

long n = 0; // n : 스택에 들어있는 요소의 개수
int min_elem = 10000;


void push(STACK* stack, STACK* minStack, int e) {
	// 새로운 노드 생성
	NODE* new = (NODE*)malloc(sizeof(NODE));
	new->elem = e;
	new->next = stack->top;

	// 최소 원소값 비교
	if (n == 0 || e <= minStack->top->elem) {	// 스택에 추가할 원소가 최솟값 스택의 top의 원소값보다 작거나 같으면
		// 최솟값 스택에 push
		NODE* newMin = (NODE*)malloc(sizeof(NODE));
		newMin->elem = e;
		newMin->next = minStack->top;
		minStack->top = newMin;
	}

	stack->top = new;
	n++;
}


int pop(STACK* stack, STACK* minStack) {
	if (n == 0) {
		printf("Stack Empty\n");
		return;
	}
	else {
		NODE* temp = stack->top;
		stack->top = stack->top->next;

		int p = temp->elem;
		free(temp);
		n--;

		if (p == minStack->top->elem) { // pop한 원소값이 최솟값 스택의 top값과 같으면
			//최솟값 스택 pop
			temp = minStack->top;
			minStack->top = minStack->top->next;
			free(temp);
		}

		return p;
	}
}


void pushMillion(STACK* stack, STACK* minStack) {
	for (int i = 0; i < 1000000; i++) {

		// 1000~9999 사이의 랜덤한 정수 생성
		int randint = rand() % 9000 + 1000;
		push(stack, minStack, randint);
	}
}

void popMillion(STACK* stack, STACK* minStack) {
	for (int i = 0; i < 1000000; i++) {
		if (n == 0)
			break;
		else
			pop(stack, minStack);
	}
}

int findMin(STACK* minStack) {
	return minStack->top->elem;
}

void print(STACK* stack) {
	NODE* p = stack->top;

	while (p->next != NULL) {
		printf("%d ", p->elem);
		p = p->next;
	}
	printf("\n");
}

void freeStack(STACK* stack) {
	NODE* cur = stack->top;
	NODE* temp;

	while (cur != NULL) {
		temp = cur;
		cur = cur->next;
		free(temp);
	}

	stack->top = NULL;
}


int main() {

	// 시드 초기화 및 시간 변수 초기화
	srand(time(NULL));
	LARGE_INTEGER ticksPerSec;
	LARGE_INTEGER start, end, diff;


	// 스택 구조체 선언 및 top 포인터 할당
	STACK stack;
	stack.top = (NODE*)malloc(sizeof(NODE));
	stack.top->elem = 0;
	stack.top->next = NULL;

	// 메인 스택의 최소 원소들을 저장할 최솟값 스택 선언
	STACK minStack;
	minStack.top = (NODE*)malloc(sizeof(NODE));
	minStack.top->elem = INT_MAX;
	minStack.top->next = NULL;


	char com;
	int tmp;
	while (1) {

		scanf("%c", &com);

		// q 입력시 반복문 종료
		if (com == 'q') {
			freeStack(&stack);
			freeStack(&minStack);
			break;
		}

		switch (com) {
		case 'p':
			scanf("%d", &tmp);

			QueryPerformanceFrequency(&ticksPerSec);
			QueryPerformanceCounter(&start);
			push(&stack, &minStack, tmp); // 시간 측정할 작업
			QueryPerformanceCounter(&end);
			diff.QuadPart = end.QuadPart - start.QuadPart;
			printf("push %d (%d), cputime = %.10f\n", tmp, n, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));
			break;

		case 'P':
			QueryPerformanceFrequency(&ticksPerSec);
			QueryPerformanceCounter(&start);
			pushMillion(&stack, &minStack); // 시간 측정할 작업
			QueryPerformanceCounter(&end);
			diff.QuadPart = end.QuadPart - start.QuadPart;
			printf("pushMillion (%d), cputime = %.10f\n", n, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));
			break;

		case 'o':

			QueryPerformanceFrequency(&ticksPerSec);
			QueryPerformanceCounter(&start);
			tmp = pop(&stack, &minStack); // 시간 측정할 작업
			QueryPerformanceCounter(&end);
			diff.QuadPart = end.QuadPart - start.QuadPart;
			printf("pop %d (%d), cputime = %.10f\n", tmp, n, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));
			break;

		case'O':

			QueryPerformanceFrequency(&ticksPerSec);
			QueryPerformanceCounter(&start);
			popMillion(&stack, &minStack); // 시간 측정할 작업
			QueryPerformanceCounter(&end);
			diff.QuadPart = end.QuadPart - start.QuadPart;
			printf("popMillion (%d), cputime = %.10f\n", n, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));
			break;

		case 'f':
			QueryPerformanceFrequency(&ticksPerSec);
			QueryPerformanceCounter(&start);
			tmp = findMin(&minStack);
			QueryPerformanceCounter(&end);
			diff.QuadPart = end.QuadPart - start.QuadPart;
			printf("min %d (%d), cputime = %.10f\n", tmp, n, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));
			break;
		}
	}



	return 0;
}