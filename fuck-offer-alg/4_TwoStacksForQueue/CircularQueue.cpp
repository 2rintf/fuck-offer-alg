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
	cout << "init success." << endl;

	return true;
}

void CircularQueue::destroyQueue(queue* PQueue)
{
	free(PQueue);
	PQueue = NULL;// ����ָ��NULL�������ΪҰָ��
	cout << "destroyed." << endl;
}

void CircularQueue::clearQueue(queue * PQueue)
{
	PQueue->front = 0;
	PQueue->rear = 0;
}

bool CircularQueue::isEmpityQueue(queue * PQueue)
{
	if (PQueue->front==PQueue->rear)
	{
		cout << "queue is empty" << endl;
		return true;
	}
	return false;
}

bool CircularQueue::isFullQueue(queue * PQueue)
{
	if ((PQueue->rear+1)%PQueue->maxSize == PQueue->front)
	{
		cout << "queue is full." << endl;
		return true;
	}
	return false;
}

int CircularQueue::getQueueLen(queue * PQueue)
{
	//? ����enQueue(),rearָ����Զ�������maxSize,Ӧ�ò����ٽ���ȡ������?

	// ��Ϊ��ѭ�����У�����Ҫ����maxSize��ȡ�࣬�Ի����ʵ�Ķ��г���
	return (PQueue->rear-PQueue->front+PQueue->maxSize)%PQueue->maxSize;
}

bool CircularQueue::enQueue(queue * PQueue, ElemType element)
{
	if (isFullQueue(PQueue))
	{
		cout << "can not entry Queue." << endl;
		return false;
	}

	PQueue->pBase[PQueue->rear] = element;// rear��ָ��λ�������Ԫ��
	//PQueue->rear += 1;
	PQueue->rear = (PQueue->rear + 1) % PQueue->maxSize;// ����rear

	return true;
}

bool CircularQueue::deQueue(queue * PQueue, ElemType * pElement)
{
	if (isEmpityQueue(PQueue))
	{
		cout << "can not deQueue." << endl;
		return false;
	}

	*pElement = PQueue->pBase[PQueue->front];
	PQueue->front = (PQueue->front + 1) % PQueue->maxSize;
	return true;
}

void CircularQueue::queueTraverse(queue * PQueue)
{
	cout << "print queue:" << endl;
	for (int i = PQueue->front; i != PQueue->rear; i++)
	{
		cout << PQueue->pBase[i] << "  ";
		//? i = (i + 1) % PQueue->maxSize;
	}
	cout << endl;
}


