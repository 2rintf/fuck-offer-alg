# �����ӡ����    
**����һ������������ֵ��β��ͷ��˳�򷵻�һ��ArrayList��** PS���������������ͷָ��ָ�ľ��ǵ�һ����ֵ��������NULL��
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

˼��:  
1. I hate linked list.  
2. ��һ�뷨�ǰ���������ڵ��nextָ�뷴��һ�顣  
3. ~~�������ʵ��Ϊ����ListNode���һ�㡣����vector����Щ�𰸾�ֱ����vector�ϲ���������û�дﵽ��������֪ʶ���Ŀ�ġ�~~ ��ԭ�����滹��һ�������`��ת����`������������leetcode��[�����Ŀ](https://leetcode.com/problems/reverse-linked-list/)�ͺ�һ�㡣������Ĵ������`����ListNode`Ϊ���

---  
����(���к�ʱ���ڴ������leetcode���߷��صĽ��)��  
�� �ҵĽ��8ms��9.2MB��  
�е���ֿ����쳣����ˣ�̫��Ӧ�ο����ۡ�����˼���������`ListNode*`��`prev`��`now`��`next`���ڽ�����
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

�� �ݹ�(8ms��9.2MB)  
��һ��Ӧ���û�뵽�������������Ӳ����á��õݹ�Ļ����ռ临�Ӷ�`O(n)`��ʱ�临�Ӷ�`O(n)`.
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
�� ����ָ��Ĳο��𰸣�8ms��9MB��  
�˼�Ҳ�ǵ���ָ�룬���Ǿͼ�����ˡ�����Ϊ�˿����쳣���������ԽдԽ�ҡ�����ȷ��ȴ��ʾ��˼·֮���ҡ�:sob: ʹ�õ��ÿռ临�Ӷ�`O(1)`��ʱ�临�Ӷ�`O(n)`��   
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


