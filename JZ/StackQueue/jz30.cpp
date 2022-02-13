//
// Created by Alienware on 2021/11/13.
//

// JZ30 包含min函数的栈

#include <iostream>
#include <vector>
#include <stack>


struct Stack{
    int val;
    struct Stack*next;
    Stack(int num):
    val(num),next(NULL){}
};

using namespace std;
class Solution {
public:
    void push(int value) {
        Stack*temp = STACKTOP->next;
        Stack*NEW = new Stack(value);
        STACKTOP->next = NEW;
        NEW->next = temp;
    }
    void pop() {
        STACKTOP->next = STACKTOP->next->next;
    }
    int top() {
        return STACKTOP->next->val;
    }
    int min() {
        Stack*minstack = STACKTOP->next;
        int minnum = minstack->val;
        while(minstack!= nullptr)
        {
            if(minstack->val < minnum)
            {
                minnum = minstack->val;
            }
            minstack= minstack->next;
        }
        return minnum;
    }

private:
    Stack* STACKTOP = new Stack(-1);
};

int main()
{
    Solution*solution = new Solution;

    solution->push(-3);
    solution->push(0);
    solution->push(2);
    cout<<solution->min();

}