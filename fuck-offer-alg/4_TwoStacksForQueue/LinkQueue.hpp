#ifndef LINKQUEUE_H
#define LINKQUEUE_H

#include <stdlib.h>
#include <iostream>

using namespace std;

typedef int Elemtype;

typedef	struct
{
	Elemtype data;
	QNode* next;

} QNode;

typedef struct {
	QNode* front;
	QNode* rear;
} queue;


class LinkQueue {

public:
	LinkQueue() {};
	~LinkQueue() {};

	// ��ʼ������
	bool initQueue(queue* q);
	// ���ٶ���
	void destroyQueue(queue* q);
	// ��ն���
	void clearQueue(queue* q);
	// �Ƿ�ӿ�
	bool isEmptyQueue(queue* q);
	// ��ȡ���г���
	int getQueueLen(queue* q);
	// ��element��ö�ͷԪ�أ���������
	bool getHead(queue* q,Elemtype& element);
	// ���
	bool enQueue(queue* q,Elemtype& element);
	// ����
	bool deQueue(queue* q, Elemtype& element);
	// ���б���
	void queueTraverse(queue* q);



};




#endif // !LINKQUEUE_H
