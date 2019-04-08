/*******************************************************************
测试代码来自 https://github.com/zhedahht/CodingInterviewChinese2
作者：何海涛
*******************************************************************/

#include <vector>
#include <stdlib.h>
#include <iostream>
#include "List.h"

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
//typedef struct ListNode lnode, *list;

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



class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode* prev = NULL;
		ListNode* curr = head;
		while (curr != NULL)
		{
			ListNode* next = curr->m_pNext;
			curr->m_pNext = prev;
			prev = curr;
			curr = next;
		}
		return prev;
	}
};

// ====================测试代码====================
void Test(ListNode* pHead)
{
	Solution s;

	PrintList(pHead);

	ListNode* pReverse = s.reverseList(pHead);
	PrintList(pReverse);
	printf("\n");
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

	Test1();
	Test2();
	Test3();


	system("pause");


}