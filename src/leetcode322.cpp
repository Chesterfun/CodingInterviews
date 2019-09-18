//
// Created by shmil on 2019/9/17.
// 找零钱，给定总金额和面值，求组成金额的最少零钱张数

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < coins.size(); ++j) {
                if (i - coins[j] >= 0 && dp[i - coins[j]] != -1) {
                    if (dp[i] == -1 || dp[i] > 1 + dp[i - coins[j]]) {
                        dp[i] = 1 + dp[i - coins[j]];
                    }
                }
            }
        }
        return dp[amount];
    }
};

int main(){
    vector<int> change = {1, 2, 5, 7, 10};
    int amount = 21;
    Solution solution;
    cout << solution.coinChange(change, amount) << endl;
    return 0;
}