#ifndef CIRCULARQUEUE_H
#define CIRCULARQUEUE_H

#include <stdlib.h>
#include <iostream>

using namespace std;

/*循环队列 Circular Queue
参考： 《数据结构(C语言版)》-- 严蔚敏等著 -- 清华大学出版社
*/

typedef int ElemType;
typedef struct Queue {
	ElemType* pBase;
	ElemType front;
	ElemType rear;
	ElemType maxSize;// 队列最大
}queue;



class CircularQueue
{
public:


	CircularQueue() {}
	CircularQueue(queue* PQueue, int queueCapacity);
	~CircularQueue();

	// 创建空队列
	//! 循环队列为了解决队满的标志问题，故利用了一个元素空间，所以实际上可以用的元素空间比开辟空间少1
	bool initQueue(queue *PQueue, int queueCapacity);
	// 销毁队列
	void destroyQueue(queue *PQueue);
	// 清空队列
	void clearQueue(queue *PQueue);
	// 判断队列是否为空
	bool isEmpityQueue(queue *PQueue);
	// 判断队列是否为满
	bool isFullQueue(queue *PQueue);
	// 获得队列长度
	int getQueueLen(queue *PQueue);
	// 新元素入队 [先进先出原则：在队尾的位置插入] element-要插入元素
	bool enQueue(queue *PQueue, ElemType element);
	// 新元素出队,同时保存出队的元素 [先进先出原则：在队头的位置删除]
	bool deQueue(queue *PQueue, ElemType *pElement);
	// 遍历队列
	void queueTraverse(queue *PQueue);


private:

};

#endif // CIRCULARQUEUE_H


