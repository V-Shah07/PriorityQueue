#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "PriorityQueue.h"
#pragma warning(disable:4996)

void print(int* arr, int length)
{
	printf("Length is %d\n", length);
	for (int i = 0; i < length; ++i)
	{
		printf("%d  ", arr[i]);
		
	}
	printf("\n");
}
/*
void testMax(PriorityQueue q, int num)
{
	for (int i = 0; i < num; ++i)
	{
		q.add((int)rand() % INT_MAX);
	}
	printf("Added %d numbers\n", num);
	int lastRemoved = q.get();
	int curRemoved;
	for (int i = 1; i < num; ++i)
	{
		curRemoved = q.get();
		if (curRemoved > lastRemoved)
		{
			printf("You did not develop the tree properly.");
			exit(-1);
		}
		lastRemoved = curRemoved;
	}
	printf("tree succesfully built!");
}
void testMin(PriorityQueue q, int num)
{
	for (int i = 0; i < num; ++i)
	{
		q.add((int)rand() % 20);
	}
	printf("Added %d numbers\n", num);
	int lastRemoved = q.get();
	int curRemoved;
	for (int i = 1; i < num; ++i)
	{
		curRemoved = q.get();
		if (curRemoved < lastRemoved)
		{
			printf("You did not develop the tree properly.");
			exit(-1);
		}
		lastRemoved = curRemoved;
	}
	printf("tree succesfully built!");
}
*/
int cmpInts(void* a, void* b)
{
	int* x = (int*)a;
	int* y = (int*)b;

	return (*x) - (*y);
}
struct testStruct
{
	int a;
	double b;
	char c;
};
int cmpStruct(void* a, void* b)
{
	testStruct* x = (testStruct*)a;
	testStruct* y = (testStruct*)b;
	if (x->a == y->a)
	{
		if (x->b == y->b)
		{
			return x->c - y->c;
		}
		else
		{
			return (int)(x->b - y->b);
		}
	}
	else
	{
		return x->a - y->a;
	}
}
void printStruct(testStruct t)
{
	printf("%d %f %c\n", t.a, t.b, t.c);
}
int main()
{

	srand(time(NULL));
	/*
	PriorityQueue maxQueue(PriorityQueue::max);
	PriorityQueue minQueue(PriorityQueue::min);
	int num;
	printf("How many elements would you like to add to the max priority queue: ");
	scanf("%d", &num);
	testMax(maxQueue, num);
	printf("\nHow many elements would you like to add to the min priority queue: ");
	scanf("%d", &num);
	testMin(minQueue, num);
	*/
	PriorityQueue maxQ(PriorityQueue::max, sizeof(int), cmpStruct);
	testStruct temp[5];
	int A = 1;
	int B = 1.0;
	char C = 'a';
	for (int i = 0; i < 5; i++)
	{
		temp[i].a = A + i;
		temp[i].b = B + i;
		temp[i].c = C + i;
	}
	for (int i = 0; i < 5; i++)
	{
		maxQ.add(&temp[i]);
		printf("Added: \n");
		printStruct(temp[i]);
	}
	for (int i = 0; i < 5; i++)
	{
		printf("Removed: \n");
		printStruct(*(testStruct*)maxQ.get());
	}

}