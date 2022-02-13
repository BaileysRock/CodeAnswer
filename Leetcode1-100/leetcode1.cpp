//
// Created by Alienware on 2021/8/20.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

// 暴力搜索
//class Solution {
//public:
//    vector<int> twoSum(vector<int>& nums, int target) {
//
//        for(int i =0;i<nums.size()-1;i++)
//        {
//            for(int j =0;j<nums.size();j++)
//            {
//                if(nums[i]+nums[j]==target)
//                {
//                    return vector<int>{i,j};
//                }
//            }
//        }
//    }
//};

// 使用减法
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result(2,-1);
        map<int,int> DataMap;
        // 将所有元素插入DataMap中
        for(int i = 0;i<nums.size();i++)
        {
            DataMap.insert(map<int,int>::value_type(nums[i],i));
        }
        // 遍历
        // 使用target减去当前的数，若存在数组，且序号不同
        // 则说明这两个为带寻找元素
        for(int i =0;i<nums.size();i++)
        {
            if(DataMap.count(target-nums[i])>0 && DataMap[target-nums[i]] != i)
            {
                result[0] = i;
                result[1] = DataMap[target-nums[i]];
                break;
            }
        }
        return result;
    };
};


int main()
{
    vector <int> num = {1,2,3,4,5};

    vector<int> result = (new Solution)->twoSum(num,5);

    std:cout<<"["<<result[0]<<","<<result[1]<<"]"<<endl;

    return 0;
}

