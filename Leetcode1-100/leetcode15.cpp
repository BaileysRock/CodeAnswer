//
// Created by Alienware on 2022/2/13.
//

//给你一个包含 n 个整数的数组nums，判断nums中是否存在三个元素 a，b，c ，使得a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。
//
//注意：答案中不可以包含重复的三元组。
//示例 1：
//输入：nums = [-1,0,1,2,-1,-4]
//输出：[[-1,-1,2],[-1,0,1]]
//示例 2：
//输入：nums = []
//输出：[]
//示例 3：
//输入：nums = [0]
//输出：[]

// 思路：
// 首先对数组排序
// 设置i指针从头遍历到length-2
// 再设置jk指针j=i+1，k=length-1
// 每次移动指针时候检测移动后和移动前的值是否相同，若相同则继续移动
// j++，k--
// 遇到与目标值相同，则记录

# include <iostream>
# include <string>
# include <vector>
# include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> Sum0 = {};
        int length = nums.size();
        if (length < 3)
            return Sum0;
        vector<int> numsSort;
        numsSort.assign(nums.begin(), nums.end());
        sort(numsSort.begin(), numsSort.end());
        for (int i = 0; i < length - 2 && numsSort[i] <= 0; i++) {
            // 判断是否有重复的数
            if (i != 0 && numsSort[i] == numsSort[i - 1])
                continue;
            // 若不存在重复的数，即可以求解
            int j = i + 1;
            int k = length - 1;
            int sum;
            while (j < k) {
                sum = numsSort[i] + numsSort[j] + numsSort[k];
                if (sum == 0) {
                    Sum0.emplace_back(vector<int>() = {numsSort[i], numsSort[j], numsSort[k]});
                    while (j < k && numsSort[j] == numsSort[j + 1]) j++;
                    while (k > j && numsSort[k] == numsSort[k - 1]) k--;
                    j++;
                    k--;
                }
                    // sum<0表明j部分过小，j指针移动
                else if (sum < 0) {
                    while (j < k && numsSort[j] == numsSort[j + 1]) j++;
                    j++;
                }
                    // sum>0表明k部分过大，k指针移动
                else if (sum > 0) {
                    while (k > j && numsSort[k] == numsSort[k - 1]) k--;
                    k--;
                }
            }
        }
        return Sum0;
    }





};

int main() {
    Solution *solution = new Solution();
    vector<int> test = {-2, 0, 0, 2, 2};
    vector<vector<int>> a = solution->threeSum(test);
    return 0;

}
