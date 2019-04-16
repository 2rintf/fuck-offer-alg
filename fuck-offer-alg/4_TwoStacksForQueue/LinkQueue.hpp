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

	// 初始化队列
	bool initQueue(queue* q);
	// 销毁队列
	void destroyQueue(queue* q);
	// 清空队列
	void clearQueue(queue* q);
	// 是否队空
	bool isEmptyQueue(queue* q);
	// 获取队列长度
	int getQueueLen(queue* q);
	// 用element获得队头元素，但不出队
	bool getHead(queue* q,Elemtype& element);
	// 入队
	bool enQueue(queue* q,Elemtype& element);
	// 出队
	bool deQueue(queue* q, Elemtype& element);
	// 队列遍历
	void queueTraverse(queue* q);



};




#endif // !LINKQUEUE_H
