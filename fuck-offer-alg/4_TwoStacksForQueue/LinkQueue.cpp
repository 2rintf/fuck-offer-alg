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

	q->rear->next = node;// β����nextָ����Ԫ��
	q->rear = node;// ����Ԫ�أ���㣩����β���

	return true;
}
