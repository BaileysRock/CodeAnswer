//
// Created by Alienware on 2022/2/13.
//

//罗马数字包含以下七种字符：I，V，X，L，C，D和M。
//字符          数值
//I             1
//V             5
//X             10
//L             50
//C             100
//D             500
//M             1000
//例如， 罗马数字 2 写做II，即为两个并列的 1。12 写做XII，即为X+II。 27 写做XXVII, 即为XX+V+II。
//
//通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做IIII，而是IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为IX。这个特殊的规则只适用于以下六种情况：
//
//I可以放在V(5) 和X(10) 的左边，来表示 4 和 9。
//X可以放在L(50) 和C(100) 的左边，来表示 40 和90。
//C可以放在D(500) 和M(1000) 的左边，来表示400 和900。
//给你一个整数，将其转为罗马数字。
//
//
//
//示例1:
//
//输入:num = 3
//输出: "III"
//示例2:
//
//输入:num = 4
//输出: "IV"
//示例3:
//
//输入:num = 9
//输出: "IX"
//示例4:
//
//输入:num = 58
//输出: "LVIII"
//解释: L = 50, V = 5, III = 3.
//示例5:
//
//输入:num = 1994
//输出: "MCMXCIV"
//解释: M = 1000, CM = 900, XC = 90, IV = 4.

// 思路，将罗马数字的组成按照从大到小排列
// 若匹配上则加上这个字母


# include <iostream>
# include <string>
# include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        // 双指针
        int i = 0;
        int j = height.size() - 1;
        int Area = 0;
        while (i < j) {
            if (height.at(i) > height.at(j)) {
                int AreaTemp = (j - i) * height.at(j);
                Area = AreaTemp > Area ? AreaTemp : Area;
                j--;
            } else {
                int AreaTemp = (j - i) * height.at(i);
                Area = AreaTemp > Area ? AreaTemp : Area;
                i++;
            }
        }
        return Area;
    }

    string intToRoman(int num) {
        pair<int, string> numDict[] = {
                {1000, "M"},
                {900,  "CM"},
                {500,  "D"},
                {400,  "CD"},
                {100,  "C"},
                {90,   "XC"},
                {50,   "L"},
                {40,   "XL"},
                {10,   "X"},
                {9,    "IX"},
                {5,    "V"},
                {4,    "IV"},
                {1,    "I"}
        };
        string Roman = "";
        int useNum = num;
        int i = 0;
        while(useNum>0)
        {
            for(int j = i;j<13;j++)
            {
                if(useNum>=numDict[j].first)
                {
                    useNum = useNum - numDict[j].first;
                    Roman = Roman + numDict[j].second;
                    i = j;
                    break;
                }
            }
        }
        return Roman;
    }
};

int main() {
    vector<int> height = {4, 3, 2, 1, 4};
    Solution *solution = new Solution;
//    cout << solution->maxArea(height);
    cout << solution->intToRoman(30);

}