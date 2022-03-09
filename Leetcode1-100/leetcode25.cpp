//
// Created by Alienware on 2022/2/13.
//


//给你一个链表，每k个节点一组进行翻转，请你返回翻转后的链表。
//
//k是一个正整数，它的值小于或等于链表的长度。
//
//如果节点总数不是k的整数倍，那么请将最后剩余的节点保持原有顺序。
//
//进阶：
//
//你可以设计一个只使用常数额外空间的算法来解决此问题吗？
//你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
//
//示例 1：
//
//
//输入：head = [1,2,3,4,5], k = 2
//输出：[2,1,4,3,5]
//示例 2：
//
//
//输入：head = [1,2,3,4,5], k = 3
//输出：[3,2,1,4,5]
//示例 3：
//
//输入：head = [1,2,3,4,5], k = 1
//输出：[1,2,3,4,5]
//示例 4：
//
//输入：head = [1], k = 1
//输出：[1]



# include <iostream>
# include <string>
# include <vector>
# include <unordered_map>
# include <stack>

using namespace std;


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
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        stack<ListNode *> stackListNode;
        ListNode *headNode = new ListNode(0, head);
        ListNode *temp = headNode;
        ListNode *swapHead = head;
        while (swapHead != nullptr) {
            if (stackListNode.size() < k)
                stackListNode.push(swapHead);
            swapHead = swapHead->next;
            if (stackListNode.size() == k) {
                while (!stackListNode.empty()) {
                    temp->next = stackListNode.top();
                    temp = temp->next;
                    stackListNode.pop();
                    temp->next = nullptr;
                }
            }
        }
        ListNode *reverseHead = new ListNode;
        while (!stackListNode.empty()) {
            ListNode *reverse = stackListNode.top();
            stackListNode.pop();
            reverse->next = reverseHead->next;
            reverseHead->next = reverse;
        }
        temp->next = reverseHead->next;
        return headNode->next;
    }
};


int main() {
    // [[1,4,5,6],[1,3,4],[2,6]]
    ListNode *head15 = new ListNode(5);
    ListNode *head14 = new ListNode(4,head15);
    ListNode *head13 = new ListNode(3, head14);
    ListNode *head12 = new ListNode(2, head13);
    ListNode *head11 = new ListNode(1, head12);

    ListNode *head23 = new ListNode(4);
    ListNode *head22 = new ListNode(3, head23);
    ListNode *head21 = new ListNode(1, head22);

    ListNode *head32 = new ListNode(6);
    ListNode *head31 = new ListNode(2, head32);
//    vector<ListNode*> temp = {head11,head21,head31};
    ListNode *head = (new Solution)->reverseKGroup(head11,2);
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}