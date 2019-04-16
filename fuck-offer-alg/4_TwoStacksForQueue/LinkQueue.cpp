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
	q->rear = q->front; // �ȰѶ��е�βָ������һ�£�������ͷָ��
	// ��ʼɾ�����нڵ�
	nextNode = q->front->next;
	q->front->next = NULL; // ��ͷָ������
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

	//? ���������������?
	//? �о� q->rear = node; �����ְ�q->rear->next��ֵΪNULL����?

	q->rear->next = node;// β����nextָ����Ԫ��
	q->rear = node;// ����Ԫ�أ���㣩����β���

	return true;
}

bool LinkQueue::deQueue(queue * q, Elemtype & element)
{
	QNode* help;
	if (q->front==q->rear) 
		return false;
	// �Ȱ�ͷ�ڵ�ָ��ĵ�һ��Ԫ���õ�
	help = q->front->next;
	element = help->data;
	// ��֮ǰ��һ��Ԫ�ص�next����ͷָ���next
	q->front->next = help->next;

	// �����ӵ�Ԫ�������һ��Ԫ�أ���βָ��Ҳ����һ��
	if (q->rear == help)
		q->rear = q->front;

	free(help);// �ͷų���Ԫ�ص�node�ڴ�
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
