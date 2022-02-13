//
// Created by Alienware on 2022/2/13.
//

//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
//有效字符串需满足：
//左括号必须用相同类型的右括号闭合。
//左括号必须以正确的顺序闭合。
//示例 1：
//输入：s = "()"
//输出：true
//示例2：
//输入：s = "()[]{}"
//输出：true
//示例3：
//输入：s = "(]"
//输出：false
//示例4：
//输入：s = "([)]"
//输出：false
//示例5：
//输入：s = "{[]}"
//输出：true


// 思路
// 用栈，若当前为左括号，则存进去
// 否则比较当前是否为堆顶的左括号的右括号


# include <iostream>
# include <string>
# include <vector>
# include <unordered_map>
# include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stackChar;
        for (int i = 0; i < s.length(); i++) {
            if (s.at(i) == '(' || s.at(i) == '[' || s.at(i) == '{')
                stackChar.push(s.at(i));
            else {
                if (s.at(i) == ')') {
                    if ( stackChar.empty()||stackChar.top() != '(')
                        return false;
                    else
                        stackChar.pop();
                } else if (s.at(i) == ']') {
                    if ( stackChar.empty()||stackChar.top() != '[')
                        return false;
                    else
                        stackChar.pop();
                } else if (s.at(i) == '}') {
                    if ( stackChar.empty()||stackChar.top() != '{')
                        return false;
                    else
                        stackChar.pop();
                }
            }
        }
        if (stackChar.empty())
            return true;
        return false;
    }
};


int main() {

    Solution *solution = new Solution();
    cout << solution->isValid("{[]}");
    return 0;
}