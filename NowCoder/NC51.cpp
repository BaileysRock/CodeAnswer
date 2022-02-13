//
// Created by Alienware on 2021/11/12.
//
// NC51 合并k个已排序的链表
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.size() == 0)
            return nullptr;
        else if (lists.size() == 1)
            return lists[0];
        else {
            ListNode *head = lists[0];
            for (int i = 1; i < lists.size(); i++) {
                head = merge(head, lists[i]);
            }

            return head;
        }

    }


    ListNode*merge1(ListNode*l1,ListNode*l2)
    {
        if(l1== nullptr)
            return l2;
        else if (l2== nullptr)
            return l1;
        if(l1->val < l2->val)
        {
            l1->next = merge(l1->next,l2);
            return l1;
        }
        else
        {
            l2->next = merge(l1,l2->next);
            return l2;
        }
    }



    ListNode*merge(ListNode*l1,ListNode*l2)
    {
        if(l1== nullptr)
            return l2;
        else if (l2== nullptr)
            return l1;
        else if (l1->val<l2->val)
        {
            l1->next = merge(l1->next,l2);
            return l1;
        }
        else
        {
            l2->next = merge(l1,l2->next);
            return l2;
        }
    }


    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        ListNode *head = new ListNode(-1);
        ListNode *returnNode = head;
        while (list1 != nullptr) {
            while (list2 != nullptr) {
                if (list1!=nullptr && list1->val < list2->val) {
                    head->next = list1;
                    list1 = list1->next;
                    head = head->next;
                    head ->next = nullptr;


                } else {
                    head->next = list2;
                    list2 = list2->next;
                    head = head->next;
                    head->next = nullptr;

                }

            }
        }
        while (list1 != nullptr) {
            head->next = new ListNode(list1->val);
            list1 = list1->next;
        }
        while (list2 != nullptr) {
            head->next = new ListNode(list2->val);
            list2 = list2->next;
        }
        return returnNode;

    }

};

int main()
{

    ListNode* node00 = new ListNode(1);
    ListNode* node01 = new ListNode(2);
    ListNode* node02 = new ListNode(3);
    node00->next = node01;
    node01->next = node02;

    ListNode* node10 = new ListNode(4);
    ListNode* node11 = new ListNode(5);
    ListNode* node12 = new ListNode(6);
    ListNode* node13 = new ListNode(7);
    node10->next = node11;
    node11->next = node12;
    node12->next = node13;
    vector<ListNode*> vectorNode = {node00,node10};
    ListNode * sort = (new Solution)->mergeKLists(vectorNode);

    return 0;

}