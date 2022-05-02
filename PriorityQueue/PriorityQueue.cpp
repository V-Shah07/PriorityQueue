#include "PriorityQueue.h"


void PriorityQueue::increaseSize()
{
	arr = (int*)realloc(arr, (2 * length + 1) * sizeof(int));
	++length;
}

void PriorityQueue::addToMin(int val)
{
	int insertIndex = length;
	increaseSize();
	arr[insertIndex] = val;
	int valIndex = insertIndex; //index of where value is located
	int swapIndex;
	int temp;
	while (true)
	{
		swapIndex = (valIndex - 1) / 2;
		if (swapIndex < 0)
		{
			swapIndex = 0;
		}
		if (arr[valIndex] < arr[swapIndex])
		{
			temp = arr[valIndex];
			arr[valIndex] = arr[swapIndex];
			arr[swapIndex] = temp;
			valIndex = swapIndex;
		}
		else //in right spot, no need to continue
		{
			return;
		}
	}
}

void PriorityQueue::addToMax(int val)
{
	int insertIndex = length;
	increaseSize(); //length is changed over here
	arr[insertIndex] = val;
	int valIndex = insertIndex; //index of where value is located
	int swapIndex;
	int temp;
	while (true)
	{
		swapIndex = (valIndex - 1) / 2;
		if (valIndex < 1)
		{
			return;
		}
		if (arr[valIndex] > arr[swapIndex])
		{
			temp = arr[valIndex];
			arr[valIndex] = arr[swapIndex];
			arr[swapIndex] = temp;
			valIndex = swapIndex;
		}
		else //in right spot, no need to continue
		{
			return;
		}
	}
}

int PriorityQueue::getMin()
{
	int returnValue = arr[0];
	arr[0] = arr[length - 1];

	int headIndex = 0;
	int swapIndex;
	int temp;
	while (true)
	{
		//determining smallest child
		if ((headIndex * 2 + 1 < length) && (headIndex * 2 + 2 < length))
		{
			if (arr[headIndex * 2 + 1] < arr[headIndex * 2 + 2])
			{
				swapIndex = headIndex * 2 + 1;
			}
			else
			{
				swapIndex = headIndex * 2 + 2;
			}
		}
		else if (headIndex * 2 + 1 < length)
		{
			swapIndex = headIndex * 2 + 1;
		}
		else
		{
			break;
		}
		//actually swapping and terminating if no need to swap
		if (arr[headIndex] > arr[swapIndex])
		{
			temp = arr[headIndex];
			arr[headIndex] = arr[swapIndex];
			arr[swapIndex] = temp;
			headIndex = swapIndex;
		}
		else
		{
			break;
		}
	}
	length--;
	return returnValue;
}

int PriorityQueue::getMax()
{
	int returnValue = arr[0];
	arr[0] = arr[length - 1];

	int headIndex = 0;
	int swapIndex;
	int temp;
	while (true)
	{
		//determining biggest child
		if ((headIndex * 2 + 1 < length) && (headIndex * 2 + 2 < length))
		{
			if (arr[headIndex * 2 + 1] > arr[headIndex * 2 + 2])
			{
				swapIndex = headIndex * 2 + 1;
			}
			else
			{
				swapIndex = headIndex * 2 + 2;
			}
		}
		else if (headIndex * 2 + 1 < length)
		{
			swapIndex = headIndex * 2 + 1;
		}
		else
		{
			break;
		}
		//actually swapping and terminating if no need to swap
		if (arr[headIndex] < arr[swapIndex])
		{
			temp = arr[headIndex];
			arr[headIndex] = arr[swapIndex];
			arr[swapIndex] = temp;
			headIndex = swapIndex;
		}
		else
		{
			break;
		}
	}
	length--;
	return returnValue;
}

PriorityQueue::PriorityQueue(Type t)
{
	arr = NULL;
	length = 0;
	treeType = t;
}

PriorityQueue::PriorityQueue(Type t, int len)
{
	arr = (int*)calloc(len, sizeof(int));
	length = len;
	treeType = t;
}

int PriorityQueue::getLength()
{
	return length;
}

int* PriorityQueue::getArray()
{
	return arr;
}

void PriorityQueue::add(int val)
{
	if (treeType == min)
	{
		addToMin(val);
	}
	else
	{
		addToMax(val);
	}
}

int PriorityQueue::get()
{
	if (treeType == min)
	{
		return getMin();
	}
	else
	{
		return getMax();
	}
}