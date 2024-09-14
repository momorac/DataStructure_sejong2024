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

NODE* array_name[5]; // group : 사용자명
NODE* array_coupon[4]; // element : 쿠폰 

NODE* getNode(char, int); 
void addShare(char, int);
void removeShare(int, char);
void traverseShareGroups(int);
void traverseShareElements(char);

// NG = 5, NE = 4를 사용하고 가입자명은 [A,B,C,D,E]를 쿠폰 명은 [1,2,3,4]를 사용하시오.
int main()
{

	int ng = 5; // 가입자
	int ne = 4; // 쿠폰 종류

	// 배열 초기화
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

        // 종료 조건 : q 입력
		if (command == 'q')
			break;

		switch (command)
		{
		case 'a': // 노드 추가
			scanf("%d %c", &coupon, &name);
			getchar();
			addShare(name, coupon);
			printf("OK\n");
			break;
		case 'r': // 노드 삭제
			scanf("%d %c", &coupon, &name);
			getchar();
			removeShare(coupon, name);
			printf("OK\n");
			break;
		case 'e': // element 순회출력
			scanf("%c", &name);
			getchar();
			traverseShareElements(name);
			break;
		case 'g': // group 순회출력
			scanf("%d", &coupon);
			getchar();
			traverseShareGroups(coupon);
			break;
		}
	}


    // 동적할당 메모리 해제
	for (int i = 0; i < ng; i++)
	{
		NODE* current = array_name[i];
		NODE* next;
		while (current != NULL)
		{
            // next 포인터에 해제할 다음 노드 주소 저장
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
            // next 포인터에 해제할 다음 노드 주소 저장
			next = current->nextName;
			free(current);
			current = next;
		}
	}

	return 0;
}

//노드 생성 및 초기화 함수
NODE* getNode(char name, int coupon)
{
	NODE* new = (NODE*)malloc(sizeof(NODE));
	new->name = name;
	new->coupon = coupon;
	new->nextCoupon = NULL;
	new->nextName = NULL;
	return new;
}

// 다중리스트 노드 추가 함수
void addShare(char name, int coupon)
{
	NODE* newnode = getNode(name, coupon);

	// p: 마지막 노드
	NODE* p = array_name[name - 'A'];
	while (p->nextCoupon != NULL)
		p = p->nextCoupon;
    // element에 새 노드 추가
	p->nextCoupon = newnode;

	p = array_coupon[coupon - 1];
	while (p->nextName != NULL)
		p = p->nextName;
    // group에 새 노드 추가
	p->nextName = newnode;
}

// 다중리스트 노드 삭제하는 함수
void removeShare(int coupon, char name)
{
	NODE* cur = array_name[name - 'A'];
	NODE* prev = NULL; // 이전 노드의 next 주소 참조를 위한 prev 포인터

	// cur: 삭제할 노드
	while (cur != NULL && cur->coupon != coupon)
	{
		prev = cur;
		cur = cur->nextCoupon;
	}
    // element에서 노드 삭제
	prev->nextCoupon = cur->nextCoupon;

	cur = array_coupon[coupon - 1];
	while (cur != NULL && cur->name != name)
	{
		prev = cur;
		cur = cur->nextName;
	}
    // group에서 노드 삭제
	prev->nextName = cur->nextName;

    // 메모리 해제
	free(cur);
}

// 사용자 리스트 출력
void traverseShareGroups(int coupon)
{
    // 첫 번째 노드부터 시작
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

// 쿠폰 리스트 출력
void traverseShareElements(char name)
{
    // 첫 번째 노드부터 시작
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
