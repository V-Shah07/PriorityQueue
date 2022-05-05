#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "PriorityQueue.h"
#pragma warning(disable:4996)

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
void testMax(PriorityQueue q, int num)
{
	testStruct* structures = (testStruct*)calloc(num, sizeof(testStruct));
	for (int i = 0; i < num; ++i)
	{
		structures[i].a = rand() % INT_MAX;
		structures[i].b = (double)(rand() % INT_MAX);
		structures[i].c = 'a' + rand() % 26;
		q.add(&structures[i]);
	}
	printf("Added %d numbers\n", num);
	testStruct lastRemoved = *((testStruct*)q.get());
	testStruct curRemoved;
	for (int i = 1; i < num; ++i)
	{
		curRemoved = *((testStruct*)q.get());
		if(cmpStruct(&curRemoved, &lastRemoved) > 0)
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
	testStruct* structures = (testStruct*)calloc(num, sizeof(testStruct));
	for (int i = 0; i < num; ++i)
	{
		structures[i].a = rand() % INT_MAX;
		structures[i].b = (double)(rand() % INT_MAX);
		structures[i].c = 'a' + rand() % 26;
		q.add(&structures[i]);
	}
	printf("Added %d numbers\n", num);
	testStruct lastRemoved = *((testStruct*)q.get());
	testStruct curRemoved;
	for (int i = 1; i < num; ++i)
	{
		curRemoved = *((testStruct*)q.get());
		if (cmpStruct(&curRemoved, &lastRemoved) < 0)
		{
			printf("You did not develop the tree properly.");
			exit(-1);
		}
		lastRemoved = curRemoved;
	}
	printf("tree succesfully built!");
}

int main()
{
	srand(time(NULL));
	int num;
	PriorityQueue MaxQ(PriorityQueue::max, sizeof(testStruct), cmpStruct);
	PriorityQueue MinQ(PriorityQueue::min, sizeof(testStruct), cmpStruct);


	printf("How many elements would you like to add to the max priority queue?: ");
	scanf("%d", &num);
	testMax(MaxQ, num);

	printf("\n\n");
	
	printf("How many elements would you like to add to the min priority queue?: ");
	scanf("%d", &num);
	testMin(MinQ, num);

	printf("\n\n");
}