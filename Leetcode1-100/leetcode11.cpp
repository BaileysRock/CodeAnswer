//
// Created by Alienware on 2022/2/13.
//

//给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点(i,ai) 。在坐标内画 n 条垂直线，垂直线 i的两个端点分别为(i,ai) 和 (i, 0) 。找出其中的两条线，使得它们与x轴共同构成的容器可以容纳最多的水。
//示例 1：
//输入：[1,8,6,2,5,4,8,3,7]
//输出：49
//解释：图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
//示例 2：
//
//输入：height = [1,1]
//输出：1
//示例 3：
//
//输入：height = [4,3,2,1,4]
//输出：16
//示例 4：
//
//输入：height = [1,2,1]
//输出：2

// 思想：
// 使用双指针
// 每次移动较小的一边
// area = min(len1,len2)*distance
// 只要移动distance就会减小
// 比较len1 len2
// 若移动较大的，由于较小的不变，因此此时得到的一定小于原来的最小边，且distance-1
// 故移动较小的一边

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
};

int main() {
    vector<int> height = {4, 3, 2, 1, 4};
    Solution *solution = new Solution;
    cout << solution->maxArea(height);
    return 0;
}