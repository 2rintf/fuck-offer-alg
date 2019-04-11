#ifndef CIRCULARQUEUE_H
#define CIRCULARQUEUE_H

#include <stdlib.h>
#include <iostream>

using namespace std;

/*ѭ������ Circular Queue
�ο��� �����ݽṹ(C���԰�)��-- ��ε������ -- �廪��ѧ������
*/

typedef int ElemType;
typedef struct Queue {
	ElemType* pBase;
	ElemType front;
	ElemType rear;
	ElemType maxSize;// �������
}queue;



class CircularQueue
{
public:


	CircularQueue() {}
	CircularQueue(queue* PQueue, int queueCapacity);
	~CircularQueue();

	// �����ն���
	//! ѭ������Ϊ�˽�������ı�־���⣬��������һ��Ԫ�ؿռ䣬����ʵ���Ͽ����õ�Ԫ�ؿռ�ȿ��ٿռ���1
	bool initQueue(queue *PQueue, int queueCapacity);
	// ���ٶ���
	void destroyQueue(queue *PQueue);
	// ��ն���
	void clearQueue(queue *PQueue);
	// �ж϶����Ƿ�Ϊ��
	bool isEmpityQueue(queue *PQueue);
	// �ж϶����Ƿ�Ϊ��
	bool isFullQueue(queue *PQueue);
	// ��ö��г���
	int getQueueLen(queue *PQueue);
	// ��Ԫ����� [�Ƚ��ȳ�ԭ���ڶ�β��λ�ò���] element-Ҫ����Ԫ��
	bool enQueue(queue *PQueue, ElemType element);
	// ��Ԫ�س���,ͬʱ������ӵ�Ԫ�� [�Ƚ��ȳ�ԭ���ڶ�ͷ��λ��ɾ��]
	bool deQueue(queue *PQueue, ElemType *pElement);
	// ��������
	void queueTraverse(queue *PQueue);


private:

};

#endif // CIRCULARQUEUE_H


