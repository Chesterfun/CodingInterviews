//
// Created by chester on 19-5-19.
// 统计数字的二进制表示中1的个数
//

#include <iostream>

using namespace std;

class Solution {
public:
    int numberOf1Solu1(int n)
    {
        unsigned int flag = 1;
        int count = 0;

        while (flag != 0)  //当flag左移超出unsigned int范围(>2^32)时,会被截断，即为0
        {
            if ((n & flag) != 0)
            {
                count++;
            }
            flag <<= 1;
        }

        return count;
    }

    int numberOf1Solu2(int n) //把一个整数n减去1，再和原来的整数做与运算，会把该整数最右边一个1变成0，
                                // 那么该整数有多少个1，就会进行多少次与运算
                                //即循环的次数，就是二进制中1的个数
    {
        int count = 0;
        while (n)
        {
            count++;
            n = n&(n-1);
        }

        return count;
    }
};


int main()
{
    Solution solu;
    cout <<solu.numberOf1Solu1(4) <<endl;
    cout <<solu.numberOf1Solu1(5) <<endl;
    cout <<solu.numberOf1Solu1(-1) <<endl;

    cout <<solu.numberOf1Solu2(4) <<endl;
    cout <<solu.numberOf1Solu2(5) <<endl;
    cout <<solu.numberOf1Solu2(-1) <<endl;
    return 0;
}