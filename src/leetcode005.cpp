//
// Created by chester on 19-5-7.
//
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {

        int n = s.size();
        bool f[n][n];
        fill_n(&f[0][0], n*n, false);
        int maxLen = 1;
        int start = 0;

        for (int i = 0; i < n; ++i) {
            f[i][i] = true;
            for (int j = 0; j < i; ++j) {
                f[j][i] = (s[j] == s[i]) && (i-j<2 || f[j+1][i-1]);
                if (f[j][i] && maxLen < i-j+1)
                {
                    maxLen = i-j+1;
                    start = j;
                }
            }
        }
        return s.substr(start, maxLen);

    }
};


int main()
{
    string s1 = "cbbccbb";
    Solution solu;
    cout<<solu.longestPalindrome(s1)<<endl;

    return 0;
}