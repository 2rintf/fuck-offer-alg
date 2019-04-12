#include "LinkQueue.hpp"

bool LinkQueue::initQueue(queue * q)
{
	q->front = (QNode*)malloc(sizeof(QNode));
	q->rear = (QNode*)malloc(sizeof(QNode));

	if (!q->front)
	{
		cout << "malloc failed." << endl;
		return false;
	}

	q->front->next = NULL;
	q->rear->next = NULL;

	return true;
}

void LinkQueue::destroyQueue(queue * q)
{
	while (q->front)
	{
		q->rear = q->front->next;
		free(q->front);
		q->front = q->rear;
	}

}

void LinkQueue::clearQueue(queue * q)
{
	
}

bool LinkQueue::enQueue(queue * q, Elemtype & element)
{
	QNode* node = (QNode*)malloc(sizeof(QNode));
	if (!node)
	{
		cout << "enQueue node malloc failed."<<endl;
		return false;
	}

	node->data = element;
	node->next = NULL;

	q->rear->next = node;// 尾结点的next指向新元素
	q->rear = node;// 将新元素（结点）赋予尾结点

	return true;
}
