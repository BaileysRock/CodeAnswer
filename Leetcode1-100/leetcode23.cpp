//
// Created by Alienware on 2022/2/13.
//
//给你一个链表数组，每个链表都已经按升序排列。
//请你将所有链表合并到一个升序链表中，返回合并后的链表。
//示例 1：
//
//输入：lists = [[1,4,5],[1,3,4],[2,6]]
//输出：[1,1,2,3,4,4,5,6]
//解释：链表数组如下：
//[
//1->4->5,
//1->3->4,
//2->6
//]
//将它们合并到一个有序链表中得到。
//1->1->2->3->4->4->5->6
//示例 2：
//
//输入：lists = []
//输出：[]
//示例 3：
//
//输入：lists = [[]]
//        输出：[]


// 思路：
// 先实现两个链表的合并
// 在遍历实现k个链表的合并


# include <iostream>
# include <string>
# include <vector>
# include <unordered_map>

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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode*ans = nullptr;
        for(int i = 0 ;i<lists.size();i++)
            ans = mergeTwoLists(ans,lists[i]);
        return ans;
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
    ListNode * head = (new Solution)->mergeKLists(temp);
    while(head!= nullptr)
    {
        cout<<head->val<<" ";
        head = head->next;
    }
    return 0;
}