//
// Created by Alienware on 2022/2/13.
//

//编写一个函数来查找字符串数组中的最长公共前缀。
//
//如果不存在公共前缀，返回空字符串""。
//
//
//
//示例 1：
//
//输入：strs = ["flower","flow","flight"]
//输出："fl"
//示例 2：
//
//输入：strs = ["dog","racecar","car"]
//输出：""
//解释：输入不存在公共前缀。

// 思路:判断就完了

# include <iostream>
# include <string>
# include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int length = strs.size();
        if(length == 0)
            return "";
        string prefix = "";
        for(int j = 0;j<strs[0].length();j++)
        {
            for(int i = 0;i<length;i++)
            {
                if(j<strs[i].length() && strs[i].at(j) == strs[0].at(j))
                {
                    if(i == length-1)
                    {
                        prefix = prefix + strs[0].at(j);
                    }
                }
                else
                    return prefix;
            }
        }
        return prefix;
    }
};


int main() {
    Solution *solution = new Solution();
    vector<string> s = {"flower","flow","flight"};
    cout<<solution->longestCommonPrefix(s);
}