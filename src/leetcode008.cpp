//
// Created by chester on 19-5-9.
// 字符串转换整数(atoi)
//

#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    int myAtoi(string str)
    {
        int num = 0;
        int sign = 1;
        int n = str.size();
        int i = 0;
        while (str[i]== ' ' && i<n) i++;

        if(str[i] == '+') i++;
        else if(str[i] == '-')
        {
            i++;
            sign = -1;
        }

        for (; i < n ; ++i) {
            if (str[i] < '0' || str[i] > '9')
                break;
            if (num > INT32_MAX / 10 || (num == INT32_MAX/10 && (str[i] - '0') > INT32_MAX%10) )
            {
                return sign==-1?INT32_MIN:INT32_MAX;
            }
            //num = num * 10 + str[i] - '0';   //当num×10恰好为INT32_MAX时，先加str[i]可能会超出int表示的范围
            num = num * 10 - '0' + str[i];
        }
        return num * sign;
    }
};


int main ()
{
    //cout << INT32_MAX << endl;

    string str = "2147483646";
    Solution solution;
    cout << solution.myAtoi(str) << endl;
    return 0;
}