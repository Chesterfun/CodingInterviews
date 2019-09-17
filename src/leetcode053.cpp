//
// Created by shmil on 2019/9/17.
// 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int maxSum = dp[0];
        for (int i = 1; i < nums.size(); ++i) {
            dp[i] = dp[i - 1] > 0 ? dp[i-1] + nums[i] : nums[i];
            if (maxSum < dp[i]) {
                maxSum = dp[i];
            }
        }
        return maxSum;
    }
};

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution solution;
    cout << solution.maxSubArray(nums) << endl;
    return 0;
}

