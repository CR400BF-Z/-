#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void initSystem()
{
	srand(time(NULL));
	printf("==========智能口算系统==========\n");
}
void generateQuestion(int type, int* num1, int* num2, int* op)
{
	*op = type;
	if (type == 0)
	{
		*num1 = rand() % 90 + 10;
		*num2 = rand() % 90 + 10;
	}
	else if (type == 1)
	{
		*num1 = rand() % 90 + 10;
		*num2 = rand() % 90 + 10;
		if (*num1 < *num2)
		{
			int tmp;
			tmp = *num1;
			*num1 = *num2;
			*num2 = tmp;
		}
	}
	else if (type == 2)
	{
		*num1 = rand() % 9 + 1;
		*num2 = rand() % 9 + 1;
	}
	else if (type == 3)
	{
		*num2 = rand() % 9 + 1;
		int result = rand() % 9 + 1;
		*num1 = (*num2) * result;
	}
}
void getOpChar(char* operator,int* op)
{
	if (*op == 0)
	{
		*operator = '+';
	}
	else if (*op == 1)
	{
		*operator = '-';
	}
	else if (*op == 2)
	{
		*operator = '*';
	}
	else if (*op == 3)
	{
		*operator = '/';
	}
}
void generate()
{
	int a, b, op;
	char operator;
	for (int i = 1; i <= 10; i++)
	{
		generateQuestion(0, &a, &b, &op);
		getOpChar(&operator, &op);
		printf("本次题目：%d %c %d = ?\n", a, operator, b);
	}
	for (int i = 1; i <= 10; i++)
	{
		generateQuestion(1, &a, &b, &op);
		getOpChar(&operator, &op);
		printf("本次题目：%d %c %d = ?\n", a, operator, b);
	}
	for (int i = 1; i <= 10; i++)
	{
		generateQuestion(2, &a, &b, &op);
		getOpChar(&operator, &op);
		printf("本次题目：%d %c %d = ?\n", a, operator, b);
	}
	for (int i = 1; i <= 10; i++)
	{
		generateQuestion(3, &a, &b, &op);
		getOpChar(&operator, &op);
		printf("本次题目：%d %c %d = ?\n", a, operator, b);
	}
}
int main()
{
	initSystem();
	int a, b, op, type;
	generate();
	return 0;
}