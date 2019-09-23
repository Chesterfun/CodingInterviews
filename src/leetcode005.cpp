//
// Created by chester on 19-5-7.
// 最长回文子串，动态规划：dp[i][j]代表区间（i,j)位置的字符串是否为回文串
// 状态转移方程为dp[i][j] = true, if i = j
//              dp[i][j] = s[i]==s[j] and (j-i<2 or dp[i-1][j+1]）
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        size_t start = 0, max_len = 1;
        for (int j = 0; j < n; ++j) {
            dp[j][j] = true;
            for (int i = 0; i < j; ++i) {
                dp[i][j] = (s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1]));
                if (dp[i][j] && j - i + 1 > max_len) {
                    max_len = j - i + 1;
                    start = i;
                }
            }
        }
        return s.substr(start, max_len);
    }
};


int main()
{
    string s1 = "cbbccbb";
    Solution solu;
    cout<<solu.longestPalindrome(s1)<<endl;

    return 0;
}