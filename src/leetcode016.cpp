//
// Created by chester on 19-6-13.
// 最接近的三数之和。
// 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。
// 返回这三个数的和。假定每组输入只存在唯一答案。
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result = 0;
        int min_gap = INT32_MAX;

        sort(nums.begin(), nums.end());

        for (auto i = nums.begin(); i < nums.end()-2; ++i) {
            auto j = i+1;
            auto k = nums.end()-1;
            while (j<k)
            {
                int sum = *i + *j + *k;
                int gap = abs(sum - target);

                if (gap < min_gap)
                {
                    min_gap = gap;
                    result = sum;
                }

                if (sum < target) j++;
                else k--;
            }
        }

        return result;
    }
};

int main()
{
    vector<int> data = {2,3,1,0,-3,-9,4,3,-6};
    Solution solu;
    int target = 18;
    int res = solu.threeSumClosest(data, target);
    cout << res << endl;
    return 0;
}

