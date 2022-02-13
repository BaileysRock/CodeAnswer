//
// Created by Alienware on 2021/9/12.
//


// 将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。
//
// 比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：
//
// P   A   H   N
// A P L S I I G
//         Y   I   R
// 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。
//
// 请你实现这个将字符串进行指定行数变换的函数：


//示例 1：
//输入：s = "PAYPALISHIRING", numRows = 3
//输出："PAHNAPLSIIGYIR"
//示例 2：
//输入：s = "PAYPALISHIRING", numRows = 4
//输出："PINALSIGYAHRPI"
//解释：
//P     I    N
//        A   L S  I G
//Y A   H R
//P     I
//示例 3：
//输入：s = "A", numRows = 1
//输出："A"



// 思路：
// 利用数学的计算，依次计算输出每一行的下标

# include <iostream>
# include <string>

using namespace std;


class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        int length = s.length();
        string str = "";
        int flag;
        for (int i = 0; i < numRows; i++) {
            flag = -1;
            if (i == 0 || i == numRows - 1) {
                for (int j = i; j < length; j += 2 * numRows - 2) {
                    str = str + s.at(j);
                }
            } else {
                for (int j = i; j < length; j += (flag > 0 ? (2 * (numRows - i) - 2) : 2 * numRows - 2 -
                                                                                       (2 * (numRows - i) - 2))) {
                    str = str + s.at(j);
                    flag = -1 * flag;
                }
            }
        }
        return str;
    }
};


int main() {
    Solution *solution = new Solution();
    cout << solution->convert("A", 1);
    return 0;
}