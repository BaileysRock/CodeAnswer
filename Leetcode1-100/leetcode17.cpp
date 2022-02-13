//
// Created by Alienware on 2022/2/13.
//

//给定一个仅包含数字2-9的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
//给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
//
//示例 1：
//输入：digits = "23"
//输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
//示例 2：
//输入：digits = ""
//输出：[]
//示例 3：
//输入：digits = "2"
//输出：["a","b","c"]

// 思路：
// 对每一轮加上字母后的跑循环
// 思路2：回溯


//
// Created by 熊峰 on 2022/2/10.
//
# include <iostream>
# include <string>
# include <vector>
# include <unordered_map>

using namespace std;


// 16 题
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> vectorNow;
        if (digits.size() == 0)
            return vectorNow;
        unordered_map<char, string> dictNum = {
                {'2', "abc"},
                {'3', "def"},
                {'4', "ghi"},
                {'5', "jkl"},
                {'6', "mno"},
                {'7', "pqrs"},
                {'8', "tuv"},
                {'9', "wxyz"}
        };
        for (int i = 0; i < dictNum[digits[0]].size(); i++) {
            string stringTemp;
            stringTemp.push_back(dictNum[digits[0]][i]);
            vectorNow.emplace_back(stringTemp);
        }
        vector<string> vectorNext;
        for (int i = 1; i < digits.size(); i++) {
            string addWord = dictNum[digits[i]];
            for (int j = 0; j < addWord.size(); j++) {
                for (int k = 0; k < vectorNow.size(); k++) {
                    vectorNext.emplace_back(vectorNow[k] + addWord[j]);
                }
            }
            vectorNow.clear();
            vectorNow.assign(vectorNext.begin(), vectorNext.end());
            vectorNext.clear();
        }
        return vectorNow;
    }
};

int main() {
    Solution *solution = new Solution();
    vector<string> b = solution->letterCombinations("23");
    return 0;
}
