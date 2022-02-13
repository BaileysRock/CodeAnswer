//
// Created by Alienware on 2022/2/13.
//

//给你一个链表，删除链表的倒数第n个结点，并且返回链表的头结点。
//
//示例 1：
//输入：head = [1,2,3,4,5], n = 2
//输出：[1,2,3,5]
//示例 2：
//输入：head = [1], n = 1
//输出：[]
//示例 3：
//输入：head = [1,2], n = 1
//输出：[1]

// 思路：
// 快慢指针的想法
// 首先设置一个快一点的指针
// 先跑n-1
// 之后快慢指针每次+1
// 当快指针到末尾时候，慢指针则到倒水第n个
// 注意边界处理


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

# include <iostream>
# include <stack>
# include <string>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        int countQuick = 1;
        ListNode *temp = head;
        ListNode *removeHead = head;
        while (temp->next != nullptr) {
            if (countQuick > n)
                removeHead = removeHead->next;
            temp = temp->next;
            countQuick++;
        }
        if (removeHead == head && countQuick > n) {
            head->next = head->next->next;
            return head;
        } else if (removeHead == head) {
            return head->next;
        } else if (removeHead->next != nullptr) {
            removeHead->next = removeHead->next->next;
            return head;
        } else
            return nullptr;
    }
};