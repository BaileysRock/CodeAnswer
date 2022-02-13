//
// Created by Alienware on 2021/11/13.
//

// JZ52 两个链表的第一个公共结点
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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {

        ListNode*l1 = pHead1;
        ListNode*l2 = pHead2;
        while(l1!=l2)
        {
            if(l1!= nullptr)
            {
                l1 = l1->next;
            }
            else
            {
                l1 = pHead2;
            }
            if(l2!= nullptr)
            {
                l2 = l2->next;
            }
            else
            {
                l2 = pHead1;
            }
        }

        return l1;

    }
};