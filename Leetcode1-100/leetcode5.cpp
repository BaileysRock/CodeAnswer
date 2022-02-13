//
// Created by Alienware on 2021/9/11.
//
//给你一个字符串 s，找到 s 中最长的回文子串。
//示例 1：
//输入：s = "babad"
//输出："bab"
//解释："aba" 同样是符合题意的答案。
//示例 2：
//输入：s = "cbbd"
//输出："bb"
//示例 3：
//输入：s = "a"
//输出："a"
//示例 4：
//输入：s = "ac"
//输出："a"

// 思路
// 中心扩展算法
// 跑i的循环
// 每次取中心为i或i+1，由于回文串中心只可能是1个或2个
// 计算由其扩展出来的字符串的最长的值，即若中心左侧和右侧的值相同，则继续扩展

#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        // 中心扩展法
        int maxlen = 0;
        string maxstr = "";
        for (int i = 0; i < s.length(); i++) {
            // 两个中心点
            int left = i;
            int right = i + 1;
            if (right < s.length() && s.at(left) == s.at(right)) {
                while (left >= 0 && right < s.length() && s.at(left) == s.at(right)) {
                    if (right - left + 1 > maxlen) {
                        maxlen = right - left + 1;
                        maxstr = s.substr(left,maxlen);
                    }
                    left--;
                    right++;
                }
            }
            // 单个中心点
            left = i;
            right = i;
            while (left >= 0 && right < s.length() && s.at(left) == s.at(right)) {
                if (right - left + 1 > maxlen) {
                    maxlen = right - left + 1;
                    maxstr = s.substr(left,maxlen);
                }
                left--;
                right++;
            }

        }
        return maxstr;
    }
};

int main() {

    cout << "hello";
}