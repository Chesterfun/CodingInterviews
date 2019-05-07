//
// Created by chester on 19-5-6.
// 两数之和：给定一个整数数组nums和一个目标值target,在数组中找出和为目标值的两个整数并返回其下标
//
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> hash;
        vector<int> res;

        for (int i = 0; i < nums.size(); ++i) {
            int numbersToFind = target - nums[i];
            if (hash.find(numbersToFind) != hash.end())
            {
                res.push_back(hash[numbersToFind]);
                res.push_back(i);
                break;
            }

            hash[nums[i]] = i;
        }
        return res;
    }
};

int main()
{
    vector<int> nums = {2,7,11,15};

    int target = 13;

    Solution solu;

    vector<int> res = solu.twoSum(nums,target);

    for (int i = 0; i < res.size(); ++i) {
        cout<<res[i]<<" ";
    }

    return 0;
}
