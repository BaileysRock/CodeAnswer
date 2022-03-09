//
// Created by Alienware on 2022/2/13.
//

//给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
//
//示例 1：
//
//输入：head = [1,2,3,4]
//输出：[2,1,4,3]
//示例 2：
//
//输入：head = []
//输出：[]
//示例 3：
//
//输入：head = [1]
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
    ListNode *swapPairs(ListNode *head) {
        stack<ListNode *> stackListNode;
        ListNode *headNode = new ListNode(0, head);
        ListNode *temp = headNode;
        ListNode *swapHead = head;
        while (swapHead != nullptr) {
            if (stackListNode.size() < 2)
                stackListNode.push(swapHead);
            swapHead = swapHead->next;
            if (stackListNode.size() == 2) {
                temp->next = stackListNode.top();
                temp = temp->next;
                stackListNode.pop();
                temp->next = stackListNode.top();
                temp = temp->next;
                stackListNode.pop();
                temp->next = nullptr;
            }
        }
        if (!stackListNode.empty())
            temp->next = stackListNode.top();
        return headNode->next;
    }
};


int main() {
    // [[1,4,5,6],[1,3,4],[2,6]]
    ListNode *head14 = new ListNode(6);
    ListNode *head13 = new ListNode(5, head14);
    ListNode *head12 = new ListNode(4, head13);
    ListNode *head11 = new ListNode(1, head12);

    ListNode *head23 = new ListNode(4);
    ListNode *head22 = new ListNode(3, head23);
    ListNode *head21 = new ListNode(1, head22);

    ListNode *head32 = new ListNode(6);
    ListNode *head31 = new ListNode(2, head32);
//    vector<ListNode*> temp = {head11,head21,head31};
    ListNode *head = (new Solution)->swapPairs(head11);
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}