//
// Created by Alienware on 2021/9/11.
//


//给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。
//
//输入：nums1 = [1,3], nums2 = [2]
//输出：2.00000
//解释：合并数组 = [1,2,3] ，中位数 2
//
//输入：nums1 = [1,2], nums2 = [3,4]
//输出：2.50000
//解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
//
//输入：nums1 = [0,0], nums2 = [0,0]
//输出：0.00000
//
//输入：nums1 = [], nums2 = [1]
//输出：1.00000
//
//输入：nums1 = [2], nums2 = []
//输出：2.00000

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int Length1 = nums1.size();
        int Length2 = nums2.size();

        if (Length2 == 0) {
            if (Length1 % 2 == 0) {
                return ((double) nums1[Length1 / 2 - 1] + (double) nums1[Length1 / 2]) / 2;
            } else {
                return (double) nums1[Length1 / 2];
            }
        }
        if (Length1 == 0) {
            if (Length2 % 2 == 0) {
                return ((double) nums2[Length2 / 2 - 1] + (double) nums2[Length2 / 2]) / 2;
            } else {
                return (double) nums2[Length2 / 2];
            }
        }

        int count = 0;
        int median = (Length1 + Length2 - 1) / 2;
        int nums1Ptr = 0;
        int nums2Ptr = 0;
        int flag = 0;
        while (count != median) {

            if (nums1Ptr == Length1) {
                if ((Length1 + Length2) % 2 == 0) {
                    int middle = nums2Ptr+(Length1+Length2)/2-count;
                    double left = (double)nums1[middle-1];
                    double right = (double)nums1[middle];
                    return (left+right)/2;
                } else {
                    int middle = nums2Ptr+(Length1+Length2)/2-count;
                    double middleNum = (double)nums1[middle-1];
                    return middleNum;
                }
            }
            if (nums2Ptr == Length2) {
                if ((Length1 + Length2) % 2 == 0) {
                    int middle = nums1Ptr+(Length2+Length1)/2-count;
                    double left = (double)nums2[middle-1];
                    double right = (double)nums2[middle];
                    return (left+right)/2;
                } else {
                    int middle = nums1Ptr+(Length2+Length1)/2-count;
                    double middleNum = (double)nums2[middle-1];
                    return middleNum;
                }
            }

            if (nums1[nums1Ptr] <= nums2[nums2Ptr]) {
                nums1Ptr++;
            } else if (nums1[nums1Ptr] > nums2[nums2Ptr]) {
                nums2Ptr++;
            }
            count++;
        }

        if ((Length1 + Length2) % 2 == 0) {
            return ((double) nums1[nums1Ptr] + (double) nums2[nums2Ptr]) / 2;
        } else {
            double number1 = (double) nums1[nums1Ptr];
            double number2 = (double) nums2[nums2Ptr];
            return number1 < number2 ? number1 : number2;
        }
    }
};

using namespace std;

int main() {

    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {-1,3};
    cout << (new Solution)->findMedianSortedArrays(nums1, nums2);
    return 0;
}