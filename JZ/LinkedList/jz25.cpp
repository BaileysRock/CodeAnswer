//
// Created by Alienware on 2021/11/13.
//

// JZ25 合并两个排序的链表
#include <iostream>
#include <vector>
#include <stack>


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        if(pHead1== nullptr)
            return pHead2;
        else if (pHead2== nullptr)
            return pHead1;
        if(pHead1->val <pHead2->val)
        {
            pHead1->next = Merge(pHead1->next,pHead2);
            return pHead1;
        }
        else
        {
            pHead2->next = Merge(pHead1,pHead2->next);
            return pHead2;
        }
    }
};