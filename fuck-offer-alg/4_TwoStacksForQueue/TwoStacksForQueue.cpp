//#include <vector>
//#include <stdlib.h>
//#include <iostream>
//#include <stack>

#include "CircularQueue.hpp"
using namespace std;

int main()
{
	queue *q = (queue *)malloc(sizeof(queue));
	CircularQueue cq;
	cq.initQueue(q, 5);

	for (int i = 0; i < 6; i++)
	{
		cq.enQueue(q, i);
	}

	cq.queueTraverse(q);


	system("pause");
	
	
}