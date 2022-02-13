#include <iostream>
#include <vector>
#include <stack>

using namespace std;


struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param head ListNode类
     * @param val int整型
     * @return ListNode类
     */
    ListNode *deleteNode(ListNode *head, int val) {
        // write code here
        ListNode *HEAD = head;
        ListNode *temp = head;

        if (head == nullptr)
            return nullptr;
        if (head->next == nullptr) {
            if(head->val==val)
                return head;
        }
        if(temp->val==val)
            return head->next;

        while(temp->next!= nullptr)
        {
            if(temp->next->val == val)
            {
                temp->next = temp->next->next;
                return head;
            }
            temp = temp->next;
        }
        return head;

    }
};


int main()
{

    ListNode* listNode0 = new ListNode(4);
    ListNode* listNode1 = new ListNode(5);
    listNode0->next = listNode1;
    ListNode* listNode2 = new ListNode(1);
    listNode1->next = listNode2;
    ListNode* listNode3 = new ListNode(9);
    listNode2->next = listNode3;


    ListNode * test = (new Solution)->deleteNode(listNode0,1);

    return 0;
}