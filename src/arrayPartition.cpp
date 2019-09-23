//
// Created by shmil on 2019/9/22.
// 输入一个数组，将其分为两个数组，使得两个数组的数字之和相差最小，输出相差的数值
// 示例：如输入数组为[3,5,7,10]，则输出1.即5和7分为一组，3和10分为一组
// 0-1背包问题，转化为用数组里的数组成接近sum/2的最大值
//

#include <bits/stdc++.h>

using namespace std;

int minGap(vector<int> arr){
    int sum = 0;
    for (int i = 0; i < arr.size(); ++i) {
        sum += arr[i];
    }
    vector<vector<int>> dp(arr.size()+1, vector<int> (sum / 2 + 1));  //dp[i][j]代表用前i个物体装容量为j的背包能装下的最大值

    for (int i = 0; i < dp.size(); ++i) {
        dp[i][0] = 0;
    }

    for (int j = 0; j < dp[0].size(); ++j) {
        dp[0][j] = 0;
    }

    for (int i = 1; i <= arr.size(); ++i) {
        for (int j = 1; j <= sum / 2; ++j) {
            if (arr[i-1] > j) {                         //arr[i-1]代表第i个物体容量，如果超过j，则选择不放入
                dp[i][j] = dp[i - 1][j];
            } else if (dp[i - 1][j - arr[i-1]] + arr[i-1] > dp[i - 1][j]) {
                dp[i][j] = dp[i - 1][j - arr[i-1]] + arr[i-1];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return sum - 2 * dp[arr.size()][sum / 2];
//    return dp[arr.size()][sum / 2];
}

int main(){
    vector<int> arr = {3, 5, 7, 10};
    cout << minGap(arr) << endl;
}
