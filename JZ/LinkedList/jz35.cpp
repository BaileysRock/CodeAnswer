//
// Created by Alienware on 2021/11/13.
//

// JZ35 复杂链表的复制

#include <iostream>
#include <vector>
#include <stack>

using namespace std;



struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead) {
        RandomListNode*returnHead ;
        RandomListNode * head = pHead;
        if(pHead == nullptr)
            return nullptr;
        while (head != nullptr)
        {
            RandomListNode *p = new RandomListNode(head->label);
            p->next = head->next;
            head ->next = p;
            head = p->next;
        }
        head = pHead;
        RandomListNode *copyhead = head->next;
        while (head->next->next != nullptr)
        {
            if(head->random== nullptr)
            {
                copyhead ->random = nullptr;
            }
            else {
                copyhead->random = head->random->next;
            }
            copyhead = copyhead->next->next;
            head = head->next->next;
        }
        head = pHead;
        copyhead = pHead->next;
        returnHead = copyhead;
        while(head->next->next!= nullptr)
        {
            RandomListNode*nodeTemp = head->next->next;
            copyhead->next = head->next->next->next;
            copyhead = copyhead->next;
            head->next = nodeTemp;
            head = head->next;
        }
        head->next = nullptr;
        copyhead = pHead->next;
        return returnHead;
    }
};

int main()
{
    RandomListNode*node5 = new RandomListNode(5);
    RandomListNode*node4 = new RandomListNode(4);
    node4->next = node5;
    RandomListNode*node3 = new RandomListNode(3);
    node3->next = node4;
    RandomListNode*node2 = new RandomListNode(2);
    node2->next = node3;
    RandomListNode*node1 = new RandomListNode(1);
    node1->next = node2;

    RandomListNode*node = (new Solution)->Clone(node1);








}