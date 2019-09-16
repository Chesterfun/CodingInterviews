//
// Created by shmil on 2019/9/16.
// 打家劫舍
// 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
// 给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。
// 动态规划题目（思路：从第i(i>2>个元素开始，要么打劫第i个，则i-1个不打劫，最高金额为前i-2个加当前第i个；要么不打劫第i个，则最高金额即前i-1个；最高金额为这两种情况更大的金额数量）


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        vector<int> pd(nums.size(), 0);
        pd[0] = nums[0];
        pd[1] = nums[0] > nums[1] ? nums[0] : nums[1];
        for (int i = 2; i < pd.size(); ++i) {
            int tmp_a = nums[i] + pd[i - 2];
            int tmp_b = pd[i - 1];
            pd[i] = tmp_a > tmp_b ? tmp_a : tmp_b;
        }
        return pd[nums.size() - 1];
    }
};

int main() {
    vector<int> vec = {2, 7, 9, 3, 1};
    Solution solution;
    cout << solution.rob(vec) << endl;

    return 0;
}