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


#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int length = s.length();
        int count = 0;
        string result = "";
        for (int i = 0; i < length; i++) {
            if(s[i] == s[length-i-1])
            {
                count++;
                result+
            }

        }


    }
};

int main() {

    cout << "hello";
}