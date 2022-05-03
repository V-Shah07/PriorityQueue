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
	PriorityQueue maxQ(PriorityQueue::max, sizeof(int), cmpInts);
	int addValue1 = 1;
	maxQ.add(&addValue1);
	int addValue2 = 2;
	maxQ.add(&addValue2);
	printf("removed %d\n", *((int*)maxQ.get()));
	printf("removed %d\n\n", *((int*)maxQ.get()));
}