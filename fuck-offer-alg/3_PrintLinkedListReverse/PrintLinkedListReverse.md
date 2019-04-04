# �����ӡ����    
**����һ������������ֵ��β��ͷ��˳�򷵻�һ��ArrayList��** PS���������������ͷָ��ָ�ľ��ǵ�һ����ֵ��������NULL��

---  

˼��:  
1. I hate linked list.  
2. ��һ�뷨�ǰ���������ڵ��nextָ�뷴��һ�飬�������  
3. �������ʵ��Ϊ����LinkNode���һ�㣨����ֱ�������������vector����Щ�𰸾�ֱ����vector�ϲ���������û�дﵽ��������֪ʶ���Ŀ�ġ�leetcode��[�����Ŀ](https://leetcode.com/problems/reverse-linked-list/)�ͺ�һ�㡣


---  
����(���к�ʱ���ڴ������leetcode���߷��صĽ��)�� 
�� �ҵĽ��8ms��9.2MB��  
```C
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> result;
		ListNode* pNow = head;
		if (pNow==NULL)
		{
			//cout << "������" << endl;
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

�� �ο���1��ʹ��ջ���Ƚ������  
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

�� �ο���2���ݹ飩
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

