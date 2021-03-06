#include "CircularQueue.hpp"



CircularQueue::CircularQueue(queue* PQueue, int queueCapacity)
{
	CircularQueue::initQueue(PQueue, queueCapacity);
}
CircularQueue::~CircularQueue()
{
}

bool CircularQueue::initQueue(queue* PQueue, int queueCapacity)
{
	PQueue->pBase = (ElemType*)malloc(sizeof(ElemType)*queueCapacity);

	if (!PQueue->pBase)
	{
		cout << "malloc error." << endl;
		return false;
	}
	PQueue->front = 0;
	PQueue->rear = 0;
	PQueue->maxSize = queueCapacity;
	cout << "init success." << endl << endl;

	return true;
}

void CircularQueue::destroyQueue(queue* PQueue)
{
	free(PQueue);
	PQueue = NULL;// 重新指向NULL，避免成为野指针
	cout << "destroyed." << endl << endl;
}

void CircularQueue::clearQueue(queue * PQueue)
{
	PQueue->front = 0;
	PQueue->rear = 0;
}

bool CircularQueue::isEmptyQueue(queue * PQueue)
{
	if (PQueue->front == PQueue->rear)
	{
		cout << "queue is empty" << endl;
		return true;
	}
	return false;
}


/*
利用一个元素空间来实现队列满的标志。
定义：只要rear的下一跳等于front，就认为目前队列已满。
以此来和队空标志作区分。
*/
bool CircularQueue::isFullQueue(queue * PQueue)
{
	if ((PQueue->rear + 1) % PQueue->maxSize == PQueue->front)
	{
		cout << "queue is full." << endl;
		return true;
	}
	return false;
}

int CircularQueue::getQueueLen(queue * PQueue)
{
	// 因为是循环队列，所以要借助maxSize来取余，以获得真实的队列长度
	return (PQueue->rear - PQueue->front + PQueue->maxSize) % PQueue->maxSize;
}

bool CircularQueue::enQueue(queue * PQueue, ElemType element)
{
	if (isFullQueue(PQueue))
	{
		cout << "can not entry Queue." << endl << endl;
		return false;
	}

	PQueue->pBase[PQueue->rear] = element;// rear所指空位置添加新元素
	PQueue->rear = (PQueue->rear + 1) % PQueue->maxSize;// KEY POINT!

	return true;
}

bool CircularQueue::deQueue(queue * PQueue, ElemType * pElement)
{
	if (isEmptyQueue(PQueue))
	{
		cout << "can not deQueue." << endl << endl;
		return false;
	}

	*pElement = PQueue->pBase[PQueue->front];
	PQueue->front = (PQueue->front + 1) % PQueue->maxSize;// KEY POINT!
	return true;
}

void CircularQueue::queueTraverse(queue * PQueue)
{
	cout << "print queue:" << endl;
	for (int i = PQueue->front; i != PQueue->rear;)
	{
		cout << PQueue->pBase[i] << "  ";
		i = (i + 1) % PQueue->maxSize;
	}
	cout << endl << endl;
}


