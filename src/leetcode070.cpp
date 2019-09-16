//
// Created by shmil on 2019/9/16.
// 爬楼梯
// 普通递归回溯方法超时!（即n=1||n=2时return n, 其他情况return climbStairs(n-1) + climbStairs(n-2))
// 正确解法：动态规划 （第i阶爬法数量=第i-1阶爬法数量+第i-2阶爬法数量）

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 3, 0);           //防止数组越界，当n=0时，保证下面的dp[i-1]和dp[i-2]不越界
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

int main(){
    int n;
    cin >> n;
    Solution solution;
    cout << solution.climbStairs(n) << endl;
    return 0;
}