#include "CircularQueue.hpp"
using namespace std;

int main()
{
	queue *q = (queue *)malloc(sizeof(queue));
	CircularQueue cq;
	cq.initQueue(q, 6);

	// 入队7个元素. 但实际队列初始化长度为6，实际元素容量为5.
	for (int i = 1; i < 8; i++)
	{
		cq.enQueue(q, i);
		cout <<"NOW queue length:"<< cq.getQueueLen(q) << endl;
	}

	cq.queueTraverse(q);

	int* out = (int*)malloc(6 * sizeof(int));
	cq.deQueue(q, out);
	cq.deQueue(q, out + 1);
	cq.deQueue(q, out + 2);
	//cq.deQueue(q, out + 3);
	cout << "NOW queue length:" << cq.getQueueLen(q) << endl;

	for (int i = 1; i < 6; i++)
	{
		cq.enQueue(q, i);
		cout << "NOW queue length:" << cq.getQueueLen(q) << endl;
	}

	cq.queueTraverse(q);

	system("pause");
}