//
// Created by Alienware on 2022/2/13.
//

//
// Created by 熊峰 on 2022/2/10.
//
# include <iostream>
# include <string>
# include <vector>
# include <unordered_map>
#include <algorithm>

using namespace std;

// 思路：
// 首先对数组排序
// 设置i指针从头遍历到length-2
// 再设置jk指针j=i+1，k=length-1
// 每次移动指针时候检测移动后和移动前的值是否相同，若相同则继续移动
// j++，k--
// 遇到更小的差值，则记录

// 16 题
class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        if (nums.size() < 3)
            return 0;
        vector<int> numsSort;
        numsSort.assign(nums.begin(), nums.end());
        sort(numsSort.begin(), numsSort.end());
        int minusMin = numsSort[0] + numsSort[1] + numsSort[2];
        int length = numsSort.size();
        int sum;
        for (int i = 0; i < length; i++) {
            int j = i + 1;
            int k = length - 1;
            while (j < k) {
                sum = numsSort[i] + numsSort[j] + numsSort[k];
                if (sum == target)
                    return target;
                    // sum大，只有k往左移才能减小
                else if (sum > target) {
                    if (abs(sum - target) < abs(target - minusMin))
                        minusMin = sum;
                    k--;
                }
                    // sum小，只有j往右移才能增大
                else if (sum < target) {
                    if (abs(sum - target) < abs(target - minusMin))
                        minusMin = sum;
                    j++;
                }
            }
        }
        return minusMin;
    }

};

int main() {
    Solution *solution = new Solution();
    vector<int> test = {-2, 0, 0, 2, 2};
    int a = solution->threeSumClosest(test,30);
    cout<<a;
    return 0;
}
