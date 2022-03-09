//
// Created by Alienware on 2022/2/13.
//

//22. 括号生成
//数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
//
//
//
//示例 1：
//
//输入：n = 3
//输出：["((()))","(()())","(())()","()(())","()()()"]
//示例 2：
//
//输入：n = 1
//输出：["()"]

// 思路：
// 利用深度优先搜索
// 使用递归的思路
// 设置递归出口即 左右括号数相等n
// 若左侧小于n则可继续左侧生长
// 若右侧小于左侧，且左侧小于等于右侧，则右侧继续生长

# include <iostream>
# include <string>
# include <vector>
# include <unordered_map>

using namespace std;

class Solution {
public:

    void dfs(vector<string> &generate, int countLeft, int countRight, int n, string str) {
        if (countLeft == n && countRight == n)
            generate.emplace_back(str);
        else {
            if (countLeft < n)
                dfs(generate, countLeft + 1, countRight, n, str + '(');
            if (countLeft > countRight && countLeft <= n)
                dfs(generate, countLeft, countRight + 1, n, str + ')');
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string>generate;
        dfs(generate,0,0,n,"");
        return generate;
    }
};


int main() {
    Solution*solution = new Solution();
    vector<string> test = solution->generateParenthesis(3);

    return 0;

}