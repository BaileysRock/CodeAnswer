//
// Created by Alienware on 2021/11/12.
//
// 从尾到头打印链表

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
    vector<int> printListFromTailToHead(ListNode *head) {

        ListNode*listNode = head;
        int len = 0;
        while(listNode!= nullptr)
        {
            listNode= listNode->next;
            len++;
        }

        vector<int> vectorListNode(len);
        listNode = head;
        for(int i = 0;i<len;i++)
        {

            vectorListNode[len-i-1] = listNode->val;
            listNode = listNode->next;
        }

        return vectorListNode;


    }
};