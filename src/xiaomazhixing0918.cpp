//
// Created by shmil on 2019/9/18.
// 小马智行笔试题
// 有n个石头从左到右排成一排，石头的颜色用数字ai表示。小青蛙在第1个石头上，他想跳到第n个石头。但跳跃方式只有以下两种：
// 1.每次跳一个石头，从第i个石头跳到第i+1个石头
// 2.从当前石头跳到离右边最近的一个颜色相同的石头。
// 计算青蛙一共至少需要跳几次到达第n个石头
// 输入石头个数n和每个石头的颜色ai组成的数组，输出最少跳的次数。示例：
// input:
// 6
// 1 2 4 1 4 2
// output:
// 2
// 从1（1）->2(2)->2(6)
// 思路动态规划

#include <bits/stdc++.h>

using namespace std;

int minJump(vector<int> nums){
    vector<int> dp(nums.size(), 0);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i < nums.size(); ++i) {
        int tmp = i - 1;
        for (int j = i-1; j >=0 ; --j) {
            if (nums[j] == nums[i]) {
                tmp = j;
            }
        }
        dp[i] = min(dp[i - 1] + 1, dp[tmp] + 1);
    }
    return dp[nums.size() - 1];
}

int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }

    cout << minJump(vec) << endl;
    return 0;
}
