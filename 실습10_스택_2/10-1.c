#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n = 100;
int t = -1;

void push(char *stack, char elem)
{
	if (t < n)
	{
		t++;
		*(stack + t) = elem;
	}
	else
	{
		printf("Stack FULL\n");
	}
}

char pop(char *stack)
{
	char p;
	if (t < 0)
	{
		printf("Stack Empty\n");
		return 0;
	}
	p = *(stack + t);
	*(stack + t) = 0;
	t--;
	return p;
}

char duplicate(char *stack)
{
	char elem = pop(stack);
	push(stack, elem);
	push(stack, elem);
	return elem;
}

char peek(char *stack)
{
	return *(stack + t);
}

void print(char *stack, int t)
{
	int i;
	for (i = t; i >= 0; i--)
	{
		printf("%c", *(stack + i));
	}
	printf("\n");
}

int priority(char s)
{
	if (s == '!' || s == 'p' || s == 'm')
		return 6;
	else if (s == '*' || s == '/')
		return 5;
	else if (s == '+' || s == '-')
		return 4;
	else if (s == '>' || s == '<')
		return 3;
	else if (s == '&')
		return 2;
	else if (s == '|')
		return 1;
	else
		return 0;
}

int isOperand(char s)
{
	if (s >= 'A' && s <= 'Z')
		return 1;
	else
		return 0;
}

int main()
{
	char *op_stack;

	int count;
	scanf("%d", &count);

	char infix[101];

	for (int i = 0; i < count; i++)
	{
		scanf("%s", infix);
		// 단항 연산자 처리
		if (infix[0] == '+')
			infix[0] = 'p';
		if (infix[0] == '-')
			infix[0] = 'm';

		// 연산자 스택 초기화
		op_stack = (char *)malloc(n * sizeof(char));
		t = -1;

		int j = 0;
		char s = 1;
		while (s != '\0')
		{
			s = infix[j];
			j++;

			if (s == '|')
				j++;
			if (s == '&')
				j++;

			if (isOperand(s))
			{
				printf("%c", s);
			}
			else if (s == '(')
			{
				push(op_stack, s);
			}
			else if (s == ')')
			{
				while (peek(op_stack) != '(')
				{
					if (peek(op_stack) == '|')
						printf("|");
					if (peek(op_stack) == '&')
						printf("&");
					printf("%c", pop(op_stack));
				}
				pop(op_stack);
			}
			else // 연산자이면
			{
				while (t >= 0 && (priority(s) <= priority(peek(op_stack))))
				{
					if (peek(op_stack) == '|')
						printf("|");
					if (peek(op_stack) == '&')
						printf("&");
					printf("%c", pop(op_stack));
				}
				push(op_stack, s);
			}
		}

		while (t > 0)
		{
			if (peek(op_stack) == '|')
				printf("|");
			if (peek(op_stack) == '&')
				printf("&");
			printf("%c", pop(op_stack));
		}
		printf("\n");
		free(op_stack);
	}

	return 0;
}

/*
5
A*B+C+(D+E)*F
A+B*C
A/B-C+D*E-F*G
A+(B*C+D)*E
A&&B||C||!(E>F)
*/