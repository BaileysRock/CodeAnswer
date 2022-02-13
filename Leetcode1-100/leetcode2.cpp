//
// Created by Alienware on 2021/8/20.
//

#include <iostream>

using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head = new ListNode(-1);//存放结果的链表
        ListNode *h = head;//移动指针
        int bit;
        int carry = 0;
        while (l1!= nullptr && l2!= nullptr) {
            bit = l1->val + l2->val + carry;
            carry = bit / 10;
            bit = bit - carry * 10;
            h->next = new ListNode(bit);
            h = h->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        if (l1 == nullptr) {
            while (l2 != nullptr) {
                bit = l2->val + carry;
                carry = bit / 10;
                bit = bit - carry * 10;
                h->next = new ListNode(bit);
                h = h->next;
                l2 = l2->next;
            }
        }
        else if (l2 == nullptr) {
            while (l1 != nullptr) {
                bit = l1->val + carry;
                carry = bit / 10;
                bit = bit - carry * 10;
                h->next = new ListNode(bit);
                h = h->next;
                l1 = l1->next;
            }
        }

        if (carry != 0) {
            h->next = new ListNode(carry);
        }
        return head->next;
    }
};

int main() {
    ListNode *ll1 = new ListNode(2);
    ListNode *l1 = ll1;
    ll1->next = new ListNode(4);
    ll1 = ll1->next;
    ll1->next = new ListNode(3);

    ListNode *ll2 = new ListNode(5);
    ListNode *l2 = ll2;
    ll2->next = new ListNode(6);
    ll2 = ll2->next;
    ll2->next = new ListNode(4);


    ListNode *result = (new Solution)->addTwoNumbers(l1, l2);
    while (result != nullptr) {
        cout << result->val;
        result = result->next;
    }
    return 0;
}