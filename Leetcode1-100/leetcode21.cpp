//
// Created by Alienware on 2022/2/13.
//

//将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
//
//示例 1：
//
//
//输入：l1 = [1,2,4], l2 = [1,3,4]
//输出：[1,1,2,3,4,4]
//示例 2：
//
//输入：l1 = [], l2 = []
//输出：[]
//示例 3：
//
//输入：l1 = [], l2 = [0]
//输出：[0]


// 思路：使用递归合并
//

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
# include <string>
# include <vector>
# include <unordered_map>

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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        if (list1 == nullptr)
            return list2;
        else if (list2 == nullptr)
            return list1;
        if (list1->val < list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};


int main() {
    // [[1,4,5],[1,3,4],[2,6]]
    ListNode *head13 = new ListNode(5);
    ListNode*head12 = new ListNode(4,head13);
    ListNode*head11 = new ListNode(1,head12);

    ListNode *head23 = new ListNode(4);
    ListNode*head22 = new ListNode(3,head23);
    ListNode*head21 = new ListNode(1,head22);

    ListNode *head32 = new ListNode(6);
    ListNode*head31 = new ListNode(2,head32);
    vector<ListNode*> temp = {head11,head21,head31};
    ListNode * head = (new Solution)->mergeTwoLists(head11,head21);
    return 0;
}