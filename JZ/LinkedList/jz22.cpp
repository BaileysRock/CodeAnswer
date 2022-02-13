//
// Created by Alienware on 2021/11/13.
//


// JZ22 链表中倒数最后k个结点

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
     * @param pHead ListNode类
     * @param k int整型
     * @return ListNode类
     */
    ListNode *FindKthToTail(ListNode *pHead, int k) {
        ListNode*p = pHead;
        int len=0;
        while(p!= nullptr)
        {
            len++;
            p = p->next;
        }
        if(k>len || k<1)
        {
            return nullptr;
        }
        p = pHead;
        for(int i =1;i<len-k+1;i++)
        {
            p = p->next;

        }
        return p;
    }
};