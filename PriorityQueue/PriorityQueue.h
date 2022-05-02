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
	int* arr;
	int length;
	Type treeType;

private:
	void increaseSize();
	void addToMin(int val);
	void addToMax(int val);
	int getMin();
	int getMax();
public:
	PriorityQueue(Type t);
	PriorityQueue(Type t, int len);
	int getLength();
	int* getArray();
	void add(int val);
	int get();
};