#pragma once
#include <stdio.h>
#include <stdlib.h>

class PriorityQueue
{
public:
	enum Type
	{
		min = true,
		max = false
	};
private:
	void** arr;
	int arrLength;
	int elementSize;
	Type treeType;

private:
	void increaseSize();
	void addToMin(void* val);
	void addToMax(void* val);
	void* getMin();
	void* getMax();
	int (*cmp)(void*, void*);
public:
	PriorityQueue(Type t, int size, int (*compare)(void*, void*));
	int getLength();
	void add(void* val);
	void* get();
	void* look();
};