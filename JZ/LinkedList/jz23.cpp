//
// Created by Alienware on 2021/11/13.
//

// JZ23 链表中环的入口结点


// 快慢指针法
// 第一个走一步
// 第二个走两步
// 到相遇点后，将其中一个置为起点，并令步长均为1
// 此时在遇到相遇点


#include <iostream>
#include <vector>
#include <map>
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
    ListNode *EntryNodeOfLoop(ListNode *pHead) {
        if (pHead == nullptr)
            return nullptr;
        ListNode *p1 = pHead;
        ListNode *p2 = pHead;
        while (p1 != nullptr) {
            p1 = p1->next;
            if (p1 != nullptr )
                p1 = p1->next;
            else
                return nullptr;
            p2 = p2->next;
            if (p1 == p2) {
                p1 = pHead;
                while(p1!= p2)
                {
                    p1 = p1->next;
                    p2 = p2->next;
                }
                return p1;
            }
        }
        return nullptr;
    }


//    ListNode *EntryNodeOfLoop(ListNode *pHead) {
//
//        map<ListNode*,int> mapListNode;
//        ListNode*head = pHead;
//        while(head!= nullptr)
//        {
//            if(mapListNode[head] == 0)
//            {
//                mapListNode[head] = 1;
//            }
//            else if(mapListNode[head] ==1)
//            {
//                return head;
//            }
//            head = head->next;
//        }
//        return nullptr;
//    }
};