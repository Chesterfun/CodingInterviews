//
// Created by chester on 19-5-10.
// 判断一个整数是否是回文数
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;

        int t = x;

        long long num = 0;
        for (; t ; t/=10) {
            num = num * 10 + t % 10;
        }

        if (num > INT32_MAX)
            return false;
        if (num == x)
            return true;
        else
            return false;
    }
};

int main()
{
    int x = -1111;
    Solution solution;
    cout << solution.isPalindrome(x) << endl;

    return 0;
}
