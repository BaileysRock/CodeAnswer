//
// Created by Alienware on 2021/11/12.
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
//    ListNode *ReverseList(ListNode *pHead) {
//        ListNode *temp = pHead;
//        stack<ListNode *> stackListNode;
//        while (temp != nullptr) {
//            stackListNode.push(temp);
//            temp = temp->next;
//        }
//        temp = new ListNode(-1);
//        ListNode *head = temp;
//        while (!stackListNode.empty()) {
//            temp->next = (ListNode *) stackListNode.top();
//            stackListNode.pop();
//            temp = temp->next;
//        }
//        temp->next = nullptr;
//        return head->next;
//    }



    ListNode* ReverseList(ListNode* pHead) {
        if(pHead== nullptr)
            return nullptr;
        else if (pHead->next == nullptr)
            return pHead;
        ListNode * temp = new ListNode(pHead->val);
        ListNode*temp1 = pHead->next;
        while(temp1!= nullptr)
        {
            ListNode * next = temp1->next;
            temp1->next = temp;
            temp = temp1;
            temp1= next;
        }
        return temp;
    }
};

int main()
{

    ListNode* listNode0 = new ListNode(1);
    ListNode* listNode1 = new ListNode(2);
    listNode0->next = listNode1;
    ListNode* listNode2 = new ListNode(3);
    listNode1->next = listNode2;
    ListNode* listNode3 = new ListNode(4);
    listNode2->next = listNode3;
    ListNode* listNode4 = new ListNode(5);
    listNode3->next = listNode4;

    ListNode * test = (new Solution)->ReverseList(listNode0);

    return 0;
}