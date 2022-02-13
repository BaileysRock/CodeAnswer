//
// Created by Alienware on 2022/2/13.
//

//给你一个由 n 个整数组成的数组nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组[nums[a], nums[b], nums[c], nums[d]]（若两个四元组元素一一对应，则认为两个四元组重复）：
//
//0 <= a, b, c, d< n
//        a、b、c 和 d 互不相同
//nums[a] + nums[b] + nums[c] + nums[d] == target
//        你可以按 任意顺序 返回答案 。
//
//
//
//示例 1：
//
//输入：nums = [1,0,-1,0,-2,2], target = 0
//输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
//示例 2：
//
//输入：nums = [2,2,2,2,2], target = 8
//输出：[[2,2,2,2]]


// 思路：
// 首先对数组排序
// 设置i指针从头遍历到length-3
// 设置j指针从i+1遍历到length-2
// 再设置pq指针p=j+1，q=length-1
// 每次移动指针时候检测移动后和移动前的值是否相同，若相同则继续移动
// p++，q--
// 遇到与目标值相同，则记录



//
// Created by 熊峰 on 2022/2/10.
//
# include <iostream>
# include <string>
# include <vector>
# include <unordered_map>
#include <algorithm>

using namespace std;


// 16 题
class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        vector<vector<int>> fourNum;
        if (nums.size() < 4)
            return fourNum;
        vector<int> numsSort;
        numsSort.assign(nums.begin(), nums.end());
        sort(numsSort.begin(), numsSort.end());
        int length = nums.size();
        for (int i = 0; i < length - 3; i++) {
            if(i!=0 && numsSort[i] == numsSort[i-1])
                continue;
            for (int j = i+1; j < length - 2; j++) {
                if(j!=i+1 && numsSort[j] == numsSort[j-1])
                    continue;
                int p = j + 1;
                int q = length - 1;
                while (p < q) {
                    long sum = (long)numsSort[i] + (long)numsSort[j] + (long)numsSort[p] + (long)numsSort[q];
                    if (sum == (long)target) {
                        fourNum.emplace_back(vector<int>() = {numsSort[i] ,numsSort[j] , numsSort[p] ,numsSort[q]});
                        while (p < q && numsSort[p] == numsSort[p + 1])
                            p++;
                        while (q > p && numsSort[q] == numsSort[q - 1])
                            q--;
                        p++;
                        q--;
                    }
                        // 此时要使sum减小，只能使右指针向左
                    else if (sum > (long)target) {
                        while (q > p && numsSort[q] == numsSort[q - 1])
                            q--;
                        q--;
                    } else if (sum < (long)target) {
                        while (p < q && numsSort[p] == numsSort[p + 1])
                            p++;
                        p++;
                    }
                }
            }
        }
        return fourNum;
    }

};

int main() {
    Solution *solution = new Solution();
    vector<vector<int>> c = solution->fourSum(vector<int>() = {1000000000,1000000000,1000000000,1000000000},8);
    return 0;
}
