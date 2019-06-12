//
// Created by chester on 19-6-12.
// 三数之和。给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组
// 分析思路：先排序，然后左右夹逼，跳过重复的数
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size()<3) return result;
        sort(nums.begin(), nums.end());
        const int target = 0;

        vector<int>::iterator last = nums.end();         // end()函数指向容器的最后一个元素的下一个位置
        for (auto i = nums.begin(); i < last-2; ++i) {
            auto j = i+1;
            if (i > nums.begin() && *i == *(i-1)) continue;
            auto k = last-1;
            while (j < k)
            {
                if (*i + *j + *k < target)
                {
                    j++;
                    while (*j == *(j-1) && (j<k)) j++;
                }
                else if(*i + *j + *k > target)
                {
                    k--;
                    while (*k == *(k+1) && (j<k)) k--;
                } else
                {
                    result.push_back({*i, *j, *k});
                    j++;
                    k--;
                    while (*j == *(j-1) && *k == *(k+1) && (j<k)) ++j;
                }
            }
        }

        return result;

    }


};

int main()
{
    Solution solu;
    vector<vector<int>> res;
    vector<int> data = {2,-1,5,-4,0,-3,3,1};
    res = solu.threeSum(data);
    return 0;
}

