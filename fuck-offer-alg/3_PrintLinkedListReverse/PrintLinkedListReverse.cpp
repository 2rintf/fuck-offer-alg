#include <vector>
#include <stdlib.h>
#include <iostream>
//#include <list>
#include "..\List.h"
#include <stack>

using namespace std;

/************原题解答 start ****************/
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/


//class Solution {
//public:
//	vector<int> printListFromTailToHead(ListNode* head) {
//		vector<int> result;
//		ListNode* pNow = head;
//		if (pNow == NULL)
//		{
//			//cout << "空链表" << endl;
//			return result;
//		}
//		ListNode* pNext = pNow->next == NULL ? NULL : pNow->next;
//		ListNode* pForward = NULL;
//		pNow->next = NULL;
//		ListNode* pTail = (ListNode*)malloc(sizeof(ListNode));
//		while (1)
//		{
//			if (pNext == NULL)
//			{
//				pTail->next = pNow;
//				break;
//			}
//
//			pForward = pNow;
//			pNow = pNext;
//			pNext = pNow->next;
//			pNow->next = pForward;
//
//		}
//		ListNode *p;
//
//		for (p = pTail->next; p != NULL; p = p->next)
//		{
//			result.push_back(p->val);
//			//cout << p->m_nValue << "    ";
//		}
//		cout << endl;
//		return result;
//	}
//};

/************原题解答  end ****************/



//
//struct ListNode {
//	int val;
//	struct ListNode *next;
//	ListNode(int x) :
//		val(x), next(NULL) {
//	}
//};
//
//class Solution {
//public:
	vector<int> PrintListReversingly_Iteratively(ListNode* head) {
		vector<int> result;
		ListNode* pNow = head;
		if (pNow==NULL)
		{
			cout << "空链表" << endl;
			return result;
		}
		ListNode* pNext = pNow->m_pNext == NULL?NULL: pNow->m_pNext;
		ListNode* pForward = NULL;
		pNow->m_pNext = NULL;
		ListNode* pTail = (ListNode*)malloc(sizeof(ListNode));
		while(1)
		{
			if(pNext==NULL)
			{
				pTail->m_pNext= pNow;
				break;
			}

			pForward = pNow;
			pNow = pNext;
			pNext = pNow->m_pNext;
			pNow->m_pNext = pForward;
			
		}
		ListNode *p;

		for (p = pTail->m_pNext;p!=NULL;p = p->m_pNext)
		{
			//result.push_back(p->m_nValue);
			cout << p->m_nValue << "    ";
		}
		cout << endl;
		return result;
	}
//};

typedef struct ListNode lnode, *list;

//vector<list> createList()
//{
//	list pHead = (list)malloc(sizeof(lnode));// 头节点，不存放数据
//	list pTail = (list)malloc(sizeof(lnode));// 头节点，不存放数据
//
//	if (pHead == NULL || pTail == NULL)
//	{
//		cout << "动态分配内存失败" << endl;
//		exit(-1);
//	}
//
//	pHead->next = NULL;
//	pTail->next = pHead;
//	vector<list> init;
//	init.push_back(pHead);
//	init.push_back(pTail);
//
//	return init;
//}

//list addElement(list pHead, list pTail, int val)
//{
//	list pNew = (list)malloc(sizeof(lnode));// 开辟新节点空间
//	list pOld = pTail->next;
//
//	if (pNew == NULL)
//	{
//		cout << "动态分配内存失败" << endl;
//		exit(-1);
//	}
//
//	pNew->val = val;// 新节点值
//	pNew->next = NULL;// 新节点后暂无新值，故指针为空
//	pOld->next = pNew;
//	pTail->next = pNew;// 尾指针指向新节点
//	//pTail = pNew;
//	//length += 1;// 节点长度加1
//
//	if (pHead->next == NULL)
//	{
//		pHead->next = pNew;
//		return pNew;
//	}
//
//	return pNew;
//
//}

//void printList(list pHead, list pTail)
//{
//	//list p = (list)malloc(sizeof(lnode));
//
//	list p;
//	for (p = pHead->next;p!=NULL; p = p->next)
//	{
//		if (p == NULL)
//		{
//			cout << "Linked list is NULL!" << endl;
//			break;
//		}
//		cout << p->val << " ";
//
//	}
//
//	cout << endl;
//}



// ====================测试代码====================
void Test(ListNode* pHead)
{


	PrintList(pHead);
	PrintListReversingly_Iteratively(pHead);
	printf("\n");
	//PrintListReversingly_Recursively(pHead);
}

// 1->2->3->4->5
void Test1()
{
	printf("\nTest1 begins.\n");

	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);

	Test(pNode1);

	DestroyList(pNode1);
}

// 只有一个结点的链表: 1
void Test2()
{
	printf("\nTest2 begins.\n");

	ListNode* pNode1 = CreateListNode(1);

	Test(pNode1);

	DestroyList(pNode1);
}

// 空链表
void Test3()
{
	printf("\nTest3 begins.\n");

	Test(nullptr);
}

int main()
{
	//list tail(NULL);
	//vector<list> init = createList();
	//list head = init[0];
	//list tail = init[1];



	//list node1;

	//addElement(head, tail, 1);
	//cout << head->next << endl;
	//cout << tail->next << endl;
	//addElement(head, tail, 2);
	//cout << tail->next << endl;
	//addElement(head, tail, 3);
	//cout << tail->next << endl;
	//addElement(head, tail, 4);
	//cout << tail->next << endl;

	//printList(head, tail);


	Test1();
	Test2();
	Test3();


	system("pause");


}