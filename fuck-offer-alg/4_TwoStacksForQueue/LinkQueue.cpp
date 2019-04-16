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
	QNode* nowNode;
	QNode* nextNode;
	q->rear = q->front; // 先把队列的尾指针重置一下，即等于头指针
	// 开始删除队列节点
	nextNode = q->front->next;
	q->front->next = NULL; // 把头指针重置
	while (nextNode)
	{
		nowNode = nextNode;
		nextNode = nextNode->next;
		free(nowNode);
	}
}

bool LinkQueue::isEmptyQueue(queue * q)
{
	if (q->front == q->rear)
	{
		cout<<"queue is empty."<<endl << endl;
		return false;
	}
	return true;
}

int LinkQueue::getQueueLen(queue * q)
{
	QNode* help;
	int count = 0;
	help = q->front;
	while (help!=q->rear)
	{
		count++;
		help = help->next;
	}
	return count;
}

bool LinkQueue::getHead(queue * q, Elemtype & element)
{
	QNode* help;
	if (q->front == q->rear)
	{
		cout<<"can not get head.queue is NULL."<<endl << endl;
		return false;
	}
	help = q->front->next;
	element = help->data;

	return true;
}

bool LinkQueue::enQueue(queue * q, Elemtype & element)
{
	QNode* node = (QNode*)malloc(sizeof(QNode));
	if (!node)
	{
		cout << "enQueue node malloc failed." << endl;
		return false;
	}

	node->data = element;
	node->next = NULL;

	//? 下面这两句的意义?
	//? 感觉 q->rear = node; 不是又把q->rear->next赋值为NULL了吗?

	q->rear->next = node;// 尾结点的next指向新元素
	q->rear = node;// 将新元素（结点）赋予尾结点

	return true;
}

bool LinkQueue::deQueue(queue * q, Elemtype & element)
{
	QNode* help;
	if (q->front==q->rear) 
		return false;
	// 先把头节点指向的第一个元素拿到
	help = q->front->next;
	element = help->data;
	// 把之前第一个元素的next赋给头指针的next
	q->front->next = help->next;

	// 若出队的元素是最后一个元素，把尾指针也重置一下
	if (q->rear == help)
		q->rear = q->front;

	free(help);// 释放出队元素的node内存
	return true;
}

void LinkQueue::queueTraverse(queue * q)
{
	QNode* help;
	help = q->front->next;
	while (help)
	{
		cout << help->data << "  ";
		help = help->next;
	}
	cout << endl << endl;
}
