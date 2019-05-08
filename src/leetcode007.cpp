//
// Created by chester on 19-5-8.
// 整数反转,考虑 1.负数的情况；2.整数范围溢出的情况
//

#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x)
    {
        long long r = 0;
        //long long t = x > 0?x:-x;    //严重错误！当x=-2147483648即2^-31时，-x在int类型溢出，
                                       //转化为long long时还是-2147483648；
        long long t = x;               //需要先将x强制转换为long long型再判断正负
        t = t > 0? t:-t;

        cout << t <<endl;

        for (; t; t/=10) {
            r = r*10 + t%10;
        }

        bool sign = x>0? false : true;
        //cout << sign <<endl;
        if ((r>2147483647) || (sign)&&(r>2147483648))
            return 0;
        else
        {
            if(sign)
                return -r;
            else
                return r;
        }
    }

    int reverse1 (int x) {
        long long r = 0;
        long long t = x;
        t = t > 0 ? t : -t;

        for (; t; t /= 10)
            r = r * 10 + t % 10;
        bool sign = x > 0 ? false : true;
        if (r > 2147483647 || (sign && r > 2147483648)) {
            return 0;
        } else {
            if (sign) {
                return -r;
            } else {
                return r;
            }
        }
    }
};

int main()
{
    int x = -2147483648;
    Solution solu;
    cout << solu.reverse(x) << endl;
    return 0;
}
