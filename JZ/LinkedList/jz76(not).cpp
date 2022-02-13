//
// Created by Alienware on 2021/11/13.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) :
            val(x), next(NULL) {
    }
};

class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        ListNode *vhead = new ListNode(-1);
        vhead->next = pHead;
        ListNode *pre = vhead, *cur = pHead;
        while (cur) {
            if (cur->next && cur->val == cur->next->val) {
                cur = cur->next;
                while (cur->next && cur->val == cur->next->val) {
                    cur = cur->next;
                }
                cur = cur->next;
                pre->next = cur;
            }
            else {
                pre = cur;
                cur = cur->next;
            }
        }
        return vhead->next;
    }

};