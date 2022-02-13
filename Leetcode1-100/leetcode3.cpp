//
// Created by Alienware on 2021/9/11.
//

// TODO:给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
// 输入: s = "abcabcbb"
// 输出: 3
// 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
// 输入: s = "bbbbb"
// 输出: 1
// 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
// 输入: s = "pwwkew"
// 输出: 3
// 解释: 因为无重复字符的最长子串是"wke"，所以其长度为 3。
//       请注意，你的答案必须是子串的长度，"pwke"是一个子序列，不是子串。
// 输入: s = ""
// 输出: 0

#include <iostream>
#include <map>
#include <unordered_set>
#include <cmath>

using namespace std;

// 使用哈希表
//#define max(a, b) ( ( (a) > (b) ) ? a : b )
//class Solution {
//public:
//    int lengthOfLongestSubstring(string s) {
//        int length = s.size();
//        unordered_set <char> set;
//        int left = 0;
//        int maxLength = 0;
//        for (int right = 0;  right < length; right++) {
//            while(set.count(s[right])) {
//                if(set.size()>maxLength)
//                    maxLength = set.size();
//                set.erase(s[left]);
//                left++;
//            }
//            set.insert(s[right]);
//        }
//        return max(maxLength,set.size());
//    }
//};

// 使用字符串
//class Solution {
//public:
//    int lengthOfLongestSubstring(string s) {
//        int length = s.size();
//        string substring = "";
//        int left = 0;
//        int maxLength = 0;
//        for (int right = 0; right < length; right++) {
//            while (substring.find(s[right])!=string::npos) {
//                if (substring.length() > maxLength)
//                    maxLength = substring.length();
//                substring = substring.substr(1, substring.length() - 1);
//                left++;
//            }
//            substring = s.substr(left, right - left + 1);
//        }
//        return max(maxLength, substring.length());
//    }
//};


// 使用字符数组
#include <string>
#include <cstring>
#define N 500000
class Solution {
public:
    bool search(char * pattern,char ch,int start,int end)
    {
        for(int i =start;i<end;i++)
        {
            if(pattern[i] == ch)
                return true;
        }
        return false;
    }
    int lengthOfLongestSubstring(string s) {
        int length = s.size();
        char substring[N];
        strcpy(substring,s.c_str());
        int left = 0;
        int right = 0;
        int maxLength = 0;
        for (; right < length; right++) {
            while(search(substring,substring[right],left,right))
            {
                if (right-left+1 > maxLength)
                    maxLength = right-left;
                left++;
            }
        }
        if (right-left+1 > maxLength)
            maxLength = right-left;
        return maxLength;
    }
};




int main() {
//    string s = "abcabcbb";
    string s = "bbbbb";
//    string s = "pwwkew";
//    string s =" ";

    cout << (new Solution)->lengthOfLongestSubstring(s);

    return 0;

}