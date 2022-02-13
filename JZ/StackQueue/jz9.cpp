//
// Created by Alienware on 2021/11/13.
//

// JZ9 用两个栈实现队列


#include <iostream>
#include <vector>
#include <stack>

using namespace std;


class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        while (!stack2.empty())
        {
            stack2.pop();
        }
        while(!stack1.empty())
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
        int POP = stack2.top();
        stack2.pop();
        while (!stack2.empty())
        {
            stack1.push(stack2.top());
            stack2.pop();
        }
        return POP;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};