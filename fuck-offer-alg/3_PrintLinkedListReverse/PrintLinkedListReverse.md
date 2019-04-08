# 倒序打印链表    
**输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。** PS：此题送入的链表头指针指的就是第一个数值，而不是NULL。
```C
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
```
---  

思考:  
1. I hate linked list.  
2. 第一想法是把所有链表节点的next指针反置一遍。  
3. ~~这个题其实改为返回ListNode会好一点。返回vector，有些答案就直接在vector上操作，可能没有达到考察链表知识点的目的。~~ （原来后面还有一道题就是`反转链表`，嘻嘻嘻。）leetcode上[这道题目](https://leetcode.com/problems/reverse-linked-list/)就好一点。故下面的代码均以`返回ListNode`为解答。

---  
代码(其中耗时与内存均基于leetcode在线返回的结果)：  
① 我的解答（8ms，9.2MB）  
有点过分考虑异常情况了，太丑。应参考解答③。核心思想就是三个`ListNode*`：`prev`、`now`、`next`用于交换。
```C
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pNow = head;
		if (pNow==NULL)
		{
			return pNow;
		}
		ListNode* pNext = pNow->next == NULL?NULL: pNow->next;
		ListNode* pForward = NULL;
		pNow->next = NULL;
		ListNode* pTail = (ListNode*)malloc(sizeof(ListNode));
		while(1)
		{
			if(pNext==NULL)
			{
				pTail->next= pNow;
				break;
			}

			pForward = pNow;
			pNow = pNext;
			pNext = pNow->next;
			pNow->next = pForward;
			
		}

		return pTail->next;
    }
};
```

② 递归(8ms，9.2MB)  
第一反应真的没想到，看来还是脑子不够用。用递归的话，空间复杂度`O(n)`，时间复杂度`O(n)`.
```C
class Solution {
public:
    vector<int> value;
    ListNode* reverseLinkedList(ListNode* head) {
		if(head==NULL||head->next==NULL) return head;
		ListNode* p = reverseLinkedList(head->next);
		head->next->next = head;
		head->next = NULL;
		return p;
};
```
③ 倒置指针的参考答案（8ms，9MB）  
人家也是倒置指针，但是就简洁明了。我则为了考虑异常情况，反而越写越乱。虽正确，却显示出思路之混乱。:sob: 使用倒置空间复杂度`O(1)`，时间复杂度`O(n)`。   
```C
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr!=NULL)
        {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};
```  


