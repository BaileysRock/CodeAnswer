//
// Created by Alienware on 2021/11/13.
//

// JZ31 栈的压入、弹出序列


#include <iostream>
#include <vector>
#include <stack>

using namespace std;


class Solution {
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV) {
        stack<int> Stack;
        int i = 0;
        int j = 0;
        while (i < pushV.size()) {
            if (pushV[i] != popV[j]) {
                Stack.push(pushV[i]);
                i++;
            } else {
                i++;
                j++;
                while (!Stack.empty() && Stack.top() == popV[j]) {
                    Stack.pop();
                    j++;
                }
            }
        }
        if (Stack.empty()) {
            return true;
        } else {
            return false;
        }
    }
};


int main()
{


    vector<int> v1 = {1,2,3,4,5};
    vector<int> v2 = {4,3,5,2,1};

    bool panduan = (new Solution)->IsPopOrder(v1,v2);

    return 0;

}