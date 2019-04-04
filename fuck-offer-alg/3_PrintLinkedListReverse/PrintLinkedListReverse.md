# 倒序打印链表    
**输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。** PS：此题送入的链表头指针指的就是第一个数值，而不是NULL。

---  

思考:  
1. I hate linked list.  
2. 第一想法是把所有链表节点的next指针反置一遍，再输出。  
3. 这个题其实改为返回LinkNode会好一点（或者直接输出）。返回vector，有些答案就直接在vector上操作，可能没有达到考察链表知识点的目的。leetcode上[这道题目](https://leetcode.com/problems/reverse-linked-list/)就好一点。


---  
代码(其中耗时与内存均基于leetcode在线返回的结果)： 
① 我的解答（8ms，9.2MB）  
```C
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> result;
		ListNode* pNow = head;
		if (pNow==NULL)
		{
			//cout << "空链表" << endl;
			return result;
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
		ListNode *p;

		for (p = pTail->next;p!=NULL;p = p->next)
		{
			result.push_back(p->val);
		}
		cout << endl;
		return result;
    }
};
```  

② 参考答案1（使用栈，先进后出）  
```C
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> value;
        ListNode *p=NULL;
        p=head;
        stack<int> stk;
        while(p!=NULL){
            stk.push(p->val);
            p=p->next;
        }
        while(!stk.empty()){
            value.push_back(stk.top());
            stk.pop();
        }
        return value;
    }
};
```  

③ 参考答案2（递归）
```C
class Solution {
public:
    vector<int> value;
    vector<int> printListFromTailToHead(ListNode* head) {
        ListNode *p=NULL;
        p=head;
        if(p!=NULL){
            if(p->next!=NULL){
                printListFromTailToHead(p->next);
            }
            value.push_back(p->val);
        }
        return value;
    }
};
```

